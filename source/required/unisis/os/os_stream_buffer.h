/**
 * @file os_stream_buffer.h
 * @brief stream buffer.
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

#if !defined OS_STREAM_BUFFER_H
#define OS_STREAM_BUFFER_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_STREAM_BUFFER == 1))
#include "stream_buffer.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_STREAM_BUFFER == 1)) */

#endif /* !defined OS_STREAM_BUFFER_H */
