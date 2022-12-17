/********************************************************/
/*						Name : Mohamed Essam			*/
/*						Date : 24/9/2021				*/
/*						SWC  : LCD						*/
/*					 version : 1.0						*/
/********************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define LCD_u8_LINE_1	0
#define LCD_u8_LINE_2	1

void LCD_voidInit(void);

void LCD_voidWriteChar(u8 Copy_u8Char);
void LCD_voidWriteCmnd (u8 Copy_u8Cmnd);
void LCD_voidWriteString(u8 *Copy_pu8String);
void LCD_voidWriteNumber(u16 Copy_u16Number);
void LCD_voidWriteSpecialCharacter(u8 *Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos);
void LCD_voidClear(void);

u8 LCD_u8GoToXY(u8 Copy_u8LineNum, u8 Copy_u8CharLocation);




#endif
