#include "uart.h"

void UART_init()
{
    SET_BIT(UCSRA, U2X);   /*enabling double speed*/
    SET_BIT(UCSRB, RXEN);  /*enabling reciever*/
    SET_BIT(UCSRB, TXEN);  /*enabling transmitter*/
    SET_BIT(UCSRC, URSEL); /*selecting UCSRC register*/
    SET_BIT(UCSRC, UPM1);  /*even parity*/
    SET_BIT(UCSRC, UCSZ1); /*8-bit mode*/
    SET_BIT(UCSRC, UCSZ0); /*8-bit mode*/
}

void UART_sendByte(uint8 a_data)
{
    while (BIT_IS_CLEAR(UCSRA, UDRE))
        ; /* waiting till transmitter is ready to send*/
    UDR = a_data;
}

uint8 UART_recieveByte()
{
    while (BIT_IS_CLEAR(UCSRA, RXC))
        ; /*waiting till data is written in the reciever buffer*/
    return UDR;
}

void UART_sendString(const uint8 *a_str)
{
    uint8 i = 0;
    while (a_str[i] != NULL)
    {
        UART_sendByte(a_str[i]);
        i++;
    }
}

void UART_recieveString(const uint8 *a_str)
{
    uint8 i = -1;
    do
    {
        i++;
        a_str[i] = UART_recieveByte();
    } while (a_str[i] != '$');
    a_str[i] = NULL;
}
