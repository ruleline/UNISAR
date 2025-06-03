/**
 * @file fixed_operation.h
 * @brief fixed_operation
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-06-01
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-06-03
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-06-01 |    ruleline    | initial commit
 * -----------------------------------------------------------------------------
 */

#if !defined FIXED_OPERATION_H
#define FIXED_OPERATION_H

#include "unisis.h"

/**
 * @brief retrieve the value of a specific bit in an unsigned integer.
 * @details
 * this function extracts the bit value at a specified position from an unsigned
 * integer.it uses bitwise right shift and AND operations to isolate the target bit.
 * @param[in] value the unsigned integer from which the bit value is to be extracted.
 * @param[in] position the position of the bit to extract, starting from 0 (LSB).
 * @return bool.
 */
static __force_inline bool bit_value(usize value, u8 position)
{
        return ((value >> position) & 0x01);
}

/**
 * @brief set a specific bit in an unsigned integer to high (1).
 * @details
 * This function modifies the provided unsigned integer by setting the bit at the
 * specified position to 1. It uses bitwise operations to achieve this without
 * affecting other bits in the number.
 * @param[in,out] value A pointer to the unsigned integer to be modified.
 * @param[in] position The position of the bit to set to 1, starting from 0 (LSB).
 * @return void.
 */
static __force_inline void bit_set_high(usize *value, u8 position)
{
        *value |= (1 << position);
}

/**
 * @brief Set a specific bit in an unsigned integer to low (0).
 * @details
 * This function modifies the provided unsigned integer by clearing the bit at the
 * specified position to 0. it uses bitwise operations to achieve this without
 * affecting other bits in the number.
 * @param[in,out] value A pointer to the unsigned integer to be modified.
 * @param[in] position The position of the bit to set to 0, starting from 0 (LSB).
 * @return void.
 */
static __force_inline void bit_set_low(usize *value, u8 position)
{
        *value &= ~(1 << position);
}

/**
 * @brief toggle a specific bit in an unsigned integer.
 * @details
 * this function modifies the provided unsigned integer by toggling the bit at
 * the specified position. if the bit is 1, it is set to 0, and if it is 0, it
 * is set to 1. it uses bitwise operations to achieve this without affecting
 * other bits in the number.
 * @param[in,out] value a pointer to the unsigned integer to be modified.
 * @param[in] position the position of the bit to toggle, starting from 0 (LSB).
 * @return void.
 */
static __force_inline void bit_toggle(usize *value, u8 position)
{
        *value ^= (1 << position);
}

/**
 * @brief copy data from one memory location to another.
 * @details
 * this function copies a specified number of bytes from the source memory
 * location to the destination memory location. it uses a simple loop to copy
 * each byte one at a time.
 * @param[in,out] destination a pointer to the destination memory location.
 * @param[in] source a pointer to the source memory location.
 * @param[in] size the number of bytes to copy.
 * @return void.
 */
static __force_inline void memory_copy(void *destination, void *source, usize size)
{
        char *d = (char *)destination;
        char *s = (char *)source;

        for (usize i = 0; i < size; i++) {
                d[i] = s[i];
        }
}

/**
 * @brief set a specific value in a memory location.
 * @details
 * this function sets a specified number of bytes in the memory location to a
 * given value. it uses a simple loop to set each byte to the specified value.
 * @param[in,out] destination a pointer to the memory location to be set.
 * @param[in] value the value to set each byte to.
 * @param[in] size the number of bytes to set.
 * @return void.
 */
static __force_inline void memory_set(void *destination, char value, usize size)
{
        char *d = (char *)destination;

        for (usize i = 0; i < size; i++) {
                d[i] = value;
        }
}

/**
 * @brief clear a memory location.
 * @details
 * this function sets a specified number of bytes in the memory location to 0.
 * it uses a simple loop to set each byte to 0.
 * @param[in,out] destination a pointer to the memory location to be cleared.
 * @param[in] size the number of bytes to clear.
 * @return void.
 */
static __force_inline void memory_clear(void *destination, usize size)
{
        char *d = (char *)destination;

        for (usize i = 0; i < size; i++) {
                d[i] = 0;
        }
}

/**
 * @brief compare two memory locations.
 * @details
 * this function compares a specified number of bytes between two memory
 * locations. it uses a simple loop to compare each byte.
 * @param[in] destination a pointer to the first memory location.
 * @param[in] source a pointer to the second memory location.
 * @param[in] size the number of bytes to compare.
 * @return the result of the comparison.
 */
static __force_inline bool memory_compare(void *destination,
                                                void *source, usize size)
{
        char *d = (char *)destination;
        char *s = (char *)source;

        for (usize i = 0; i < size; i++) {
                if (d[i] != s[i]) {
                        return (1);
                }
        }
        return (0);
}

#endif /* !defined FIXED_OPERATION_H */
