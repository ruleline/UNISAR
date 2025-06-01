/**
 * @file os_queue.h
 * @brief queue.
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-28
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
 *   0.00.001   | 2025-01-28 |    ruleline    | initial commit
 * -----------------------------------------------------------------------------
 */

#if !defined OS_QUEUE_H
#define OS_QUEUE_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_QUEUE == 1))
#include "queue.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_QUEUE == 1)) */

/**
 * @brief queue structure.
 * @details
 * this structure represents a queue that can be used to manage items in a
 * FIFO (First In, First Out) manner.
 */
struct QUEUE {
        /** queue handle */
        void *handle;
        /** queue length */
        usize length;
        /** item size */
        usize item_size;
};

/**
 * @brief create a queue.
 * @details
 * this function creates a queue with the specified length and item size.
 * @param[in,out] queue pointer to the queue structure.
 * @return the status of creation.
 */
static __force_inline i32 queue_create(struct QUEUE *queue)
{
        if (queue->handle) {
                return (0);
        }

        #if ((FREERTOS == 1) && (FREERTOS_QUEUE == 1))
        queue->handle = xQueueCreate(queue->length, queue->item_size);
        ASSERT(queue->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_QUEUE == 1)) */
        return (0);
}

/**
 * @brief delete a queue.
 * @details
 * this function deletes a queue and frees its resources.
 * @param[in,out] queue pointer to the queue structure.
 * @return the status of deletion.
 */
static __force_inline i32 queue_delete(struct QUEUE *queue)
{
        if (!queue->handle) {
                return (0);
        }

        #if ((FREERTOS == 1) && (FREERTOS_QUEUE == 1))
        vQueueDelete(queue->handle);
        #endif /* ((FREERTOS == 1) && (FREERTOS_QUEUE == 1)) */
        return (0);
}

/**
 * @brief push an item into the queue.
 * @details
 * this function pushes an item into the queue. if the queue is full, it will
 * block until space is available.
 * @param[in,out] queue pointer to the queue structure.
 * @param[in] item pointer to the item to be pushed.
 * @return the status of push operation.
 */
static __force_inline i32 queue_push(struct QUEUE *queue, void *item)
{
        bool is_done = 0;

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
 * @brief push an item into the head of the queue.
 * @details
 * this function pushes an item into the head of the queue. it is useful for
 * prioritizing certain items over others.
 * @param[in,out] queue pointer to the queue structure.
 * @param[in] item pointer to the item to be pushed.
 * @return the status of push operation.
 */
static __force_inline i32 queue_push_into_head(struct QUEUE *queue, void *item)
{
        bool is_done = 0;

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
 * @brief push an item into the tail of the queue.
 * @details
 * this function pushes an item into the tail of the queue. it is useful for
 * adding items to the end of the queue without affecting the order of
 * existing items.
 * @param[in,out] queue pointer to the queue structure.
 * @param[in] item pointer to the item to be pushed.
 * @return the status of push operation.
 */
static __force_inline i32 queue_push_into_tail(struct QUEUE *queue, void *item)
{
        bool is_done = 0;

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
 * @brief overwrite an item in the queue.
 * @details
 * this function overwrites the item at the front of the queue with a new item.
 * it is useful for replacing the oldest item in the queue with a new one.
 * @param[in,out] queue pointer to the queue structure.
 * @param[in] item pointer to the item to be overwritten.
 * @return the status of overwrite operation.
 */
static __force_inline i32 queue_overwrite(struct QUEUE *queue, void *item)
{
        bool is_done = 0;

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
 * @brief pop an item from the queue.
 * @details
 * this function pops an item from the front of the queue. if the queue is empty,
 * it will block until an item is available.
 * @param[in,out] queue pointer to the queue structure.
 * @param[out] item pointer to the item to be popped.
 * @return the status of pop operation.
 */
static __force_inline i32 queue_pop(struct QUEUE *queue, void *item)
{
        bool is_done = 0;

        #if ((FREERTOS == 1) && (FREERTOS_QUEUE == 1))
        is_done = xQueueReceive(queue->handle, item, portMAX_DELAY);
        #endif /* ((FREERTOS == 1) && (FREERTOS_QUEUE == 1)) */

        if (is_done) {
                return (0);
        } else {
                return (-1);
        }
}

/**
 * @brief peek an item from the queue.
 * @details
 * this function retrieves the item at the front of the queue without removing
 * it. it is useful for checking the next item to be processed without modifying
 * the queue.
 * @param[in] queue pointer to the queue structure.
 * @param[out] item pointer to the item to be peeked.
 * @return the status of peek operation.
 */
static __force_inline i32 queue_peek(struct QUEUE *queue, void *item)
{
        bool is_done = 0;

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
 * @brief empty the queue.
 * @details
 * this function empties the queue, removing all items from it. it is useful
 * for clearing the queue when it is no longer needed or before reusing it.
 * @param[in] queue pointer to the queue structure.
 * @return the status of empty operation.
 */
static __force_inline i32 queue_empty(struct QUEUE *queue)
{
        bool is_done = 0;

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
