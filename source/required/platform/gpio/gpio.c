/**
 * @file gpio.c
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

#include "gpio.h"

static struct GPIO gpio[1];

static __ctor(GPIO1_PRIORITY) void init1_(void)
{
        /* TODO */
}

static __dtor(GPIO1_PRIORITY) void deinit1_(void)
{
        /* TODO */
}

static bool read_(struct GPIO *self)
{
        bool state = 0;

        /* TODO */
        return state;
}

static i32 write_(struct GPIO *self, bool state)
{
        /* TODO */
        return (0);
}

static i32 toggle_(struct GPIO *self)
{
        /* TODO */
        return (0);
}

static i32 highz_(struct GPIO *self)
{
        /* TODO */
        return (0);
}

i32 gpio_create(struct GPIO *self, char *name)
{
        ASSERT(self);
        ASSERT(name);
        ASSERT(strlen(name));
        ASSERT(strlen(name) < sizeof(self->name));

        for (u8 i = 0; i < ARRAY_SIZE(gpio); i++) {
                if (gpio[i].name[0]) {
                        continue;
                }
                strcpy(&gpio[i].name[0], name);
                gpio[i].read = read_;
                gpio[i].write = write_;
                gpio[i].toggle = toggle_;
                gpio[i].highz = highz_;
                self = &gpio[i];
                PRINTF("[GPIO] create %s success.", self->name);
                return (0);
        }
        return (-1);
}
