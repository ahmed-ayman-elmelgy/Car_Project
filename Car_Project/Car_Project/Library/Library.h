#ifndef LIBRARY_H_
#define LIBRARY_H_


#define F_CPU 16000000
#ifndef  F_CPU
#warning "you will use default F_CPU ";
#endif

/* AVR */
#include "avr/io.h"
#include "util/delay.h"
#include "avr/interrupt.h"

/* Service */
#include "..\Library\Includes\Bit_Math.h"
#include "..\Library\Includes\Global_Enums.h"
#include "..\Library\Includes\Types_Defs.h"

/* Standard Libraries */
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "math.h"

#endif /* LIBRARY_H_ */