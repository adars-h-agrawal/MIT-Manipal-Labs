#include <LPC17xx.h>

char keypad[4][4] = {
    {'1','2','3','+'},
    {'4','5','6','-'},
    {'7','8','9','='},
    {'0','C','.','E'}
};

// Function prototypes
char read_keypad();
void PWM_init();
void set_PWM_duty(unsigned int duty_percent);
void delay(unsigned int t);

int main() {
    SystemInit();
    SystemCoreClockUpdate();

    PWM_init();

    char key;

    while (1) {
        key = read_keypad();

        switch (key) {
            case '0':
                set_PWM_duty(10); break;
            case '1':
                set_PWM_duty(25); break;
            case '2':
                set_PWM_duty(50); break;
            case '3':
                set_PWM_duty(75); break;
            default:
                break;
        }
        delay(100);  // delay to avoid bouncing
    }
}

// Set PWM1.2 duty cycle (percentage)
void set_PWM_duty(unsigned int duty_percent) {
    if (duty_percent > 100) duty_percent = 100;

    LPC_PWM1->MR2 = (LPC_PWM1->MR0 * duty_percent) / 100;  // Set duty cycle
    LPC_PWM1->LER = (1 << 2);  // Enable latch for MR2
}

// Initialize PWM1.2 on P2.1
void PWM_init() {
    LPC_PINCON->PINSEL4 &= ~(3 << 2);       // Clear bits for P2.1
    LPC_PINCON->PINSEL4 |= (1 << 3);        // Select PWM1.2 function for P2.1

    LPC_SC->PCONP |= (1 << 6);              // Power on PWM1
    LPC_PWM1->PCR = (1 << 10);              // Enable PWM1.2 output
    LPC_PWM1->MCR = (1 << 1);               // Reset TC on MR0 match

    LPC_PWM1->PR = 0;                       // No prescaler
    LPC_PWM1->MR0 = 1000;                   // PWM period (adjust for freq)
    LPC_PWM1->MR2 = 100;                    // Initial 10% duty
    LPC_PWM1->LER = (1 << 0) | (1 << 2);    // Enable latch for MR0 & MR2

    LPC_PWM1->TCR = (1 << 0) | (1 << 3);    // Enable counter and PWM mode
}

// Read key press from 4x4 keypad
char read_keypad() {
    LPC_GPIO2->FIODIR |= 0xF << 10;         // Rows P2.10–P2.13 as output
    LPC_GPIO1->FIODIR &= ~(0xF << 23);      // Columns P1.23–P1.26 as input

    while (1) {
        for (int row = 0; row < 4; row++) {
            LPC_GPIO2->FIOCLR = 0xF << 10;
            LPC_GPIO2->FIOSET = (1 << (10 + row));

            delay(1);

            for (int col = 0; col < 4; col++) {
                if (!(LPC_GPIO1->FIOPIN & (1 << (23 + col)))) {
                    while (!(LPC_GPIO1->FIOPIN & (1 << (23 + col))));  // Wait for release
                    return keypad[row][col];
                }
            }
        }
    }
}

// Simple delay
void delay(unsigned int t) {
    for (unsigned int i = 0; i < t * 1000; i++);
}