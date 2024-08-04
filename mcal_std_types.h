/* 
 * File:   mcal_std_types.h
 * Author: Okda
 *
 * Created on July 27, 2024, 10:52 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H
/*Section : includes*/

#include "std_libraries.h"
#include "compiler.h"

/*Section : Macros Declaration*/
#define STD_ON      0x01
#define STD_OFF     0x00

#define STD_HIGH    0x01
#define STD_LOW     0x00

#define STD_ACTIVE  0X01
#define STD_IDLE    0X00

#define E_OK        (Std_ReturnType)0x01
#define E_NOK       (Std_ReturnType)0x00



/*Section : Datatype Declaration*/
typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned int   uint32;

typedef signed char    sint8;
typedef signed short   sint16;
typedef signed int     sint32;

typedef uint8          Std_ReturnType;


/*Section : includes*/
/*Section : Macros Declaration*/
/*Section : Macros Functions Declaration*/
/*Section : Datatype Declaration*/
/*Section : Function Declaration */




#endif	/* MCAL_STD_TYPES_H */

