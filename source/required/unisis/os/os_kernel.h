/**
 * @file os_kernel.h
 * @brief kernel functions.
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-29
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-06-01
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-01-29 |    ruleline    | initial commit
 * -----------------------------------------------------------------------------
 */

#if !defined OS_KERNEL_H
#define OS_KERNEL_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
#include "task.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */

/**
 * @brief kernel initialization function.
 * @details
 * this function is called to initialize the kernel.
 * @return result code.
 */
static __force_inline i32 kernel_start(void)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskStartScheduler();
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief kernel stop function.
 * @details
 * this function is called to stop the kernel.
 * @return result code.
 */
static __force_inline i32 kernel_stop(void)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskEndScheduler();
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief kernel resume function.
 * @details
 * this function is called to resume the kernel.
 * @return result code.
 */
static __force_inline i32 kernel_resume(void)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        xTaskResumeAll();
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

/**
 * @brief kernel suspend function.
 * @details
 * this function is called to suspend the kernel.
 * @return result code.
 */
static __force_inline i32 kernel_suspend(void)
{
        #if ((FREERTOS == 1) && (FREERTOS_TASK == 1))
        vTaskSuspendAll();
        #endif /* ((FREERTOS == 1) && (FREERTOS_TASK == 1)) */
        return (0);
}

#endif /* !defined OS_KERNEL_H */
