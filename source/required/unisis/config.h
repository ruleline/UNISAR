/**
 * @file config.h
 * @brief config
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-28
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
 *   0.00.001   | 2025-01-28 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#if !defined CONFIG_H
#define CONFIG_H

#include "fixed.h"

#define FREERTOS        (1)
#define ZEPHYR          (0)
#define THREADX         (0)

#define LINE_BREAK      "\r\n"
#define PRINTF          printf /**< 常规打印, 需默认加上头(file&line)、尾(换行符) */
#define PRINT           printf /**< 立即打印, 需默认加上头(file&line)、尾(换行符) */

#endif /* !defined CONFIG_H */
