/**
 * @file fram.c
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

#include "fram.h"

/**
 * @brief FRAM memory object set.
 * @details
 * this is the set of FRAM memory objects.
 */
static struct FRAM fram[FRAM_MAX_ID];

/**
 * @brief read data from the XX FRAM.
 * @details
 * this function reads data from the XX FRAM.
 * @param[in] fram the XX FRAM object.
 * @param[in] package the package containing address and buffer.
 * @return status of the operation.
 */
static i32 xx_fram_read(struct FRAM *fram, struct FRAM_PACKAGE *package)
{
        ASSERT(fram);
        ASSERT(package);

        /* TODO */

        return (0);
}

/**
 * @brief read data from the XX FRAM.
 * @details
 * this function reads data from the XX FRAM.
 * @param[in] fram the XX FRAM object.
 * @param[in] package the package containing address and buffer.
 * @return status of the operation.
 */
static i32 xx_fram_write(struct FRAM *fram, struct FRAM_PACKAGE *package)
{
        ASSERT(fram);
        ASSERT(package);

        /* TODO */

        return (0);
}

/**
 * @brief initialize the XX FRAM.
 * @details
 * this function initializes the XX FRAM.
 */
static void __ctor(XX_FRAM_PRIORITY) init_fram_xx(void)
{
        struct FRAM *self = &fram[FRAM_XX];

        /* TODO */

        self->super = object_create("XX FRAM", 0, 0,
                                (i32 (*)(struct OBJECT *, void *))xx_fram_read,
                                (i32 (*)(struct OBJECT *, void *))xx_fram_write);
        PRINTF("%s initialized", fram_name(self));
}

/**
 * @brief deinitialize the XX FRAM.
 * @details
 * this function deinitializes the XX FRAM.
 */
static void __dtor(XX_FRAM_PRIORITY) deinit_fram_xx(void)
{
        struct FRAM *self = &fram[FRAM_XX];

        /* TODO */

        PRINTF("%s deinitialized", fram_name(self));
        fram_destroy(&self);
}

/**
 * @brief create a new FRAM object.
 * @details
 * this function creates a new FRAM object with the specified identifier.
 * @param[in] id FRAM object identifier.
 * @return the newly created FRAM object.
 */
struct FRAM *fram_create(enum FRAM_ID id)
{
        ASSERT(id < FRAM_MAX_ID);
        return (&fram[id]);
}

/**
 * @brief destroy a FRAM object.
 * @details
 * this function destroys a FRAM object.
 * @param[in] self FRAM object.
 * @return status of the operation.
 */
i32 fram_destroy(struct FRAM **self)
{
        ASSERT(self);

        if (*self) {
                object_destroy((struct OBJECT *)*self);
                memory_clear(*self, sizeof(struct FRAM));
                *self = 0;
        }
        return (0);
}
