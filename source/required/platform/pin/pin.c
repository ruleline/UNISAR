/**
 * @file pin.c
 * @brief PIN driver.
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-18
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-06-14
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

#include "pin.h"

/**
 * @brief the type of PIN object.
 * @details
 * this enum defines the types for different PIN objects.
 */
enum PIN_TYPE {
        /** input PIN. */
        PIN_INPUT,
        /** output PIN. */
        PIN_OUTPUT,
};

/**
 * @brief the length of PIN name.
 * @details
 * this enum defines the length for different PIN names.
 */
enum PIN_NAME_LENGTH {
        /** the length of PIN 3.3V name. */
        PIN_3V3_NAME_LENGTH = 20,
};

/**
 * @brief PIN object set.
 * @details
 * this struct defines the set of PIN objects.
 */
static struct PIN pin[PIN_MAX];

/**
 * @brief read the state of a PIN.
 * @details
 * this function reads the state of a PIN.
 * @param[in] self the PIN object.
 * @param[out] state the state of the PIN.
 * @return the status of reading the state.
 */
static bool read(struct PIN *self, bool *state)
{
        /* TODO */
        PRINTF("[PIN] read %s successfully", pin_name(self));
        return (*state);
}

/**
 * @brief write a state to a PIN.
 * @details
 * this function writes a state to a PIN.
 * @param[in] self the PIN object.
 * @param[in] state the state to be written.
 * @return the status of writing state.
 */
static i32 write(struct PIN *self, bool *state)
{
        /* TODO */
        PRINTF("[PIN] write %s successfully", pin_name(self));
        return (0);
}

/**
 * @brief toggle the state of a PIN.
 * @details
 * this function toggles the state of a PIN.
 * @param[in,out] self the PIN object.
 * @return the status of toggling the state.
 */
static i32 toggle(struct PIN *self)
{
        /* TODO */
        PRINTF("[PIN] toggle %s successfully", pin_name(self));
        return (0);
}

/**
 * @brief set the state of a PIN to high impedance.
 * @details
 * this function sets the state of a PIN to high impedance.
 * @param[in,out] self the PIN object.
 * @return the status of setting the state to high impedance.
 */
static i32 highz(struct PIN *self)
{
        /* TODO */
        PRINTF("[PIN] highz %s successfully", pin_name(self));
        return (0);
}

/**
 * @brief initialize the PIN1 object.
 * @details
 * this function initializes the PIN1 object for communication.
 * @return void
 */
static __ctor(PIN1_PRIORITY) void init_pin1(void)
{
        struct PIN *self = &pin[PIN_3V3];
        static struct OBJECT super;

        /* TODO */

        self->super = object_create("PIN 3V3", 0, 0,
                                        (i32 (*)(struct OBJECT*, void*))read,
                                        (i32 (*)(struct OBJECT*, void*))write);
        ASSERT(self->super);
        self->type = PIN_INPUT;
        self->toggle = &toggle;
        self->highz = &highz;
        PRINTF("%s initialized.", pin_name(self));
}

/**
 * @brief deinitialize the PIN1 object.
 * @details
 * this function deinitializes the PIN1 object for communication.
 * @return void
 */
static __dtor(PIN1_PRIORITY) void deinit_pin1(void)
{
        struct PIN *self = &pin[PIN_3V3];

        /* TODO */
        PRINTF("%s deinitialized.", pin_name(self));
        pin_destroy(&self);
}

/**
 * @brief create a PIN object.
 * @details
 * this function creates a PIN object.
 * @param[in,out] self the PIN object.
 * @param[in] id the ID of the PIN object.
 * @return the status of creating the PIN object.
 */
struct PIN *pin_create(enum PIN_ID id)
{
        ASSERT(id < PIN_MAX);
        return (&pin[id]);
}

/**
 * @brief destroy a PIN object.
 * @details
 * this function destroys a PIN object.
 * @param[in,out] self the PIN object.
 * @return the status of destroying the PIN object.
 */
i32 pin_destroy(struct PIN **self)
{
        ASSERT(self);

        if (*self) {
                struct OBJECT *p = (*self)->super;
                object_destroy(&p);
                memory_clear(*self, sizeof(struct PIN));
                *self = 0;
        }
        return (0);
}
