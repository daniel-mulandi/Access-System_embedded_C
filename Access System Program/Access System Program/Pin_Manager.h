/*
 * Pin_Manager.h
 *
 * Created: 11/17/2022 10:13:30 PM
 *  Author: newto
 */ 


#ifndef PIN_MANAGER_H_
#define PIN_MANAGER_H_


#define F_CPU 8000000ul
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>

#define INPUT_DIR DDRB
#define OUTPUT_DIR DDRC
#define BILED_DIR DDRD

#define INPUT_PORT PORTB
#define OUTPUT_PORT PORTC
#define BILED_PORT PORTD

#define INPUT_PIN PINB
#define OUTPUT_PIN PINC



#endif /* PIN_MANAGER_H_ */