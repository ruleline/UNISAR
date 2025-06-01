/**
 * @file os_hook.c
 * @brief hook functions for operating system.
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-30
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
 *   0.00.001   | 2025-01-30 |    ruleline    | initial commit
 * -----------------------------------------------------------------------------
 */

#include "unisis.h"

#if (FREERTOS == 1)
/**
 * @brief idle hook.
 * @details
 * this function is called when the idle task is running.
 */
void vApplicationIdleHook(void)
{
        /* TODO */
}
#endif /* (FREERTOS == 1) */

#if (FREERTOS == 1)
/**
 * @brief tick hook.
 * @details
 * this function is called when the tick timer expires.
 */
void vApplicationTickHook(void)
{
        /* TODO */
}
#endif /* (FREERTOS == 1) */

#if (FREERTOS == 1)
/**
 * @brief memory allocation failed hook.
 * @details
 * this function is called when a memory allocation fails.
 */
void vApplicationMallocFailedHook(void)
{
        /* TODO */
}
#endif /* (FREERTOS == 1) */

#if (FREERTOS == 1)
/**
 * @brief stack overflow hook.
 * @details
 * this function is called when a stack overflow occurs.
 * @param[in] handle task handle that caused the overflow.
 * @param[in] name name of the task that caused the overflow.
 */
void vApplicationStackOverflowHook(TaskHandle_t handle, char *name)
{
        /* TODO */
}
#endif /* (FREERTOS == 1) */

#if (FREERTOS == 1)
/**
 * @brief daemon task startup hook.
 * @details
 * this function is called when the daemon task is started.
 */
void vApplicationDaemonTaskStartupHook(void)
{
        /* TODO */
}
#endif /* (FREERTOS == 1) */
