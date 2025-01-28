/**
 * @file os_timers.h
 * @brief os_timers
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-28
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-01-28
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

#if !defined OS_TIMERS_H
#define OS_TIMERS_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_TIMER == 1))
#include "timers.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_TIMER == 1)) */

/**
 * @brief 定时器
 *
 */
struct TIMER {
        void *handle;           /**< 句柄 */
        char *name;             /**< 名称 */
        unsigned long period;   /**< 周期 */
        _Bool is_periodic;      /**< 是否为周期性 */
        unsigned long id;       /**< 标识符 */
        void *callback;         /**< 回调 */
};

/**
 * @brief 创建定时器
 *
 * @param[in,out] timer 定时器
 * @return 结果
 * @retval 0 成功
 */
static inline long timer_create(struct TIMER *timer)
{
        #if ((FREERTOS == 1) && (FREERTOS_TIMER == 1))
        timer->handle = xTimerCreate(timer->name, timer->period,
                        timer->is_periodic, &timer->id, timer->callback);
        ASSERT(timer->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TIMER == 1)) */
        return (0);
}

#endif /* !defined OS_TIMERS_H */
