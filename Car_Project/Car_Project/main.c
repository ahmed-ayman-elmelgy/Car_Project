/*
 * main.c
 *
 * Created: 1/3/2022 12:20:49 PM
 *  Author: Team 4
 */ 

#include "../ECUAL/DC_Motor/DC_Motor.h"
//#include "App.h"
#include "../ECUAL/Button/Button.h"
#include "util/delay.h"




int main(void)
{
	
	STR_PWM_config_t  configurations =	{.DutyCycle = 0 ,.Freq = 0x03 ,.TIMInstance = TIMER_0 ,.PWMCh.PinNum = PIN0 , .PWMCh.PortNum = PORTa};

	uint8_t State =0 ;
	
	BUTTON_init();
	MOTOR_INIT(Motor1 ,&configurations);
	//MOTOR_INIT(Motor2 ,configurations);
	
	uint8_t ButtonStatus = 0 ;
	
	
    while(1)
    {
		BUTTON_READ(0 , &ButtonStatus );
		if(ButtonStatus == 1)
		{
			configurations.DutyCycle += 10 ;
			//configurations.DutyCycle %= 101 ;
			//_delay_ms(100);
			/* changing motor configuration any where inside while(1)  */
			// change speed
			//PWM_START(&configurations);
			//SET_PWM_DutyCycle(&configurations);
			MOTOR_ACW(Motor1 ,&configurations );
			// necessary for apply a new configuration (Speed or Direction)
			MOTOR_Start (Motor1 , &configurations );
			/*************************************************************/
			
			do
			{
				BUTTON_READ(0 , &ButtonStatus );
			}while(ButtonStatus == 1);
			
			
			
		}
		
    }
}




/* 
	
	struct _State{
	 UINT8_T  SPEED ;
	INT8_T DIR ; // DIR MAY BE NEGATIVE   
	};
	
	if(MOVE_Button_IS_Pressed)
	{
			Do
			{
				MOTOR_Apply(Current_G_Speed_DiR);
			}while( DOI_GET_PIN_STATE(MOVE_BUTTON);
	}



	if(LEFT_Button_IS_Pressed)
	{
		Do
		{
			MOTOR_Apply(Left_Dir);
		}while( DOI_GET_PIN_STATE(LEFT_BUTTON);
	}
	
	
	
	
	if(Right_Button_IS_Pressed)
	{
		Do
		{
			MOTOR_Apply((Right_Dir);
		}while( DOI_GET_PIN_STATE(Right_BUTTON);
	}		
	
	
	
	
	
	ISR(INT0_VECT)
	{
		// we use ISR HIGH/LOW EGDE to ignore Long Press 
		UPdate_G_SPEED_DIR_VAR ;
		
	}
	
	*/