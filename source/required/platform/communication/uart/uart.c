/**
 * @file uart.c
 * @brief UART.
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-18
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-06-09
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-02-18 |    ruleline    | initial commit.
 * -----------------------------------------------------------------------------
 */

#include "uart.h"

/**
 * @brief UART type set.
 * @details
 * this enumeration represents the UART type.
 */
enum UART_TYPE {
        /** UART. */
        UART_COM,
        /** USART. */
        USART_COM,
};

/**
 * @brief UART name length.
 * @details
 * this enumeration represents the UART name length.
 */
enum UART_NAME_LENGTH {
        /** UART-LOG name length. */
        UART_LOG_NAME_LENGTH = 20,
};

/**
 * @brief UART object set.
 * @details
 * this structure represents the UART object.
 */
static struct UART uart[UART_MAX];

/**
 * @brief open the UART.
 * @details
 * this function opens the UART.
 * @param[in,out] self pointer to UART.
 * @return the result of opening the UART.
 */
static i32 open(struct UART *self)
{
        self->is_open = 1;
        PRINTF("[UART] open %s successfully", uart_name(self));
        return (0);
}

/**
 * @brief close the UART.
 * @details
 * this function closes the UART.
 * @param[in,out] self pointer to UART.
 * @return the result of closing the UART.
 */
static i32 close(struct UART *self)
{
        self->is_open = 0;
        PRINTF("[UART] close %s successfully", uart_name(self));
        return (0);
}

/**
 * @brief send the package.
 * @details
 * this function sends the package.
 * @param[in] self pointer to UART.
 * @param[in] package pointer to UART package.
 * @return the result of sending the package.
 */
static i32 send_uart(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == UART_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[UART] send %s successfully", uart_name(self));
        return (0);
}

/**
 * @brief receive the package.
 * @details
 * this function receives the package.
 * @param[in] self pointer to UART.
 * @param[out] package pointer to UART package.
 * @return the result of receiving the package.
 */
static i32 receive_uart(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == UART_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[UART] receive %s successfully", uart_name(self));
        return (0);
}

/**
 * @brief send the package.
 * @details
 * this function sends the package.
 * @param[in] self pointer to USART.
 * @param[in] package pointer to USART package.
 * @return the result of sending the package.
 */
static i32 send_usart(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == USART_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[UART] send %s successfully", uart_name(self));
        return (0);
}

/**
 * @brief receive the package.
 * @details
 * this function receives the package.
 * @param[in] self pointer to USART.
 * @param[out] package pointer to USART package.
 * @return the result of receiving the package.
 */
static i32 receive_usart(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == USART_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[UART] receive %s successfully", uart_name(self));
        return (0);
}

/**
 * @brief send the package by blocking.
 * @details
 * this is a blocking operation, meaning it will wait until the package is sent.
 * it is typically used when the application needs to ensure that the data is sent
 * before proceeding with further operations.
 * @param[in] self pointer to UART.
 * @param[in] package pointer to UART package.
 * @return the result of sending the package.
 */
static i32 send_blocking_uart(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == UART_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[UART] send %s successfully", uart_name(self));
        return (0);
}

/**
 * @brief receive the package by blocking.
 * @details
 * this is a blocking operation, meaning it will wait until the package is
 * received. it is typically used when the application needs to ensure that the
 * data is received before proceeding with further operations.
 * @param[in] self pointer to UART.
 * @param[out] package pointer to UART package.
 * @return the result of receiving the package.
 */
static i32 receive_blocking_uart(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == UART_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[UART] receive %s successfully", uart_name(self));
        return (0);
}

/**
 * @brief send the package by blocking.
 * @details
 * this is a blocking operation, meaning it will wait until the package is sent.
 * it is typically used when the application needs to ensure that the data is sent
 * before proceeding with further operations.
 * @param[in] self pointer to USART.
 * @param[in] package pointer to USART package.
 * @return the result of sending the package.
 */
static i32 send_blocking_usart(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == USART_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[UART] send %s successfully", uart_name(self));
        return (0);
}

/**
 * @brief receive the package by blocking.
 * @details
 * this is a blocking operation, meaning it will wait until the package is
 * received. it is typically used when the application needs to ensure that the
 * data is received before proceeding with further operations.
 * @param[in] self pointer to USART.
 * @param[out] package pointer to USART package.
 * @return the result of receiving the package.
 */
