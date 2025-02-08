/**
 * @file os_thread.h
 * @brief os_thread
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-28
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-08
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

#if !defined OS_THREAD_H
#define OS_THREAD_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
#include "task.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */

/**
 * @brief 线程
 *
 */
struct THREAD {
        void *handle;           /**< 句柄 */
        void *entry;            /**< 入口 */
        char *name;             /**< 名称 */
        usize stack_depth;      /**< 栈深度(单位:字) */
        void *parameters;       /**< 参数 */
        usize priority;         /**< 优先级 */
};

/**
 * @brief 创建线程
 *
 * @param[in,out] thread 线程
 * @return 结果
 * @retval 0 成功
 */
static inline i32 thread_create_(struct THREAD *thread)
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
 * @brief 删除线程
 *
 * @param[in] thread 线程
 * @return 结果
 * @retval 0 成功
 */
static inline i32 thread_delete_(struct THREAD *thread)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskDelete(thread->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief 挂起线程
 *
 * @param[in] thread 线程
 * @return 结果
 * @retval 0 成功
 */
static inline i32 thread_suspend_(struct THREAD *thread)
{
        if (thread_state_get_(thread) == 3) {
                return (0);
        }

        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskSuspend(thread->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief 恢复线程
 *
 * @param[in] thread 线程
 * @return 结果
 * @retval -1 未创建
 * @retval 0 成功
 */
static inline i32 thread_resume_(struct THREAD *thread)
{
        if (!thread->handle) {
                return (-1);
        }
        if (thread_state_get_(thread) == 0) {
                return (0);
        }

        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskResume(thread->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief 获取线程状态
 *
 * @param[in] thread 线程
 * @return 状态
 * @retval -2 未创建
 * @retval -1 无效
 * @retval 0 运行
 * @retval 1 就绪
 * @retval 2 阻塞
 * @retval 3 挂起
 * @retval 4 删除
 */
static inline i32 thread_get_state_(struct THREAD *thread)
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
 * @brief 获取线程名称
 *
 * @param[in] thread 线程
 * @param[out] name 名称
 * @return 结果
 * @retval 0 成功
 */
static inline i32 thread_get_name_(struct THREAD *thread, char *name)
{
        strcpy(name, thread->name);
        return (0);
}

/**
 * @brief 获取线程优先级
 *
 * @param[in] thread 线程
 * @return 优先级
 */
static inline i32 thread_get_priority_(struct THREAD *thread)
{
        return (thread->priority);
}

/**
 * @brief 设置线程优先级
 *
 * @param[in] thread 线程
 * @param[in] priority 优先级
 * @return 结果
 * @retval 0 成功
 */
static inline i32 thread_set_priority_(struct THREAD *thread, usize priority)
{
        if (thread_priority_get_(thread) == priority) {
                return (0);
        }

        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskPrioritySet(thread->handle, priority);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief 发送线程通知
 *
 * @param[in] thread 线程
 * @return 结果
 * @retval -2 未创建
 * @retval -1 失败
 * @retval 0 成功
 */
static inline i32 thread_give_notify_(struct THREAD *thread)
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
 * @brief 获取线程通知
 *
 * @param[in] thread 线程
 * @param[in] wait 等待时间(单位:ms)
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline i32 thread_take_notify_(struct THREAD *thread, usize wait)
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
