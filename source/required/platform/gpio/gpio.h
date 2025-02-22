/**
 * @file gpio.h
 * @brief gpio
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-18
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-22
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

#if !defined GPIO_H
#define GPIO_H

#include "unisis.h"

struct GPIO {
        char name[20];
        bool (*read)(struct GPIO *gpio);
        i32 (*write)(struct GPIO *gpio, bool state);
        i32 (*toggle)(struct GPIO *gpio);
        i32 (*highz)(struct GPIO *gpio);
};

static __force_inline bool gpio_read(struct GPIO *self)
{
        return self->read(self);
}

static __force_inline i32 gpio_write(struct GPIO *self, bool state)
{
        return self->write(self, state);
}

static __force_inline i32 gpio_toggle(struct GPIO *self)
{
        return self->toggle(self);
}

static __force_inline i32 gpio_highz(struct GPIO *self)
{
        return self->highz(self);
}

i32 gpio_create(struct GPIO *self, char *name);

#endif /* !defined GPIO_H */
