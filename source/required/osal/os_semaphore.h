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
 * @param[in,out] semaphore 二值信号量
 * @return 结果
 * @retval 0 成功
 */
static inline long semaphore_binary_create_(struct SEMAPHORE *semaphore)
{
        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        semaphore->handle = xSemaphoreCreateBinary();
        ASSERT(semaphore->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */
        return (0);
}

/**
 * @brief 创建计数信号量
 *
 * @param[in,out] semaphore 计数信号量
 * @return 结果
 * @retval 0 成功
 */
static inline long semaphore_counting_create_(struct SEMAPHORE *semaphore)
{
        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        semaphore->handle = xSemaphoreCreateCounting(
                                configMAX_BINARY_SEMAPHORE_COUNT, 0);
        ASSERT(semaphore->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */
        return (0);
}

/**
 * @brief 创建互斥信号量
 *
 * @param[in,out] semaphore 互斥信号量
 * @return 结果
 * @retval 0 成功
 */
static inline long semaphore_mutex_create_(struct SEMAPHORE *semaphore)
{
        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        semaphore->handle = xSemaphoreCreateMutex();
        ASSERT(semaphore->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */
        return (0);
}

/**
 * @brief 创建递归互斥信号量
 *
 * @param[in,out] semaphore 递归互斥信号量
 * @return 结果
 * @retval 0 成功
 */
static inline long semaphore_recursive_mutex_create_(struct SEMAPHORE *semaphore)
{
        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        semaphore->handle = xSemaphoreCreateRecursiveMutex();
        ASSERT(semaphore->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */
        return (0);
}

/**
 * @brief 删除信号量
 *
 * @param[in,out] semaphore 信号量
 * @return 结果
 * @retval 0 成功
 */
static inline long semaphore_delete_(struct SEMAPHORE *semaphore)
{
        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        vSemaphoreDelete(semaphore->handle);
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

/**
 * @brief 上递归锁
 *
 * @param[in] semaphore 信号量
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long semaphore_recursive_lock_(struct SEMAPHORE *semaphore)
{
        _Bool is_lock = 0;

        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        is_lock = xSemaphoreTakeRecursive(semaphore->handle, portMAX_DELAY);
        is_lock = (is_lock == pdTRUE);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */

        if (is_lock) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief 解递归锁
 *
 * @param[in] semaphore 信号量
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long semaphore_recursive_unlock_(struct SEMAPHORE *semaphore)
{
        _Bool is_unlock = 0;

        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        is_unlock = xSemaphoreGiveRecursive(semaphore->handle);
        is_unlock = (is_unlock == pdTRUE);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */

        if (is_unlock) {
                return (0);
        } else {
                return (-1);
        }
}

#endif /* !defined OS_SEMAPHORE_H */
