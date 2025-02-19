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
 *          MINIMUM_UNREACHABLE_PRIORITY 和 MAXIMUM_UNREACHABLE_PRIORITY 作为边界值，
 *          分别代表最小和最大的不可达优先级，实际的接口优先级介于这两个值之间.
 *          从 0 到 MINIMUM_UNREACHABLE_PRIORITY 为内部实现的特殊值,
 *          在构造中, 优先级值越小越早执行.
 *          在析构中, 优先级值越小越晚执行.
 */
enum ITEM_PRIORITY {
        /**
         * @brief 最小的不可达优先级.
         * @details 作为优先级范围的下限, 任何实际的接口优先级都应大于此值.
         */
        MINIMUM_UNREACHABLE_PRIORITY = 100,

        /**
         * @brief CAN1 优先级.
         * @details 用于表示 CAN1 通信接口的优先级.
         */
        CAN1_PRIORITY,

        /**
         * @brief CAN2 优先级.
         * @details 用于表示 CAN2 通信接口的优先级.
         */
        CAN2_PRIORITY,

        /**
         * @brief CAN3 优先级.
         * @details 用于表示 CAN3 通信接口的优先级.
         */
        CAN3_PRIORITY,

        /**
         * @brief CAN4 优先级.
         * @details 用于表示 CAN4 通信接口的优先级.
         */
        CAN4_PRIORITY,

        /**
         * @brief CAN5 优先级.
         * @details 用于表示 CAN5 通信接口的优先级.
         */
        CAN5_PRIORITY,

        /**
         * @brief 以太网 1 优先级.
         * @details 用于表示 ETH1 通信接口的优先级.
         */
        ETH1_PRIORITY,

        /**
         * @brief 以太网 2 优先级.
         * @details 用于表示 ETH2 通信接口的优先级.
         */
        ETH2_PRIORITY,

        /**
         * @brief 以太网 3 优先级.
         * @details 用于表示 ETH3 通信接口的优先级.
         */
        ETH3_PRIORITY,

        /**
         * @brief 以太网 4 优先级.
         * @details 用于表示 ETH4 通信接口的优先级.
         */
        ETH4_PRIORITY,

        /**
         * @brief 以太网 5 优先级.
         * @details 用于表示 ETH5 通信接口的优先级.
         */
        ETH5_PRIORITY,

        /**
         * @brief UART1 优先级.
         * @details 用于表示 UART1 通信接口的优先级.
         */
        UART1_PRIORITY,

        /**
         * @brief UART2 优先级.
         * @details 用于表示 UART2 通信接口的优先级.
         */
        UART2_PRIORITY,

        /**
         * @brief UART3 优先级.
         * @details 用于表示 UART3 通信接口的优先级.
         */
        UART3_PRIORITY,

        /**
         * @brief UART4 优先级.
         * @details 用于表示 UART4 通信接口的优先级.
         */
        UART4_PRIORITY,

        /**
         * @brief UART5 优先级.
         * @details 用于表示 UART5 通信接口的优先级.
         */
        UART5_PRIORITY,

        /**
         * @brief SPI1 优先级.
         * @details 用于表示 SPI1 通信接口的优先级.
         */
        SPI1_PRIORITY,

        /**
         * @brief SPI2 优先级.
         * @details 用于表示 SPI2 通信接口的优先级.
         */
        SPI2_PRIORITY,

        /**
         * @brief SPI3 优先级.
         * @details 用于表示 SPI3 通信接口的优先级.
         */
        SPI3_PRIORITY,

        /**
         * @brief SPI4 优先级.
         * @details 用于表示 SPI4 通信接口的优先级.
         */
        SPI4_PRIORITY,

        /**
         * @brief SPI5 优先级.
         * @details 用于表示 SPI5 通信接口的优先级.
         */
        SPI5_PRIORITY,

        /**
         * @brief I2C1 优先级.
         * @details 用于表示 IIC1 通信接口的优先级.
         */
        IIC1_PRIORITY,

        /**
         * @brief I2C2 优先级.
         * @details 用于表示 IIC2 通信接口的优先级.
         */
        IIC2_PRIORITY,

        /**
         * @brief I2C3 优先级.
         * @details 用于表示 IIC3 通信接口的优先级.
         */
        IIC3_PRIORITY,

        /**
         * @brief I2C4 优先级.
         * @details 用于表示 IIC4 通信接口的优先级.
         */
        IIC4_PRIORITY,

        /**
         * @brief I2C5 优先级.
         * @details 用于表示 IIC5 通信接口的优先级.
         */
        IIC5_PRIORITY,

        /**
         * @brief LIN1 优先级.
         * @details 用于表示 LIN1 通信接口的优先级.
         */
        LIN1_PRIORITY,

        /**
         * @brief LIN2 优先级.
         * @details 用于表示 LIN2 通信接口的优先级.
         */
        LIN2_PRIORITY,

        /**
         * @brief LIN3 优先级.
         * @details 用于表示 LIN3 通信接口的优先级.
         */
        LIN3_PRIORITY,

        /**
         * @brief LIN4 优先级.
         * @details 用于表示 LIN4 通信接口的优先级.
         */
        LIN4_PRIORITY,

        /**
         * @brief LIN5 优先级.
         * @details 用于表示 LIN5 通信接口的优先级.
         */
        LIN5_PRIORITY,

        /**
         * @brief 最大的不可达优先级.
         * @details 作为优先级范围的上限，任何实际的接口优先级都应小于此值.
         */
        MAXIMUM_UNREACHABLE_PRIORITY = 65536,
};

#endif /* !defined CONFIG_H */
