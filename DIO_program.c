/*********************************************/
/* 				Name : Mohamed Essam 		 */
/*				Date : 17/9/2021			 */
/*				SWC  :	DIO		 			 */
/*			version  : 1.0					 */
/*********************************************/
/* Lib Layer*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

u8 DIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId,
		u8 Copy_u8PinDirection) {
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if ((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7)) {
		switch (Copy_u8PortId) {
		case DIO_u8_PORTA:
			switch (Copy_u8PinDirection) {
			case DIO_u8_INPUT_PULLED_UP:
				SET_BIT(DIO_u8_PORTA_REG, Copy_u8PinId);
			case DIO_u8_INPUT_FLOATING:
				CLR_BIT(DIO_u8_DDRA_REG, Copy_u8PinId);
				break;
			case DIO_u8_OUTPUT:
				SET_BIT(DIO_u8_DDRA_REG, Copy_u8PinId);
				break;
			default:
				Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
		case DIO_u8_PORTB:
			switch (Copy_u8PinDirection) {
			case DIO_u8_INPUT_PULLED_UP:
				SET_BIT(DIO_u8_PORTB_REG, Copy_u8PinId);
			case DIO_u8_INPUT_FLOATING:
				CLR_BIT(DIO_u8_DDRB_REG, Copy_u8PinId);
				break;
			case DIO_u8_OUTPUT:
				SET_BIT(DIO_u8_DDRB_REG, Copy_u8PinId);
				break;
			default:
				Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
		case DIO_u8_PORTC:
			switch (Copy_u8PinDirection) {
			case DIO_u8_INPUT_PULLED_UP:
				SET_BIT(DIO_u8_PORTC_REG, Copy_u8PinId);
			case DIO_u8_INPUT_FLOATING:
				CLR_BIT(DIO_u8_DDRC_REG, Copy_u8PinId);
				break;
			case DIO_u8_OUTPUT:
				SET_BIT(DIO_u8_DDRC_REG, Copy_u8PinId);
				break;
			default:
				Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
		case DIO_u8_PORTD:
			switch (Copy_u8PinDirection) {
			case DIO_u8_INPUT_PULLED_UP:
				SET_BIT(DIO_u8_PORTD_REG, Copy_u8PinId);
			case DIO_u8_INPUT_FLOATING:
				CLR_BIT(DIO_u8_DDRD_REG, Copy_u8PinId);
				break;
			case DIO_u8_OUTPUT:
				SET_BIT(DIO_u8_DDRD_REG, Copy_u8PinId);
				break;
			default:
				Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
		}
	} else {
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue) {
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if ((Copy_u8PinId <= DIO_u8_PIN7)
			&& ((Copy_u8PinValue == DIO_u8_HIGH)
					|| (Copy_u8PinValue == DIO_u8_LOW))) {
		switch (Copy_u8PortId) {
		case DIO_u8_PORTA:
			switch (Copy_u8PinValue) {
			case DIO_u8_HIGH:
				SET_BIT(DIO_u8_PORTA_REG, Copy_u8PinId);
				break;
			case DIO_u8_LOW:
				CLR_BIT(DIO_u8_PORTA_REG, Copy_u8PinId);
				break;
			}
			break;
		case DIO_u8_PORTB:
			switch (Copy_u8PinValue) {
			case DIO_u8_HIGH:
				SET_BIT(DIO_u8_PORTB_REG, Copy_u8PinId);
				break;
			case DIO_u8_LOW:
				CLR_BIT(DIO_u8_PORTB_REG, Copy_u8PinId);
				break;
			}
			break;
		case DIO_u8_PORTC:
			switch (Copy_u8PinValue) {
			case DIO_u8_HIGH:
				SET_BIT(DIO_u8_PORTC_REG, Copy_u8PinId);
				break;
			case DIO_u8_LOW:
				CLR_BIT(DIO_u8_PORTC_REG, Copy_u8PinId);
				break;
			}
			break;
		case DIO_u8_PORTD:
			switch (Copy_u8PinValue) {
			case DIO_u8_HIGH:
				SET_BIT(DIO_u8_PORTD_REG, Copy_u8PinId);
				break;
			case DIO_u8_LOW:
				CLR_BIT(DIO_u8_PORTD_REG, Copy_u8PinId);
				break;
			}
			break;
		default:
			Local_u8ErrorState = STD_TYPES_NOK;
		}
	} else {
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}


u8 DIO_u8GetPinValue	(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 * Copy_pu8ReturnedValue)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if((Copy_u8PinId <= DIO_u8_PIN7)&&(Copy_pu8ReturnedValue != NULL))
	{
		Local_u8ErrorState = STD_TYPES_OK;
		switch(Copy_u8PortId)
		{
		case DIO_u8_PORTA:*Copy_pu8ReturnedValue = GET_BIT(DIO_u8_PINA_REG,Copy_u8PinId);break;
		case DIO_u8_PORTB:*Copy_pu8ReturnedValue = GET_BIT(DIO_u8_PINB_REG,Copy_u8PinId);break;
		case DIO_u8_PORTC:*Copy_pu8ReturnedValue = GET_BIT(DIO_u8_PINC_REG,Copy_u8PinId);break;
		case DIO_u8_PORTD:*Copy_pu8ReturnedValue = GET_BIT(DIO_u8_PIND_REG,Copy_u8PinId);break;
		default 	:Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	return Local_u8ErrorState;

}

u8 DIO_u8TogPinValue	(u8 Copy_u8PortId,u8 Copy_u8PinId)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8PinId <= DIO_u8_PIN7)
	{
		switch(Copy_u8PortId)
		{
		case DIO_u8_PORTA:TOG_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);break;
		case DIO_u8_PORTB:TOG_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);break;
		case DIO_u8_PORTC:TOG_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);break;
		case DIO_u8_PORTD:TOG_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);break;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}


u8 DIO_u8SetPortDirection(u8 Copy_u8PortId,u8 Copy_u8PortDirection)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch(Copy_u8PortId)
	{
	case DIO_u8_PORTA:
		switch(Copy_u8PortDirection)
		{
		case DIO_u8_INPUT_PULLED_UP:DIO_u8_PORTA_REG = 0xff;
		case DIO_u8_INPUT_FLOATING :DIO_u8_DDRA_REG  = 0x00;break;
		case DIO_u8_OUTPUT		   :DIO_u8_DDRA_REG  = 0xff;break;
		default					   :Local_u8ErrorState = STD_TYPES_NOK;

		}
		break;
		case DIO_u8_PORTB:
			switch(Copy_u8PortDirection)
			{
			case DIO_u8_INPUT_PULLED_UP:DIO_u8_PORTB_REG = 0xff;
			case DIO_u8_INPUT_FLOATING :DIO_u8_DDRB_REG  = 0x00;break;
			case DIO_u8_OUTPUT		   :DIO_u8_DDRB_REG  = 0xff;break;
			default					   :Local_u8ErrorState = STD_TYPES_NOK;

			}
			break;
		case DIO_u8_PORTC:
			switch(Copy_u8PortDirection)
			{
			case DIO_u8_INPUT_PULLED_UP:DIO_u8_PORTC_REG = 0xff;
			case DIO_u8_INPUT_FLOATING :DIO_u8_DDRC_REG  = 0x00;break;
			case DIO_u8_OUTPUT		   :DIO_u8_DDRC_REG  = 0xff;break;
			default					   :Local_u8ErrorState = STD_TYPES_NOK;

			}
			break;
		case DIO_u8_PORTD:
			switch(Copy_u8PortDirection)
			{
			case DIO_u8_INPUT_PULLED_UP:DIO_u8_PORTD_REG = 0xff;
			case DIO_u8_INPUT_FLOATING :DIO_u8_DDRD_REG  = 0x00;break;
			case DIO_u8_OUTPUT		   :DIO_u8_DDRD_REG  = 0xff;break;
			default					   :Local_u8ErrorState = STD_TYPES_NOK;

			}
			break;
			default : Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8SetPortValue	 (u8 Copy_u8PortId,u8 Copy_u8PortValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch(Copy_u8PortId)
	{
	case DIO_u8_PORTA:DIO_u8_PORTA_REG = Copy_u8PortValue;break;
	case DIO_u8_PORTB:DIO_u8_PORTB_REG = Copy_u8PortValue;break;
	case DIO_u8_PORTC:DIO_u8_PORTC_REG = Copy_u8PortValue;break;
	case DIO_u8_PORTD:DIO_u8_PORTD_REG = Copy_u8PortValue;break;
	default 	:Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8GetPortValue	 (u8 Copy_u8PortId,u8 * Copy_pu8PortValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pu8PortValue != NULL)
	{
		switch(Copy_u8PortId)
		{
		case DIO_u8_PORTA:*Copy_pu8PortValue = DIO_u8_PINA_REG;break;
		case DIO_u8_PORTB:*Copy_pu8PortValue = DIO_u8_PINB_REG;break;
		case DIO_u8_PORTC:*Copy_pu8PortValue = DIO_u8_PINC_REG;break;
		case DIO_u8_PORTD:*Copy_pu8PortValue = DIO_u8_PIND_REG;break;
		default			 :Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	return Local_u8ErrorState;

}

void DIO_u8Init         (void)
{
	/*Direction DDR*/
