#include<LPC17xx.h>
unsigned int i;
unsigned int j;
unsigned long LED =0x00000FF0;
int main(void){
SystemInit();
SystemCoreClockUpdate();
LPC_PINCON->PINSEL0=0x00000000;//P0.15-P0.0 GPIO
LPC_GPIO0->FIODIR=0x00000ff0;
while(1){
	while(LPC_GPIO2->FIOPIN &1<<12)
	{
	LED=0X00000010;//intial value on LED
	for(i=1;i<5;i++)//on the LED's serially
	{
		LPC_GPIO0->FIOSET=LED;
		for(j=0;j<1000000;j++);
		LPC_GPIO0->FIOCLR=LED;
		LED<<=1;
	}
}

	while(!(LPC_GPIO2->FIOPIN &1<<12))
	{
		LED=0X00000100;//intial value on LED
	for(i=1;i<5;i++)//on the LED's serially
	{
		LPC_GPIO0->FIOSET=LED;
		for(j=0;j<1000000;j++);
		LED<<=1;
}
	LED=0x00000100;
	for(i=1;i<5;i++){ //off the LED's serially
		LPC_GPIO0->FIOCLR=LED;
		for(j=0;j<1000000;j++);
		LED<<=1;
}
}
}
}