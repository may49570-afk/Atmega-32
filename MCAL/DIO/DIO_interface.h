/**
 * @file DIO_interface.h
 * @brief Interface header file for the Digital Input/Output (DIO) driver.
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

/**
 * @brief DIO port identifiers.
 */
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

/**
 * @brief Pin number identifiers.
 */
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
#define PIN8 8

/**
 * @brief Digital pin logic values.
 */
#define DIO_HIGH 1
#define DIO_LOW 0

/**
 * @brief Pin and port direction options.
 */
#define DIO_INPUT 0
#define DIO_OUTPUT 1
#define DIO_PULLUP 2

/**
 * @brief Port configuration values.
 */
#define INPUT_PORT  0X00
#define OUTPUT_PORT 0XFF

/**
 * @brief Sets the direction of a specific pin.
 * @param PORT The port containing the selected pin.
 * @param PIN The pin number to configure.
 * @param DIR The required direction (input, output, or pull-up).
 */
void SetPinDir(u8 PORT,u8 PIN,u8 DIR);

/**
 * @brief Sets the direction of an entire port.
 * @param PORT The port to configure.
 * @param DIR The required port direction.
 */
void SetPortDir(u8 PORT,u8 DIR);

/**
 * @brief Sets the digital value of a specific pin.
 * @param PORT The port containing the selected pin.
 * @param PIN The pin number to modify.
 * @param Val The required value (DIO_HIGH or DIO_LOW).
 */
void SetPinVal(u8 PORT,u8 PIN,u8 Val);

/**
 * @brief Sets the digital value of an entire port.
 * @param PORT The port to modify.
 * @param Val The value to write to the port.
 */
void SetPortVal(u8 PORT,u8 Val);

/**
 * @brief Reads the digital value of a specific pin.
 * @param PORT The port containing the selected pin.
 * @param PIN The pin number to read.
 * @return The pin value (0 or 1).
 */
u8 GetPinVal(u8 PORT , u8 PIN );

/**
 * @brief Reads the input value of an entire port.
 * @param PORT The port to read.
 * @return The current input value of the selected port.
 */
u8 GetPortVal(u8 PORT);

/**
 * @brief Toggles the digital value of a specific pin.
 * @param PORT The port containing the selected pin.
 * @param PIN The pin number to toggle.
 */
void TogPinVal(u8 PORT,u8 PIN);

/**
 * @brief Inverts the output values of an entire port.
 * @param PORT The port whose output values will be inverted.
 */
void TogPortDir(u8 PORT);

#endif
