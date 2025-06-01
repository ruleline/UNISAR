/**
 * @file fixed_type.h
 * @brief fixed_type
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-19
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-06-01
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-02-19 |    ruleline    | initial commit
 * -----------------------------------------------------------------------------
 */

#if !defined FIXED_TYPE_H
#define FIXED_TYPE_H

/**
 * @brief boolean type.
 * @details
 * this type is used to represent boolean values. it is defined as an unsigned
 * char type, which is 1 byte in size. the value 0 is considered false, and any
 * non-zero value is considered true.
 */
typedef _Bool                   bool;
/**
 * @brief signed char type.
 * @details
 * this type is used to represent signed characters. it is defined as a signed
 * char type, which is 1 byte in size. the range of values is -128 to 127.
 */
typedef signed char             i8;
/**
 * @brief signed short int type.
 * @details
 * this type is used to represent signed short integers. it is defined as a signed
 * short int type, which is 2 bytes in size. the range of values is -32768 to
 * 32767.
 */
typedef signed short int        i16;
/**
 * @brief signed int type.
 * @details
 * this type is used to represent signed integers. it is defined as a signed int
 * type, which is 4 bytes in size. the range of values is -2147483648 to
 * 2147483647.
 */
typedef signed int              i32;
/**
 * @brief signed long int type.
 * @details
 * this type is used to represent signed long integers. it is defined as a signed
 * long int type, which is 4 bytes in size. the range of values is -9223372036854775808
 * to 9223372036854775807.
 */
typedef signed long long int    i64;
/**
 * @brief signed long int type.
 * @details
 * this type is used to represent signed long integers. in the 32 bit platform,
 * this type is the same as i32. it is defined as a signed long int type, which
 * is 4 bytes in size. the range of values is -2147483648 to 2147483647. in the
 * 64 bit platform, this type is the same as i64. it is defined as a signed long
 * int type, which is 8 bytes in size. the range of values is -9223372036854775808
 * to 9223372036854775807.
 */
typedef signed long int         isize;
/**
 * @brief unsigned char type.
 * @details
 * this type is used to represent unsigned characters. it is defined as an unsigned
 * char type, which is 1 byte in size. the range of values is 0 to 255.
 */
typedef unsigned char           u8;
/**
 * @brief unsigned short int type.
 * @details
 * this type is used to represent unsigned short integers. it is defined as an
 * unsigned short int type, which is 2 bytes in size. the range of values is 0 to
 * 65535.
 */
typedef unsigned short int      u16;
/**
 * @brief unsigned int type.
 * @details
 * this type is used to represent unsigned integers. it is defined as an unsigned
 * int type, which is 4 bytes in size. the range of values is 0 to 4294967295.
 */
typedef unsigned int            u32;
/**
 * @brief unsigned long int type.
 * @details
 * this type is used to represent unsigned long integers. it is defined as an
 * unsigned long int type, which is 4 bytes in size. the range of values is 0 to
 * 18446744073709551615.
 */
typedef unsigned long long int  u64;
/**
 * @brief unsigned long int type.
 * @details
 * this type is used to represent unsigned long integers. in the 32 bit platform,
 * this type is the same as u32. it is defined as an unsigned long int type, which
 * is 4 bytes in size. the range of values is 0 to 4294967295. in the 64 bit
 * platform, this type is the same as u64. it is defined as an unsigned long int
 * type, which is 8 bytes in size. the range of values is 0 to 18446744073709551615.
 */
typedef unsigned long int       usize;
/**
 * @brief float type.
 * @details
 * this type is used to represent floating point numbers. it is defined as a float
 * type, which is 4 bytes in size. the range of values is -3.4e+38 to 3.4e+38.
 */
typedef float                   f32;
/**
 * @brief double type.
 * @details
 * this type is used to represent floating point numbers. it is defined as a double
 * type, which is 8 bytes in size. the range of values is -1.7e+308 to 1.7e+308.
 */
typedef double                  f64;

#endif /* !defined FIXED_TYPE_H */
