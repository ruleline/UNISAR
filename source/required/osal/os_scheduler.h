/**
 * @file os_scheduler.h
 * @brief os_scheduler
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-29
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
 *   0.00.001   | 2025-01-29 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#if !defined OS_SCHEDULER_H
#define OS_SCHEDULER_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
#include "task.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */

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
static inline long scheduler_suspend_(void)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskSuspendAll();
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

#endif /* !defined OS_SCHEDULER_H */
