/**
 * @file os_event_groups.h
 * @brief os_event_groups
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

#if !defined OS_EVENT_GROUPS_H
#define OS_EVENT_GROUPS_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_EVENT_GROUPS == 1))
#include "event_groups.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_EVENT_GROUPS == 1)) */

#endif /* !defined OS_EVENT_GROUPS_H */
