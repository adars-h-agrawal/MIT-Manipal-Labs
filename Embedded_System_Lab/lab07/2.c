#include<LPC17xx.h>
unsigned int i;
unsigned char count;
void delay()
{
	for(i = 0;i < 500000;i++);//time delay
}

int main(void)
{
	LPC_PINCON->PINSEL3 &= ~(3<<14);//configure P1.23 as GPIO
	LPC_GPIO1->FIODIR &= ~(1<< 23);// set P2.0 - P2.7 as output(LEDs)
	
	count = 0;
	//8-bit counter
	while(1){
		if(LPC_GPIO1->FIOPIN &(1<<23))
		{
			count++;
		}
		else{
			count--;
		}
		LPC_GPIO1->FIOPIN = count;
		delay();
		
}
}
