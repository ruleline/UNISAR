/**
 * @file flash.h
 * @brief flash
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-19
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
 *   0.00.001   | 2025-02-19 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#if !defined FLASH_H
#define FLASH_H

#include "unisis.h"

/**
 * @brief Flash identifiers.
 * @details
 * this enumeration defines the identifiers for different Flash objects.
 */
enum FLASH_ID {
        /** XX Flash */
        FLASH_XX = 0,
        /** the maximum identifier for Flash objects */
        FLASH_MAX_ID,
};

/**
 * @brief Flash package.
 * @details
 * this structure represents a Flash package, which is used to read and write
 * data to and from flash memory.
 */
struct FLASH_PACKAGE {
        /** address in flash memory. */
        usize address;
        /** size of the data to read/write. */
        u8 *buffer;
        /** size of the data in bytes. */
        usize size;
};

/**
 * @brief Flash object.
 * @details
 * this structure represents a Flash object, which is used to interact with
 * flash memory.
 */
struct FLASH {
        /** parent object. */
        struct OBJECT *super;
};

/**
 * @brief get name of the Flash object.
 * @details
 * this function retrieves the name of the Flash object.
 * @param self pointer to the Flash object.
 * @return name of the Flash object.
 */
static __force_inline char *flash_name(struct FLASH *self)
{
        return object_name((struct OBJECT *)self);
}

/**
 * @brief read data from the Flash object.
 * @details
 * this function reads data from the Flash object using the specified package.
 * @param self pointer to the Flash object.
 * @param package pointer to the Flash package to read data into.
 * @return status of the read operation.
 */
static __force_inline i32 flash_read(struct FLASH *self,
                                        struct FLASH_PACKAGE *package)
{
        return object_read((struct OBJECT *)self, package);
}

/**
 * @brief write data to the Flash object.
 * @details
 * this function writes data to the Flash object using the specified package.
 * @param self pointer to the Flash object.
 * @param package pointer to the Flash package containing data to write.
 * @return status of the write operation.
 */
static __force_inline i32 flash_write(struct FLASH *self,
                                        struct FLASH_PACKAGE *package)
{
        return object_write((struct OBJECT *)self, package);
}

/**
 * @brief create a Flash object.
 * @details
 * this function creates a Flash object with the specified identifier.
 * @param id the identifier of the Flash object to be created.
 * @return pointer to the created Flash object.
 */
struct FLASH *flash_create(enum FLASH_ID id);

/**
 * @brief destroy a Flash object.
 * @details
 * this function destroys a Flash object, releasing any resources it holds.
 * @param self pointer to the Flash object to be destroyed.
 * @return status of the operation.
 */
i32 flash_destroy(struct FLASH **self);

#endif /* !defined FLASH_H */
