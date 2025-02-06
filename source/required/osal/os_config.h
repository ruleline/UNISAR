/**
 * @file os_config.h
 * @brief os_config
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-28
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-07
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

#if !defined OS_CONFIG_H
#define OS_CONFIG_H

#if (FREERTOS == 1)
#define FREERTOS_TASK           (1)
#define FREERTOS_QUEUE          (1)
#define FREERTOS_SEMAPHORE      (1)
#define FREERTOS_TIMER          (1)
#define FREERTOS_EVENT_GROUPS   (1)
#define FREERTOS_STREAM_BUFFER  (1)
#define FREERTOS_MESSAGE_BUFFER (1)
#endif /* (FREERTOS == 1) */

#if (FREERTOS == 1)
#include "FreeRTOS.h"
#endif /* (FREERTOS == 1) */

#endif /* !defined OS_CONFIG_H */
