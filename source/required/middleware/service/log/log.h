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

/**
 * @brief the maximum size of LOG buffer.
 * @details
 * this enum defines the maximum size of LOG buffer.
 */
#define LOG_BUFFER_SIZE 1024

/**
 * @brief the type of LOG.
 * @details
 * this enum defines the types for different LOG.
 */
enum LOG_TYPE {
        /** char LOG. */
        CHAR_LOG,
        /** HEX LOG. */
        HEX_LOG,
};

/**
 * @brief LOG package.
 * @details
 * this struct defines the LOG package.
 */
struct LOG_PACKAGE {
        /** the buffer of LOG. */
        u8 buffer[LOG_BUFFER_SIZE];
        /** the length of LOG. */
        usize length;
        /** the type of LOG. */
        u8 type;
};

/**
 * @brief LOG object.
 * @details
 * this struct defines a LOG object.
 */
struct LOG {
        /** parent object of this object. */
        struct UART *super;
        /** thread for sending log messages. */
        struct THREAD send_thread;
        /** queue for sending log messages. */
        struct QUEUE send_queue;
        /** function for sending log messages. */
        i32 (*send)(struct LOG *self, struct LOG_PACKAGE *log);
};

/**
 * @brief send a log message.
 * @details
 * this function sends a log message.
 * @param[in] self the LOG object.
 * @param[in] package the LOG package.
 * @return the status of sending the log message.
 */
static __force_inline i32 log_send(struct LOG *self,
                                        struct LOG_PACKAGE *package)
{
        return self->send(self, package);
}

#endif /* !defined LOG_H */
