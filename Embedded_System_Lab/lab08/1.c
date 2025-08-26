#include <LPC17xx.h>

unsigned char seg[10] = {0x3F, 0x06, 0x5B, 0x4F,
                         0x66, 0x6D, 0x7D, 0x07,
                         0x7F, 0x6F}; // 0–9

unsigned int count = 0; // 0000 to 9999

void delay_ms(unsigned int ms) {
    LPC_TIM0->TCR = 0x02; // Reset timer
    LPC_TIM0->PR = 3000;  // 1ms
    LPC_TIM0->MR0 = ms;
    LPC_TIM0->MCR = 0x04;
    LPC_TIM0->TCR = 0x01; // Start timer

    while (LPC_TIM0->TCR & 0x01);
}

void display(unsigned int value) {
    unsigned int digit[4];
    digit[0] = value / 1000;
    digit[1] = (value / 100) % 10;
    digit[2] = (value / 10) % 10;
    digit[3] = value % 10;

    for (int i = 0; i < 4; i++) {
        LPC_GPIO1->FIOCLR = 0x07800000;             // Clear P1.23-26
        LPC_GPIO1->FIOSET = (1 << (23 + i));        // Select digit

        LPC_GPIO0->FIOCLR = 0x00000FF0;             // Clear segments
        LPC_GPIO0->FIOSET = (seg[digit[i]] << 4);   // Set segments

        delay_ms(2);  // Small delay for persistence
    }
}

int main(void) {
    SystemInit();
    SystemCoreClockUpdate();

    // Configure 7-seg (P0.4–P0.11) and digit select (P1.23–P1.26)
    LPC_GPIO0->FIODIR |= 0x00000FF0;
    LPC_GPIO1->FIODIR |= 0x07800000;

    // Configure switch input on P2.12
    LPC_GPIO2->FIODIR &= ~(1 << 12);

    while (1) {
        for (int i = 0; i < 250; i++)  // ~1s refresh (4ms × 250 = 1s)
            display(count);

        if (!(LPC_GPIO2->FIOPIN & (1 << 12))) {
            count = (count + 1) % 10000;  // UP count
        } else {
            count = (count == 0) ? 9999 : count - 1;  // DOWN count
        }
    }
}
