/*
 * access_system_functions.h
 *
 * Created: 11/17/2022 10:14:05 PM
 *  Author: newto
 */ 


#ifndef ACCESS_SYSTEM_FUNCTIONS_H_
#define ACCESS_SYSTEM_FUNCTIONS_H_

#include "Pin_Manager.h"

/*
    Function:
            void Init_Access_System()
    Description:
            This function Initializes GPIO registers; 
            i.e. sets the GPIO as per the requirement
            of the circuit
			
 */
void Init_Access_System();


/* 
	Function: 
            void light_BiColor_LED(bool state);
	Description:
            This function lights the Bi color LED depending on the value of
			its argument state if state is 1; it lights green if state is 0; it lights red
 
*/
void light_BiColor_LED(bool state);


/* 
	Function:
		void light_Output_LEDs(unsigned char entered_pw[4]);
	Description:
		This function lights output LEDs in a sequence corresponding to the order in which the PBs are pressed
*/

void light_Output_LEDs(unsigned char entered_pw[4]);

/* 
	Function:
		void read_entered_pw(unsigned char pw_char_index, unsigned char entered_pw[4])
	
	Description:
		This function reads the sequence of the PB presses and stores it as a user entered password
*/
unsigned char read_entered_pw(unsigned char pw_char_index);

/* 
	Function:
		unsigned int check_entered_pw(unsigned char entered_pw[4], unsigned char PASSWORD[4]);
	Description:
		This function compares the password entered by the user with the correct password and returns 1 if 
		the passwords are same else it returns a 0
	*/

bool check_entered_pw(unsigned char entered_pw[4], unsigned char PASSWORD[4]);


#endif /* ACCESS_SYSTEM_FUNCTIONS_H_ */