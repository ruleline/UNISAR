/**
 * @file object.h
 * @brief object
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-26
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-27
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-02-26 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#if !defined OBJECT_H
#define OBJECT_H

struct OBJECT {
        char *name;
        i32 (*open)(struct OBJECT *self);
        i32 (*close)(struct OBJECT *self);
        i32 (*read)(struct OBJECT *self, void *package);
        i32 (*write)(struct OBJECT *self, void *package);
};

static __force_inline char *object_name_(struct OBJECT *self)
{
        return (self->name);
}

static __force_inline i32 object_open_(struct OBJECT *self)
{
        return (self->open(self));
}

static __force_inline i32 object_close_(struct OBJECT *self)
{
        return (self->close(self));
}

static __force_inline i32 object_read_(struct OBJECT *self, void *package)
{
        return (self->read(self, package));
}

static __force_inline i32 object_write_(struct OBJECT *self, void *package)
{
        return (self->write(self, package));
}

#endif /* !defined OBJECT_H */
