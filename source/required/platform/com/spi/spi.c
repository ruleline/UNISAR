/**
 * @file spi.c
 * @brief spi
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

#include "spi.h"

static struct SPI spi[1];

static __ctor(SPI1_PRIORITY) void init1_(void)
{
        /* TODO */
}

static __dtor(SPI1_PRIORITY) void deinit1_(void)
{
        /* TODO */
}

static i32 send_spi_(struct SPI *self, struct SPI_PACKAGE *package)
{
        ASSERT(self->type == SPI_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        /* TODO */
        return 0;
}

static i32 receive_spi_(struct SPI *self, struct SPI_PACKAGE *package)
{
        ASSERT(self->type == SPI_COM);
        ASSERT(package);
        ASSERT(package->data);

        /* TODO */
        return 0;
}

static i32 send_qspi_(struct SPI *self, struct SPI_PACKAGE *package)
{
        ASSERT(self->type == QSPI_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        /* TODO */
        return 0;
}

static i32 receive_qspi_(struct SPI *self, struct SPI_PACKAGE *package)
{
        ASSERT(self->type == QSPI_COM);
        ASSERT(package);
        ASSERT(package->data);

        /* TODO */
        return 0;
}

i32 spi_create(struct SPI *self, char *name, u8 type)
{
        ASSERT(self);
        ASSERT(name);
        ASSERT(strlen(name));
        ASSERT(strlen(name) < sizeof(self->name));
        ASSERT((type == SPI_COM) || (type == QSPI_COM));

        for (u8 i = 0; i < ARRAY_SIZE(spi); i++) {
                if (spi[i].name[0]) {
                        continue;
                }
                strcpy(&spi[i].name[0], name);
                spi[i].type = type;
                if (type == SPI_COM) {
                        spi[i].send = send_spi_;
                        spi[i].receive = receive_spi_;
                } else {
                        spi[i].send = send_qspi_;
                        spi[i].receive = receive_qspi_;
                }
                self = &spi[i];
                PRINTF("[SPI] create %s success.", self->name);
                return 0;
        }
        return -1;
}
