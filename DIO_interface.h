#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

//PORT
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

//PIN
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
#define PIN8 8

//pin value
#define DIO_HIGH 1
#define DIO_LOW 0

//DIRICTION
#define DIO_INPUT 0
#define DIO_OUTPUT 1
#define DIO_PULLUP 2

//PORT_VALLUE
#define INPUT_PORT  0X00
#define OUTPUT_PORT 0XFF


//FUNCTION
void SetPinDir(u8 PORT,u8 PIN,u8 DIR);

void SetPortDir(u8 PORT,u8 DIR);

void SetPinVal(u8 PORT,u8 PIN,u8 Val);

void SetPortVal(u8 PORT,u8 Val);

u8 GetPinVal(u8 PORT , u8 PIN );

u8 GetPortVal(u8 PORT);

void TogPinVal(u8 PORT,u8 PIN);

void TogPortDir(u8 PORT);

#endif
