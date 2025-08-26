#include <LPC17xx.h>

unsigned char seg[2] = {0x3F, 0x06}; // 0 and 1

unsigned char ring[4] = {1, 2, 4, 8};  // Binary values

void delay_ms(unsigned int ms) {
    LPC_TIM0->TCR = 0x02;
    LPC_TIM0->PR = 3000;
    LPC_TIM0->MR0 = ms;
    LPC_TIM0->MCR = 0x04;
    LPC_TIM0->TCR = 0x01;

    while (LPC_TIM0->TCR & 0x01);
}

void display_ring(unsigned char val) {
    for (int i = 0; i < 4; i++) {
        LPC_GPIO1->FIOCLR = 0x07800000;
        LPC_GPIO1->FIOSET = (1 << (23 + i));

        LPC_GPIO0->FIOCLR = 0x00000FF0;
        LPC_GPIO0->FIOSET = ((val >> (3 - i)) & 0x01 ? seg[1] : seg[0]) << 4;

        delay_ms(2);
    }
}

int main(void) {
    SystemInit();
    SystemCoreClockUpdate();

    LPC_GPIO0->FIODIR |= 0x00000FF0;
    LPC_GPIO1->FIODIR |= 0x07800000;

    int i = 0;

    while (1) {
        for (int j = 0; j < 250; j++)  // ~1s delay with refresh
            display_ring(ring[i]);

        i = (i + 1) % 4;
    }
}
