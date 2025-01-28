/**
 * @file os_task.h
 * @brief os_task
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
static inline int task_create_(struct TASK *task)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        BaseType_t xReturn = pdPASS;
        xReturn = xTaskCreate(task->entry, task->name, task->stack_depth,
                        task->parameters, task->priority, &task->handle);
        ASSERT(xReturn == pdPASS);
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

#endif /* !defined OS_TASK_H */
