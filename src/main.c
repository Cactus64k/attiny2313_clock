#include "chunks.h"

uint8_t sdigit[] = {
		SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,			// 0
		SEG_B | SEG_C,											// 1
		SEG_A | SEG_B | SEG_G | SEG_E | SEG_D,					// 2
		SEG_A | SEG_B | SEG_G | SEG_C | SEG_D,					// 3
		SEG_F | SEG_G | SEG_B | SEG_C,							// 4
		SEG_A | SEG_F | SEG_G | SEG_C | SEG_D,					// 5
		SEG_A | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G,			// 6
		SEG_A | SEG_B | SEG_C,									// 7
		SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G,	// 8
		SEG_A | SEG_B | SEG_C | SEG_D | SEG_F | SEG_G};			// 9

#define SIG_t (SEG_F | SEG_E | SEG_G | SEG_D)					// t
#define SIG_o (SEG_A | SEG_B | SEG_G | SEG_F)					// o

//		*----A----*
//		|         |
//		F         B
//		|         |
//		*----G----*
//		|         |
//		E         C
//		|         |
//		*----D----*  (DOT)

int main(void)
{
	DDRD	= DIG_0 | DIG_1 | DIG_2 | DIG_3 | LED;
	PORTD	= DIG_0 | DIG_1 | DIG_2 | DIG_3 | LED;
	DDRB	= 0XFF;

	uint8_t frame[4]		= {0, 0, 0, 0};

	timer1_frame_set(frame);

	timer1_init();
	UART_init();

	sei();

	while(1)
	{
		char buff[8] = {0};

		for(uint8_t i=0; i<8; i++)
		{
			buff[i] = UART_get();
			if(buff[i] == '\n')
				break;
		}

		uint8_t buff_pos = 0;

		for(uint8_t i=0; i<4; i++)
		{
			if((buff[buff_pos] >= '0') && (buff[buff_pos] <= '9'))
			{
				frame[i] = sdigit[buff[buff_pos] - '0'];

				buff_pos++;

				if(buff[buff_pos] == ':')
				{
					frame[i] = frame[i] | SEG_DOT;
					buff_pos++;
				}
			}
			else if(buff[buff_pos] == 't')
			{
				frame[i] = SIG_t;
				buff_pos++;
			}
			else if(buff[buff_pos] == 'o')
			{
				frame[i] = SIG_o;
				buff_pos++;
			}
			else
				frame[i] = 0;
		}

		timer1_frame_set(frame);


//		UART_put_str("Buff:\'");
//		for(uint8_t i=0; i<8; i++)
//			if(buff[i] == '\n')
//				UART_put_str("\\n");
//			else
//				UART_put(buff[i]);
//		UART_put_str("\'\n");

		PORTD = PORTD &(~LED);
		_delay_ms(10);
		PORTD = PORTD | LED;

	}

}
