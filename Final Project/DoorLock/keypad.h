
#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "common_macros.h"
#include "micro_config.h"
#include "std_types.h"

#define N_COL 4
#define N_ROW 4

#define KEYPAD_PORT_DIR DDRC
#define KEYPAD_PORT_OUT PORTC
#define KEYPAD_PORT_IN PINC

uint8 KEYPAD_getPressedKey();

#endif /*KEYPAD_H_*/