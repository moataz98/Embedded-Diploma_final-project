/*
 * lcd.h
 *
 *  Created on: 9 Oct 2019
 *      Author: Moataz
 */

#ifndef LCD_H_
#define LCD_H_

#include "common_macros.h"
#include "micro_config.h"
#include "std_types.h"

#define RS PB2
#define RW PB1
#define E PB0
#define LCD_CTRL_PORT PORTB
#define LCD_CTRL_PORT_DIR DDRB

#define LCD_DATA_PORT PORTA
#define LCD_DATA_PORT_DIR DDRA

/* LCD commands*/
#define CLEAR_COMMAND 0x01
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Four_BIT_MODE 0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80

void LCD_init();
void LCD_sendCommand(uint8 a_command);
void LCD_displayCharacter(uint8 a_data);
void LCD_displayString(const uint8 *a_str);
void LCD_goToRowColumn(uint8 a_row, uint8 a_col);
void LCD_displayStringRowColumn(const uint8 *a_str, uint8 a_row, uint8 a_col);
void LCD_clearScreen();
void LCD_integerToString();

#endif /* LCD_H_ */
