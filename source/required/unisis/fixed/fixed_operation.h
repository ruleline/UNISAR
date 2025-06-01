/**
 * @file fixed_operation.h
 * @brief fixed_operation
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-06-01
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-06-01
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
 * @return bool
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
 * @return void
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
 * @return void
 */
static __force_inline void bit_set_low(usize *value, u8 position)
{
        *value &= ~(1 << position);
}

#endif /* !defined FIXED_OPERATION_H */
