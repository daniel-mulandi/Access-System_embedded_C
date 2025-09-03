/*
 * access_system.c
 *
 * Created: 23/08/2025 19:57:46
 * Author : Envy
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void setup(void);
void btn_press_flash();
void success(void);
void fail(void);
int count = 0;
int ACCESS [4] = {4,3,2,1};
int USER_IN [4] = {0,0,0,0};

int main(void)
{
    /* Replace with your application code */
	setup();
    while (1) 
    {
		
		// listen for button press
		while(count < 4){
			btn_press_flash();	
		}

		// validate access
		for(int i = 0; i < 4; i++){
			// validating users input
			if(USER_IN[i] != ACCESS[i]){
				// flash fail
				fail();	
			}
		}
		// flash success
		success();
		for(int i = 0; i < 4; i++){
			USER_IN [i] = 0;
		}
		return 0;	
    }
	void setup(void){
		// button setup
		DDRB = 0x00;
		// enabling internal pull up
		PORTB |= 0x0F;
		// led for button press
		DDRC = 0xFF;
		// bi-color led
		DDRD = 0xFF;
	}
	void btn_press_flash(int count){
		for (int i = 0; i < 4; i++) {
			if (!(PINB & (1 << i))) { // button pressed (active low)
				_delay_ms(50);        // press delay debouncing
				if (!(PINB & (1 << i))) {
					USER_IN[count] = i;   // store button number
					PORTC |= (1 << count); // light next feedback LED
					count++;

					while (!(PINB & (1 << i))); // wait until released
					_delay_ms(50); // release delay debouncing
				}
			}
		}
	}
	void success(void){
		PORTD |=(1 << PD0);
		PORTD &= ~(1 << PD1);
		_delay_ms(500);
		PORTD &= ~(1 << PD0);
		_delay_ms(500);
	}
	
	void fail(void){
		PORTD |=(1 << PD1);
		PORTD &= ~(1 << PD0);
		_delay_ms(500);
		PORTD &= ~(1 << PD1);
		_delay_ms(500);
	}
}