static i32 receive_blocking_usart(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == USART_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[UART] receive %s successfully", uart_name(self));
        return (0);
}

/**
 * @brief send the package by polling.
 * @details
 * this is a polling operation, meaning it will check the status of the transmission
 * until the package is sent. it is typically used when the application needs to
 * ensure that the data is sent before proceeding with further operations.
 * @param[in] self pointer to UART.
 * @param[in] package pointer to UART package.
 * @return the result of sending the package.
 */
static i32 send_polling_uart(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == UART_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[UART] send %s successfully", uart_name(self));
        return (0);
}

/**
 * @brief receive the package by polling.
 * @details
 * this is a polling operation, meaning it will check the status of the reception
 * until the package is received. it is typically used when the application needs to
 * ensure that the data is received before proceeding with further operations.
 * @param[in] self pointer to UART.
 * @param[out] package pointer to UART package.
 * @return the result of receiving the package.
 */
static i32 receive_polling_uart(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == UART_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[UART] receive %s successfully", uart_name(self));
        return (0);
}

/**
 * @brief send the package by polling.
 * @details
 * this is a polling operation, meaning it will check the status of the transmission
 * until the package is sent. it is typically used when the application needs to
 * ensure that the data is sent before proceeding with further operations.
 * @param[in] self pointer to USART.
 * @param[in] package pointer to USART package.
 * @return the result of sending the package.
 */
static i32 send_polling_usart(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == USART_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[UART] send %s successfully", uart_name(self));
        return (0);
}

/**
 * @brief receive the package by polling.
 * @details
 * this is a polling operation, meaning it will check the status of the reception
 * until the package is received. it is typically used when the application needs to
 * ensure that the data is received before proceeding with further operations.
 * @param[in] self pointer to USART.
 * @param[out] package pointer to USART package.
 * @return the result of receiving the package.
 */
static i32 receive_polling_usart(struct UART *self, struct UART_PACKAGE *package)
{
        ASSERT(self->type == USART_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[UART] receive %s successfully", uart_name(self));
        return (0);
}

/**
 * @brief initialize UART1.
 * @details
 * this function initializes UART1.
 * @return the result of initializing UART1.
 */
static __ctor(UART1_PRIORITY) void init_uart1(void)
{
        struct UART *self = &uart[UART_LOG];

        /* TODO */

        self->super = object_create("UART Log",
                        (i32 (*)(struct OBJECT *))open,
                        (i32 (*)(struct OBJECT *))close,
                        (i32 (*)(struct OBJECT *, void *))send_uart,
                        (i32 (*)(struct OBJECT *, void *))receive_uart);
        ASSERT(self->super);
        self->type = UART_COM;
        self->is_open = 0;
        self->send_blocking = &send_blocking_uart;
        self->receive_blocking = &receive_blocking_uart;
        self->send_polling = &send_polling_uart;
        self->receive_polling = &receive_polling_uart;
        PRINTF("%s initialized.", uart_name(self));
}

/**
 * @brief deinitialize UART1.
 * @details
 * this function deinitializes UART1.
 * @return the result of deinitializing UART1.
 */
static __dtor(UART1_PRIORITY) void deinit_uart1(void)
{
        struct UART *self = &uart[UART_LOG];

        /* TODO */

        PRINTF("%s deinitialized.", uart_name(self));
        uart_destroy(&self);
}

/**
 * @brief create a UART object.
 * @details
 * this function creates a UART object.
 * @param[in] id identifier of UART.
 * @return the result of creating a UART object.
 */
struct UART *uart_create(enum UART_ID id)
{
        ASSERT(id < UART_MAX);
        return (&uart[id]);
}

/**
 * @brief destroy a UART object.
 * @details
 * this function destroys a UART object.
 * @param[in,out] self pointer to UART object.
 * @return the result of destroying a UART object.
 */
i32 uart_destroy(struct UART **self)
{
        ASSERT(self);

        if (*self) {
                object_destroy((struct OBJECT *)*self);
                memory_clear(*self, sizeof(struct UART));
                *self = 0;
        }
        return (0);
}
