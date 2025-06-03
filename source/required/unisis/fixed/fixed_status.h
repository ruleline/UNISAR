/**
 * @file fixed_status.h
 * @brief fixed status.
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-06-02
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-06-03
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-06-02 |    ruleline    | initial commit
 * -----------------------------------------------------------------------------
 */

#if !defined FIXED_STATUS_H
#define FIXED_STATUS_H

/**
 * @brief status.
 * @details
 * this enumeration represents the status of an operation.
 */
enum STATUS {
        /** timeout. */
        STATUS_TIMEOUT = -9,
        /** not supported */
        STATUS_NOT_SUPPORTED = -8,
        /** not implemented */
        STATUS_NOT_IMPLEMENTED = -7,
        /** null pointer */
        STATUS_NULL_POINTER = -6,
        /** unknown status */
        STATUS_UNKNOWN = -5,
        /** underflow */
        STATUS_UNDERFLOW = -4,
        /** overflow */
        STATUS_OVERFLOW = -3,
        /** invalid status */
        STATUS_INVALID = -2,
        /** error */
        STATUS_ERROR = -1,
        /** ok */
        STATUS_OK = 0,
        /** busy */
        STATUS_BUSY = 1,
};

#endif /* !defined FIXED_STATUS_H */
