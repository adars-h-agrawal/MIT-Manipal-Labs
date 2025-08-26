#include <LPC17xx.h>
#include <stdio.h>
#include <stdlib.h>  // for abs()

#define RS (1<<8)
#define EN (1<<9)
#define LCD_DATA_MASK 0xF0

void delay(unsigned int t) {
    for (unsigned int i = 0; i < t * 1000; i++);
}

void lcd_cmd(unsigned char cmd) {
    LPC_GPIO0->FIOCLR = LCD_DATA_MASK;  // Clear data
    LPC_GPIO0->FIOCLR = RS;
    LPC_GPIO0->FIOSET = (cmd & 0xF0);   // Send upper nibble
    LPC_GPIO0->FIOSET = EN;
    delay(2);
    LPC_GPIO0->FIOCLR = EN;

    delay(2);

    LPC_GPIO0->FIOCLR = LCD_DATA_MASK;
    LPC_GPIO0->FIOSET = (cmd << 4) & LCD_DATA_MASK; // Lower nibble
    LPC_GPIO0->FIOSET = EN;
    delay(2);
    LPC_GPIO0->FIOCLR = EN;

    delay(5);
}

void lcd_data(unsigned char data) {
    LPC_GPIO0->FIOCLR = LCD_DATA_MASK;
    LPC_GPIO0->FIOSET = RS;
    LPC_GPIO0->FIOSET = (data & 0xF0);
    LPC_GPIO0->FIOSET = EN;
    delay(2);
    LPC_GPIO0->FIOCLR = EN;

    delay(2);

    LPC_GPIO0->FIOCLR = LCD_DATA_MASK;
    LPC_GPIO0->FIOSET = RS;
    LPC_GPIO0->FIOSET = (data << 4) & LCD_DATA_MASK;
    LPC_GPIO0->FIOSET = EN;
    delay(2);
    LPC_GPIO0->FIOCLR = EN;

    delay(5);
}

void lcd_init() {
    LPC_GPIO0->FIODIR |= 0xFF;  // Set P0.0–P0.7 as output
    delay(20);
    lcd_cmd(0x02); // 4-bit mode
    lcd_cmd(0x28); // 2-line, 5x7
    lcd_cmd(0x0C); // Display ON, cursor OFF
    lcd_cmd(0x06); // Entry mode
    lcd_cmd(0x01); // Clear display
}

void lcd_print(char *str) {
    while (*str) {
        lcd_data(*str++);
    }
}

unsigned int read_adc(int channel) {
    LPC_SC->PCONP |= (1 << 12);      // Power up ADC
    LPC_ADC->ADCR = (1 << channel) | (1 << 21);  // Select channel & start ADC

    while (!(LPC_ADC->ADGDR & (1 << 31)));       // Wait for conversion

    unsigned int result = (LPC_ADC->ADGDR >> 4) & 0xFFF;  // 12-bit result
    LPC_ADC->ADCR &= ~(1 << 21);                 // Stop ADC

    return result;
}

int main() {
    SystemInit();
    SystemCoreClockUpdate();
    lcd_init();

    // Configure P1.30 (AD4) and P1.31 (AD5) as ADC inputs
    LPC_PINCON->PINSEL3 |= (3 << 28) | (3 << 30);  // P1.30 → AD4, P1.31 → AD5

    char buffer[16];
    unsigned int val1, val2, diff;

    while (1) {
        val1 = read_adc(4);  // Read ADC channel 4
        val2 = read_adc(5);  // Read ADC channel 5
        diff = abs(val1 - val2);

        lcd_cmd(0x80);  // First line
        lcd_print("ADC4-ADC5 Diff:");

        sprintf(buffer, "%4d", diff);
        lcd_cmd(0xC0);  // Second line
        lcd_print("Value: ");
        lcd_print(buffer);

        delay(500);  // ~500ms
        lcd_cmd(0x01); // Clear screen for refresh
    }
}
