/*	Author: mbaut030
 *  Partner(s) Name: Maverick
 *	Lab Section:
 *	Assignment: Lab 2  Exercise 4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
	unsigned char tmpA;
	unsigned char tmpB;
	unsigned char tmpC;
	unsigned char total = 0x00;
    while (1) {
	tmpA = PINA;
	tmpB = PINB;
	tmpC = PINC;
	total = tmpA + tmpB + tmpC;

	total = total >> 2;

	PORTD = total;
	PORTD = PORTD & 0xFC;

	if(total > 140) {
		PORTD = PORTD + 1;
	}
	if((tmpA - tmpC) > 80 || (tmpC - tmpA) > 80) {
		PORTD = PORTD + 2;
	}
    }
    return 1;
}
