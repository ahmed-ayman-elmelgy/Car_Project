#ifndef DATA_TYPES_H_
#define DATA_TYPES_H_

/*****************************************************************************************/

typedef unsigned char		  u8;
typedef unsigned short 		 u16;
typedef unsigned long		 u32;
typedef unsigned long long	 u64;
							 
typedef signed char			  s8;
typedef signed short 		 s16;
typedef signed long			 s32;
typedef signed long long	 s64;

typedef float                f32;
typedef double               f64;
typedef long double          f128;

typedef u8 * 		         string_t;

/*****************************************************************************************/

typedef unsigned char         uint8_t;          /*           0 .. 255                    */
typedef signed char           int8_t;           /*        -128 .. +127                   */
//typedef unsigned short        uint16_t;         /*           0 .. 65535                  */
//typedef signed short          int16_t;          /*      -32768 .. +32767                 */
typedef unsigned long         uint32_t;         /*           0 .. 4294967295             */
typedef signed long           int32_t;          /* -2147483648 .. +2147483647            */
typedef unsigned long long    uint64_t;         /*           0..18446744073709551615     */
typedef signed long long      int64_t;
typedef float                 float32_t;
typedef double                float64_t;

/*****************************************************************************************/

#endif /* DATA_TYPES_H_ */