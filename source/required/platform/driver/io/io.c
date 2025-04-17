/**
 * @file io.c
 * @brief io
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-18
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-04-17
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

enum IO_TYPE {
        IO_INPUT,
        IO_OUTPUT,
};

enum IO_NAME_LENGTH {
        IO_3V3_NAME_LENGTH = 20,
};

static struct IO io[IO_MAX];

static bool read_(struct IO *self, bool *state)
{
        /* TODO */
        PRINTF("[IO] read %s successfully", io_name_(self));
        return (*state);
}

static i32 write_(struct IO *self, bool state)
{
        /* TODO */
        PRINTF("[IO] write %s successfully", io_name_(self));
        return (0);
}

static i32 toggle_(struct IO *self)
{
        /* TODO */
        PRINTF("[IO] toggle %s successfully", io_name_(self));
        return (0);
}

static i32 highz_(struct IO *self)
{
        /* TODO */
        PRINTF("[IO] highz %s successfully", io_name_(self));
        return (0);
}

static __ctor(IO1_PRIORITY) void init1_(void)
{
        struct IO *self = &io[IO_3V3];
        static struct OBJECT super;

        /* TODO */

        super.name = "io-3v3";
        super.open = 0;
        super.close = 0;
        super.read = &read_;
        super.write = &write_;
        self->super = &super;
        self->type = IO_INPUT;
        self->toggle = &toggle_;
        self->highz = &highz_;
        PRINTF("[IO] init %s successfully", io_name_(self));
}

static __dtor(IO1_PRIORITY) void deinit1_(void)
{
        struct IO *self = &io[IO_3V3];

        /* TODO */
        PRINTF("[IO] deinit %s successfully", io_name_(self));
}

i32 io_create(struct IO *self, u8 id)
{
        ASSERT(self);
        ASSERT(id < ARRAY_SIZE(io));

        self = &io[id];
        PRINTF("[IO] create %s successfully", io_name_(self));
        return (0);
}
