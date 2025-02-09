/**
 * @file os_hook.c
 * @brief os_hook
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-30
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-09
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-01-30 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#include "unisis.h"

#if (FREERTOS == 1)
/**
 * @brief 空闲钩子
 *
 */
void vApplicationIdleHook(void)
{
        /* TODO */
}
#endif /* (FREERTOS == 1) */

#if (FREERTOS == 1)
/**
 * @brief 滴答钩子
 *
 */
void vApplicationTickHook(void)
{
        /* TODO */
}
#endif /* (FREERTOS == 1) */

#if (FREERTOS == 1)
/**
 * @brief 内存分配失败钩子
 *
 */
void vApplicationMallocFailedHook(void)
{
        /* TODO */
}
#endif /* (FREERTOS == 1) */

#if (FREERTOS == 1)
/**
 * @brief 堆栈溢出钩子
 *
 * @param[in] handle 句柄
 * @param[in] name 名称
 */
void vApplicationStackOverflowHook(TaskHandle_t handle, char *name)
{
        /* TODO */
}
#endif /* (FREERTOS == 1) */

#if (FREERTOS == 1)
/**
 * @brief 守护进程任务启动钩子
 *
 */
void vApplicationDaemonTaskStartupHook(void)
{
        /* TODO */
}
#endif /* (FREERTOS == 1) */
