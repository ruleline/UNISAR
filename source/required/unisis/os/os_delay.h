/**
 * @file os_delay.h
 * @brief delay functions
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-29
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
 *   0.00.001   | 2025-01-29 |    ruleline    | initial commit
 * -----------------------------------------------------------------------------
 */

#if !defined OS_DELAY_H
#define OS_DELAY_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
#include "task.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */

/**
 * @brief delay function.
 * @param[in] time delay time in milliseconds.
 * @return result code.
 */
static __force_inline i32 delay(usize time)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskDelay((TickType_t)pdMS_TO_TICKS(time));
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief delay until function.
 * @param[in,out] start pointer to the start time in milliseconds.
 * @param[in] time delay time in milliseconds.
 * @return result code.
 */
static __force_inline i32 delay_until(usize *start, usize time)
{
        bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        *start = pdMS_TO_TICKS(*start);
        is_done = xTaskDelayUntil((TickType_t *)start,
                                        (TickType_t)pdMS_TO_TICKS(time));
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

#endif /* !defined OS_DELAY_H */
