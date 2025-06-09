/**
 * @file can.h
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

#if !defined CAN_H
#define CAN_H

#include "unisis.h"

/**
 * @brief the identifier of CAN object.
 * @details
 * this enum defines the identifiers for different CAN objects.
 */
enum CAN_ID {
        /** cockpit CAN bus. */
        CAN_COCKPIT,
        /** the maximum number of CAN objects. */
        CAN_MAX_ID,
};

/**
 * @brief CAN bus package.
 * @details
 * this struct defines the structure of a CAN bus package.
 */
struct CAN_PACKAGE {
        /** the data of CAN package. */
        u8 *data;
        /** the length of CAN package data. */
        usize length;
};

/**
 * @brief CAN bus object.
 * @details
 * this struct defines the structure of a CAN bus object.
 */
struct CAN {
        /** the parent object of CAN object. */
        struct OBJECT *super;
        /** the name of CAN object. */
        u8 type;
        /** the status of CAN object. */
        bool is_open;
};

/**
 * @brief get the name of CAN object.
 * @details
 * this function retrieves the name of the CAN object.
 * @param[in] self the CAN object.
 * @return the name of CAN object.
 */
static __force_inline char *can_name(struct CAN *self)
{
        return object_name((struct OBJECT *)self);
}

/**
 * @brief open the CAN object.
 * @details
 * this function opens the CAN object for communication.
 * @param[in,out] self the CAN object.
 * @return the status of opening CAN object.
 */
static __force_inline i32 can_open(struct CAN *self)
{
        return object_open((struct OBJECT *)self);
}

/**
 * @brief close the CAN object.
 * @details
 * this function closes the CAN object for communication.
 * @param[in,out] self the CAN object.
 * @return the status of closing CAN object.
 */
static __force_inline i32 can_close(struct CAN *self)
{
        return object_close((struct OBJECT *)self);
}

/**
 * @brief send a package through the CAN bus.
 * @details
 * this function sends a package through the CAN bus.
 * @param[in,out] self the CAN object.
 * @param[in] package the package to be sent.
 * @return the status of sending package.
 */
static __force_inline i32 can_send(struct CAN *self,
                                        struct CAN_PACKAGE *package)
{
        return object_write((struct OBJECT *)self, package);
}

/**
 * @brief receive a package from the CAN bus.
 * @details
 * this function receives a package from the CAN bus.
 * @param[in,out] self the CAN object.
 * @param[in] package the package to be received.
 * @return the status of receiving package.
 */
static __force_inline i32 can_receive(struct CAN *self,
                                        struct CAN_PACKAGE *package)
{
        return object_read((struct OBJECT *)self, package);
}

/**
 * @brief create a CAN object.
 * @details
 * this function creates a CAN object.
 * @param[in] id the identifier of CAN object.
 * @return the status of creating CAN object.
 */
struct CAN *can_create(enum CAN_ID id);

/**
 * @brief destroy a CAN object.
 * @details
 * this function destroys a CAN object.
 * @param[in,out] self the CAN object to be destroyed.
 * @return the status of destroying CAN object.
 */
i32 can_destroy(struct CAN **self);

#endif /* !defined CAN_H */
