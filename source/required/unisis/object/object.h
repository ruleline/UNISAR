/**
 * @file object.h
 * @brief object
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-26
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-06-07
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-02-26 |    ruleline    | initial commit
 * -----------------------------------------------------------------------------
 */

#if !defined OBJECT_H
#define OBJECT_H

#include "unisis.h"

/**
 * @brief object structure.
 * @details
 * this structure represents an object.
 */
struct OBJECT {
        /** name of the object */
        char *name;
        /** open the object. */
        i32 (*open)(struct OBJECT *self);
        /** close the object. */
        i32 (*close)(struct OBJECT *self);
        /** read data from the object. */
        i32 (*read)(struct OBJECT *self, void *package);
        /** write data to the object. */
        i32 (*write)(struct OBJECT *self, void *package);
};

/**
 * @brief get the name of the object.
 * @details
 * this function returns the name of the given object.
 * @param[in] self a pointer to the `OBJECT` structure representing the target object.
 * @return a pointer to the name of the object.
 */
static __force_inline char *object_name(struct OBJECT *self)
{
        return self->name;
}

/**
 * @brief open the object.
 * @details
 * this function invokes the `open` method of the given object.
 * @param[in] self a pointer to the `OBJECT` structure representing the target object.
 * @return the result of the `open` operation.
 */
static __force_inline i32 object_open(struct OBJECT *self)
{
        return self->open(self);
}

/**
 * @brief close the object.
 * @details
 * this function invokes the `close` method of the given object.
 * @param[in] self a pointer to the `OBJECT` structure representing the target object.
 * @return the result of the `close` operation.
 */
static __force_inline i32 object_close(struct OBJECT *self)
{
        return self->close(self);
}

/**
 * @brief read data from the object.
 * @details
 * this function invokes the `read` method of the given object.
 * @param[in] self a pointer to the `OBJECT` structure representing the target object.
 * @param[out] package a pointer to the data package to be read from the object.
 * @return the result of the `read` operation.
 */
static __force_inline i32 object_read(struct OBJECT *self, void *package)
{
        return self->read(self, package);
}

/**
 * @brief write data to the object.
 * @details
 * this function invokes the `write` method of the given object.
 * @param[in] self a pointer to the `OBJECT` structure representing the target object.
 * @param[in] package a pointer to the data package to be written to the object.
 * @return the result of the `write` operation.
 */
static __force_inline i32 object_write(struct OBJECT *self, void *package)
{
        return self->write(self, package);
}

/**
 * @brief create a new Object.
 * @details
 * this function creates a new Object and initializes its members.
 * @param[out] self a pointer to a pointer to the Object structure to be created.
 * @param[in] name the name of the object.
 * @param[in] open the open function of the object.
 * @param[in] close the close function of the object.
 * @param[in] read the read function of the object.
 * @param[in] write the write function of the object.
 * @return the result of the operation.
 */
static __force_inline i32 object_create(struct OBJECT **self, char *name,
                                        i32 (*open)(struct OBJECT *),
                                        i32 (*close)(struct OBJECT *),
                                        i32 (*read)(struct OBJECT *, void *),
                                        i32 (*write)(struct OBJECT *, void *))
{
        ASSERT(*self);
        (*self)->name = name;
        (*self)->open = open;
        (*self)->close = close;
        (*self)->read = read;
        (*self)->write = write;
        return (0);
}

/**
 * @brief destroy an Object.
 * @param[in,out] self a pointer to a pointer to the Object structure to be destroyed.
 * @return the result of the operation.
 */
static __force_inline i32 object_destroy(struct OBJECT **self)
{
        ASSERT(*self);
        memory_clear(*self, sizeof(struct OBJECT));
        return (0);
}

#endif /* !defined OBJECT_H */
