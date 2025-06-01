/**
 * @file fixed_macro.h
 * @brief fixed_macro
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-19
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
 *   0.00.001   | 2025-02-19 |    ruleline    | initial commit
 * -----------------------------------------------------------------------------
 */

#if !defined FIXED_MACRO_H
#define FIXED_MACRO_H

#if !defined ASSERT
/**
 * @brief assert a condition and print an error message if the condition is false.
 * @details
 * this macro can be used to assert a condition and print an error message if the
 * condition is false. the error message is formatted using the printf-style
 * format string and arguments.
 * @param[in] x the condition to assert.
 */
#define ASSERT(x)                               \
do {                                            \
        if (!(x)) {                             \
                PRINT("[ASSERT] %s", #x);       \
                for (;;);                       \
        }                                       \
} while (0)
#endif /* !defined ASSERT */

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
