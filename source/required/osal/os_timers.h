/**
 * @file os_timers.h
 * @brief os_timers
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-28
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-01-29
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
static inline long timer_create_(struct TIMER *timer)
{
        #if ((FREERTOS == 1) && (FREERTOS_TIMER == 1))
        timer->handle = xTimerCreate(timer->name, timer->period,
                        timer->is_periodic, &timer->id, timer->callback);
        ASSERT(timer->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TIMER == 1)) */
        return (0);
}

/**
 * @brief 删除定时器
 *
 * @param[in,out] timer 定时器
 * @return 结果
 * @retval 0 成功
 */
static inline long timer_delete_(struct TIMER *timer)
{
        #if ((FREERTOS == 1) && (FREERTOS_TIMER == 1))
        vTimerDelete(timer->handle, 0);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TIMER == 1)) */
        return (0);
}

/**
 * @brief 启动定时器
 *
 * @param[in] timer 定时器
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long timer_start_(struct TIMER *timer)
{
        _Bool is_start = 0;

        #if ((FREERTOS == 1) && (FREERTOS_TIMER == 1))
        is_start = xTimerStart(timer->handle, 0);
        is_start = (is_start == pdPASS);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TIMER == 1)) */

        if (is_start) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief 停止定时器
 *
 * @param[in] timer 定时器
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long timer_stop_(struct TIMER *timer)
{
        _Bool is_stop = 0;

        #if ((FREERTOS == 1) && (FREERTOS_TIMER == 1))
        is_stop = xTimerStop(timer->handle, 0);
        is_stop = (is_stop == pdPASS);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TIMER == 1)) */

        if (is_stop) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief 获取定时器状态
 *
 * @param[in] timer 定时器
 * @return 状态
 * @retval 0 运行
 * @retval -1 休眠
 */
static inline long timer_state_get_(struct TIMER *timer)
{
        _Bool is_running = 0;

        #if ((FREERTOS == 1) && (FREERTOS_TIMER == 1))
        is_running = xTimerIsTimerActive(timer->handle);
        is_running = (is_running == pdTRUE);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TIMER == 1)) */

        if (is_running) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief s
 *
 * @param[in] timer 定时器
 * @return 周期
 */
static inline long timer_period_get_(struct TIMER *timer)
{
        return (timer->period);
}

/**
 * @brief 设置定时器周期
 *
 * @param[in] timer 定时器
 * @param[in] period 周期
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long timer_period_set_(struct TIMER *timer, unsigned long period)
{
        _Bool is_set = 0;

        #if ((FREERTOS == 1) && (FREERTOS_TIMER == 1))
        is_set = xTimerChangePeriod(timer->handle, period, 0);
        is_set = (is_set == pdPASS);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TIMER == 1)) */

        if (is_set) {
                return (0);
        } else {
                return (-1);
        }
}

#endif /* !defined OS_TIMERS_H */
