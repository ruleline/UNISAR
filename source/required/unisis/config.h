/**
 * @file config.h
 * @brief config
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-28
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-25
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

/**
 * @def FREERTOS
 * @brief 定义一个标识, 用于启用 FreeRTOS 相关功能.
 * @details 值为 1 表示启用, 值为 0 表示不启用.
 */
#define FREERTOS        (1)
/**
 * @def ZEPHYR
 * @brief 定义一个标识, 用于启用 Zephyr 相关功能.
 * @details 值为 1 表示启用, 值为 0 表示不启用.
 */
#define ZEPHYR          (0)
/**
 * @def THREADX
 * @brief 定义一个标识, 用于启用 ThreadX 相关功能.
 * @details 值为 1 表示启用, 值为 0 表示不启用.
 */
#define THREADX         (0)

/**
 * @def LINE_BREAK
 * @brief 定义换行符常量.
 * @details Windows 风格的换行符 "\r\n", Linux 风格的换行符 "\n".
 */
#define LINE_BREAK      "\r\n"
/**
 * @def PRINTF
 * @brief 定义常规打印函数.
 * @details 默认加上头(file&line)、尾(换行符).
 */
#define PRINTF          printf
/**
 * @def PRINT
 * @brief 定义立即打印函数.
 * @details 默认加上头(file&line)、尾(换行符).
 */
#define PRINT           printf

/**
 * @enum ITEM_PRIORITY
 * @brief 定义各种 item 的优先级.
 * @details 该枚举类型用于表示不同 item 的优先级.
 *          ITEM_MINIMUM_UNREACHABLE_PRIORITY 和 ITEM_MAXIMUM_UNREACHABLE_PRIORITY
 *          作为边界值, 分别代表最小和最大的不可达优先级，实际的接口优先级介于这两个值之间.
 *          从 0 到 MINIMUM_UNREACHABLE_PRIORITY 为内部实现的特殊值,
 *          在构造中, 优先级值越小越早执行.
 *          在析构中, 优先级值越小越晚执行.
 */
enum ITEM_PRIORITY {
        /**
         * @brief 最小的不可达优先级.
         * @details 作为优先级范围的下限, 任何实际的接口优先级都应大于此值.
         */
        ITEM_MINIMUM_UNREACHABLE_PRIORITY = 100,

        GPIO1_PRIORITY,

        /**
         * @brief UART1 优先级.
         * @details 用于表示 UART1 通信接口的优先级.
         */
        UART1_PRIORITY,

        /**
         * @brief CAN1 优先级.
         * @details 用于表示 CAN1 通信接口的优先级.
         */
        CAN1_PRIORITY,

        /**
         * @brief 以太网 1 优先级.
         * @details 用于表示 ETH1 通信接口的优先级.
         */
        ETH1_PRIORITY,

        /**
         * @brief SPI1 优先级.
         * @details 用于表示 SPI1 通信接口的优先级.
         */
        SPI1_PRIORITY,

        /**
         * @brief I2C1 优先级.
         * @details 用于表示 IIC1 通信接口的优先级.
         */
        IIC1_PRIORITY,

        /**
         * @brief LIN1 优先级.
         * @details 用于表示 LIN1 通信接口的优先级.
         */
        LIN1_PRIORITY,

        LOG_PRIORITY,

        /**
         * @brief 最大的不可达优先级.
         * @details 作为优先级范围的上限，任何实际的接口优先级都应小于此值.
         */
        ITEM_MAXIMUM_UNREACHABLE_PRIORITY = 65536,
};

#endif /* !defined CONFIG_H */
