/**
 * @file io.h
 * @brief io
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-18
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-26
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

enum IO_ID {
        IO_3V3,
        IO_MAX,
};

struct IO {
        char *name;
        u8 type;
        bool (*read)(struct IO *self);
        i32 (*write)(struct IO *self, bool state);
        i32 (*toggle)(struct IO *self);
        i32 (*highz)(struct IO *self);
};

static __force_inline bool io_read_(struct IO *self)
{
        return self->read(self);
}

static __force_inline i32 io_write_(struct IO *self, bool state)
{
        return self->write(self, state);
}

static __force_inline i32 io_toggle_(struct IO *self)
{
        return self->toggle(self);
}

static __force_inline i32 io_highz_(struct IO *self)
{
        return self->highz(self);
}

i32 io_create(struct IO *self, u8 id);

#endif /* !defined IO_H */
