/**
 * @file log.c
 * @brief log
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-24
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
 *   0.00.001   | 2025-02-24 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#include "log.h"

struct LOG log;

static i32 send_(struct LOG *self, struct LOG_PACKAGE *package)
{
        i32 state = 0;

        state = queue_push_(&self->send_queue, package);
        ASSERT(state == 0);
        return 0;
}

static __force_inline i32 parse_send_(struct LOG *self, struct LOG_PACKAGE *package)
{
        usize size = 3*package->length + 1;
        u8 buffer[size];

        ASSERT((package->type == CHAR_LOG) || (package->type == HEX_LOG));

        if (package->type == HEX_LOG) {
                if (package->length > (LOG_BUFFER_SIZE/3-1)) {
                        return -1;
                }
                u8 high = 0, low = 0;
                for (usize i = 0; i < package->length; i++) {
                        high = (package->buffer[i] & 0xf0) >> 4;
                        low = (package->buffer[i] & 0x0f) >> 0;
                        buffer[3*i] = high + ((high < 10) ? '0' : 'A' - 10);
                        buffer[3*i+1] = low + ((low < 10) ? '0' : 'A' - 10);
                        buffer[3*i+2] = ' ';
                }
                buffer[size-1] = '\0';
                package->length = size;
                memcpy(&package->buffer[0], &buffer[0], package->length);
        }
        return 0;
}

static void send_entry_(void *parameters)
{
        struct LOG *self = (struct LOG *)parameters;
        struct LOG_PACKAGE package = {0};
        struct UART_PACKAGE *uart = 0;
        i32 state = 0;

        for (;;) {
                if (queue_pop_(&self->send_queue, &package) == 0) {
                        parse_send_(self, &package);
                        uart->data = &package.buffer[0];
                        uart->length = package.length;
                        state = uart_tx_(self->super, uart);
                        ASSERT(state == 0);
                }
        }
}

static __ctor(LOG_PRIORITY) void init_(void)
{
        i32 state = 0;
        struct LOG *self = &log;

        state = uart_create(self->super, "UART1", UART_COM);
        ASSERT(state == 0);

        self->send_thread.entry = &send_entry_;
        self->send_thread.name = "LOG";
        self->send_thread.stack_depth = 0;
        self->send_thread.parameters = self;
        self->send_thread.priority = 0;
        state = thread_create_(&self->send_thread);
        ASSERT(state == 0);

        self->send_queue.length = 0;
        self->send_queue.item_size = sizeof(struct LOG_PACKAGE);
        state = queue_create_(&self->send_queue);
        ASSERT(state == 0);

        self->send = &send_;
        PRINT("[LOG] init success.");

        state = uart_open_(self->super);
        ASSERT(state == 0);
        PRINT("[LOG] open success.");
}

static __dtor(LOG_PRIORITY) void deinit_(void)
{
        PRINT("[LOG] deinit success.");
}
