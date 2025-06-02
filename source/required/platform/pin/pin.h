/**
 * @file pin.h
 * @brief PIN driver.
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

#if !defined PIN_H
#define PIN_H

#include "unisis.h"

/**
 * @brief the type of PIN object.
 * @details
 * this enum defines the types for different PIN objects.
 */
enum PIN_ID {
        /** 3.3V power supply pin. */
        PIN_3V3,
        /** the maximum number of PINs. */
        PIN_MAX,
};

/**
 * @brief the structure of a PIN object.
 * @details
 * this struct defines the structure of a PIN object.
 */
struct PIN {
        /** parent object of this object. */
        struct OBJECT *super;
        /** type of this object. */
        u8 type;
        /** current state of this object. */
        bool state;
        /** toggle the state of this object. */
        i32 (*toggle)(struct PIN *self);
        /** set the state of this object to high impedance. */
        i32 (*highz)(struct PIN *self);
};

/**
 * @brief get the name of a PIN object.
 * @details
 * this function gets the name of a PIN object.
 * @param[in] self the PIN object.
 * @return the name of the PIN object.
 */
static __force_inline char *pin_name(struct PIN *self)
{
        return (object_name(self));
}

/**
 * @brief read the state of a PIN object.
 * @details
 * this function reads the state of a PIN object.
 * @param[in] self the PIN object.
 * @param[out] state the state of the PIN object.
 * @return the status of reading the state.
 */
static __force_inline bool pin_read(struct PIN *self, bool *state)
{
        return (object_read(self, state));
}

/**
 * @brief write the state of a PIN object.
 * @details
 * this function writes the state of a PIN object.
 * @param[in,out] self the PIN object.
 * @param[in] state the state to be written.
 * @return the status of writing the state.
 */
static __force_inline i32 pin_write(struct PIN *self, bool state)
{
        return (object_write(self, &state));
}

/**
 * @brief toggle the state of a PIN object.
 * @details
 * this function toggles the state of a PIN object.
 * @param[in,out] self the PIN object.
 * @return the status of toggling the state.
 */
static __force_inline i32 pin_toggle(struct PIN *self)
{
        return self->toggle(self);
}

/**
 * @brief set the state of a PIN object to high impedance.
 * @details
 * this function sets the state of a PIN object to high impedance.
 * @param[in,out] self the PIN object.
 * @return the status of setting the state to high impedance.
 */
static __force_inline i32 pin_highz(struct PIN *self)
{
        return self->highz(self);
}

/**
 * @brief create a PIN object.
 * @details
 * this function creates a PIN object.
 * @param[in,out] self the PIN object.
 * @param[in] id the ID of the PIN object.
 * @return the status of creating the PIN object.
 */
i32 pin_create(struct PIN *self, u8 id);

#endif /* !defined PIN_H */
