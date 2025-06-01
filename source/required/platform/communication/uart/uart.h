/**
 * @file uart.h
 * @brief UART.
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-18
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-06-02
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

#if !defined UART_H
#define UART_H

#include "unisis.h"

/**
 * @brief UART ID set.
 * @details
 * this enumeration represents the UART ID.
 */
enum UART_ID {
        /** UART-LOG. */
        UART_LOG,
        /** the maximum identifier of UART. */
        UART_MAX,
};

/**
 * @brief UART package.
 * @details
 * this structure represents the UART package.
 */
struct UART_PACKAGE {
        /** data. */
        u8 *data;
        /** length of data. */
        usize length;
};

/**
 * @brief UART.
 * @details
 * this structure represents the UART.
 */
struct UART {
        /** parent object. */
        struct OBJECT *super;
        /** type of UART. */
        u8 type;
        /** status of UART. */
        bool is_open;
        /** send blocking. */
        i32 (*send_blocking)(struct UART *self, struct UART_PACKAGE *package);
        /** receive blocking. */
        i32 (*receive_blocking)(struct UART *self, struct UART_PACKAGE *package);
        /** send polling. */
        i32 (*send_polling)(struct UART *self, struct UART_PACKAGE *package);
        /** receive polling. */
        i32 (*receive_polling)(struct UART *self, struct UART_PACKAGE *package);
};

/**
 * @brief get the name of UART.
 * @details
 * this function gets the name of UART.
 * @param[in] self pointer to UART.
 * @return the name of UART.
 */
static __force_inline char *uart_name(struct UART *self)
{
        return (object_name(self));
}

/**
 * @brief open the UART.
 * @details
 * this function opens the UART.
 * @param[in] self pointer to UART.
 * @return the result of opening the UART.
 */
static __force_inline i32 uart_open(struct UART *self)
{
        return (object_open(self));
}

/**
 * @brief close the UART.
 * @details
 * this function closes the UART.
 * @param[in] self pointer to UART.
 * @return the result of closing the UART.
 */
static __force_inline i32 uart_close(struct UART *self)
{
        return (object_close(self));
}

/**
 * @brief send the package.
 * @details
 * this function sends the package.
 * @param[in] self pointer to UART.
 * @param[in] package pointer to UART package.
 * @return the result of sending the package.
 */
static __force_inline i32 uart_send(struct UART *self,
                                        struct UART_PACKAGE *package)
{
        return (object_write(self, package));
}

/**
 * @brief receive the package.
 * @details
 * this function receives the package.
 * @param[in] self pointer to UART.
 * @param[out] package pointer to UART package.
 * @return the result of receiving the package.
 */
static __force_inline i32 uart_receive(struct UART *self,
                                        struct UART_PACKAGE *package)
{
        return (object_read(self, package));
}

/**
 * @brief send the package.
 * @details
 * this function sends the package.
 * @param[in] self pointer to UART.
 * @param[in] package pointer to UART package.
 * @return the result of sending the package.
 */
static __force_inline i32 uart_send_blocking(struct UART *self,
                                                struct UART_PACKAGE *package)
{
        return self->send_blocking(self, package);
}

/**
 * @brief receive the package.
 * @details
 * this function receives the package.
 * @param[in] self pointer to UART.
 * @param[out] package pointer to UART package.
 * @return the result of receiving the package.
 */
static __force_inline i32 uart_receive_blocking(struct UART *self,
                                                struct UART_PACKAGE *package)
{
        return self->receive_blocking(self, package);
}

/**
 * @brief send the package.
 * @details
 * this function sends the package.
 * @param[in] self pointer to UART.
 * @param[in] package pointer to UART package.
 * @return the result of sending the package.
 */
static __force_inline i32 uart_send_polling(struct UART *self,
                                                struct UART_PACKAGE *package)
{
        return self->send_polling(self, package);
}

/**
 * @brief receive the package.
 * @details
 * this function receives the package.
 * @param[in] self pointer to UART.
 * @param[out] package pointer to UART package.
 * @return the result of receiving the package.
 */
static __force_inline i32 uart_receive_polling(struct UART *self,
                                                struct UART_PACKAGE *package)
{
        return self->receive_polling(self, package);
}

/**
 * @brief create a UART object.
 * @details
 * this function creates a UART object.
 * @param[in] self pointer to UART.
 * @param[in] id identifier of UART.
 * @return the result of creating a UART object.
 */
i32 uart_create(struct UART *self, u8 id);

#endif /* !defined UART_H */
