/*
 * Button.h
 *
 * Created: 1/4/2022 1:11:44 PM
 *  Author: Ali Dorgham
 */ 

#ifndef BUTTON_H
#define BUTTON_H

/**************************************************************************************************
* Local data types
***************************************************************************************************/

typedef enum
{	
	Btn_Start ,
	Button1 = Btn_Start ,
	Button2 ,
	Button3 ,
	Button4 ,
	Btn_End 
}EN_Button_t;

typedef enum 
{
	BTN_LOW,
	BTN_HIGH
}BTN_State_t;

typedef enum 
{
	Valid_BTN_init  = 0x00,
	Invalid_Num     = 0x01,
	Invalid_Pointer = 0x02
}BUTTON_ERROR_state_t;

/**************************************************************************************************
* Extern Functions
***************************************************************************************************/

void                            BUTTON_init       (void);
BUTTON_ERROR_state_t            BUTTON_READ       (EN_Button_t num, BTN_State_t * ptr_return_value);


#endif /* BUTTON_H */