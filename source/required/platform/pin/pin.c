/**
 * @file pin.c
 * @brief pin
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-18
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-05-10
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-02-18 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#include "pin.h"

enum PIN_TYPE {
        PIN_INPUT,
        PIN_OUTPUT,
};

enum PIN_NAME_LENGTH {
        PIN_3V3_NAME_LENGTH = 20,
};

static struct PIN pin[PIN_MAX];

static bool read_(struct PIN *self, bool *state)
{
        /* TODO */
        PRINTF("[PIN] read %s successfully", pin_name_(self));
        return (*state);
}

static i32 write_(struct PIN *self, bool state)
{
        /* TODO */
        PRINTF("[PIN] write %s successfully", pin_name_(self));
        return (0);
}

static i32 toggle_(struct PIN *self)
{
        /* TODO */
        PRINTF("[PIN] toggle %s successfully", pin_name_(self));
        return (0);
}

static i32 highz_(struct PIN *self)
{
        /* TODO */
        PRINTF("[PIN] highz %s successfully", pin_name_(self));
        return (0);
}

static __ctor(PIN1_PRIORITY) void init1_(void)
{
        struct PIN *self = &pin[PIN_3V3];
        static struct OBJECT super;

        /* TODO */

        super.name = "pin-3v3";
        super.open = 0;
        super.close = 0;
        super.read = &read_;
        super.write = &write_;
        self->super = &super;
        self->type = PIN_INPUT;
        self->toggle = &toggle_;
        self->highz = &highz_;
        PRINTF("[PIN] init %s successfully", pin_name_(self));
}

static __dtor(PIN1_PRIORITY) void deinit1_(void)
{
        struct PIN *self = &pin[PIN_3V3];

        /* TODO */
        PRINTF("[PIN] deinit %s successfully", pin_name_(self));
}

i32 pin_create(struct PIN *self, u8 id)
{
        ASSERT(self);
        ASSERT(id < ARRAY_SIZE(pin));

        self = &pin[id];
        PRINTF("[PIN] create %s successfully", pin_name_(self));
        return (0);
}
