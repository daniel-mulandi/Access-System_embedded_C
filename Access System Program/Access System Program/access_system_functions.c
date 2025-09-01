/*
 * access_system_functions.c
 *
 * Created: 11/17/2022 10:14:25 PM
 *  Author: newto
 */ 

#include "access_system_functions.h"

void Init_Access_System(){
	DDRA = 0xFF;
	
	
	INPUT_DIR = INPUT_DIR & ~(0xF0); // Set 4 LS pins of PORTB as input
	INPUT_PORT = INPUT_PORT | 0x0F; // Enable pull up on the 4 LS pins of PORTB
	
	OUTPUT_DIR = 0x0F;  /* Set 4 LS pins of PORTC as output */
	
	BILED_DIR = 0x03; // Set the first 2 pins of PORTC as output
}

/* Function to light output LEDs */
void light_Output_LEDs(unsigned char entered_pw[4]){
		if (entered_pw[0] == 1)		 OUTPUT_PORT = OUTPUT_PORT | 0x01; // Light first LED
		if(entered_pw[1] == 2)  OUTPUT_PORT = OUTPUT_PORT | 0x02; // Light second LED
		if(entered_pw[2] == 3)  OUTPUT_PORT = OUTPUT_PORT | 0x04; // Light third LED
		if(entered_pw[3] == 4)  OUTPUT_PORT = OUTPUT_PORT | 0x08; // Light fourth LED

}

/* Function to light the Bi Color LED */
void light_BiColor_LED(bool state){
	if(state){
		BILED_PORT = BILED_PORT | 0x02; // Light Green
		}else{
		BILED_PORT = ~BILED_PORT & 0x01; // Light Red
	}
}


/* Function to read the squence of PB presses */
unsigned char read_entered_pw(unsigned char pw_char_index){
	
	if (INPUT_PIN == 14)	 return 1;
	else if(INPUT_PIN == 13) return 2;
	else if(INPUT_PIN == 11) return 3;
	else if(INPUT_PIN == 7)  return 4;
	else	return 0;
	
}


/* Function to compare the correct password to the entered password */
bool check_entered_pw(unsigned char entered_pw[4], unsigned char PASSWORD[4]){
	bool comparison_bit;
	
	if (entered_pw[0] == PASSWORD[0] && entered_pw[1] == PASSWORD[1] && entered_pw[2] == PASSWORD[2] && entered_pw[3] == PASSWORD[3])
		{
			comparison_bit = 1;
		}
		else{
			comparison_bit = 0;
		}

	return comparison_bit;
}