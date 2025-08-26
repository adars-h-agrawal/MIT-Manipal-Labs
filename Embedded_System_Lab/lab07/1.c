#include<LPC17xx.h>
unsigned int i;
unsigned char count;
void delay()
{
	for(i = 0;i < 500000;i++);//time delay
}

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_GPIO2->FIODIR=0XFF; // set P2.0 - P2.7 as output
	count = 0;//8-bit counter
	while(1)
		{
			LPC_GPIO2->FIOPIN = count;//display count on LEDs
			count++;
			delay();//short delay
}
}