DIO_u8_DDRA_REG = PRIVATE_u8_CONC(DIO_u8_PA7_DIRECTION,DIO_u8_PA6_DIRECTION,DIO_u8_PA5_DIRECTION,DIO_u8_PA4_DIRECTION,
		                          DIO_u8_PA3_DIRECTION,DIO_u8_PA2_DIRECTION,DIO_u8_PA1_DIRECTION,DIO_u8_PA0_DIRECTION);

DIO_u8_DDRB_REG = PRIVATE_u8_CONC(DIO_u8_PB7_DIRECTION,DIO_u8_PB6_DIRECTION,DIO_u8_PB5_DIRECTION,DIO_u8_PB4_DIRECTION,
		                          DIO_u8_PB3_DIRECTION,DIO_u8_PB2_DIRECTION,DIO_u8_PB1_DIRECTION,DIO_u8_PB0_DIRECTION);

DIO_u8_DDRC_REG = PRIVATE_u8_CONC(DIO_u8_PC7_DIRECTION,DIO_u8_PC6_DIRECTION,DIO_u8_PC5_DIRECTION,DIO_u8_PC4_DIRECTION,
		                          DIO_u8_PC3_DIRECTION,DIO_u8_PC2_DIRECTION,DIO_u8_PC1_DIRECTION,DIO_u8_PC0_DIRECTION);

