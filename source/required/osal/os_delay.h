/**
 * @file os_delay.h
 * @brief os_delay
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-29
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-02
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-01-29 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#if !defined OS_DELAY_H
#define OS_DELAY_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
#include "task.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */

/**
 * @brief 相对延时
 *
 * @param[in] time 时间(单位:ms)
 * @return 结果
 * @retval 0 成功
 */
static inline long delay1_(unsigned long time)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskDelay(pdMS_TO_TICKS(time));
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief 绝对延时
 *
 * @param[in,out] start 开始时间(单位:ms)
 * @param[in] time 时间(单位:ms)
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long delay2_(unsigned long *start, unsigned long time)
{
        _Bool is_delay = 0;

        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        is_delay = xTaskDelayUntil(pdMS_TO_TICKS(start), pdMS_TO_TICKS(time));
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */

        if (is_delay) {
                return 0;
        } else {
                return -1;
        }
}

#endif /* !defined OS_DELAY_H */
