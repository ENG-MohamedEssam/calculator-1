/*********************************************/
/* 				Name : Mohamed Essam 		 */
/*				Date : 17/9/2021			 */
/*				SWC  :	DIO		 			 */
/*			version  : 1.0					 */
/*********************************************/
#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H

/* Config of Directions of Pins    */
/* Options : 1- DIO_u8_INIT_INPUT
		   : 2- DIO_u8_INIT_OUTPUT */
#define DIO_u8_PA0_DIRECTION			DIO_u8_INIT_INPUT
#define DIO_u8_PA1_DIRECTION            DIO_u8_INIT_INPUT
#define DIO_u8_PA2_DIRECTION            DIO_u8_INIT_INPUT
#define DIO_u8_PA3_DIRECTION            DIO_u8_INIT_INPUT
#define DIO_u8_PA4_DIRECTION            DIO_u8_INIT_INPUT
#define DIO_u8_PA5_DIRECTION            DIO_u8_INIT_INPUT
#define DIO_u8_PA6_DIRECTION            DIO_u8_INIT_INPUT
#define DIO_u8_PA7_DIRECTION            DIO_u8_INIT_INPUT

#define DIO_u8_PB0_DIRECTION            DIO_u8_INIT_INPUT
#define DIO_u8_PB1_DIRECTION            DIO_u8_INIT_INPUT
#define DIO_u8_PB2_DIRECTION            DIO_u8_INIT_INPUT
#define DIO_u8_PB3_DIRECTION            DIO_u8_INIT_INPUT
#define DIO_u8_PB4_DIRECTION            DIO_u8_INIT_INPUT
#define DIO_u8_PB5_DIRECTION            DIO_u8_INIT_INPUT
#define DIO_u8_PB6_DIRECTION            DIO_u8_INIT_INPUT
#define DIO_u8_PB7_DIRECTION            DIO_u8_INIT_INPUT

#define DIO_u8_PC0_DIRECTION            DIO_u8_INIT_OUTPUT
#define DIO_u8_PC1_DIRECTION            DIO_u8_INIT_OUTPUT
#define DIO_u8_PC2_DIRECTION            DIO_u8_INIT_OUTPUT
#define DIO_u8_PC3_DIRECTION            DIO_u8_INIT_INPUT
#define DIO_u8_PC4_DIRECTION            DIO_u8_INIT_INPUT
#define DIO_u8_PC5_DIRECTION            DIO_u8_INIT_INPUT
#define DIO_u8_PC6_DIRECTION            DIO_u8_INIT_INPUT
#define DIO_u8_PC7_DIRECTION            DIO_u8_INIT_INPUT

#define DIO_u8_PD0_DIRECTION            DIO_u8_INIT_OUTPUT
#define DIO_u8_PD1_DIRECTION            DIO_u8_INIT_OUTPUT
#define DIO_u8_PD2_DIRECTION            DIO_u8_INIT_OUTPUT
#define DIO_u8_PD3_DIRECTION            DIO_u8_INIT_OUTPUT
#define DIO_u8_PD4_DIRECTION            DIO_u8_INIT_OUTPUT
#define DIO_u8_PD5_DIRECTION            DIO_u8_INIT_OUTPUT
#define DIO_u8_PD6_DIRECTION            DIO_u8_INIT_OUTPUT
#define DIO_u8_PD7_DIRECTION            DIO_u8_INIT_OUTPUT

/*Macros for initial values of all pins */

/*options: 1-DIO_u8_INIT_OUTPUT_HIGH
 *         2-DIO_u8_INIT_OUTPUT_LOW
 *         3-DIO_u8_INIT_INPUT_FLOATING
 *         4-DIO_u8_INIT_INPUT_PULLUP     */
#define DIO_u8_PA0_VALUE       DIO_u8_INIT_INPUT_FLOATING
#define DIO_u8_PA1_VALUE       DIO_u8_INIT_INPUT_FLOATING
#define DIO_u8_PA2_VALUE       DIO_u8_INIT_INPUT_FLOATING
#define DIO_u8_PA3_VALUE       DIO_u8_INIT_INPUT_FLOATING
#define DIO_u8_PA4_VALUE       DIO_u8_INIT_INPUT_FLOATING
#define DIO_u8_PA5_VALUE       DIO_u8_INIT_INPUT_FLOATING
#define DIO_u8_PA6_VALUE       DIO_u8_INIT_INPUT_FLOATING
#define DIO_u8_PA7_VALUE       DIO_u8_INIT_INPUT_FLOATING

#define DIO_u8_PB0_VALUE       DIO_u8_INIT_INPUT_FLOATING
#define DIO_u8_PB1_VALUE       DIO_u8_INIT_INPUT_FLOATING
#define DIO_u8_PB2_VALUE       DIO_u8_INIT_INPUT_FLOATING
#define DIO_u8_PB3_VALUE       DIO_u8_INIT_INPUT_FLOATING
#define DIO_u8_PB4_VALUE       DIO_u8_INIT_INPUT_FLOATING
#define DIO_u8_PB5_VALUE       DIO_u8_INIT_INPUT_FLOATING
#define DIO_u8_PB6_VALUE       DIO_u8_INIT_INPUT_FLOATING
#define DIO_u8_PB7_VALUE       DIO_u8_INIT_INPUT_FLOATING

#define DIO_u8_PC0_VALUE       DIO_u8_INIT_OUTPUT_LOW
#define DIO_u8_PC1_VALUE       DIO_u8_INIT_OUTPUT_LOW
#define DIO_u8_PC2_VALUE       DIO_u8_INIT_OUTPUT_LOW
#define DIO_u8_PC3_VALUE       DIO_u8_INIT_INPUT_PULLUP
#define DIO_u8_PC4_VALUE       DIO_u8_INIT_INPUT_PULLUP
#define DIO_u8_PC5_VALUE       DIO_u8_INIT_INPUT_PULLUP
#define DIO_u8_PC6_VALUE       DIO_u8_INIT_INPUT_PULLUP
#define DIO_u8_PC7_VALUE       DIO_u8_INIT_INPUT_PULLUP

#define DIO_u8_PD0_VALUE       DIO_u8_INIT_OUTPUT_LOW
#define DIO_u8_PD1_VALUE       DIO_u8_INIT_OUTPUT_LOW
#define DIO_u8_PD2_VALUE       DIO_u8_INIT_OUTPUT_LOW
#define DIO_u8_PD3_VALUE       DIO_u8_INIT_OUTPUT_LOW
#define DIO_u8_PD4_VALUE       DIO_u8_INIT_OUTPUT_LOW
#define DIO_u8_PD5_VALUE       DIO_u8_INIT_OUTPUT_LOW
#define DIO_u8_PD6_VALUE       DIO_u8_INIT_OUTPUT_LOW
#define DIO_u8_PD7_VALUE       DIO_u8_INIT_OUTPUT_LOW

#endif
