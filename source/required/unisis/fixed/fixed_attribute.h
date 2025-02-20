/**
 * @file fixed_attribute.h
 * @brief fixed_attribute
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-19
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-20
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-02-19 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#if !defined FIXED_ATTRIBUTE_H
#define FIXED_ATTRIBUTE_H

#define __used          __attribute__((__used__))
#define __unused        __attribute__((__unused__))
#define __packed        __attribute__((__packed__))
#define __aligned(x)    __attribute__((aligned(x)))
#define __force_inline  __attribute__((__always_inline__))
#define __section(x)    __attribute__((__section__(x)))
#define __first         __attribute__((constructor))    /**< 早于__ctor(x)执行 */
#define __last          __attribute__((destructor))     /**< 晚于__dtor(x)执行 */
#define __ctor(x)       __attribute__((constructor(x))) /**< x越小越早执行,x=[101,65535] */
#define __dtor(x)       __attribute__((destructor(x)))  /**< x越小越晚执行,x=[101,65535] */

#endif /* !defined FIXED_ATTRIBUTE_H */
