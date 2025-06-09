/**
 * @file fram.h
 * @brief FRAM memory driver.
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-06-06
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
 *   0.00.001   | 2025-06-06 |    ruleline    | initial commit.
 * -----------------------------------------------------------------------------
 */

#if !defined FRAM_H
#define FRAM_H

#include "unisis.h"

/**
 * @brief FRAM identifiers.
 * @details
 * this enumeration defines the identifiers for different FRAM objects.
 */
enum FRAM_ID {
        /** XX FRAM. */
        FRAM_XX = 0,
        /** the maximum identifier for FRAM objects. */
        FRAM_MAX_ID,
};

/**
 * @brief FRAM package.
 * @details
 * this structure represents a package for reading or writing data to/from FRAM.
 */
struct FRAM_PACKAGE {
        /** address in FRAM memory. */
        usize address;
        /** buffer for data. */
        u8 *buffer;
        /** size of the data buffer. */
        usize size;
};

/**
 * @brief FRAM object.
 * @details
 * this structure represents a FRAM object.
 */
struct FRAM {
        /** parent object. */
        struct object *super;
};

/**
 * @brief get name of FRAM object.
 * @details
 * this function retrieves the name of the specified FRAM object.
 * @param[in] fram FRAM object.
 * @return name of the FRAM object.
 */
static __force_inline char *fram_name(struct FRAM *fram)
{
        return object_name((struct OBJECT *)fram);
}

/**
 * @brief read data from FRAM.
 * @details
 * this function reads data from the specified FRAM object.
 * @param[in] fram FRAM object.
 * @param[in] package FRAM package.
 * @return status of the read operation.
 */
static __force_inline i32 fram_read(struct FRAM *fram,
                                        struct FRAM_PACKAGE *package)
{
        return object_read((struct OBJECT *)fram, package);
}

/**
 * @brief write data to FRAM.
 * @details
 * this function writes data to the specified FRAM object.
 * @param[in] fram FRAM object.
 * @param[in] package FRAM package.
 * @return status of the write operation.
 */
static __force_inline i32 fram_write(struct FRAM *fram,
                                        struct FRAM_PACKAGE *package)
{
        return object_write((struct OBJECT *)fram, package);
}

/**
 * @brief create a new FRAM object.
 * @details
 * this function creates a new FRAM object with the specified identifier.
 * @param[in] id FRAM object identifier.
 * @return the newly created FRAM object.
 */
struct FRAM *fram_create(enum FRAM_ID id);

/**
 * @brief destroy a FRAM object.
 * @details
 * this function destroys a FRAM object.
 * @param[in] fram FRAM object to destroy.
 * @return status of the operation.
 */
i32 fram_destroy(struct FRAM **fram);

#endif /* !defined FRAM_H */
