/**
 * @file uart.c
 * @brief uart
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-18
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-24
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

#include "uart.h"

static struct UART uart[1];

static __ctor(UART1_PRIORITY) void init1_(void)
{
        /* TODO */
}

static __dtor(UART1_PRIORITY) void deinit1_(void)
{
        /* TODO */
}

static i32 open_(struct UART *self)
{
        self->state = 1;
        return 0;
}

static i32 close_(struct UART *self)
{
        self->state = 0;
        return 0;
}

static i32 send_uart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == UART_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        if (self->state == 0) {
                return -1;
        }

        /* TODO */
        return 0;
}

static i32 receive_uart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == UART_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (self->state == 0) {
                return -1;
        }

        /* TODO */
        return 0;
}

static i32 send_usart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == USART_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        if (self->state == 0) {
                return -1;
        }

        /* TODO */
        return 0;
}

static i32 receive_usart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == USART_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (self->state == 0) {
                return -1;
        }

        /* TODO */
        return 0;
}

static i32 send_blocking_uart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == UART_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        if (self->state == 0) {
                return -1;
        }

        /* TODO */
        return 0;
}

static i32 receive_blocking_uart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == UART_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (self->state == 0) {
                return -1;
        }

        /* TODO */
        return 0;
}

static i32 send_blocking_usart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == USART_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        if (self->state == 0) {
                return -1;
        }

        /* TODO */
        return 0;
}

static i32 receive_blocking_usart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == USART_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (self->state == 0) {
                return -1;
        }

        /* TODO */
        return 0;
}

static i32 send_polling_uart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == UART_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        if (self->state == 0) {
                return -1;
        }

        /* TODO */
        return 0;
}

static i32 receive_polling_uart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == UART_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (self->state == 0) {
                return -1;
        }

        /* TODO */
        return 0;
}

static i32 send_polling_usart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == USART_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        if (self->state == 0) {
                return -1;
        }

        /* TODO */
        return 0;
}

static i32 receive_polling_usart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == USART_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (self->state == 0) {
                return -1;
        }

        /* TODO */
        return 0;
}

i32 uart_create(struct UART *self, char *name, u8 type)
{
        ASSERT(self);
        ASSERT(name);
        ASSERT(strlen(name));
        ASSERT(strlen(name) < sizeof(self->name));
        ASSERT((type == UART_COM) || (type == USART_COM));

        for (u8 i = 0; i < ARRAY_SIZE(uart); i++) {
                if (uart[i].name[0]) {
                        continue;
                }
                strcpy(&uart[i].name[0], name);
                uart[i].type = type;
                uart[i].state = 0;
                uart[i].open = open_;
                uart[i].close = close_;
                if (type == UART_COM) {
                        uart[i].send = send_uart_;
                        uart[i].receive = receive_uart_;
                        uart[i].send_blocking = send_blocking_uart_;
                        uart[i].receive_blocking = receive_blocking_uart_;
                        uart[i].send_polling = send_polling_uart_;
                        uart[i].receive_polling = receive_polling_uart_;
                } else {
                        uart[i].send = send_usart_;
                        uart[i].receive = receive_usart_;
                        uart[i].send_blocking = send_blocking_usart_;
                        uart[i].receive_blocking = receive_blocking_usart_;
                        uart[i].send_polling = send_polling_usart_;
                        uart[i].receive_polling = receive_polling_usart_;
                }
                self = &uart[i];
                PRINTF("[UART] create %s success.", self->name);
                return 0;
        }
        return -1;
}
