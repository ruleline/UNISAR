/**
 * @file uart.c
 * @brief uart
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-18
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-04-17
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

enum UART_NAME_LENGTH {
        UART_LOG_NAME_LENGTH = 20,
};

static struct UART uart[UART_MAX];

static i32 open_(struct UART *self)
{
        self->is_open = 1;
        PRINTF("[UART] open %s successfully", uart_name_(self));
        return (0);
}

static i32 close_(struct UART *self)
{
        self->is_open = 0;
        PRINTF("[UART] close %s successfully", uart_name_(self));
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
        PRINTF("[UART] send %s successfully", uart_name_(self));
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
        PRINTF("[UART] receive %s successfully", uart_name_(self));
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
        PRINTF("[UART] send %s successfully", uart_name_(self));
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
        PRINTF("[UART] receive %s successfully", uart_name_(self));
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
        PRINTF("[UART] send %s successfully", uart_name_(self));
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
        PRINTF("[UART] receive %s successfully", uart_name_(self));
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
        PRINTF("[UART] send %s successfully", uart_name_(self));
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
        PRINTF("[UART] receive %s successfully", uart_name_(self));
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
        PRINTF("[UART] send %s successfully", uart_name_(self));
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
        PRINTF("[UART] receive %s successfully", uart_name_(self));
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
        PRINTF("[UART] send %s successfully", uart_name_(self));
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
        PRINTF("[UART] receive %s successfully", uart_name_(self));
        return (0);
}

static __ctor(UART1_PRIORITY) void init1_(void)
{
        struct UART *self = &uart[UART_LOG];
        static struct OBJECT super;

        /* TODO */

        super.name = "uart-log";
        super.open = &open_;
        super.close = &close_;
        super.read = &receive_uart_;
        super.write = &send_uart_;
        self->super = &super;
        self->type = UART_COM;
        self->is_open = 0;
        self->send_blocking = &send_blocking_uart_;
        self->receive_blocking = &receive_blocking_uart_;
        self->send_polling = &send_polling_uart_;
        self->receive_polling = &receive_polling_uart_;
        PRINTF("[UART] init %s successfully", uart_name_(self));
}

static __dtor(UART1_PRIORITY) void deinit1_(void)
{
        struct UART *self = &uart[UART_LOG];

        /* TODO */
        PRINTF("[UART] deinit %s successfully", uart_name_(self));
}

i32 uart_create(struct UART *self, u8 id)
{
        ASSERT(self);
        ASSERT(id < ARRAY_SIZE(uart));

        self = &uart[id];
        PRINTF("[UART] create %s successfully", uart_name_(self));
        return (0);
}
