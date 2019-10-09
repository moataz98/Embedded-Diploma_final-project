/*
 * lcd.c
 *
 *  Created on: 9 Oct 2019
 *      Author: Moataz
 */

#include "lcd.h"

void LCD_init()
{
    SET_BIT(LCD_CTRL_PORT_DIR, RS);
    SET_BIT(LCD_CTRL_PORT_DIR, RW);
    SET_BIT(LCD_CTRL_PORT_DIR, E);
    LCD_DATA_PORT_DIR = 0xFF;
    LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE);
    LCD_sendCommand(CURSOR_OFF);
    LCD_sendCommand(CLEAR_COMMAND);
}

void LCD_sendCommand(uint8 a_command)
{
    CLEAR_BIT(LCD_CTRL_PORT, RS);
    CLEAR_BIT(LCD_CTRL_PORT, RW);
    _delay_ms(1);
    SET_BIT(LCD_CTRL_PORT, E);
    _delay_ms(1);
    LCD_DATA_PORT = a_command;
    _delay_ms(1);
    CLEAR_BIT(LCD_CTRL_PORT, E);
    _delay_ms(1);
}

void LCD_displayCharacter(uint8 a_data)
{
    SET_BIT(LCD_CTRL_PORT, RS);
    CLEAR_BIT(LCD_CTRL_PORT, RW);
    _delay_ms(1);
    SET_BIT(LCD_CTRL_PORT, E);
    _delay_ms(1);
    LCD_DATA_PORT = a_data;
    _delay_ms(1);
    CLEAR_BIT(LCD_CTRL_PORT, E);
    _delay_ms(1);
}

void LCD_displayString(const uint8 *a_str)
{
    uint8 current_char = 0;
    while (a_str[current_char] != NULL)
    {
        LCD_displayCharacter(a_str[current_char]);
        current_char++;
    }
}

void LCD_goToRowColumn(uint8 a_row, uint8 a_col)
{
    uint8 address;
    switch (a_row)
    {
    case 0:
        address = a_col;
        break;

    case 1:
        address = 0x40 + a_col;
        break;
    }
    LCD_sendCommand(SET_CURSOR_LOCATION | address);
}

void LCD_displayStringRowColumn(const uint8 *a_str, uint8 a_row, uint8 a_col)
{
    LCD_goToRowColumn(a_row, a_col);
    LCD_displayString(a_str);
}

void LCD_clearScreen()
{
    LCD_sendCommand(CLEAR_COMMAND);
}

void LCD_integerToString(uint32 a_data)
{
    uint8 res[16];
    itoa(a_data, res, 10);
    LCD_displayString(res);
}
