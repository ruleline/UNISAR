/**
 * @file object.c
 * @brief OBJECT.
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-06-09
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-06-09
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-06-09 |    ruleline    | initial commit.
 * -----------------------------------------------------------------------------
 */

#include "object.h"

/**
 * @brief object max count.
 * @details
 * this constant represents the maximum number of objects that can be created.
 */
#define OBJECT_MAX_COUNT (50)

/**
 * @brief object set.
 * @details
 * this structure represents an object set.
 */
static struct OBJECT object[OBJECT_MAX_COUNT];

/**
 * @brief create an object.
 * @details
 * this function creates an object.
 * @param[in] name the name of the object.
 * @param[in] open the open function.
 * @param[in] close the close function.
 * @param[in] read the read function.
 * @param[in] write the write function.
 * @return a pointer to the created object.
 */
struct OBJECT *object_create(char *name,
                                i32 (*open)(struct OBJECT *),
                                i32 (*close)(struct OBJECT *),
                                i32 (*read)(struct OBJECT *, void *),
                                i32 (*write)(struct OBJECT *, void *))
{
        ASSERT(name);

        for (usize i = 0; i < OBJECT_MAX_COUNT; i++) {
                if (!object[i].name) {
                        object[i].name = name;
                        object[i].open = open;
                        object[i].close = close;
                        object[i].read = read;
                        object[i].write = write;
                        return (&object[i]);
                }
        }
        return (0);
}

/**
 * @brief destroy an object.
 * @details
 * this function destroys an object.
 * @param[in,out] self the object to destroy.
 * @return status of the operation.
 */
i32 object_destroy(struct OBJECT *self)
{
        if (!self) {
                memory_clear(self, sizeof(struct OBJECT));
        }
        return (0);
}
