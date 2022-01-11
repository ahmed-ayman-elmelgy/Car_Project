#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define Set_Bit(REG,bit)                        (REG |=   (1<<bit))
#define Clr_Bit(REG,bit)                        (REG &= ~ (1<<bit))
#define Toggle_Bit(REG,bit)                     (REG ^=   (1<<bit))

#define setBits(REG,BM)							((REG) |=  (BM))
#define clearBits(REG,BM)						((REG) &= ~(BM))
#define toggleBits(REG,BM)						((REG) ^=  (BM))

#define setAllBits(REG)							((REG)  =  (0xFF))
#define clearAllBits(REG)						((REG)  =  (0x00))
#define toggleAllBits(REG)						((REG) ^=  (0xFF))

#define Get_Bit(REG,bit)                        (((REG>>bit)&(0x01)))

#endif /* BIT_MATH_H_ */