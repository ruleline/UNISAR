/**
 * @file os_queue.h
 * @brief os_queue
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
        unsigned long item_size;        /* 数据大小 */
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
 * @param[in] item 数据
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long queue_send_(struct QUEUE *queue, void *item)
{
        _Bool is_send = 0;

        #if ((FREERTOS == 1) && (FREERTOS_QUEUE == 1))
        is_send = xQueueSend(queue->handle, item, 0);
        is_send = (is_send == pdTRUE);
        #endif /* ((FREERTOS == 1) && (FREERTOS_QUEUE == 1)) */

        if (is_send) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief 入队头
 *
 * @param[in] queue 队列
 * @param[in] item 数据
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long queue_send_head_(struct QUEUE *queue, void *item)
{
        _Bool is_send = 0;

        #if ((FREERTOS == 1) && (FREERTOS_QUEUE == 1))
        is_send = xQueueSendToFront(queue->handle, item, 0);
        is_send = (is_send == pdTRUE);
        #endif /* ((FREERTOS == 1) && (FREERTOS_QUEUE == 1)) */

        if (is_send) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief 入队尾
 *
 * @param[in] queue 队列
 * @param[in] item 数据
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long queue_send_tail_(struct QUEUE *queue, void *item)
{
        _Bool is_send = 0;

        #if ((FREERTOS == 1) && (FREERTOS_QUEUE == 1))
        is_send = xQueueSendToBack(queue->handle, item, 0);
        is_send = (is_send == pdTRUE);
        #endif /* ((FREERTOS == 1) && (FREERTOS_QUEUE == 1)) */

        if (is_send) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief 查看队头
 *
 * @param[in] queue 队列
 * @param[out] item 数据
 * @return 结果
 * @retval 0 成功
 * @retval -1 失败
 */
static inline long queue_peek_(struct QUEUE *queue, void *item)
{
        _Bool is_peek = 0;

        #if ((FREERTOS == 1) && (FREERTOS_QUEUE == 1))
        is_peek = xQueuePeek(queue->handle, item, 0);
        is_peek = (is_peek == pdTRUE);
        #endif /* ((FREERTOS == 1) && (FREERTOS_QUEUE == 1)) */

        if (is_peek) {
                return (0);
        } else {
                return (-1);
        }
}

#endif /* !defined OS_QUEUE_H */
