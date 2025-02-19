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

enum ITEM_PRIORITY {
        MINIMUM_UNREACHABLE_PRIORITY = 100,
        CAN1_PRIORITY,
        CAN2_PRIORITY,
        CAN3_PRIORITY,
        CAN4_PRIORITY,
        CAN5_PRIORITY,
        ETH1_PRIORITY,
        ETH2_PRIORITY,
        ETH3_PRIORITY,
        ETH4_PRIORITY,
        ETH5_PRIORITY,
        UART1_PRIORITY,
        UART2_PRIORITY,
        UART3_PRIORITY,
        UART4_PRIORITY,
        UART5_PRIORITY,
        SPI1_PRIORITY,
        SPI2_PRIORITY,
        SPI3_PRIORITY,
        SPI4_PRIORITY,
        SPI5_PRIORITY,
        IIC1_PRIORITY,
        IIC2_PRIORITY,
        IIC3_PRIORITY,
        IIC4_PRIORITY,
        IIC5_PRIORITY,
        LIN1_PRIORITY,
        LIN2_PRIORITY,
        LIN3_PRIORITY,
        LIN4_PRIORITY,
        LIN5_PRIORITY,
        MAXIMUM_UNREACHABLE_PRIORITY = 65536,
};

#endif /* !defined CONFIG_H */
