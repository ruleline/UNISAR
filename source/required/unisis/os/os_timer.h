/**
 * @file os_timer.h
 * @brief software timer management.
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-28
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-06-02
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-01-28 |    ruleline    | initial commit.
 * -----------------------------------------------------------------------------
 */

#if !defined OS_TIMER_H
#define OS_TIMER_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_TIMER == 1))
#include "timers.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_TIMER == 1)) */

/**
 * @brief timer structure.
 * @details
 * this structure represents a software timer that can be used for executing
 * tasks at a specific time interval.
 */
struct TIMER {
        /** timer handle. */
        void *handle;
        /** timer name. */
        char *name;
        /** timer period. */
        usize period;
        /** timer is reload. */
        bool is_reload;
        /** timer id. */
        usize id;
        /** timer callback. */
        void *callback;
};

/**
 * @brief create a timer.
 * @details
 * this function creates a timer with the given name, period, is_reload, id, and
 * callback. if the timer already exists, it does nothing.
 * @param[in,out] timer pointer to the timer structure.
 * @return the status of creation.
 */
static __force_inline i32 timer_create(struct TIMER *timer)
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
 * @brief delete a timer.
 * @details
 * this function deletes a timer. if the timer does not exist, it does nothing.
 * @param[in,out] timer pointer to the timer structure.
 * @return the status of deletion.
 */
static __force_inline i32 timer_delete(struct TIMER *timer)
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
 * @brief get the state of a timer.
 * @details
 * this function gets the state of a timer. if the timer does not exist, it
 * returns -2. if the timer is running, it returns 0. if the timer is not
 * running, it returns -1.
 * @param[in,out] timer pointer to the timer structure.
 * @return the state of the timer.
 */
static __force_inline i32 timer_get_state(struct TIMER *timer)
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
 * @brief start a timer.
 * @details
 * this function starts a timer. if the timer does not exist, it returns -2. if
 * the timer is already running, it returns 0. if the timer is not running, it
 * returns -1.
 * @param[in,out] timer pointer to the timer structure.
 * @return the status of start operation.
 */
static __force_inline i32 timer_start(struct TIMER *timer)
{
        if (!timer->handle) {
                return (-2);
        }
        if (timer_get_state(timer) == 0) {
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
 * @brief stop a timer.
 * @details
 * this function stops a timer. if the timer does not exist, it returns -2. if
 * the timer is not running, it returns 0. if the timer is running, it returns
 * -1.
 * @param[in,out] timer pointer to the timer structure.
 * @return the status of stop operation.
 */
static __force_inline i32 timer_stop(struct TIMER *timer)
{
        if (!timer->handle) {
                return (-2);
        }
        if (timer_get_state(timer) != 0) {
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
 * @brief get the period of a timer.
 * @details
 * this function gets the period of a timer. if the timer does not exist, it
 * returns 0.
 * @param[in,out] timer pointer to the timer structure.
 * @return the period of the timer.
 */
static __force_inline usize timer_get_period(struct TIMER *timer)
{
        return (timer->period);
}

/**
 * @brief set the period of a timer.
 * @details
 * this function sets the period of a timer. if the timer does not exist, it
 * does nothing.
 * @param[in,out] timer pointer to the timer structure.
 * @param[in] period new period of the timer.
 * @return the status of setting the period.
 */
static __force_inline i32 timer_set_period(struct TIMER *timer, usize period)
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
