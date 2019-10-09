
#ifndef UART_H_
#define UART_H_

#include "common_macros.h"
#include "micro_config.h"
#include "std_types.h"

#define RX PD0
#define TX PD1

void UART_init();
void UART_sendByte(uint8 a_data);
uint8 UART_recieveByte();
void UART_sendString(const uint8 *a_str);
void UART_recieveString(const uint8 *a_str);

#endif /*UART_H_*/