/*
 * DC_Motor_cfg.h
 *
 * Created: 1/4/2022 1:11:44 PM
 *  Author: Ali Dorgham
 */ 

#ifndef BUTTON_CFG_H
#define BUTTON_CFG_H

/**************************************************************************************************
* User defined Libraries
***************************************************************************************************/
#include "../Library/Library.h"
#include "../MCAL/DIO/DIO.h"


/**************************************************************************************************
* File Configurations
***************************************************************************************************/

/*
* Using H-Bridge to control DC Motor direction, so there are two pins H1, H2
* To Enable Motor using Pin EN  
*/

/* Control Pins */
#define MOTOR_EN            0
#define MOTOR_H1            1
#define MOTOR_H2            2
#define MOTOR_CONTROL_PIN   3

/* Motor 1 */
#define MTR_1_EN_PORT       PORTa
#define MTR_1_EN            PIN0

#define MTR_1_H1_PORT    	PORTa
#define MTR_1_H1         	PIN1
	
#define MTR_1_H2_PORT    	PORTa
#define MTR_1_H2         	PIN2

/* Motor 2 */
#define MTR_2_EN_PORT  	    PORTb
#define MTR_2_EN       	    PIN0

#define MTR_2_H1_PORT    	PORTb
#define MTR_2_H1         	PIN1
	
#define MTR_2_H2_PORT    	PORTb
#define MTR_2_H2         	PIN2


/**************************************************************************************************
* User data type
***************************************************************************************************/

typedef struct
{
	/* ports of speed pin */
	uint8_t PORT;
	uint8_t num_pin;
}MTR_Pins_CFG_t;

typedef MTR_Pins_CFG_t  MTR_CFG_t [MOTOR_CONTROL_PIN];

#endif /* BUTTON_CFG_H */