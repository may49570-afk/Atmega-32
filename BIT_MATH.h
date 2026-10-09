#ifndef bit_math
#define bit_math

#define SET_BIT(Reg,Bit) ((Reg) |= 1<<(Bit))

#define CLR_BIT(Reg,Bit) ((Reg) &= ~(1<<Bit))

#define TOG_BIT(Reg,Bit) ((Reg) ^= 1<<(Bit))

#define GET_BIT(Reg,Bit) ((Reg >> Bit) & 0x01)

#endif
