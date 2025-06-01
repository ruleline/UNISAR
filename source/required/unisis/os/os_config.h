/**
 * @file os_config.h
 * @brief os_config
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

#if !defined OS_CONFIG_H
#define OS_CONFIG_H

#include "unisis.h"

#if (FREERTOS == 1)
/**
 * @brief task.
 * @details
 * this option enables the use of tasks in FreeRTOS.
 */
#define FREERTOS_TASK           (0)
/**
 * @brief queue.
 * @details
 * this option enables the use of queues in FreeRTOS.
 */
#define FREERTOS_QUEUE          (0)
/**
 * @brief semaphore.
 * @details
 * this option enables the use of semaphores in FreeRTOS.
 */
#define FREERTOS_SEMAPHORE      (0)
/**
 * @brief mutex.
 * @details
 * this option enables the use of mutexes in FreeRTOS.
 */
#define FREERTOS_TIMER          (0)
/**
 * @brief event groups.
 * @details
 * this option enables the use of event groups in FreeRTOS.
 */
#define FREERTOS_EVENT_GROUPS   (0)
/**
 * @brief stream buffer.
 * @details
 * this option enables the use of stream buffers in FreeRTOS.
 */
#define FREERTOS_STREAM_BUFFER  (0)
/**
 * @brief message buffer.
 * @details
 * this option enables the use of message buffers in FreeRTOS.
 */
#define FREERTOS_MESSAGE_BUFFER (0)
#endif /* (FREERTOS == 1) */

#if (FREERTOS == 1)
#include "FreeRTOS.h"
#endif /* (FREERTOS == 1) */

#endif /* !defined OS_CONFIG_H */
