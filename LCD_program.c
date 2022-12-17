/********************************************************/
/*						Name : Mohamed Essam			*/
/*						Date : 24/9/2021				*/
/*						SWC  : LCD						*/
/*					 version : 1.0						*/
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <avr/delay.h>

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

void LCD_voidInit(void)
{
	_delay_ms(35);
	LCD_voidWriteCmnd(0b00111000);
	_delay_us(40);
	LCD_voidWriteCmnd(0b00001111);
	_delay_us(40);
	LCD_voidWriteCmnd(0x01);
	_delay_ms(2);
	LCD_voidWriteCmnd(0b00000110);
}

void LCD_voidWriteChar(u8 Copy_u8Char)
{
	/* RS = 1 (Data Byte) 		*/
	DIO_u8SetPinValue(LCD_u8_RS_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
	/* RW = 0 (Write Operation) */
	DIO_u8SetPinValue(LCD_u8_RW_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	/* Send Data Byte to LCD 	*/
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Char);
	/* Enable Pulse				*/
	DIO_u8SetPinValue(LCD_u8_EN_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_EN_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);
}

void LCD_voidWriteCmnd (u8 Copy_u8Cmnd)
{
	/* RS = 0 (Command Byte) 		*/
	DIO_u8SetPinValue(LCD_u8_RS_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	/* RW = 0 (Write Operation) */
	DIO_u8SetPinValue(LCD_u8_RW_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	/* Send Data Byte to LCD 	*/
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Cmnd);
	/* Enable Pulse				*/
	DIO_u8SetPinValue(LCD_u8_EN_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_EN_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);
}



void LCD_voidWriteString(u8 *Copy_pu8String)
{
	u8 Local_u8_stringcounter = 0;
	/*	Send Data Byte to LCD	*/
	while (Copy_pu8String[Local_u8_stringcounter] != '\0')
	{
		LCD_voidWriteChar(Copy_pu8String[Local_u8_stringcounter]);
		Local_u8_stringcounter++;
	}

}

void LCD_voidWriteNumber(u16 Copy_u16Number)
{
	u16 Local_u16_Remaining;
	u16 Local_u16_Reverse = 1;
	u8 Local_u8_FinalReverse;

	if (Copy_u16Number == 0)
	{
		LCD_voidWriteChar(Copy_u16Number + '0');
	}
	else
	{
		while (Copy_u16Number != 0)
		{
			Local_u16_Remaining = Copy_u16Number % 10;
			Local_u16_Reverse = Local_u16_Reverse * 10 + Local_u16_Remaining;
			Copy_u16Number /= 10;
		}
		while (Local_u16_Reverse != 1)
		{
			Local_u8_FinalReverse = Local_u16_Reverse % 10;
			LCD_voidWriteChar (Local_u8_FinalReverse + '0');
			Local_u16_Reverse /= 10;
		}
	}
}

u8 LCD_u8GoToXY(u8 Copy_u8LineNum, u8 Copy_u8CharLocation)
{
	u8 Local_u8Adress;
	/* Location of first line */
	if(Copy_u8LineNum == 0)
	{
		Local_u8Adress = Copy_u8CharLocation;
	}
	/* Location is at second line */
	else if (Copy_u8LineNum == 1)
	{
		Local_u8Adress = Copy_u8CharLocation + 0x40;
	}
	/* set bit num 8 to 1 */
	LCD_voidWriteCmnd(Local_u8Adress + 128);
}

void LCD_voidWriteSpecialCharacter(u8 *Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAdress = 0 , Local_u8Iterator;
	/* Calculate the CGRAM Adress whose each block is 8 bytes */
	Local_u8CGRAMAdress = Copy_u8PatternNumber * 8;
	/* Send CGRAM adress command to LCD with setting bit 6 , clearing bit 7 (already cleared) */
	LCD_voidWriteCmnd(Local_u8CGRAMAdress + 64);
	/* Write pattern into CGRAM */
	for(Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator ++)
	{
		LCD_voidWriteChar(Copy_pu8Pattern[Local_u8Iterator]);
	}
	/* Go back to DDRAM to display the pattern */
	LCD_u8GoToXY(Copy_u8XPos,Copy_u8YPos);
	/* Display the pattern written in the CGRAM */
	LCD_voidWriteChar(Copy_u8PatternNumber);
}

void LCD_voidClear(void)
{
	LCD_u8GoToXY(0,0);
	LCD_voidWriteString("                                                       ");
	LCD_u8GoToXY(0,0);
}
