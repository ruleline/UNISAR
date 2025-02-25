/**
 * @file uart.c
 * @brief uart
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-18
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-25
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @defgroup UART-INIT UART 设备初始化
 * @defgroup UART-DEINIT UART 设备反初始化
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-02-18 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#include "uart.h"

enum UART_TYPE {
        UART_COM,
        USART_COM,
};

static struct UART uart[UART_MAX];

static i32 open_(struct UART *self)
{
        self->is_open = 1;
        return (0);
}

static i32 close_(struct UART *self)
{
        self->is_open = 0;
        return (0);
}

static i32 send_uart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == UART_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        return (0);
}

static i32 receive_uart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == UART_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        return (0);
}

static i32 send_usart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == USART_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        return (0);
}

static i32 receive_usart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == USART_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        return (0);
}

static i32 send_blocking_uart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == UART_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        return (0);
}

static i32 receive_blocking_uart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == UART_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        return (0);
}

static i32 send_blocking_usart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == USART_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        return (0);
}

static i32 receive_blocking_usart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == USART_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        return (0);
}

static i32 send_polling_uart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == UART_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        return (0);
}

static i32 receive_polling_uart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == UART_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        return (0);
}

static i32 send_polling_usart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == USART_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        return (0);
}

static i32 receive_polling_usart_(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == USART_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        return (0);
}

static __ctor(UART1_PRIORITY) void init1_(void)
{
        struct UART *self = &uart[UART_LOG];

        strcpy(&self->name[0], "uart-log");
        self->is_open = 0;
        self->type = UART_COM;
        self->open = open_;
        self->close = close_;
        self->send = send_uart_;
        self->receive = receive_uart_;
        self->send_blocking = send_blocking_uart_;
        self->receive_blocking = receive_blocking_uart_;
        self->send_polling = send_polling_uart_;
        self->receive_polling = receive_polling_uart_;

        /* TODO */
        PRINT("[UART] init %s success.", self->name);
}

static __dtor(UART1_PRIORITY) void deinit1_(void)
{
        /* TODO */
}

i32 uart_create(struct UART *self, u8 id)
{
        ASSERT(self);
        ASSERT(id < ARRAY_SIZE(uart));

        self = &uart[id];
        PRINTF("[UART] create %s success.", self->name);
        return (0);
}
