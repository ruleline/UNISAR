/**
 * @file log.h
 * @brief log
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-24
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-25
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-02-24 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#if !defined LOG_H
#define LOG_H

#include "uart.h"

#define LOG_BUFFER_SIZE 1024

enum LOG_TYPE {
        CHAR_LOG,
        HEX_LOG,
};

struct LOG_PACKAGE {
        u8 buffer[LOG_BUFFER_SIZE];
        usize length;
        u8 type;
};

struct LOG {
        struct UART *super;
        struct THREAD send_thread;
        struct QUEUE send_queue;
        i32 (*send)(struct LOG *self, struct LOG_PACKAGE *log);
};

static __force_inline i32 log_send_(struct LOG *self,
                                        struct LOG_PACKAGE *package)
{
        return self->send(self, package);
}

#endif /* !defined LOG_H */
