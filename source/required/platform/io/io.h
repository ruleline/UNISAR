/**
 * @file gpio.h
 * @brief gpio
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-18
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-25
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

#if !defined IO_H
#define IO_H

#include "unisis.h"

struct IO {
        char name[20];
        bool (*read)(struct IO *gpio);
        i32 (*write)(struct IO *gpio, bool state);
        i32 (*toggle)(struct IO *gpio);
        i32 (*highz)(struct IO *gpio);
};

static __force_inline bool gpio_read_(struct IO *self)
{
        return self->read(self);
}

static __force_inline i32 gpio_write_(struct IO *self, bool state)
{
        return self->write(self, state);
}

static __force_inline i32 gpio_toggle_(struct IO *self)
{
        return self->toggle(self);
}

static __force_inline i32 gpio_highz_(struct IO *self)
{
        return self->highz(self);
}

i32 gpio_create(struct IO *self, char *name);

#endif /* !defined IO_H */
