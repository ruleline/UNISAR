/**
 * @file os_thread.h
 * @brief thread management.
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

#if !defined OS_THREAD_H
#define OS_THREAD_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
#include "task.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */

/**
 * @brief thread structure.
 * @details
 * this structure represents a thread that can be used for executing tasks.
 */
struct THREAD {
        /** thread handle. */
        void *handle;
        /** thread entry function. */
        void *entry;
        /** thread name. */
        char *name;
        /** thread stack depth. */
        usize stack_depth;
        /** thread parameters. */
        void *parameters;
        /** thread priority. */
        usize priority;
};

/**
 * @brief create a thread.
 * @details
 * this function creates a thread with the given entry function, name, stack
 * depth, parameters, and priority. if the thread already exists, it does
 * nothing.
 * @param[in,out] thread pointer to the thread structure.
 * @return the status of creation.
 */
static __force_inline i32 thread_create(struct THREAD *thread)
{
        if (thread->handle) {
                return (0);
        }

        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        BaseType_t xReturn = pdPASS;
        xReturn = xTaskCreate(thread->entry, thread->name, thread->stack_depth,
                        thread->parameters, thread->priority, &thread->handle);
        ASSERT(xReturn == pdPASS);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief delete a thread.
 * @details
 * this function deletes a thread. if the thread does not exist, it does
 * nothing.
 * @param[in,out] thread pointer to the thread structure.
 * @return the status of deletion.
 */
static __force_inline i32 thread_delete(struct THREAD *thread)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskDelete(thread->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief get the state of a thread.
 * @details
 * this function gets the state of a thread. if the thread does not exist, it
 * returns -1.
 * @param[in,out] thread pointer to the thread structure.
 * @return the state of the thread.
 */
static __force_inline i32 thread_get_state(struct THREAD *thread)
{
        if (!thread->handle) {
                return (-2);
        }

        i8 state = 0;

        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        state = eTaskGetState(thread->handle);
        if (state >= eInvalid) {
                state = -1;
        }
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */

        return (state);
}

/**
 * @brief suspend a thread.
 * @details
 * this function suspends a thread. if the thread does not exist, it does
 * nothing.
 * @param[in,out] thread pointer to the thread structure.
 * @return the status of suspension.
 */
static __force_inline i32 thread_suspend(struct THREAD *thread)
{
        if (thread_get_state(thread) == 3) {
                return (0);
        }

        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskSuspend(thread->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief resume a thread.
 * @details
 * this function resumes a thread. if the thread does not exist, it does
 * nothing.
 * @param[in,out] thread pointer to the thread structure.
 * @return the status of resumption.
 */
static __force_inline i32 thread_resume(struct THREAD *thread)
{
        if (!thread->handle) {
                return (-1);
        }
        if (thread_get_state(thread) == 0) {
                return (0);
        }

        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskResume(thread->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief get the name of a thread.
 * @details
 * this function gets the name of a thread. if the thread does not exist, it
 * returns -1.
 * @param[in,out] thread pointer to the thread structure.
 * @param[in,out] name pointer to the name buffer.
 * @return the status of getting the name.
 */
static __force_inline i32 thread_get_name(struct THREAD *thread, char *name)
{
        strncpy(name, thread->name, strlen(thread->name));
        return (0);
}

/**
 * @brief get the priority of a thread.
 * @details
 * this function gets the priority of a thread. if the thread does not exist, it
 * returns -1.
 * @param[in,out] thread pointer to the thread structure.
 * @return the priority of the thread.
 */
static __force_inline usize thread_get_priority(struct THREAD *thread)
{
        return (thread->priority);
}

/**
 * @brief set the priority of a thread.
 * @details
 * this function sets the priority of a thread. if the thread does not exist, it
 * does nothing.
 * @param[in,out] thread pointer to the thread structure.
 * @param[in] priority new priority of the thread.
 * @return the status of setting the priority.
 */
static __force_inline i32 thread_set_priority(struct THREAD *thread, usize priority)
{
        if (thread_get_priority(thread) == priority) {
                return (0);
        }

        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskPrioritySet(thread->handle, priority);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief give a notification to a thread.
 * @details
 * this function gives a notification to a thread. if the thread does not exist,
 * it does nothing.
 * @param[in,out] thread pointer to the thread structure.
 * @return the status of giving the notification.
 */
static __force_inline i32 thread_give_notify(struct THREAD *thread)
{
        if (!thread->handle) {
                return (-2);
        }

        bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        is_done = xTaskNotifyGive(thread->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief take a notification from a thread.
 * @details
 * this function takes a notification from a thread. if the thread does not
 * exist, it does nothing.
 * @param[in,out] thread pointer to the thread structure.
 * @param[in] wait wait time in milliseconds.
 * @return the status of taking the notification.
 */
static __force_inline i32 thread_take_notify(struct THREAD *thread, usize wait)
{
        bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        is_done = ulTaskNotifyTake(pdTRUE, pdMS_TO_TICKS(wait));
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

#endif /* !defined OS_THREAD_H */
