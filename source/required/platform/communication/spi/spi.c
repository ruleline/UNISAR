/**
 * @file spi.c
 * @brief SPI.
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

#include "spi.h"

/**
 * @brief SPI type set.
 * @details
 * this enumeration represents the SPI type.
 */
enum SPI_TYPE {
        /** SPI */
        SPI_COM,
        /** QSPI */
        QSPI_COM,
};

/**
 * @brief SPI name length.
 * @details
 * this enumeration represents the SPI name length.
 */
enum SPI_NAME_LENGTH {
        SPI_FLASH_NAME_LENGTH = 20,
};

/**
 * @brief SPI set.
 * @details
 * this structure represents the SPI.
 */
static struct SPI spi[SPI_MAX];

/**
 * @brief open the SPI.
 * @details
 * this function opens the SPI.
 * @param[in,out] self pointer to SPI.
 * @return the result of opening the SPI.
 */
static i32 open(struct SPI *self)
{
        self->is_open = 1;
        PRINTF("[SPI] open %s successfully", spi_name(self));
        return (0);
}

/**
 * @brief close the SPI.
 * @details
 * this function closes the SPI.
 * @param[in,out] self pointer to SPI.
 * @return the result of closing the SPI.
 */
static i32 close(struct SPI *self)
{
        self->is_open = 0;
        PRINTF("[SPI] close %s successfully", spi_name(self));
        return (0);
}

/**
 * @brief send the package.
 * @details
 * this function sends the package.
 * @param[in] self pointer to SPI.
 * @param[in] package pointer to SPI package.
 * @return the result of sending the package.
 */
static i32 send_spi(struct SPI *self, struct SPI_PACKAGE *package)
{
        ASSERT(self->type == SPI_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        /* TODO */
        PRINTF("[SPI] send %s successfully", spi_name(self));
        return (0);
}

/**
 * @brief receive the package.
 * @details
 * this function receives the package.
 * @param[in] self pointer to SPI.
 * @param[out] package pointer to SPI package.
 * @return the result of receiving the package.
 */
static i32 receive_spi(struct SPI *self, struct SPI_PACKAGE *package)
{
        ASSERT(self->type == SPI_COM);
        ASSERT(package);
        ASSERT(package->data);

        /* TODO */
        PRINTF("[SPI] receive %s successfully", spi_name(self));
        return (0);
}

/**
 * @brief send the package.
 * @details
 * this function sends the package.
 * @param[in] self pointer to QSPI.
 * @param[in] package pointer to QSPI package.
 * @return the result of sending the package.
 */
static i32 send_qspi(struct SPI *self, struct SPI_PACKAGE *package)
{
        ASSERT(self->type == QSPI_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->data);

        /* TODO */
        PRINTF("[SPI] send %s successfully", spi_name(self));
        return (0);
}

/**
 * @brief receive the package.
 * @details
 * this function receives the package.
 * @param[in] self pointer to QSPI.
 * @param[out] package pointer to QSPI package.
 * @return the result of receiving the package.
 */
static i32 receive_qspi(struct SPI *self, struct SPI_PACKAGE *package)
{
        ASSERT(self->type == QSPI_COM);
        ASSERT(package);
        ASSERT(package->data);

        /* TODO */
        PRINTF("[SPI] receive %s successfully", spi_name(self));
        return (0);
}

/**
 * @brief initialize the SPI1.
 * @details
 * this function initializes the SPI1.
 * @returns void.
 */
static __ctor(SPI1_PRIORITY) void init_spi1(void)
{
        struct SPI *self = &spi[SPI_FLASH];
        static struct OBJECT super;

        /* TODO */

        super.name = "spi-flash";
        super.open = &open;
        super.close = &close;
        super.read = &receive_qspi;
        super.write = &send_qspi;
        self->super = &super;
        self->type = QSPI_COM;
        self->is_open = 0;
        PRINTF("[SPI] init %s successfully", spi_name(self));
}

/**
 * @brief deinitialize the SPI1.
 * @details
 * this function deinitializes the SPI1.
 * @returns void.
 */
static __dtor(SPI1_PRIORITY) void deinit_spi1(void)
{
        struct SPI *self = &spi[SPI_FLASH];

        /* TODO */
        PRINTF("[SPI] deinit %s successfully", spi_name(self));
}

/**
 * @brief create a SPI object.
 * @details
 * this function creates a SPI object.
 * @param[in,out] self pointer to SPI.
 * @param[in] id the identifier of SPI.
 * @return the result of creating a SPI object.
 */
i32 spi_create(struct SPI *self, u8 id)
{
        ASSERT(self);
        ASSERT(id < ARRAY_SIZE(spi));

        self = &spi[id];
        PRINTF("[SPI] create %s successfully", spi_name(self));
        return (0);
}
