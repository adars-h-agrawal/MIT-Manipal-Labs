#include <LPC17xx.h>
#include <stdio.h>

#define RS (1<<8)
#define EN (1<<9)
#define LCD_PORT LPC_GPIO0
#define CTRL_PORT LPC_GPIO0

void delay(unsigned int t) {
    for (unsigned int i = 0; i < t * 1000; i++);
}

void lcd_cmd(unsigned char cmd) {
    LCD_PORT->FIOCLR = 0xFF << 4;       // Clear data pins
    LCD_PORT->FIOCLR = RS;              // RS = 0 for command
    LCD_PORT->FIOSET = (cmd & 0xF0) << 0;   // Upper nibble
    LCD_PORT->FIOSET = EN;
    delay(2);
    LCD_PORT->FIOCLR = EN;

    delay(2);

    LCD_PORT->FIOCLR = 0xFF << 4;
    LCD_PORT->FIOSET = (cmd & 0x0F) << 4;   // Lower nibble
    LCD_PORT->FIOSET = EN;
    delay(2);
    LCD_PORT->FIOCLR = EN;

    delay(5);
}

void lcd_data(unsigned char data) {
    LCD_PORT->FIOCLR = 0xFF << 4;
    LCD_PORT->FIOSET = RS;              // RS = 1 for data
    LCD_PORT->FIOSET = (data & 0xF0) << 0;
    LCD_PORT->FIOSET = EN;
    delay(2);
    LCD_PORT->FIOCLR = EN;

    delay(2);

    LCD_PORT->FIOCLR = 0xFF << 4;
    LCD_PORT->FIOSET = (data & 0x0F) << 4;
    LCD_PORT->FIOSET = EN;
    delay(2);
    LCD_PORT->FIOCLR = EN;

    delay(5);
}

void lcd_init() {
    LCD_PORT->FIODIR |= 0xFF << 4;  // P0.4–P0.11 as output
    CTRL_PORT->FIODIR |= RS | EN;

    delay(20);
    lcd_cmd(0x02); // 4-bit mode
    lcd_cmd(0x28); // 2-line, 5x7
    lcd_cmd(0x0C); // Display ON, cursor OFF
    lcd_cmd(0x06); // Auto increment
    lcd_cmd(0x01); // Clear screen
}

void lcd_print(char *str) {
    while (*str) {
        lcd_data(*str++);
    }
}

char keypad[4][4] = {
    {'1','2','3','+'},
    {'4','5','6','-'},
    {'7','8','9','='},
    {'C','0','.','E'}
};

char read_keypad() {
    LPC_GPIO2->FIODIR = 0xF << 10;   // P2.10–P2.13 output (rows)
    LPC_GPIO1->FIODIR &= ~(0xF << 23); // P1.23–P1.26 input (columns)

    while (1) {
        for (int row = 0; row < 4; row++) {
            LPC_GPIO2->FIOCLR = 0xF << 10;
            LPC_GPIO2->FIOSET = (1 << (10 + row));

            delay(1);

            for (int col = 0; col < 4; col++) {
                if (!(LPC_GPIO1->FIOPIN & (1 << (23 + col)))) {
                    while (!(LPC_GPIO1->FIOPIN & (1 << (23 + col))));  // wait for release
                    return keypad[row][col];
                }
            }
        }
    }
}

int main() {
    SystemInit();
    SystemCoreClockUpdate();
    lcd_init();

    char A = 0, B = 0, op = 0;
    char key;
    char result_str[16];
    int result = 0;

    lcd_print("Expr: ");

    while (1) {
        key = read_keypad();

        lcd_data(key);  // Display key

        if (key >= '0' && key <= '9') {
            if (!A)
                A = key - '0';
            else
                B = key - '0';
        }
        else if (key == '+' || key == '-') {
            op = key;
        }
        else if (key == '=') {
            if (op == '+')
                result = A + B;
            else if (op == '-')
                result = A - B;

            lcd_cmd(0xC0);  // Move to second line
            sprintf(result_str, "Res: %d", result);
            lcd_print(result_str);

            // Reset for next input
            A = B = op = 0;
            delay(5000);
            lcd_cmd(0x01); // Clear LCD
            lcd_print("Expr: ");
        }
    }
}