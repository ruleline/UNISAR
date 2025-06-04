/**
 * @file system.h
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

#if !defined SYSTEM_H
#define SYSTEM_H

#include "unisis.h"

/**
 * @brief system identifier enumeration.
 * @details
 * this enumeration defines the various system identifiers.
 */
enum SYSTEM_ID {
        /** Bootloader system. */
        BOOTLOADER_SYSTEM = 0,
        /** Application system. */
        APPLICATION_SYSTEM = 1,
        /** the maximum identifier of system. */
        SYSTEM_MAXIMUM_ID,
};

/**
 * @brief system service structure.
 * @details
 * this structure defines the system service interface, providing methods for
 * suspending, resuming, and resetting the system.
 */
struct SYSTEM {
        /** parent object. */
        struct OBJECT *super;
        /** system status. */
        u8 status;
        /** reset system. */
        i32 (*reset)(struct SYSTEM *self);
};

/**
 * @brief get system name.
 * @details
 * this function retrieves the name of the system object.
 * @param[in] self pointer to the system object.
 * @return system name.
 */
static __force_inline char *system_name(struct SYSTEM *self)
{
        return object_name(self->super);
}

/**
 * @brief get system status.
 * @details
 * this function retrieves the current status of the system.
 * @param[in] self pointer to the system object.
 * @return system status.
 */
static __force_inline u8 system_status(struct SYSTEM *self)
{
        return (self->status);
}

/**
 * @brief suspend system.
 * @details
 * this function suspends the system.
 * @param[in,out] self pointer to the system object.
 * @return result of the suspend operation.
 */
static __force_inline i32 system_suspend(struct SYSTEM *self)
{
        return object_open(self);
}

/**
 * @brief resume system.
 * @details
 * this function resumes the system.
 * @param[in,out] self pointer to the system object.
 * @return result of the resume operation.
 */
static __force_inline i32 system_resume(struct SYSTEM *self)
{
        return object_close(self);
}

/**
 * @brief reset system.
 * @details
 * this function resets the system to its initial state.
 * @param[in,out] self pointer to the system object.
 * @return result of the reset operation.
 */
static __force_inline i32 system_reset(struct SYSTEM *self)
{
        return self->reset(self);
}

#endif /* !defined SYSTEM_H */
