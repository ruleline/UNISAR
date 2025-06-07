/**
 * @file flash.c
 * @brief flash
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-19
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-06-08
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

#include "flash.h"

static struct FLASH flash[FLASH_MAX_ID];

/**
 * @brief read data from the XX Flash.
 * @details
 * this function reads data from the XX Flash.
 * @param[in] self the XX Flash object.
 * @param[in] package the package containing address and buffer.
 * @return status of the operation.
 */
static i32 xx_flash_read(struct FLASH *self, struct FLASH_PACKAGE *package)
{
        ASSERT(self);
        ASSERT(package);

        /* TODO */
        return (0);
}

/**
 * @brief write data to the XX Flash.
 * @details
 * this function writes data to the XX Flash.
 * @param[in] self the XX Flash object.
 * @param[in] package the package containing address and buffer.
 * @return status of the operation.
 */
static i32 xx_flash_write(struct FLASH *self, struct FLASH_PACKAGE *package)
{
        ASSERT(self);
        ASSERT(package);

        /* TODO */
        return (0);
}

/**
 * @brief initialize the XX Flash.
 * @details
 * this function initializes the XX Flash.
 * @return void.
 */
static __ctor(XX_FLASH_PRIORITY) void init_flash_xx(void)
{
        struct FLASH *self = &flash[FLASH_XX];
        static struct OBJECT super;

        /* TODO */

        self->super = &super;
        object_create(&self->super, "XX Flash", 0, 0,
                        &xx_flash_read, &xx_flash_write);
        PRINTF("%s initialized", object_name(self));
}

/**
 * @brief deinitialize the XX Flash.
 * @details
 * this function deinitializes the XX Flash.
 * @return void.
 */
static __ctor(XX_FLASH_PRIORITY) void deinit_flash_xx(void)
{
        struct FLASH *self = &flash[FLASH_XX];

        /* TODO */

        PRINTF("%s deinitialized", object_name(self));
        flash_destroy(self);
}

/**
 * @brief create a Flash object.
 * @details
 * this function creates a Flash object with the specified identifier.
 * @param id the identifier of the Flash object to be created.
 * @return pointer to the created Flash object.
 */
struct FLASH *flash_create(enum FLASH_ID id)
{
        ASSERT(id < FLASH_MAX_ID);
        return (&flash[id]);
}

/**
 * @brief destroy a Flash object.
 * @details
 * this function destroys a Flash object, releasing any resources it holds.
 * @param self pointer to the Flash object to be destroyed.
 * @return status of the operation.
 */
i32 flash_destroy(struct FLASH *self)
{
        if (self) {
                object_destroy(&self->super);
                memory_clear(self, sizeof(struct FLASH));
        }
        return (0);
}