DIO_u8_DDRD_REG = PRIVATE_u8_CONC(DIO_u8_PD7_DIRECTION,DIO_u8_PD6_DIRECTION,DIO_u8_PD5_DIRECTION,DIO_u8_PD4_DIRECTION,
		                          DIO_u8_PD3_DIRECTION,DIO_u8_PD2_DIRECTION,DIO_u8_PD1_DIRECTION,DIO_u8_PD0_DIRECTION);

/*Value PORT*/

DIO_u8_PORTA_REG = PRIVATE_u8_CONC(DIO_u8_PA7_VALUE,DIO_u8_PA6_VALUE,DIO_u8_PA5_VALUE,DIO_u8_PA4_VALUE,
	                               DIO_u8_PA3_VALUE,DIO_u8_PA2_VALUE,DIO_u8_PA1_VALUE,DIO_u8_PA0_VALUE);

DIO_u8_PORTB_REG = PRIVATE_u8_CONC(DIO_u8_PB7_VALUE,DIO_u8_PB6_VALUE,DIO_u8_PB5_VALUE,DIO_u8_PB4_VALUE,
								   DIO_u8_PB3_VALUE,DIO_u8_PB2_VALUE,DIO_u8_PB1_VALUE,DIO_u8_PB0_VALUE);

DIO_u8_PORTC_REG = PRIVATE_u8_CONC(DIO_u8_PC7_VALUE,DIO_u8_PC6_VALUE,DIO_u8_PC5_VALUE,DIO_u8_PC4_VALUE,
	                                DIO_u8_PC3_VALUE,DIO_u8_PC2_VALUE,DIO_u8_PC1_VALUE,DIO_u8_PC0_VALUE);

DIO_u8_PORTD_REG = PRIVATE_u8_CONC(DIO_u8_PD7_VALUE,DIO_u8_PD6_VALUE,DIO_u8_PD5_VALUE,DIO_u8_PD4_VALUE,
		                          DIO_u8_PD3_VALUE,DIO_u8_PD2_VALUE,DIO_u8_PD1_VALUE,DIO_u8_PD0_VALUE);



}
