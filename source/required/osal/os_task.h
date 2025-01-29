/**
 * @file os_task.h
 * @brief os_task
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

#if !defined OS_TASK_H
#define OS_TASK_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
#include "task.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */

/**
 * @brief 任务
 *
 */
struct TASK {
        void *handle;                   /**< 句柄 */
        void *entry;                    /**< 入口 */
        char *name;                     /**< 名称 */
        unsigned long stack_depth;      /**< 栈深度(单位:字) */
        void *parameters;               /**< 参数 */
        unsigned long priority;         /**< 优先级 */
};

/**
 * @brief 创建任务
 *
 * @param[in,out] task 任务
 * @return 结果
 * @retval 0 成功
 */
static inline long task_create_(struct TASK *task)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        BaseType_t xReturn = pdPASS;
        xReturn = xTaskCreate(task->entry, task->name, task->stack_depth,
                        task->parameters, task->priority, &task->handle);
        ASSERT(xReturn == pdPASS);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief 删除任务
 *
 * @param[in] task 任务
 * @return 结果
 * @retval 0 成功
 */
static inline long task_delete_(struct TASK *task)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskDelete(task->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief 挂起任务
 *
 * @param[in] task 任务
 * @return 结果
 * @retval 0 成功
 */
static inline long task_suspend_(struct TASK *task)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskSuspend(task->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief 恢复任务
 *
 * @param[in] task 任务
 * @return 结果
 * @retval 0 成功
 */
static inline long task_resume_(struct TASK *task)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskResume(task->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief 获取任务状态
 *
 * @param[in] task 任务
 * @return 状态
 * @retval -1 无效
 * @retval 0 运行
 * @retval 1 就绪
 * @retval 2 阻塞
 * @retval 3 挂起
 * @retval 4 删除
 */
static inline long task_state_get_(struct TASK *task)
{
        long state = 0;

        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        state = eTaskGetState(task->handle);
        if (state >= eInvalid) {
                state = -1;
        }
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */

        return (state);
}

/**
 * @brief 获取任务优先级
 *
 * @param[in] task 任务
 * @return 优先级
 */
static inline long task_priority_get_(struct TASK *task)
{
        return (task->priority);
}

/**
 * @brief 设置任务优先级
 *
 * @param[in] task 任务
 * @param[in] priority 优先级
 * @return 结果
 * @retval 0 成功
 */
static inline long task_priority_set_(struct TASK *task, unsigned long priority)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskPrioritySet(task->handle, priority);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief 发送任务通知
 *
 * @param[in] task 任务
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long task_notify_give_(struct TASK *task)
{
        _Bool is_notify = 0;

        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        is_notify = xTaskNotifyGive(task->handle);
        is_notify = (is_notify == pdPASS);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */

        if (is_notify) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief 获取任务通知
 *
 * @param[in] task 任务
 * @param[in] wait 等待时间(单位:ms)
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long task_notify_take_(struct TASK *task, unsigned long wait)
{
        _Bool is_notify = 0;

        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        is_notify = ulTaskNotifyTake(task->handle, pdTRUE, pdMS_TO_TICKS(wait));
        is_notify = (is_notify == pdTRUE);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */

        if (is_notify) {
                return (0);
        } else {
                return (-1);
        }
}

#endif /* !defined OS_TASK_H */
