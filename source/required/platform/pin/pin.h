/**
 * @file pin.h
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

#if !defined PIN_H
#define PIN_H

#include "unisis.h"

enum PIN_ID {
        PIN_3V3,
        PIN_MAX,
};

struct PIN {
        struct OBJECT *super;
        u8 type;
        i32 (*toggle)(struct PIN *self);
        i32 (*highz)(struct PIN *self);
};

static __force_inline char *pin_name_(struct PIN *self)
{
        return (object_name_(self));
}

static __force_inline bool pin_read_(struct PIN *self, bool *state)
{
        return (object_read_(self, state));
}

static __force_inline i32 pin_write_(struct PIN *self, bool state)
{
        return (object_write_(self, &state));
}

static __force_inline i32 pin_toggle_(struct PIN *self)
{
        return self->toggle(self);
}

static __force_inline i32 pin_highz_(struct PIN *self)
{
        return self->highz(self);
}

i32 pin_create(struct PIN *self, u8 id);

#endif /* !defined PIN_H */
