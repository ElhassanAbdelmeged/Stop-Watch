#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#define F_CPU 1000000UL

unsigned char g_sec=0;
unsigned char g_min=0;
unsigned char g_hour=0;


void INT0_SET (void)
{
	MCUCR|=(1<<ISC01);
	MCUCR &= ~(1<<ISC00); 	// INT0 TRIGRRING FALLING edge
	GICR|=(1<<INT0);		//enable IRQ of INT0
	// i bit was enabled in the main before
}


ISR(INT0_vect)
{
 //RESET
	g_sec=0;
	g_min=0;
	g_hour=0;

}


void INT1_SET(void)
{
	MCUCR |= (1<<ISC11)|(1<<ISC10); // INT1 TRIGRRING Rising edge
	GICR |=(1<<INT1);

}


ISR(INT1_vect)
{
	TCCR1B=0;  //pause
}

void INT2_SET(void)
{

	MCUCSR &= ~(1<<ISC2);		// INT2 TRIGRRING falling edge
	GICR |= (1<<INT2);
}

ISR(INT2_vect)
{

	TCCR1B|=(1<<WGM12)|(1<<CS10)|(1<<CS12);	//RESUME

}

void TIMER1_SET(void)
{

	TCNT1=0; 									//initial value
	TCCR1A=(1<<FOC1A);							// non PWM mode
	TCCR1B|=(1<<WGM12)|(1<<CS10)|(1<<CS12);  	/*CTC mode with N=1024	-->the resolution is 1MS so to make interrupt count until 1000*/
	OCR1A=1000; 								//compare value
	TIMSK=(1<<OCIE1A);							//interrupt enable

}



ISR(TIMER1_COMPA_vect)
{

	if(g_sec==60)
	{
		g_sec=0;

		if(g_min==60)
		{
			g_min=0;
			if(g_hour==24)
			{
				g_hour=0;
			}
			else
			{
				g_hour++;
			}

		}
		else{
			g_min++;

		}
	}

	else{
		g_sec++;

	}
}


int main (void)
{
	/*setting the pins */
	DDRA|=0x3F; 			// SET  THE Fist six pin in port A AS OUTPUT PINS
	PORTA &= ~0x3F;			// turning the segments off by applying 0 on the NPN transistors.

	DDRC |= 0x0F;			//setting the decoder pins as output
	PORTC &= ~0x0F;         // the decoder  pins  of PORTC=0

	DDRD|=(1<<PD3);  		// setting INT1 Pin as input pin
	PIND &= ~(1<<PD3);		// the button is not pressed as it is external pull down RES

	DDRD &= ~(1<<PD2); 		// setting INT0 Pin as input pin
	PORTD |= (1<<PD2);		// enable of the internal pull up RES
	PIND |=(1<<PD2);		// the button is not pressed as it is pull UP RES

	DDRB &= ~(1<<PB2);			// setting INT2 Pin as input pin
	PORTB |= (1<<PB2);		// enable of the internal pull up RES
	PINB |= (1<<PB2);
	sei();			// enable of I-bit IN SREG

	INT0_SET();
	INT1_SET();
	INT2_SET();
	TIMER1_SET();


	while(1){


		PORTA=0;
		PORTC= g_sec%10; //taking the ones of g_sec
		PORTA|=(1<<0);
		_delay_ms(2);




		PORTA=0;
		PORTC=g_sec/10; // taking the tens of g_sec
		PORTA|=(1<<1);
		_delay_ms(2);



		PORTA=0;
		PORTC=g_min%10;
		PORTA|=(1<<2);
		_delay_ms(2);


		PORTA=0;
		PORTC=g_min/10;
		PORTA|=(1<<3);
		_delay_ms(2);

		PORTA=0;
		PORTC=g_hour%10;
		PORTA|=(1<<4);
		_delay_ms(2);




		PORTA=0;
		PORTC=g_hour/10;
		PORTA|=(1<<5);
		_delay_ms(2);

	}
}