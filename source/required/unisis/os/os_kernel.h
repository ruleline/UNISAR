/**
 * @file os_kernel.h
 * @brief 内核
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-29
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-04-20
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

#if !defined OS_KERNEL_H
#define OS_KERNEL_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
#include "task.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */

/**
 * @brief 启动内核
 *
 * @return 结果
 * @retval 0 成功
 */
static __force_inline i32 kernel_start(void)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskStartScheduler();
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief 停止内核
 *
 * @return 结果
 * @retval 0 成功
 */
static __force_inline i32 kernel_stop(void)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskEndScheduler();
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief 恢复内核
 *
 * @return 结果
 * @retval 0 成功
 */
static __force_inline i32 kernel_resume(void)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        xTaskResumeAll();
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief 挂起内核
 *
 * @return 结果
 * @retval 0 成功
 */
static __force_inline i32 kernel_suspend_(void)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskSuspendAll();
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

#endif /* !defined OS_KERNEL_H */
