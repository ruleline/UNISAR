/**
 * @file init_config.h
 * @brief init
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-09
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-11
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-02-09 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#if !defined INIT_CONFIG_H
#define INIT_CONFIG_H

#include "config.h"

#if 0
ld 文件配置
SECTIONS {
        /* 其他段的定义... */

        .init.text : {
                *(.init.text)
                *(.initcall.early.data)
                *(.initcall.0.init)
                *(.initcall.1.init)
                *(.initcall.2.init)
                *(.initcall.3.init)
                *(.initcall.4.init)
                *(.initcall.5.init)
                *(.initcall.6.init)
                *(.initcall.7.init)
        }

        /* 其他段的定义... */
}
#endif

#define __init __section(".init.text")

#define __define_initcall(func, id)                                     \
                static initcall_t __initcall_##func##id __used          \
                __section(".initcall." #id ".init") = func

typedef i32 (*initcall_t)(void);

#endif /* !defined INIT_CONFIG_H */
