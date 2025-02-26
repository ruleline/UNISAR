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
        char *name;
        u8 type;
        bool is_open;
        i32 (*open)(struct SPI *self);
        i32 (*close)(struct SPI *self);
        i32 (*send)(struct SPI *self, struct SPI_PACKAGE *package);
        i32 (*receive)(struct SPI *self, struct SPI_PACKAGE *package);
};

static __force_inline i32 spi_open_(struct SPI *self)
{
        return self->open(self);
}

static __force_inline i32 spi_close_(struct SPI *self)
{
        return self->close(self);
}

static __force_inline i32 spi_send_(struct SPI *self, struct SPI_PACKAGE *package)
{
        return self->send(self, package);
}

static __force_inline i32 spi_receive_(struct SPI *self, struct SPI_PACKAGE *package)
{
        return self->receive(self, package);
}

i32 spi_create(struct SPI *self, u8 id);

#endif /* !defined SPI_H */
