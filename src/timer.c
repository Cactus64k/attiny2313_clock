#include "chunks.h"

uint8_t frame[4]		= {0, 0, 0, 0};
uint8_t common_pin[4]	= {DIG_0, DIG_1, DIG_2, DIG_3};
uint8_t cur_seg			= 0;

ISR(TIMER1_COMPA_vect)
{
	PORTD = PORTD | common_pin[cur_seg];	// выключаем

	cur_seg++;
	if(cur_seg>3)
		cur_seg = 0;

	PORTB = frame[cur_seg];					// выставляем
	PORTD = PORTD & (~common_pin[cur_seg]);	// включаем
}

void timer1_init(void)
{
	TCCR1B	= _BV(WGM12) | _BV(CS12);//BV(CS11) | _BV(CS10);
	OCR1A	= 10;
	TIMSK	= _BV(OCIE1A);
}

void timer1_frame_set(uint8_t* new_frame)
{
	frame[0] = new_frame[0];
	frame[1] = new_frame[1];
	frame[2] = new_frame[2];
	frame[3] = new_frame[3];
}
