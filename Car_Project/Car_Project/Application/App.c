/*
 * App.c
 *
 * Created: 1/9/2022 6:15:08 PM
 *  Author: Ahmed_Ayman
 */ 



#include "App.h"

STR_PWM_config_t  configurations[2] =	{{.DutyCycle = 0 ,.Freq = 0x03 ,.TIMInstance = TIMER_0 , .PWMCh.PortNum = PORTa , .PWMCh.PinNum = PIN0},
{.DutyCycle = 0 , .Freq = 0x04 ,.TIMInstance = TIMER_2 , .PWMCh.PortNum = PORTb , .PWMCh.PinNum = PIN0}} ;

void App_Init(void)
{
	
	BUTTON_init();
	/* Motor initialization Before while(1)   */
	configurations[Motor1] .DutyCycle = 0 ;
	MOTOR_INIT(Motor1 , &configurations[Motor1] );
	/******************************************/



	
	
	/* Motor initialization Before while(1)   */
	configurations[Motor2].DutyCycle = 0 ;
	MOTOR_INIT(Motor2 , &configurations[Motor2] );
	/******************************************/

	
	
}


void  APP_Apply(uint8_t Speed , uint8_t  Direction )
{
	
	
	
	
	if(Direction == Forward)
	{
		/* changing motor configuration any where inside while(1)  */
		// change speed
		configurations[Motor1].DutyCycle = Speed  ;
		// change direction
		MOTOR_CW(Motor1 ,&configurations[Motor1]);
		// necessary for apply a new configuration (Speed or Direction)
		MOTOR_Start (Motor1 , &configurations[Motor1]);
		/*************************************************************/
	
	


		/* changing motor configuration any where inside while(1)  */
		// change speed
		configurations[Motor2].DutyCycle =  Speed   ;
		// change direction
		MOTOR_CW(Motor2 ,&configurations[Motor2] );
		// necessary for apply a new configuration (Speed or Direction)
		MOTOR_Start (Motor2 , &configurations[Motor2] );
		/*************************************************************/	

	}else if(Direction == Backward)
	{
		/* changing motor configuration any where inside while(1)  */
		// change speed
		configurations[Motor1].DutyCycle = Speed  ;
		// change direction
		MOTOR_ACW(Motor1 ,&configurations[Motor1] );
		// necessary for apply a new configuration (Speed or Direction)
		MOTOR_Start (Motor1 , &configurations[Motor1] );
		/*************************************************************/
		
		


		/* changing motor configuration any where inside while(1)  */
		// change speed
		configurations[Motor2].DutyCycle = Speed ;
		// change direction
		MOTOR_ACW(Motor2 ,&configurations[Motor2] );
		// necessary for apply a new configuration (Speed or Direction)
		MOTOR_Start (Motor2 , &configurations[Motor2] );
		/*************************************************************/			
	}else if(Direction == LEFT)
	{
		/* changing motor configuration any where inside while(1)  */
		// change speed
		configurations[Motor1].DutyCycle = Speed  ;
		// change direction
		MOTOR_ACW(Motor1 ,&configurations[Motor1] );
		// necessary for apply a new configuration (Speed or Direction)
		MOTOR_Start (Motor1 , &configurations[Motor1] );
		/*************************************************************/
		
		


		/* changing motor configuration any where inside while(1)  */
		// change speed
		configurations[Motor2].DutyCycle =  Speed   ;
		// change direction
		MOTOR_CW(Motor2 ,&configurations[Motor2] );
		// necessary for apply a new configuration (Speed or Direction)
		MOTOR_Start (Motor2 , &configurations[Motor2] );
		/*************************************************************/

	}else if(Direction == RIGHT)
	{
		/* changing motor configuration any where inside while(1)  */
		// change speed
		configurations[Motor1].DutyCycle = Speed   ;
		// change direction
		MOTOR_CW(Motor1 ,&configurations[Motor1] );
		// necessary for apply a new configuration (Speed or Direction)
		MOTOR_Start (Motor1 , &configurations[Motor1] );
		/*************************************************************/
		
		


		/* changing motor configuration any where inside while(1)  */
		// change speed
		configurations[Motor2].DutyCycle =  Speed   ;
		// change direction
		MOTOR_ACW(Motor2 ,&configurations[Motor2] );
		// necessary for apply a new configuration (Speed or Direction)
		MOTOR_Start (Motor2 , &configurations[Motor2] );
		/*************************************************************/
	}else
	{
		
		
	}	

}


uint8_t Speed[4] = {0 , 30 ,60 , 90 };

uint8_t * MotorSpeed = Speed+1 ;
uint8_t  Direction =1;



void App_Update(void)
{
	DDRD = 0xff ; 
	uint8_t num = 0  ; 
	uint8_t  Button_Move_State = 0 ,
				 Button_LEFT_State = 0 ,
				 Button_RIGHT_State = 0 ,
					Button_speed_State = 0 ;
					
					
					
					
	BUTTON_READ(BUTTON_MOVE , &Button_Move_State);	
	BUTTON_READ(BUTTON_LEFT , &Button_LEFT_State);
	BUTTON_READ(BUTTON_RIGHT , &Button_RIGHT_State);
	BUTTON_READ(BUTTON_SPEED , &Button_speed_State);
	
	
	if(Button_Move_State == 1)
	{
			if((*MotorSpeed <= Speed[3]) &&(*MotorSpeed >= Speed[0]))
			PORTD ^= 0x0f ; 
			if(Direction == Forward)
			PORTD ^= 0xf0 ;
			
			
			APP_Apply(*MotorSpeed , Direction);
			while( Button_Move_State == 1)
			{
				BUTTON_READ(BUTTON_MOVE , &Button_Move_State);			
			}
	}
	else if(Button_LEFT_State == 1)
	{

			APP_Apply(*MotorSpeed , LEFT );
			
			while(Button_LEFT_State == 1)
			{
				BUTTON_READ(BUTTON_LEFT , &Button_LEFT_State);
			}
	}
	else if(Button_RIGHT_State == 1)
	{

			APP_Apply(*MotorSpeed , RIGHT );
			while(Button_RIGHT_State == 1)
			{
				BUTTON_READ(BUTTON_RIGHT , &Button_RIGHT_State);	
			}
	}
	else if (Button_speed_State == 1)
	{				
			MotorSpeed++ ;
			Direction = Forward ;
			if (MotorSpeed > Speed+2)
			{
				MotorSpeed = Speed ;
				Direction = Backward ; 
			}
			_delay_ms(10);
	}
	else
	{
		
			APP_Apply(Speed_0 , Direction );
		
	}
	
	
}

	
	/*
	ISR(INT0_vect)
	{
		// we use ISR HIGH/LOW EGDE to ignore Long Press
		//UPdate_G_SPEED_DIR_VAR ;
		
		Speed += 3 ;
		if (Speed > Speed_90)
		{
			Speed = Speed_0 ;
		}
	}
	*/