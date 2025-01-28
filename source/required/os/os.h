/**
 * @file os.h
 * @brief os
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-28
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-01-28
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

#if !defined OS_H
#define OS_H

#if defined FREERTOS
#include "FreeRTOS.h"
#endif /* defined FREERTOS */

#if defined FREERTOS && defined FREERTOS_TASK
#include "task.h"
#endif /* defined FREERTOS && defined FREERTOS_TASK */

#if defined FREERTOS && defined FREERTOS_QUEUE
#include "queue.h"
#endif /* defined FREERTOS && defined FREERTOS_QUEUE */

#if defined FREERTOS && defined FREERTOS_SEMAPHORE
#include "semphr.h"
#endif /* defined FREERTOS && defined FREERTOS_SEMAPHORE */

#if defined FREERTOS && defined FREERTOS_TIMER
#include "timers.h"
#endif /* defined FREERTOS && defined FREERTOS_TIMER */

#if defined FREERTOS && defined FREERTOS_EVENT_GROUPS
#include "event_groups.h"
#endif /* defined FREERTOS && defined FREERTOS_EVENT_GROUPS */

#if defined FREERTOS && defined FREERTOS_STREAM_BUFFER
#include "stream_buffer.h"
#endif /* defined FREERTOS && defined FREERTOS_STREAM_BUFFER */

#if defined FREERTOS && defined FREERTOS_MESSAGE_BUFFER
#include "message_buffer.h"
#endif /* defined FREERTOS && defined FREERTOS_MESSAGE_BUFFER */

#endif /* !defined OS_H */
