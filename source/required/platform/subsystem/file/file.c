/**
 * @file file.c
 * @brief file
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-03-03
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-03-03
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-03-03 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#include "file.h"

static struct FILE file[FILE_MAX];

static __force_inline i32 open_(struct FILE *self)
{
        /* TODO */
        return (0);
}

static __force_inline i32 close_(struct FILE *self)
{
        /* TODO */
        return (0);
}

static __force_inline i32 read_(struct FILE *self, struct FILE_PACKAGE *package)
{
        /* TODO */
        return (0);
}

static __force_inline i32 write_(struct FILE *self, struct FILE_PACKAGE *package)
{
        /* TODO */
        return (0);
}

static __force_inline i32 erase_(struct FILE *self)
{
        /* TODO */
        return (0);
}

static __ctor(FILE1_PRIORITY) void init1_(void)
{
        struct FILE *self = &file[FILE_ALL];
        static char *name = "file-all";
        static struct OBJECT super;

        /* TODO */
        super.name = name;
        super.open = &open_;
        super.close = &close_;
        super.read = &read_;
        super.write = &write_;
        self->super = &super;
        self->erase = &erase_;
        PRINTF("[FILE] init %s successfully", file_name_(self));
}

static __dtor(FILE1_PRIORITY) void deinit1_(void)
{
        struct FILE *self = &file[FILE_ALL];

        /* TODO */
        PRINTF("[FILE] deinit %s successfully", file_name_(self));
}

i32 file_create(struct FILE *self, u8 id)
{
        ASSERT(self);
        ASSERT(id < ARRAY_SIZE(file));

        self = &file[id];
        PRINTF("[FILE] create %s successfully", file_name_(self));
        return (0);
}
