#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "LCD_interface.h"

#include <avr/delay.h>

u8 calc (u8 n, u8 n1, u8 n2);
int main (void)
{
	DIO_u8Init();
	LCD_voidInit();
	u8 arth[4] = {'+','-','*','/'};
	u8 up = 1, down = 1, enter = 1;
	LCD_u8GoToXY(0,0);
	u8 Yindex = 0 , n = 0 ,n1 = 0, n2 = 0, ans = 0;
	u16 delay = 500;

	LCD_voidClear();
	while (1)
	{
		// get values from the input PBs
		DIO_u8GetPinValue(DIO_u8_PORTC,DIO_u8_PIN3,&up);
		DIO_u8GetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,&down);
		DIO_u8GetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,&enter);
		// got to the next locaion
		if (enter != 1 && Yindex < 2)
		{
			Yindex++;
			LCD_u8GoToXY(0,Yindex);
			_delay_ms(delay);
		}
		// get the final answer
		else if (enter != 1 && Yindex == 2)
		{
			Yindex = 3;
			LCD_u8GoToXY(0,Yindex);
			LCD_voidWriteChar('=');
			ans = calc(n, n1, n2);
			if (ans == 255)
			{
				LCD_voidClear();
				LCD_voidWriteString("Error");
				n = n1 = n2 = 0;
				_delay_ms(delay);
			}
			else
			{
				LCD_voidWriteNumber(ans);
				_delay_ms(delay);
			}
		}
		// reset everthing
		else if (enter != 1 && Yindex == 3)
		{
			LCD_voidClear();
			Yindex = 0;
			n = n1 = n2 = 0;
			_delay_ms(delay);
		}
		// count up in index 0
		else if (up != 1 && Yindex == 0)
		{
			n++;
			if(n > 9 || n < 0){n = 0;}
			LCD_voidWriteNumber(n);
			LCD_u8GoToXY(0,Yindex);
			_delay_ms(delay);
		}
		// count up in index 2
		else if (up != 1 && Yindex == 2)
		{
			n1++;
			if(n1 > 9 || n1 < 0){n1 = 0;}
			LCD_voidWriteNumber(n1);
			LCD_u8GoToXY(0,Yindex);
			_delay_ms(delay);
		}
		// count up in chars index 1
		else if (up != 1 && Yindex == 1)
		{
			n2++;
			if (n2 < 0 || n2 > 3){n2 = 0;}
			LCD_voidWriteChar(arth[n2]);
			LCD_u8GoToXY(0,Yindex);
			_delay_ms(delay);
		}
		// count down in index 0
		else if (down != 1 && Yindex == 0)
		{
			n--;
			if(n > 9 || n < 0){n = 9;}
			LCD_voidWriteNumber(n);
			LCD_u8GoToXY(0,Yindex);
			_delay_ms(delay);
		}
		// count down in index 2
		else if (down != 1 && Yindex == 2)
		{
			n1--;
			if(n1 > 9 || n1 < 0){n1 = 9;}
			LCD_voidWriteNumber(n1);
			LCD_u8GoToXY(0,Yindex);
			_delay_ms(delay);
		}
		// count down chars in index 1
		else if (down != 1 && Yindex == 1)
		{
			n2--;
			if (n2 < 0 || n2 > 3){n2 = 3;}
			LCD_u8GoToXY(0,Yindex);
			LCD_voidWriteChar(arth[n2]);
			_delay_ms(delay);
		}
	}
	return 0;
}
// function for the calculations
u8 calc (u8 n, u8 n1, u8 n2)
{
	u8 r = 0;
	switch (n2)
	{
	case 0 : r = n + n1;break;
	case 1 :
		if (n1 > n)
		r = 255;
		else
		r = n - n1;
		break;
	case 2 : r = n * n1;break;
	case 3 :
		if (n1 == 0)
			r = 255;
		else
		r = n / n1;
		break;
	}
	return r;
}
