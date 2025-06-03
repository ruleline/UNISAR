/**
 * @file fixed_macro.h
 * @brief fixed_macro
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-19
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
 *   0.00.001   | 2025-02-19 |    ruleline    | initial commit
 * -----------------------------------------------------------------------------
 */

#if !defined FIXED_MACRO_H
#define FIXED_MACRO_H

#if !defined UNUSED
/**
 * @brief define a function as unused.
 * @details
 * this macro can be used to define a function as unused. the function is defined
 * as unused and will not be compiled.
 * @param[in] x the function to define as unused.
 */
#define UNUSED(x) (void)(0)
#endif /*!defined UNUSED */

#if !defined ARRAY_SIZE
/**
 * @brief get the size of an array.
 * @details
 * this macro can be used to get the size of an array. the array size is calculated
 * as the size of the array divided by the size of the first element in the array.
 * @param[in] x the array to get the size of.
 */
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#endif /*!defined ARRAY_SIZE */

#endif /* !defined FIXED_MACRO_H */
