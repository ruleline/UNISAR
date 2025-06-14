/**
 * @file file.h
 * @brief FILE module.
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-03-03
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-06-14
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-03-03 |    ruleline    | initial commit.
 * -----------------------------------------------------------------------------
 */

#if !defined FILE_H
#define FILE_H

#include "unisis.h"

/**
 * @brief the identifier for file objects.
 * @details
 * this enum defines the identifiers for file objects.
 */
enum FILE_ID {
        /** all file objects. */
        FILE_ALL,
        /** the maximum number of file objects. */
        FILE_MAX,
};

/**
 * @brief file package.
 * @details
 * this struct defines the file package.
 */
struct FILE_PACKAGE {
        /** the buffer of the file package. */
        u8 *data;
        /** the length of the file package. */
        usize length;
};

/**
 * @brief file object.
 * @details
 * this struct defines a file object.
 */
struct FILE {
        /** the parent object of this object. */
        struct OBJECT *super;
        /** the erase function of the file. */
        i32 (*erase)(struct FILE *self);
};

/**
 * @brief get the name of the file.
 * @details
 * this function gets the name of the file.
 * @param[in] self the file object.
 * @return the name of the file.
 */
static __force_inline char *file_name(struct FILE *self)
{
        return object_name((struct OBJECT *)self);
}

/**
 * @brief open the file.
 * @details
 * this function opens the file.
 * @param[in] self the file object.
 * @return the status of opening the file.
 */
static __force_inline i32 file_open(struct FILE *self)
{
        return object_open((struct OBJECT *)self);
}

/**
 * @brief close the file.
 * @details
 * this function closes the file.
 * @param[in] self the file object.
 * @return the status of closing the file.
 */
static __force_inline i32 file_close(struct FILE *self)
{
        return object_close(self);
}

/**
 * @brief read from the file.
 * @details
 * this function reads from the file.
 * @param[in] self the file object.
 * @param[out] package the file package.
 * @return the status of reading from the file.
 */
static __force_inline i32 file_read(struct FILE *self,
                                        struct FILE_PACKAGE *package)
{
        return object_read((struct OBJECT *)self, package);
}

/**
 * @brief write to the file.
 * @details
 * this function writes to the file.
 * @param[in] self the file object.
 * @param[in] package the file package.
 * @return the status of writing to the file.
 */
static __force_inline i32 file_write(struct FILE *self,
                                        struct FILE_PACKAGE *package)
{
        return object_write((struct OBJECT *)self, package);
}

/**
 * @brief erase the file.
 * @details
 * this function erases the file.
 * @param[in] self the file object.
 * @return the status of erasing the file.
 */
static __force_inline i32 file_erase(struct FILE *self)
{
        return self->erase(self);
}

/**
 * @brief create a file object.
 * @details
 * this function creates a file object.
 * @param[in] self the file object.
 * @param[in] id the id of the file.
 * @return the status of creating the file.
 */
i32 file_create(struct FILE *self, u8 id);

#endif /* !defined FILE_H */
