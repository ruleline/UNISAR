/**
 * @file config.h
 * @brief config
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-28
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
 *   0.00.001   | 2025-01-28 |    ruleline    | initial commit
 * -----------------------------------------------------------------------------
 */

#if !defined CONFIG_H
#define CONFIG_H

/**
 * @brief the identifier of FreeRTOS.
 * @details when the identifier is 1, FreeRTOS will be used.
 */
#define FREERTOS        (1)
/**
 * @brief the identifier of Zephyr.
 * @details
 */
#define ZEPHYR          (0)
/**
 * @brief the identifier of ThreadX.
 * @details when the identifier is 1, ThreadX will be used.
 */
#define THREADX         (0)

/**
 * @brief the identifier of Little-FS.
 * @details when the identifier is 1, Little-FS will be used.
 */
#define LITTLE_FILE_SYSTEM       (1)
/**
 * @brief the identifier of FAT-FS.
 * @details when the identifier is 1, FAT-FS will be used.
 */
#define FAT_FILE_SYSTEM          (0)

/**
 * @brief line break.
 * @details windows: "\r\n", linux: "\n".
 */
#define LINE_BREAK      "\r\n"
/**
 * @brief regular printing.
 * @details it is recommended to use this macro for regular information,
 *              such as debug information.
 */
#define PRINTF          printf
/**
 * @brief immediate printing.
 * @details it is recommended to use this macro for critical information,
 *              such as errors.
 */
#define PRINT           printf

/**
 * @brief item priority set.
 * @details the priority is used to determine the order of execution of the items.
 */
enum ITEM_PRIORITY {
        /** the minimum unreachable priority. */
        ITEM_MINIMUM_UNREACHABLE_PRIORITY = 100,

        /** FILE1 priority. */
        FILE1_PRIORITY,
        /** PIN1 priority. */
        PIN1_PRIORITY,
        /** UART1 priority. */
        UART1_PRIORITY,
        /** CAN1 priority. */
        CAN1_PRIORITY,
        /** ETH1 priority. */
        ETH1_PRIORITY,
        /** SPI1 priority. */
        SPI1_PRIORITY,
        /** IIC1 priority. */
        IIC1_PRIORITY,
        /** LIN1 priority. */
        LIN1_PRIORITY,
        /** LOG priority. */
        LOG_PRIORITY,

        /** the maximum reachable priority. */
        ITEM_MAXIMUM_UNREACHABLE_PRIORITY = 65536,
};

#endif /* !defined CONFIG_H */
