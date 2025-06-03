/**
 * @file config.h
 * @brief config
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-28
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
 *   0.00.001   | 2025-01-28 |    ruleline    | initial commit
 * -----------------------------------------------------------------------------
 */

#if !defined CONFIG_H
#define CONFIG_H

/**
 * @brief the identifier of debug mode.
 * @details
 * when the identifier is 1, debug mode will be used. when the identifier is 0,
 * release mode will be used.
 */
#define DEBUG   (1)
/**
 * @brief the identifier of release mode.
 * @details
 * when the identifier is 1, release mode will be used. when the identifier is 0,
 * debug mode will be used.
 */
#define RELEASE (0)

/**
 * @brief the identifier of bare metal.
 * @details
 * when the identifier is 1, bare metal will be used. when the identifier is 0,
 * bare metal will not be used.
 */
#define BARE_METAL      (0)
/**
 * @brief the identifier of FreeRTOS.
 * @details
 * when the identifier is 1, FreeRTOS will be used. when the identifier is 0,
 * FreeRTOS will not be used.
 */
#define FREERTOS        (0)
/**
 * @brief the identifier of Zephyr.
 * @details
 * when the identifier is 1, Zephyr will be used. when the identifier is 0,
 * Zephyr will not be used.
 */
#define ZEPHYR          (0)
/**
 * @brief the identifier of ThreadX.
 * @details
 * when the identifier is 1, ThreadX will be used. when the identifier is 0,
 * ThreadX will not be used.
 */
#define THREADX         (0)

/**
 * @brief the identifier of Little-FS.
 * @details
 * when the identifier is 1, Little-FS will be used. when the identifier is 0,
 * Little-FS will not be used.
 */
#define LITTLE_FILE_SYSTEM       (0)
/**
 * @brief the identifier of FAT-FS.
 * @details
 * when the identifier is 1, FAT-FS will be used. when the identifier is 0,
 * FAT-FS will not be used.
 */
#define FAT_FILE_SYSTEM          (0)

/**
 * @brief line break.
 * @details
 * this macro is used to define the line break character. it is recommended to
 * use "\r\n" for Windows and "\n" for Linux.
 */
#define LINE_BREAK      "\r\n"

#if (DEBUG == 1)
/**
 * @brief regular printing.
 * @details
 * this macro is used to define the regular printing function. it is recommended
 * to use this macro for regular information, such as debug information.
 */
#define PRINTF(x, ...)  printf(x LINE_BREAK, ##__VA_ARGS__)
#elif (RELEASE == 1)
/**
 * @brief regular printing.
 * @details
 * this macro is used to define the regular printing function. it is recommended
 * to use this macro for regular information, such as debug information.
 */
#define PRINTF(x, ...) (void)0
#else /* (DEBUG != 1) && (RELEASE != 1) */
#error "please define the printing function."
#endif /* (DEBUG == 1) || (RELEASE == 1) */
/**
 * @brief immediate printing.
 * @details
 * this macro is used to define the immediate printing function. it is recommended
 * to use this macro for immediate information, such as error information.
 */
#define PRINT(x, ...)   printf(x LINE_BREAK, ##__VA_ARGS__)

/**
 * @brief item priority set.
 * @details
 * this enum defines the priority of each item in the system. the priority is
 * used to determine the order of execution of each item.
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
