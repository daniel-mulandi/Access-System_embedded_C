/*
 * Access System Program.c
 *
 * Created: 11/17/2022 10:12:44 PM
 * Author : newto
 */ 

#include "access_system_functions.h"


/* Global variable declaration and initialization */

unsigned char PASSWORD[4] = {1, 2, 3, 4};	// Array containing the characters making up the password
unsigned char entered_pw[4];				// Array to store the user entered password
unsigned char pw_char_index;				// variable to store the index value of the PASSWORD array and entered_pw array

	
	
int main(void)
{
	/*	Initialize the access system program */
    Init_Access_System();
    
	/*
		While loop to 'read' sequence of PB presses and store the sequence in an array as 
		defined by the function read_entered_pw()
	*/
	while(1){
		if(pw_char_index > 3)break;									// Exit the loop if the entered_pw array is fully populated
		
		_delay_ms(2000);											// Delay for 2 seconds to allow user sufficient time to press the a PB
		entered_pw[pw_char_index] = read_entered_pw(pw_char_index); // Store the PB press sequence in the array entered_pw
		light_Output_LEDs(entered_pw);								
		PORTA = pw_char_index;
		pw_char_index = pw_char_index + 1;
			}
	
	pw_char_index = 0;												// Reset the pw_char_index variable so that it can be used in the following loop
	
	/* 
	Blink the green LED 5 times if the entered password is correct else blink red 5 times
	
	*/
    while(1){
		if(pw_char_index > 5)break;									// Exit the loop after 5 iterations
		
		/* 
			Switch on the Bi color LED for 0.5 seconds depending on whether the entered password is correct
		*/
		if(check_entered_pw(entered_pw, PASSWORD))					// light green
			light_BiColor_LED(0); 
		else light_BiColor_LED(1);									// light red
		
		_delay_ms(500);
		
		// Switch off the Bi Color LED for 0.5 sec
		BILED_PORT = 0x00;	
		_delay_ms(500);
		
		pw_char_index = pw_char_index + 1;
	}
}

