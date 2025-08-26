#include <LPC17xx.h>

unsigned int j;
unsigned long LED = 0x000000FF;

int main(void)
{
    SystemInit();
    SystemCoreClockUpdate();

    LPC_PINCON->PINSEL0 = 0x00000000;       // Configure P0.0 to P0.15 as GPIO
    LPC_GPIO0->FIODIR |= 0x000000FF;        // Set P0.0 to P0.7 as output

    while(1)
    {
        LPC_GPIO0->FIOSET = LED;            // Turn ON LEDs
        for(j = 0; j < 100000; j++);        // Delay
        LPC_GPIO0->FIOCLR = LED;            // Turn OFF LEDs
        for(j = 0; j < 100000; j++);        // Delay
    }
}