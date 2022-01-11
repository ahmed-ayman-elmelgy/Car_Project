 /******************************************************************************
 *
 * [MODULE]: Common - Platform Types Abstraction
 *
 * [FILE NAME]: std_types.h
 *
 * [DESCRIPTION]: Types for AVR
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Boolean Data Type */
typedef unsigned char bool;

/* Boolean Values */

#ifndef FALSE
#define FALSE       (0u)
#endif

#ifndef TRUE
#define TRUE        (1u)
#endif

#define HIGH        (1u)
#define LOW         (0u)

#define STD_HIGH    (1u)   	  /* Standard HIGH */
#define STD_LOW     (0u)	  /* Standard LOW */

#define E_OK        (0u)      /* Function Return OK */
#define E_NOT_OK    (1u)      /* Function Return NOT OK */

#define NULL_PTR    ((void*)0)

#endif /* STD_TYPE_H_ */
