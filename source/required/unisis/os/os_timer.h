/**
 * @file os_timer.h
 * @brief 定时器
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-28
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-09
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

#if !defined OS_TIMER_H
#define OS_TIMER_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_TIMER == 1))
#include "timers.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_TIMER == 1)) */

/**
 * @brief 定时器
 *
 */
struct TIMER {
        void *handle;   /**< 句柄 */
        char *name;     /**< 名称 */
        usize period;   /**< 周期 */
        bool is_reload; /**< 是否重载 */
        usize id;       /**< 标识符 */
        void *callback; /**< 回调 */
};

/**
 * @brief 创建定时器
 *
 * @param[in,out] timer 定时器
 * @return 结果
 * @retval 0 成功
 */
static inline i32 timer_create_(struct TIMER *timer)
{
        if (timer->handle) {
                return (0);
        }

        #if ((FREERTOS == 1) && (FREERTOS_TIMER == 1))
        timer->handle = xTimerCreate(timer->name,
                pdMS_TO_TICKS(timer->period), timer->is_reload,
                &timer->id, timer->callback);
        ASSERT(timer->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TIMER == 1)) */
        return (0);
}

/**
 * @brief 删除定时器
 *
 * @param[in,out] timer 定时器
 * @return 结果
 * @retval -2 未创建
 * @retval -1 失败
 * @retval 0 成功
 */
static inline i32 timer_delete_(struct TIMER *timer)
{
        if (!timer->handle) {
                return (-2);
        }

        bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_TIMER == 1))
        is_done = xTimerDelete(timer->handle, 0);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TIMER == 1)) */

        if (is_done) {
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
 * @retval -2 未创建
 * @retval -1 休眠
 * @retval 0 运行
 */
static inline i32 timer_get_state_(struct TIMER *timer)
{
        if (!timer->handle) {
                return (-2);
        }

        bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_TIMER == 1))
        is_done = xTimerIsTimerActive(timer->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TIMER == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief 启动定时器
 *
 * @param[in] timer 定时器
 * @return 结果
 * @retval -2 未创建
 * @retval -1 失败
 * @retval 0 成功
 */
static inline i32 timer_start_(struct TIMER *timer)
{
        if (!timer->handle) {
                return (-2);
        }
        if (timer_get_state_(timer) == 0) {
                return (0);
        }

        bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_TIMER == 1))
        is_done = xTimerStart(timer->handle, 0);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TIMER == 1)) */

        if (is_done) {
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
 * @retval -2 未创建
 * @retval -1 失败
 * @retval 0 成功
 */
static inline i32 timer_stop_(struct TIMER *timer)
{
        if (!timer->handle) {
                return (-2);
        }
        if (timer_get_state_(timer) != 0) {
                return (0);
        }

        bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_TIMER == 1))
        is_done = xTimerStop(timer->handle, 0);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TIMER == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief 获取定时器周期
 *
 * @param[in] timer 定时器
 * @return 周期
 */
static inline usize timer_get_period_(struct TIMER *timer)
{
        return (timer->period);
}

/**
 * @brief 设置定时器周期
 *
 * @param[in] timer 定时器
 * @param[in] period 周期(单位:ms)
 * @return 结果
 * @retval -2 未创建
 * @retval -1 失败
 * @retval 0 成功
 */
static inline i32 timer_set_period_(struct TIMER *timer, usize period)
{
        if (!timer->handle) {
                return (-2);
        }

        bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_TIMER == 1))
        is_done = xTimerChangePeriod(timer->handle,
                                        pdMS_TO_TICKS(period), 0);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TIMER == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

#endif /* !defined OS_TIMER_H */
