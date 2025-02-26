/**
 * @file spi.c
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

#include "spi.h"

enum SPI_TYPE {
        SPI_COM,
        QSPI_COM,
};

enum SPI_NAME_LENGTH {
        SPI_FLASH_NAME_LENGTH = 20,
};

static struct SPI spi[SPI_MAX];

static i32 open_(struct SPI *self)
{
        self->is_open = 1;
        PRINTF("[SPI] open %s successfully", spi_name_(self));
        return (0);
}

static i32 close_(struct SPI *self)
{
        self->is_open = 0;
        PRINTF("[SPI] close %s successfully", spi_name_(self));
        return (0);
}

static i32 send_spi_(struct SPI *self, struct SPI_PACKAGE *package)
{
        ASSERT(self->type == SPI_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        /* TODO */
        PRINTF("[SPI] send %s successfully", spi_name_(self));
        return (0);
}

static i32 receive_spi_(struct SPI *self, struct SPI_PACKAGE *package)
{
        ASSERT(self->type == SPI_COM);
        ASSERT(package);
        ASSERT(package->data);

        /* TODO */
        PRINTF("[SPI] receive %s successfully", spi_name_(self));
        return (0);
}

static i32 send_qspi_(struct SPI *self, struct SPI_PACKAGE *package)
{
        ASSERT(self->type == QSPI_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        /* TODO */
        PRINTF("[SPI] send %s successfully", spi_name_(self));
        return (0);
}

static i32 receive_qspi_(struct SPI *self, struct SPI_PACKAGE *package)
{
        ASSERT(self->type == QSPI_COM);
        ASSERT(package);
        ASSERT(package->data);

        /* TODO */
        PRINTF("[SPI] receive %s successfully", spi_name_(self));
        return (0);
}

static __ctor(SPI1_PRIORITY) void init1_(void)
{
        struct SPI *self = &spi[SPI_FLASH];
        static char name[SPI_FLASH_NAME_LENGTH];

        /* TODO */

        memset(&name[0], '\0', sizeof(name));
        strncpy(&name[0], "spi-flash", strlen("spi-flash"));
        self->super.name = &name[0];
        self->is_open = 0;
        self->type = QSPI_COM;
        self->super.open = open_;
        self->super.close = close_;
        self->super.write = send_qspi_;
        self->super.read = receive_qspi_;
        PRINTF("[SPI] init %s successfully", spi_name_(self));
}

static __dtor(SPI1_PRIORITY) void deinit1_(void)
{
        struct SPI *self = &spi[SPI_FLASH];

        /* TODO */
        PRINTF("[SPI] deinit %s successfully", spi_name_(self));
}

i32 spi_create(struct SPI *self, u8 id)
{
        ASSERT(self);
        ASSERT(id < ARRAY_SIZE(spi));

        self = &spi[id];
        PRINTF("[SPI] create %s successfully", spi_name_(self));
        return (0);
}
