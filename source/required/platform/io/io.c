/**
 * @file io.c
 * @brief io
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

#include "io.h"

static struct IO io[1];

static bool read_(struct IO *self)
{
        bool state = 0;

        /* TODO */
        return state;
}

static i32 write_(struct IO *self, bool state)
{
        /* TODO */
        return (0);
}

static i32 toggle_(struct IO *self)
{
        /* TODO */
        return (0);
}

static i32 highz_(struct IO *self)
{
        /* TODO */
        return (0);
}

static __ctor(IO1_PRIORITY) void init1_(void)
{
        /* TODO */
}

static __dtor(IO1_PRIORITY) void deinit1_(void)
{
        /* TODO */
}

i32 io_create(struct IO *self, char *name)
{
        ASSERT(self);
        ASSERT(name);
        ASSERT(strlen(name));
        ASSERT(strlen(name) < sizeof(self->name));

        for (u8 i = 0; i < ARRAY_SIZE(io); i++) {
                if (io[i].name[0]) {
                        continue;
                }
                strcpy(&io[i].name[0], name);
                io[i].read = read_;
                io[i].write = write_;
                io[i].toggle = toggle_;
                io[i].highz = highz_;
                self = &io[i];
                PRINTF("[IO] create %s success.", self->name);
                return (0);
        }
        return (-1);
}
