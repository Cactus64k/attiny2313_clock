#ifndef CHUNKS_H_
	#define CHUNKS_H_

	#ifndef FCPU
		#define F_CPU 3686400UL
	#endif

	#ifndef DEVICE
		#define DEVICE attiny2313
	#endif

	#ifndef BAUD
		#define BAUD 9600
	#endif

	#ifndef __AVR_ATtiny2313__
		#define __AVR_ATtiny2313__
	#endif

	#include <avr/io.h>
	#include <util/delay.h>
	#include <stdint.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <util/setbaud.h>
	#include <avr/interrupt.h>

	#define SEG_A	_BV(PB2)
	#define SEG_B	_BV(PB0)
	#define SEG_C	_BV(PB4)
	#define SEG_D	_BV(PB6)
	#define SEG_E	_BV(PB7)
	#define SEG_F	_BV(PB1)
	#define SEG_G	_BV(PB3)
	#define SEG_DOT	_BV(PB5)

	#define LED		_BV(PD2)

	#define DIG_0	_BV(PD4)
	#define DIG_1	_BV(PD3)
	#define DIG_2	_BV(PD6)
	#define DIG_3	_BV(PD5)

	void UART_init(void);
	void UART_put(uint8_t data);
	void UART_put_str(char* str);
	char UART_get(void);

	void timer1_init(void);
	void timer1_frame_set(uint8_t* new_frame);

#endif /* CHUNKS_H_ */
