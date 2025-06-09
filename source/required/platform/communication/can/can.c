/**
 * @file can.c
 * @brief CAN bus driver.
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-18
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
 *   0.00.001   | 2025-02-18 |    ruleline    | initial commit.
 * -----------------------------------------------------------------------------
 */

#include "can.h"

/**
 * @brief the type of CAN object.
 * @details
 * this enum defines the types for different CAN objects.
 */
enum CAN_TYPE {
        /** classic CAN bus. */
        CAN_COM,
        /** CAN-FD bus. */
        CANFD_COM,
        /** CAN-XL bus. */
        CANXL_COM,
};

/**
 * @brief the length of CAN name.
 * @details
 * this enum defines the length for different CAN names.
 */
enum CAN_NAME_LENGTH {
        /** the length of CAN cockpit name. */
        CAN_COCKPIT_NAME_LENGTH = 20,
};

/**
 * @brief the length of CAN data.
 * @details
 * this enum defines the length for different CAN data.
 */
enum CAN_DATA_LENGTH {
        /** the length of CAN classic data. */
        CLASSIC_CAN_DATA_LENGTH = 8,
        /** the length of CAN flexible data. */
        FLEXIBLE_CAN_DATA_LENGTH = 64,
};

/**
 * @brief CAN object set.
 * @details
 * this struct defines the structure of a CAN object set.
 */
static struct CAN can[CAN_MAX_ID];

/**
 * @brief open the CAN object.
 * @details
 * this function opens the CAN object for communication.
 * @param[in,out] self the CAN object.
 * @return the status of opening CAN object.
 */
static i32 open(struct CAN *self)
{
        self->is_open = 1;
        PRINTF("[CAN] open %s successfully", can_name(self));
        return (0);
}

/**
 * @brief close the CAN object.
 * @details
 * this function closes the CAN object for communication.
 * @param[in,out] self the CAN object.
 * @return the status of closing CAN object.
 */
static i32 close(struct CAN *self)
{
        self->is_open = 0;
        PRINTF("[CAN] close %s successfully", can_name(self));
        return (0);
}

/**
 * @brief send a package through a classic CAN bus.
 * @details
 * this function sends a package through a classic CAN bus.
 * @param[in,out] self the CAN object.
 * @param[in] package the package to be sent.
 * @return the status of sending package.
 */
static i32 send_classic(struct CAN *self, struct CAN_PACKAGE *package)
{
        ASSERT(self->type == CAN_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->length <= CLASSIC_CAN_DATA_LENGTH);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[CAN] send %s successfully", can_name(self));
        return (0);
}

/**
 * @brief receive a package from a classic CAN bus.
 * @details
 * this function receives a package from a classic CAN bus.
 * @param[in,out] self the CAN object.
 * @param[out] package the package to be received.
 * @return the status of receiving package.
 */
static i32 receive_classic(struct CAN *self, struct CAN_PACKAGE *package)
{
        ASSERT(self->type == CAN_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[CAN] receive %s successfully", can_name(self));
        return (0);
}

/**
 * @brief send a package through a CAN-FD bus.
 * @details
 * this function sends a package through a CAN-FD bus.
 * @param[in,out] self the CAN object.
 * @param[in] package the package to be sent.
 * @return the status of sending package.
 */
static i32 send_flexible(struct CAN *self, struct CAN_PACKAGE *package)
{
        ASSERT(self->type == CANFD_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->length <= FLEXIBLE_CAN_DATA_LENGTH);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[CAN] send %s successfully", can_name(self));
        return (0);
}

/**
 * @brief receive a package from a CAN-FD bus.
 * @details
 * this function receives a package from a CAN-FD bus.
 * @param[in,out] self the CAN object.
 * @param[out] package the package to be received.
 * @return the status of receiving package.
 */
static i32 receive_flexible(struct CAN *self, struct CAN_PACKAGE *package)
{
        ASSERT(self->type == CANFD_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[CAN] receive %s successfully", can_name(self));
        return (0);
}

/**
 * @brief initialize the CAN1 object.
 * @details
 * this function initializes the CAN1 object for communication.
 * @return void
 */
static __ctor(CAN1_PRIORITY) void init_can1(void)
{
        struct CAN *self = &can[CAN_COCKPIT];

        /* TODO */

        self->super = object_create("Cockpit CAN",
                                (i32 (*)(struct OBJECT *))open,
                                (i32 (*)(struct OBJECT *))close,
                                (i32 (*)(struct OBJECT *, void *))send_classic,
                                (i32 (*)(struct OBJECT *, void *))receive_classic);
        ASSERT(self->super);
        self->type = CAN_COM;
        self->is_open = 0;
        PRINTF("%s initialized.", can_name(self));
}

/**
 * @brief deinitialize the CAN1 object.
 * @details
 * this function deinitializes the CAN1 object for communication.
 * @return void
 */
static __dtor(CAN1_PRIORITY) void deinit_can1(void)
{
        struct CAN *self = &can[CAN_COCKPIT];

        /* TODO */

        PRINTF("%s deinitialized.", can_name(self));
        can_destroy(self);
}

/**
 * @brief create a CAN object.
 * @details
 * this function creates a CAN object.
 * @param[in] id the identifier of CAN object.
 * @return the status of creating CAN object.
 */
struct CAN *can_create(enum CAN_ID id)
{
        ASSERT(id < CAN_MAX_ID);
        return (&can[id]);
}

/**
 * @brief destroy a CAN object.
 * @details
 * this function destroys a CAN object.
 * @param[in] self the pointer of CAN object.
 * @return the status of destroying CAN object.
 */
i32 can_destroy(struct CAN *self)
{
        if (!self) {
                object_destroy((struct OBJECT *)self);
        }
        memory_clear(self, sizeof(struct CAN));
        return (0);
}
