/**
 * @file spi.h
 * @brief spi
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

#if !defined SPI_H
#define SPI_H

#include "unisis.h"

enum SPI_ID {
        SPI_FLASH,
        SPI_MAX,
};

struct SPI_PACKAGE {
        u8 *data;
        usize length;
};

struct SPI {
        struct OBJECT *super;
        u8 type;
        bool is_open;
};

static __force_inline char *spi_name_(struct SPI *self)
{
        return (object_name_(self));
}

static __force_inline i32 spi_open_(struct SPI *self)
{
        return (object_open_(self));
}

static __force_inline i32 spi_close_(struct SPI *self)
{
        return (object_close_(self));
}

static __force_inline i32 spi_send_(struct SPI *self, struct SPI_PACKAGE *package)
{
        return (object_write_(self, package));
}

static __force_inline i32 spi_receive_(struct SPI *self, struct SPI_PACKAGE *package)
{
        return (object_read_(self, package));
}

i32 spi_create(struct SPI *self, u8 id);

#endif /* !defined SPI_H */
