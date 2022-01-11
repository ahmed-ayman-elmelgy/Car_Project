/*
 * Button_cfg.h
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

#define BTN_1_PORT    PORTc
#define BTN_1         PIN0

#define BTN_2_PORT    PORTc
#define BTN_2         PIN1

#define BTN_3_PORT    PORTc
#define BTN_3         PIN2

#define BTN_4_PORT    PORTc
#define BTN_4         PIN3




/**************************************************************************************************
* User data type
***************************************************************************************************/

typedef struct
{
	uint8_t PORT;
	uint8_t num_pin;
}volatile BTN_CFG_t;

#endif /* BUTTON_CFG_H */