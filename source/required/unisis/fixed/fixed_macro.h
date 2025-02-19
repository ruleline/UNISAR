/**
 * @file fixed_macro.h
 * @brief fixed_macro
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-19
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-19
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-02-19 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#if !defined FIXED_MACRO_H
#define FIXED_MACRO_H

#if !defined ASSERT
#define ASSERT(x)                               \
do {                                            \
        if (!(x)) {                             \
                PRINT("[ASSERT] %s", #x);       \
                for (;;);                       \
        }                                       \
} while (0)
#endif /* !defined ASSERT */

#if !defined ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#endif /*!defined ARRAY_SIZE */

#endif /* !defined FIXED_MACRO_H */
