/*
 * App.h
 *
 * Created: 1/9/2022 6:15:22 PM
 *  Author: Ahmed_Ayman
 */ 


#ifndef APP_H_
#define APP_H_

#include <stdint.h>
#include "../ECUAL/DC_Motor/DC_Motor.h"
#include "../ECUAL/Button/Button.h"




#define  BUTTON_MOVE		0
#define  BUTTON_LEFT		1
#define  BUTTON_RIGHT		2

#define  BUTTON_SPEED		3


#define  Forward			0x01 
#define  Backward			0x02
#define  LEFT				0x03
#define  RIGHT				0x04


typedef enum {Speed_0 = 0 , Speed_30 = 3 , Speed_60 = 6 , Speed_90 = 9 }Speed_t;
void App_Init(void);



void App_Update(void);
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



#endif /* APP_H_ */