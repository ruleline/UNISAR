/**
 * @file config.h
 * @brief config
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-28
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-10
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-01-28 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#if !defined CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <time.h>

typedef _Bool                   bool;
typedef signed char             i8;
typedef signed short int        i16;
typedef signed int              i32;
typedef signed long long int    i64;
typedef signed long int         isize;
typedef unsigned char           u8;
typedef unsigned short int      u16;
typedef unsigned int            u32;
typedef unsigned long long int  u64;
typedef unsigned long int       usize;
typedef float                   f32;
typedef double                  f64;

#define __used __attribute__((__used__))
#define __unused __attribute__((__unused__))
#define __packed __attribute__((__packed__))
#define __aligned(x) __attribute__((aligned(x)))
#define __always_inline __attribute__((__always_inline__))

#define FREERTOS (1)

#define LINE_BREAK      "\r\n"
#define PRINTF          printf /**< 常规打印, 需默认加上头(file&line)、尾(换行符) */
#define PRINT           printf /**< 立即打印, 需默认加上头(file&line)、尾(换行符) */

#if !defined ASSERT
#define ASSERT(x)                       \
do {                                    \
        if (!(x)) {                     \
                PRINT("[ASSERT]");      \
                for (;;);               \
        }                               \
} while (0)
#endif /* !defined ASSERT */

#endif /* !defined CONFIG_H */
