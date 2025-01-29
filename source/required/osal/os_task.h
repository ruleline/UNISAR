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
 * @brief 相对延时
 *
 * @param[in] time 时间(单位:ms)
 * @return 结果
 * @retval 0 成功
 */
static inline long general_delay_(unsigned long time)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskDelay(pdMS_TO_TICKS(time));
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
 * @brief 绝对延时
 *
 * @param[in,out] start 开始时间(单位:ms)
 * @param[in] time 时间(单位:ms)
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long precise_delay_(unsigned long *start, unsigned long time)
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

/**
 * @brief 启动调度器
 *
 * @return 结果
 * @retval 0 成功
 */
static inline long scheduler_start_(void)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskStartScheduler();
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief 恢复调度器
 *
 * @return 结果
 * @retval 0 成功
 */
static inline long scheduler_resume_(void)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        xTaskResumeAll();
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief 停止调度器
 *
 * @return 结果
 * @retval 0 成功
 */
static inline long scheduler_stop_(void)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskEndScheduler();
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief 挂起调度器
 *
 * @return 结果
 * @retval 0 成功
 */
static inline long suspend_scheduler_(void)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskSuspendAll();
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

#endif /* !defined OS_TASK_H */
