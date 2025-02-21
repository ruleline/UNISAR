/**
 * @file uart.h
 * @brief uart
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-18
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-21
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

#include "unisis.h"

enum UART_TYPE {
        UART_COM,
        USART_COM,
};

struct UART_PACKAGE {
        u8 *data;
        usize length;
};

struct UART {
        char *name;
        u8 type;
        i32 (*send)(struct UART *self, struct UART_PACKAGE *package);
        i32 (*receive)(struct UART *self, struct UART_PACKAGE *package);
};

static __force_inline i32 uart_send(struct UART *self, struct UART_PACKAGE *package)
{
        return self->send(self, package);
}

static __force_inline i32 uart_receive(struct UART *self, struct UART_PACKAGE *package)
{
        return self->receive(self, package);
}

i32 uart_create(struct UART *self, char *name, u8 type);

#endif /* !defined UART_H */
