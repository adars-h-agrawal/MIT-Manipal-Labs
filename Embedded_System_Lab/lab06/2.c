#include <LPC17xx.h>

int main(void)
{
    SystemInit();
    SystemCoreClockUpdate();

    LPC_PINCON->PINSEL0 = 0x00000000;       // P0.0 as GPIO (LED)
    LPC_PINCON->PINSEL4 &= ~(3 << 24);      // P2.12 as GPIO

    LPC_GPIO0->FIODIR |= (1 << 0);          // P0.0 as output (LED)
    LPC_GPIO2->FIODIR &= ~(1 << 12);        // P2.12 as input (Switch)

    while(1)
    {
        if ((LPC_GPIO2->FIOPIN & (1 << 12)) == 0)  // If switch is pressed (active low)
            LPC_GPIO0->FIOSET = (1 << 0);          // Turn ON LED
        else
            LPC_GPIO0->FIOCLR = (1 << 0);          // Turn OFF LED
    }
}