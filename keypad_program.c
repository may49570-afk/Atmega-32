//#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD.h"
#include "DIO_interface.h"
#include "Keypad_interface.h"
#include "Keypad_private.h"
#include "Keypad_config.h"
#include <util/delay.h>

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

u8 Get_pressed(){

	u8 Button = NO_KEY;
	u8 COL_ARR[COL_SIZE]={C0,C1,C2,C3};
	u8 ROW_ARR[ROWS_SIZE]={R0,R1,R2,R3};
	u8 KEYPAD_arr[ROWS_SIZE][COL_SIZE]=KEYPAD_VAL;

	for(int i=0;i<COL_SIZE;i++){
		SetPinVal(Keypad_PORT,COL_ARR[i],DIO_LOW);

		for(int j=0;j<ROWS_SIZE;j++){

			if(GetPinVal(Keypad_PORT,ROW_ARR[j])==DIO_LOW){
				_delay_ms(30);
				Button=KEYPAD_arr[j][i];
				while(GetPinVal(Keypad_PORT,ROW_ARR[j])==DIO_LOW){}
				break;
			}
		}
		SetPinVal(Keypad_PORT,COL_ARR[i],DIO_HIGH);
	}
	return Button;
}









