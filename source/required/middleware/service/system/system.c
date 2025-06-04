/**
 * @file system.c
 * @brief system service.
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-06-04
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-06-04
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-06-04 |    ruleline    | initial commit.
 * -----------------------------------------------------------------------------
 */

#include "system.h"

/**
 * @brief system object set.
 * @details
 * this set contains all system objects, indexed by their identifiers.
 */
static struct SYSTEM system[SYSTEM_MAXIMUM_ID];

/**
 * @brief suspend system.
 * @details
 * this function suspends the system.
 * @param[in,out] self pointer to the system object.
 * @return result of the suspend operation.
 */
static i32 suspend_(struct SYSTEM *self)
{
        /* TODO */
        return (0);
}

/**
 * @brief resume system.
 * @details
 * this function resumes the system.
 * @param[in,out] self pointer to the system object.
 * @return result of the resume operation.
 */
static i32 resume_(struct SYSTEM *self)
{
        /* TODO */
        return (0);
}

/**
 * @brief reset system.
 * @details
 * this function resets the system to its initial state.
 * @param[in,out] self pointer to the system object.
 * @return result of the reset operation.
 */
static i32 reset_(struct SYSTEM *self)
{
        /* TODO */
        return (0);
}

/**
 * @brief bootloader system constructor.
 * @details
 * this function initializes the bootloader system.
 * @return void.
 */
static __ctor(BOOTLOADER_SYSTEM_PRIORITY) void init_bootloader_system(void)
{
        /* TODO */
}

/**
 * @brief initialize application system.
 * @details
 * this function initializes the application system.
 * @return void.
 */
static __ctor(APPLICATION_SYSTEM_PRIORITY) void init_application_system(void)
{
        /* TODO */
}

/**
 * @brief deinitialize bootloader system.
 * @details
 * this function deinitializes the bootloader system.
 * @return void.
 */
static __dtor(BOOTLOADER_SYSTEM_PRIORITY) void deinit_bootloader_system(void)
{
        /* TODO */
}

/**
 * @brief deinitialize application system.
 * @details
 * this function deinitializes the application system.
 * @return void.
 */
static __dtor(APPLICATION_SYSTEM_PRIORITY) void deinit_application_system(void)
{
        /* TODO */
}

/**
 * @brief create system object.
 * @details
 * this function creates a system object with the specified identifier.
 * @param[in] id identifier of the system.
 * @return pointer to the created system object.
 */
struct SYSTEM *system_create(enum SYSTEM_ID id)
{
        ASSERT(id < SYSTEM_MAXIMUM_ID);
        return (&system[id]);
}
