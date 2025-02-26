/**
 * @file uart.h
 * @brief uart
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-18
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-27
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-02-18 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#if !defined UART_H
#define UART_H

#include "object.h"

enum UART_ID {
        UART_LOG,
        UART_MAX,
};

struct UART_PACKAGE {
        u8 *data;
        usize length;
};

struct UART {
        struct OBJECT *super;
        u8 type;
        bool is_open;
        i32 (*send_blocking)(struct UART *self, struct UART_PACKAGE *package);
        i32 (*receive_blocking)(struct UART *self, struct UART_PACKAGE *package);
        i32 (*send_polling)(struct UART *self, struct UART_PACKAGE *package);
        i32 (*receive_polling)(struct UART *self, struct UART_PACKAGE *package);
};

static __force_inline char *uart_name_(struct UART *self)
{
        return (object_name_(self));
}

static __force_inline i32 uart_open_(struct UART *self)
{
        return (object_open_(self));
}

static __force_inline i32 uart_close_(struct UART *self)
{
        return (object_close_(self));
}

static __force_inline i32 uart_send_(struct UART *self,
                                        struct UART_PACKAGE *package)
{
        return (object_write_(self, package));
}

static __force_inline i32 uart_receive_(struct UART *self,
                                        struct UART_PACKAGE *package)
{
        return (object_read_(self, package));
}

static __force_inline i32 uart_send_blocking_(struct UART *self,
                                                struct UART_PACKAGE *package)
{
        return self->send_blocking(self, package);
}

static __force_inline i32 uart_receive_blocking_(struct UART *self,
                                                struct UART_PACKAGE *package)
{
        return self->receive_blocking(self, package);
}

static __force_inline i32 uart_send_polling_(struct UART *self,
                                                struct UART_PACKAGE *package)
{
        return self->send_polling(self, package);
}

static __force_inline i32 uart_receive_polling_(struct UART *self,
                                                struct UART_PACKAGE *package)
{
        return self->receive_polling(self, package);
}

i32 uart_create(struct UART *self, u8 id);

#endif /* !defined UART_H */
