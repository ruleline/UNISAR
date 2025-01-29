/**
 * @file os_semaphore.h
 * @brief os_semaphore
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

#if !defined OS_SEMAPHORE_H
#define OS_SEMAPHORE_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
#include "semphr.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */

/**
 * @brief 信号量
 *
 */
struct SEMAPHORE {
        void *handle; /**< 句柄 */
};

/**
 * @brief 创建二值信号量
 *
 * @param[in,out] binary_semaphore 二值信号量
 * @return 结果
 * @retval 0 成功
 */
static inline long binary_semaphore_create_(
                                struct SEMAPHORE *binary_semaphore)
{
        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        binary_semaphore->handle = xSemaphoreCreateBinary();
        ASSERT(binary_semaphore->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */
        return (0);
}

/**
 * @brief 创建计数信号量
 *
 * @param[in,out] counting_semaphore 计数信号量
 * @return 结果
 * @retval 0 成功
 */
static inline long counting_semaphore_create_(
                                struct SEMAPHORE *counting_semaphore)
{
        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        counting_semaphore->handle = xSemaphoreCreateCounting(
                                configMAX_BINARY_SEMAPHORE_COUNT, 0);
        ASSERT(counting_semaphore->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */
        return (0);
}

/**
 * @brief 创建互斥信号量
 *
 * @param[in,out] mutex_semaphore 互斥信号量
 * @return 结果
 * @retval 0 成功
 */
static inline long mutex_semaphore_create_(
                                struct SEMAPHORE *mutex_semaphore)
{
        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        mutex_semaphore->handle = xSemaphoreCreateMutex();
        ASSERT(mutex_semaphore->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */
        return (0);
}

/**
 * @brief 创建递归互斥信号量
 *
 * @param[in,out] recursive_mutex_semaphore 递归互斥信号量
 * @return 结果
 * @retval 0 成功
 */
static inline long recursive_mutex_create_(
                                struct SEMAPHORE *recursive_mutex_semaphore)
{
        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        recursive_mutex_semaphore->handle = xSemaphoreCreateRecursiveMutex();
        ASSERT(recursive_mutex_semaphore->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */
        return (0);
}

/**
 * @brief 上锁
 *
 * @param[in] semaphore 信号量
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long semaphore_lock_(struct SEMAPHORE *semaphore)
{
        _Bool is_lock = 0;

        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        is_lock = xSemaphoreGive(semaphore->handle);
        is_lock = (is_lock == pdTRUE);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */

        if (is_lock) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief 解锁
 *
 * @param[in] semaphore 信号量
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long semaphore_unlock_(struct SEMAPHORE *semaphore)
{
        _Bool is_unlock = 0;

        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        is_unlock = xSemaphoreTake(semaphore->handle, portMAX_DELAY);
        is_unlock = (is_unlock == pdTRUE);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */

        if (is_unlock) {
                return (0);
        } else {
                return (-1);
        }
}

#endif /* !defined OS_SEMAPHORE_H */
