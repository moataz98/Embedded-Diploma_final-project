#include "keypad.h"

static uint8 KEYPAD_4x4_adjustSwitchNumber(uint8 a_btnNum);

uint8 KEYPAD_getPressedKey()
{
    uint8 col, row;
    while (1)
    {
        for (col = 0; col < N_COL; col++)
        {
            KEYPAD_PORT_DIR = (0b00000001 << col);
            KEYPAD_PORT_OUT = (~(0b00000001 << col));

            for (row = 0; row < N_ROW; row++)
            {
                if (BIT_IS_CLEAR(KEYPAD_PORT_IN, row + 4))
                {

                    while (BIT_IS_CLEAR(KEYPAD_PORT_IN, row + 4));

                    return KEYPAD_4x4_adjustSwitchNumber((row * N_COL) + col + 1);
                }
            }
        }
    }
}

static uint8 KEYPAD_4x4_adjustSwitchNumber(uint8 a_btnNum)
{
    switch (a_btnNum)
    {
    case 1:
        return '7';
        break;
    case 2:
        return '8';
        break;
    case 3:
        return '9';
        break;
    case 4:
        return '/';
        break;
    case 5:
        return '4';
        break;
    case 6:
        return '5';
        break;
    case 7:
        return '6';
        break;
    case 8:
        return '*';
        break;
    case 9:
        return '1';
        break;
    case 10:
        return '2';
        break;
    case 11:
        return '3';
        break;
    case 12:
        return '-';
        break;
    case 13:
        return 'c';
        break;
    case 14:
        return '0';
        break;
    case 15:
        return '=';
        break;
    case 16:
        return '+';
        break;

    default:
        break;
    }
}
