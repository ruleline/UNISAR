/**
 * @file spi.h
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

#if !defined SPI_H
#define SPI_H

#include "unisis.h"

/**
 * @brief SPI ID set.
 * @details
 * this enumeration represents the SPI ID.
 */
enum SPI_ID {
        /** SPI-Flash */
        SPI_FLASH,
        /** the maximum identifier of SPI */
        SPI_MAX,
};

/**
 * @brief SPI package.
 * @details
 * this structure represents the SPI package.
 */
struct SPI_PACKAGE {
        /** data */
        u8 *data;
        /** length of data */
        usize length;
};

/**
 * @brief SPI.
 * @details
 * this structure represents the SPI.
 */
struct SPI {
        /** parent object */
        struct OBJECT *super;
        /** type of SPI */
        u8 type;
        /** status of SPI */
        bool is_open;
};

/**
 * @brief get the name of SPI.
 * @details
 * this function gets the name of SPI.
 * @param[in] self pointer to SPI.
 * @return the name of SPI.
 */
static __force_inline char *spi_name(struct SPI *self)
{
        return object_name(self);
}

/**
 * @brief open the SPI.
 * @details
 * this function opens the SPI.
 * @param[in] self pointer to SPI.
 * @return the result of opening the SPI.
 */
static __force_inline i32 spi_open(struct SPI *self)
{
        return object_open(self);
}

/**
 * @brief close the SPI.
 * @details
 * this function closes the SPI.
 * @param[in] self pointer to SPI.
 * @return the result of closing the SPI.
 */
static __force_inline i32 spi_close(struct SPI *self)
{
        return object_close(self);
}

/**
 * @brief send the package.
 * @details
 * this function sends the package.
 * @param[in] self pointer to SPI.
 * @param[in] package pointer to SPI package.
 * @return the result of sending the package.
 */
static __force_inline i32 spi_send(struct SPI *self, struct SPI_PACKAGE *package)
{
        return object_write(self, package);
}

/**
 * @brief receive the package.
 * @details
 * this function receives the package.
 * @param[in] self pointer to SPI.
 * @param[out] package pointer to SPI package.
 * @return the result of receiving the package.
 */
static __force_inline i32 spi_receive_(struct SPI *self, struct SPI_PACKAGE *package)
{
        return object_read(self, package);
}

/**
 * @brief create a SPI object.
 * @details
 * this function creates a SPI object.
 * @param[in] self pointer to SPI.
 * @param[in] id identifier of SPI.
 * @return the result of creating the SPI object.
 */
i32 spi_create(struct SPI *self, u8 id);

#endif /* !defined SPI_H */
