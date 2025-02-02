/**
 * @file os_queue.h
 * @brief os_queue
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-28
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-02
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

#if !defined OS_QUEUE_H
#define OS_QUEUE_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_QUEUE == 1))
#include "queue.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_QUEUE == 1)) */

/**
 * @brief 队列
 *
 */
struct QUEUE {
        void *handle;                   /* 句柄 */
        unsigned long length;           /* 长度 */
        unsigned long item_size;        /* 元素大小 */
};

/**
 * @brief 创建队列
 *
 * @param[in,out] queue 队列
 * @return 结果
 * @retval 0 成功
 */
static inline long queue_create_(struct QUEUE *queue)
{
        #if ((FREERTOS == 1) && (FREERTOS_QUEUE == 1))
        queue->handle = xQueueCreate(queue->length, queue->item_size);
        ASSERT(queue->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_QUEUE == 1)) */
        return (0);
}

/**
 * @brief 删除队列
 *
 * @param[in,out] queue 队列
 * @return 结果
 * @retval 0 成功
 */
static inline long queue_delete_(struct QUEUE *queue)
{
        #if ((FREERTOS == 1) && (FREERTOS_QUEUE == 1))
        vQueueDelete(queue->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_QUEUE == 1)) */
        return (0);
}

/**
 * @brief 入队
 *
 * @param[in] queue 队列
 * @param[in] item 元素
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long queue_write_(struct QUEUE *queue, void *item)
{
        _Bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_QUEUE == 1))
        is_done = xQueueSend(queue->handle, item, 0);
        #endif /* ((FREERTOS == 1) && (FREERTOS_QUEUE == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief 入队头
 *
 * @param[in] queue 队列
 * @param[in] item 元素
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long queue_write_head_(struct QUEUE *queue, void *item)
{
        _Bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_QUEUE == 1))
        is_done = xQueueSendToFront(queue->handle, item, 0);
        #endif /* ((FREERTOS == 1) && (FREERTOS_QUEUE == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief 入队尾
 *
 * @param[in] queue 队列
 * @param[in] item 元素
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long queue_write_tail_(struct QUEUE *queue, void *item)
{
        _Bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_QUEUE == 1))
        is_done = xQueueSendToBack(queue->handle, item, 0);
        #endif /* ((FREERTOS == 1) && (FREERTOS_QUEUE == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief 覆盖入队
 *
 * @param[in] queue 队列
 * @param[in] item 元素
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long queue_overwrite_(struct QUEUE *queue, void *item)
{
        _Bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_QUEUE == 1))
        is_done = xQueueOverwrite(queue->handle, item);
        #endif /* ((FREERTOS == 1) && (FREERTOS_QUEUE == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief 出队
 *
 * @param[in] queue 队列
 * @param[out] item 元素
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long queue_read_(struct QUEUE *queue, void *item)
{
        _Bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_QUEUE == 1))
        is_done = xQueueReceive(queue->handle, item, 0);
        #endif /* ((FREERTOS == 1) && (FREERTOS_QUEUE == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief 查看队头
 *
 * @param[in] queue 队列
 * @param[out] item 元素
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long queue_peek_(struct QUEUE *queue, void *item)
{
        _Bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_QUEUE == 1))
        is_done = xQueuePeek(queue->handle, item, 0);
        #endif /* ((FREERTOS == 1) && (FREERTOS_QUEUE == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief 清空队列
 *
 * @param[in] queue 队列
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long queue_empty_(struct QUEUE *queue)
{
        _Bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_QUEUE == 1))
        is_done = xQueueReset(queue->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_QUEUE == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

#endif /* !defined OS_QUEUE_H */
