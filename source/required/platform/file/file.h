/**
 * @file file.h
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

#if !defined FILE_H
#define FILE_H

#include "unisis.h"

enum FILE_ID {
        FILE_ALL,
        FILE_MAX,
};

struct FILE_PACKAGE {
        u8 *data;
        usize length;
};

struct FILE {
        struct OBJECT *super;
        i32 (*erase)(struct FILE *self);
};

static __force_inline char *file_name_(struct FILE *self)
{
        return (object_name_(self));
}

static __force_inline i32 file_open_(struct FILE *self)
{
        return (object_open_(self));
}

static __force_inline i32 file_close_(struct FILE *self)
{
        return (object_close_(self));
}

static __force_inline i32 file_read_(struct FILE *self,
                                        struct FILE_PACKAGE *package)
{
        return (object_read_(self, package));
}

static __force_inline i32 file_write_(struct FILE *self,
                                        struct FILE_PACKAGE *package)
{
        return (object_write_(self, package));
}

static __force_inline i32 file_erase_(struct FILE *self)
{
        return (self->erase(self));
}

i32 file_create(struct FILE *self, u8 id);

#endif /* !defined FILE_H */
