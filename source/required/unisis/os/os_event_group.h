/**
 * @file os_event_group.h
 * @brief 事件组
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-01-28
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-09
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

#if !defined OS_EVENT_GROUP_H
#define OS_EVENT_GROUP_H

#include "os_config.h"

#if ((FREERTOS == 1) && (FREERTOS_EVENT_GROUPS == 1))
#include "event_groups.h"
#endif /* ((FREERTOS == 1) && (FREERTOS_EVENT_GROUPS == 1)) */

#endif /* !defined OS_EVENT_GROUP_H */
