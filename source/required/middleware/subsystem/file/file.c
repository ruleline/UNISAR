/**
 * @file file.c
 * @brief FILE module.
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-03-03
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-06-02
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

#include "file.h"

/**
 * @brief file objects.
 * @details
 * this array holds all file objects.
 */
static struct FILE file[FILE_MAX];

/**
 * @brief open the file.
 * @details
 * this function opens the file.
 * @param[in] self the file object.
 * @return the status of opening the file.
 */
static __force_inline i32 open(struct FILE *self)
{
        /* TODO */
        return (0);
}

/**
 * @brief close the file.
 * @details
 * this function closes the file.
 * @param[in] self the file object.
 * @return the status of closing the file.
 */
static __force_inline i32 close(struct FILE *self)
{
        /* TODO */
        return (0);
}

/**
 * @brief read from the file.
 * @details
 * this function reads from the file.
 * @param[in] self the file object.
 * @param[out] package the file package.
 * @return the status of reading from the file.
 */
static __force_inline i32 read(struct FILE *self, struct FILE_PACKAGE *package)
{
        /* TODO */
        return (0);
}

/**
 * @brief write to the file.
 * @details
 * this function writes to the file.
 * @param[in] self the file object.
 * @param[in] package the file package.
 * @return the status of writing to the file.
 */
static __force_inline i32 write(struct FILE *self, struct FILE_PACKAGE *package)
{
        /* TODO */
        return (0);
}

/**
 * @brief erase the file.
 * @details
 * this function erases the file.
 * @param[in] self the file object.
 * @return the status of erasing the file.
 */
static __force_inline i32 erase(struct FILE *self)
{
        /* TODO */
        return (0);
}

/**
 * @brief initialize file1.
 * @details
 * this function initializes file1.
 */
static __ctor(FILE1_PRIORITY) void init_file1(void)
{
        struct FILE *self = &file[FILE_ALL];
        static struct OBJECT super;

        /* TODO */
        super.name = "file-all";
        super.open = &open;
        super.close = &close;
        super.read = &read;
        super.write = &write;
        self->super = &super;
        self->erase = &erase;
        PRINTF("[FILE] init %s successfully", file_name(self));
}

/**
 * @brief deinitialize file1.
 * @details
 * this function deinitializes file1.
 */
static __dtor(FILE1_PRIORITY) void deinit_file1(void)
{
        struct FILE *self = &file[FILE_ALL];

        /* TODO */
        PRINTF("[FILE] deinit %s successfully", file_name(self));
}

/**
 * @brief create a file object.
 * @details
 * this function creates a file object.
 * @param[in] self the file object.
 * @param[in] id the id of the file.
 * @return the status of creating the file.
 */
i32 file_create(struct FILE *self, u8 id)
{
        ASSERT(self);
        ASSERT(id < ARRAY_SIZE(file));

        self = &file[id];
        PRINTF("[FILE] create %s successfully", file_name(self));
        return (0);
}
