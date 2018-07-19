#include "chunks.h"
#include <util/setbaud.h>



void UART_init(void)
{
	UCSRB = _BV(RXEN) | _BV(TXEN);
	UCSRC = _BV(UCSZ1) | _BV(UCSZ0);
	UBRRL = UBRR_VALUE;				// from setbaud.h
}

char UART_get(void)
{
	while ( !(UCSRA & (1<<RXC)));
	return UDR;
}

void UART_put(uint8_t data)
{
	while ( !(UCSRA & (1<<UDRE)));
	UDR = data;
}

void UART_put_str(char* str)
{
	while(*str != '\0')
	{
		UART_put(*str);
		str++;
	}
}
