#include "lcd.h"
#include "keypad.h"

int main(void)
{
    LCD_init();

    while (1)
    {
        LCD_displayCharacter(KEYPAD_getPressedKey());
    }
}
