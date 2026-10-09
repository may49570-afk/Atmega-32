#ifndef bit_math
#define bit_math

/**
 * @brief Sets a specific bit in a register to 1.
 *
 * @param Reg The register to be modified.
 * @param Bit The bit position to be set.
 */
#define SET_BIT(Reg,Bit) ((Reg) |= 1<<(Bit))

/**
 * @brief Clears a specific bit in a register to 0.
 *
 * @param Reg The register to be modified.
 * @param Bit The bit position to be cleared.
 */
#define CLR_BIT(Reg,Bit) ((Reg) &= ~(1<<Bit))

/**
 * @brief Toggles a specific bit in a register.
 *
 * @param Reg The register to be modified.
 * @param Bit The bit position to be toggled.
 */
#define TOG_BIT(Reg,Bit) ((Reg) ^= 1<<(Bit))

/**
 * @brief Reads the value of a specific bit in a register.
 *
 * @param Reg The register to be read.
 * @param Bit The bit position to be checked.
 * @return The value of the selected bit (0 or 1).
 */
#define GET_BIT(Reg,Bit) ((Reg >> Bit) & 0x01)

#endif
