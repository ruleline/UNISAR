/**
 * @file os_semaphore.h
 * @brief semaphore management.
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-28
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-06-02
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-01-28 |    ruleline    | initial commit.
 * -----------------------------------------------------------------------------
 */

#if !defined OS_SEMAPHORE_H
#define OS_SEMAPHORE_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
#include "semphr.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */

/**
 * @brief semaphore structure.
 * @details
 * this structure represents a semaphore that can be used for synchronization
 * between tasks or threads.
 */
struct SEMAPHORE {
        void *handle;
};

/**
 * @brief create a binary semaphore.
 * @details
 * this function creates a binary semaphore. if the semaphore already exists,
 * it does nothing.
 * @param[in,out] semaphore pointer to the semaphore structure.
 * @return the status of creation.
 */
static __force_inline i32 semaphore_binary_create(struct SEMAPHORE *semaphore)
{
        if (semaphore->handle) {
                return (0);
        }

        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        semaphore->handle = xSemaphoreCreateBinary();
        ASSERT(semaphore->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */
        return (0);
}

/**
 * @brief create a counting semaphore.
 * @details
 * this function creates a counting semaphore with a maximum count and an initial
 * count. if the semaphore already exists, it does nothing.
 * @param[in,out] semaphore pointer to the semaphore structure.
 * @param[in] max_count maximum count of the semaphore.
 * @param[in] init_count initial count of the semaphore.
 * @return the status of creation.
 */
static __force_inline i32 semaphore_counting_create(
                struct SEMAPHORE *semaphore, usize max_count, usize init_count)
{
        if (semaphore->handle) {
                return (0);
        }

        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        semaphore->handle = xSemaphoreCreateCounting(max_count, init_count);
        ASSERT(semaphore->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */
        return (0);
}

/**
 * @brief create a binary semaphore with a timeout.
 * @details
 * this function creates a binary semaphore that can be used with a timeout.
 * if the semaphore already exists, it does nothing.
 * @param[in,out] semaphore pointer to the semaphore structure.
 * @return the status of creation.
 */
static __force_inline i32 semaphore_mutex_create(struct SEMAPHORE *semaphore)
{
        if (semaphore->handle) {
                return (0);
        }

        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        semaphore->handle = xSemaphoreCreateMutex();
        ASSERT(semaphore->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */
        return (0);
}

/**
 * @brief create a recursive mutex semaphore.
 * @details
 * this function creates a recursive mutex semaphore that allows the same task
 * to acquire the semaphore multiple times without blocking. if the semaphore
 * already exists, it does nothing.
 * @param[in,out] semaphore pointer to the semaphore structure.
 * @return the status of creation.
 */
static __force_inline i32 semaphore_recursive_mutex_create(
                                                struct SEMAPHORE *semaphore)
{
        if (semaphore->handle) {
                return (0);
        }

        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        semaphore->handle = xSemaphoreCreateRecursiveMutex();
        ASSERT(semaphore->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */
        return (0);
}

/**
 * @brief delete a semaphore.
 * @details
 * this function deletes a semaphore and frees its resources. if the semaphore
 * does not exist, it does nothing.
 * @param[in,out] semaphore pointer to the semaphore structure.
 * @return the status of deletion.
 */
static __force_inline i32 semaphore_delete(struct SEMAPHORE *semaphore)
{
        if (!semaphore->handle) {
                return (0);
        }

        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        vSemaphoreDelete(semaphore->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */
        return (0);
}

/**
 * @brief acquire a semaphore.
 * @details
 * this function acquires a semaphore. if the semaphore is not available, it
 * will block until it becomes available.
 * @param[in,out] semaphore pointer to the semaphore structure.
 * @return the status of acquisition.
 */
static __force_inline i32 semaphore_acquire(struct SEMAPHORE *semaphore)
{
        bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        is_done = xSemaphoreTake(semaphore->handle, portMAX_DELAY);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief release a semaphore.
 * @details
 * this function releases a semaphore. if the semaphore is not held, it does
 * nothing.
 * @param[in,out] semaphore pointer to the semaphore structure.
 * @return the status of release operation.
 */
static __force_inline i32 semaphore_release(struct SEMAPHORE *semaphore)
{
        bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        is_done = xSemaphoreGive(semaphore->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief lock a semaphore.
 * @details
 * this function locks a semaphore. if the semaphore is already held, it will
 * block until it becomes available.
 * @param[in,out] semaphore pointer to the semaphore structure.
 * @return the status of lock operation.
 */
static __force_inline i32 semaphore_lock(struct SEMAPHORE *semaphore)
{
        bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        is_done = xSemaphoreTake(semaphore->handle, portMAX_DELAY);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief unlock a semaphore.
 * @details
 * this function unlocks a semaphore. if the semaphore is not held, it does
 * nothing.
 * @param[in,out] semaphore pointer to the semaphore structure.
 * @return the status of unlock operation.
 */
static __force_inline i32 semaphore_unlock(struct SEMAPHORE *semaphore)
{
        bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        is_done = xSemaphoreGive(semaphore->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief lock a semaphore recursively.
 * @details
 * this function locks a semaphore recursively. if the semaphore is already held,
 * it will block until it becomes available.
 * @param[in,out] semaphore pointer to the semaphore structure.
 * @return the status of lock operation.
 */
static __force_inline i32 semaphore_recursive_lock(struct SEMAPHORE *semaphore)
{
        bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        is_done = xSemaphoreTakeRecursive(semaphore->handle, portMAX_DELAY);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief unlock a semaphore recursively.
 * @details
 * this function unlocks a semaphore recursively. if the semaphore is not held,
 * it does nothing.
 * @param[in,out] semaphore pointer to the semaphore structure.
 * @return the status of unlock operation.
 */
static __force_inline i32 semaphore_recursive_unlock(struct SEMAPHORE *semaphore)
{
        bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1))
        is_done = xSemaphoreGiveRecursive(semaphore->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_SEMAPHORE == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

#endif /* !defined OS_SEMAPHORE_H */
