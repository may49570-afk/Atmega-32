/**
 * @file Keypad_program.c
 * @brief Implementation file for the keypad driver.
 *
 * This file contains the functions responsible for initializing
 * the keypad pins and detecting the pressed key using the
 * row-column scanning technique.
 *
 * @author Mai Essam
 */

//#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD.h"
#include "DIO_interface.h"
#include "Keypad_interface.h"
#include "Keypad_private.h"
#include "Keypad_config.h"
#include <util/delay.h>

/**
 * @brief Initializes the keypad pins.
 *
 * Configures the column pins as outputs and the row pins as inputs
 * with internal pull-up resistors enabled. All column pins are
 * initially set to HIGH.
 */
void Keypad_init(){
	//column direction
	SetPinDir(Keypad_PORT,C0,DIO_OUTPUT);
	SetPinDir(Keypad_PORT,C1,DIO_OUTPUT);
	SetPinDir(Keypad_PORT,C2,DIO_OUTPUT);
	SetPinDir(Keypad_PORT,C3,DIO_OUTPUT);

	//Row direction
	SetPinDir(Keypad_PORT,R0,DIO_PULLUP);
	SetPinDir(Keypad_PORT,R1,DIO_PULLUP);
	SetPinDir(Keypad_PORT,R2,DIO_PULLUP);
	SetPinDir(Keypad_PORT,R3,DIO_PULLUP);

	//column value
	SetPinVal(Keypad_PORT,C0,DIO_HIGH);
	SetPinVal(Keypad_PORT,C1,DIO_HIGH);
	SetPinVal(Keypad_PORT,C2,DIO_HIGH);
	SetPinVal(Keypad_PORT,C3,DIO_HIGH);
}

/**
 * @brief Detects and returns the pressed keypad key.
 *
 * Scans each column by setting it LOW, then checks the row pins
 * to detect a pressed key. A short delay is used for debouncing,
 * and the function waits until the detected key is released.
 *
 * @return The value assigned to the pressed key, or NO_KEY if
 *         no key is pressed.
 */
u8 Get_pressed(){

	/**
	 * @brief Stores the detected key value.
	 */
	u8 Button = NO_KEY;

	/**
	 * @brief Array containing the keypad column pin numbers.
	 */
	u8 COL_ARR[COL_SIZE]={C0,C1,C2,C3};

	/**
	 * @brief Array containing the keypad row pin numbers.
	 */
	u8 ROW_ARR[ROWS_SIZE]={R0,R1,R2,R3};

	/**
	 * @brief Two-dimensional array mapping keypad positions to key values.
	 */
	u8 KEYPAD_arr[ROWS_SIZE][COL_SIZE]=KEYPAD_VAL;

	for(int i=0;i<COL_SIZE;i++){
		SetPinVal(Keypad_PORT,COL_ARR[i],DIO_LOW);

		for(int j=0;j<ROWS_SIZE;j++){

			/**
			 * @brief Checks whether the current row is LOW,
			 *        indicating that a key is pressed in this column.
			 */
			if(GetPinVal(Keypad_PORT,ROW_ARR[j])==DIO_LOW){
				_delay_ms(30);
				Button=KEYPAD_arr[j][i];

				/**
				 * @brief Waits until the pressed key is released.
				 */
				while(GetPinVal(Keypad_PORT,ROW_ARR[j])==DIO_LOW){}
				break;
			}
		}

		/**
		 * @brief Returns the current column pin to HIGH.
		 */
		SetPinVal(Keypad_PORT,COL_ARR[i],DIO_HIGH);
	}
	return Button;
}
