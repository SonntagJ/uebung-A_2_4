/*
 * BlinkaLed.c
 *
 * Created: 30.11.2017 14:23:25
 * Author : mtr87345
 */ 

//#include <avr/io.h>
//
//
//int main(void)
//{
	///* Replace with your application code */
	//while (1) 
	//{
	//}
//}

/* Der ATmega328P l�uft mit einer Frequenz von 16 MHz */
#define F_CPU 16000000L
/* Einbinden der benoetigten Bibliotheken */
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	/* LED A3 (PORTB01) als Ausgang setzen */
	DDRB = 0x02;
	/* Sensor Bandanfang und Bandende als Eingang definieren */
	DDRD = 0x00;
	PORTD = 0x0C;
	while (1)
	{
		/* Abfrage ob der Sensor an PORTD3 auf HIGH geschalten wird
		*/
		if ((PIND & 0x08)==0)
		{
			PORTB = 0x02; // LED einschalten Mode 1
			_delay_ms(200); // 100 ms warten
			PORTB = 0x00; // LED ausschalten Mode 1
			_delay_ms(200); // 100 ms warten
		}
		else
		{
			PORTB = 0x02; // LED einschalten Mode 2
			_delay_ms(100); // 500 ms warten
			PORTB = 0x00; // LED ausschalten Mode 2
			_delay_ms(100); // 500 ms warten
		}
	}
}
