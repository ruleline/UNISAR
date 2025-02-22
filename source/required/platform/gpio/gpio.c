/**
 * @file gpio.c
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

#include "gpio.h"

static struct GPIO gpio[5];

static __ctor(GPIO1_PRIORITY) void init1(void)
{
        /* TODO */
}

static __ctor(GPIO2_PRIORITY) void init2(void)
{
        /* TODO */
}

static __ctor(GPIO3_PRIORITY) void init3(void)
{
        /* TODO */
}

static __ctor(GPIO4_PRIORITY) void init4(void)
{
        /* TODO */
}

static __ctor(GPIO5_PRIORITY) void init5(void)
{
        /* TODO */
}

static __dtor(GPIO1_PRIORITY) void deinit1(void)
{
        /* TODO */
}

static __dtor(GPIO2_PRIORITY) void deinit2(void)
{
        /* TODO */
}
static __dtor(GPIO3_PRIORITY) void deinit3(void)
{
        /* TODO */
}

static __dtor(GPIO4_PRIORITY) void deinit4(void)
{
        /* TODO */
}

static __dtor(GPIO5_PRIORITY) void deinit5(void)
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
        return 0;
}

static i32 toggle_(struct GPIO *self)
{
        /* TODO */
        return 0;
}

static i32 highz_(struct GPIO *self)
{
        /* TODO */
        return 0;
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
                return 0;
        }
        return -1;
}
