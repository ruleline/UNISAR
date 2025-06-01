/**
 * @file os_message_buffer.h
 * @brief message buffer functions
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

#if !defined OS_MESSAGE_BUFFER_H
#define OS_MESSAGE_BUFFER_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_MESSAGE_BUFFER == 1))
#include "message_buffer.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_MESSAGE_BUFFER == 1)) */

#endif /* !defined OS_MESSAGE_BUFFER_H */
