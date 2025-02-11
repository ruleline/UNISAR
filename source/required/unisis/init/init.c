/**
 * @file init.c
 * @brief init
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-10
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-11
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @todo 1. 引入 linux initcall 机制
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-02-10 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#include "init.h"

#define __initdata __section(".init.data")

typedef i32 initcall_entry_t;

extern initcall_entry_t __initcall_start[];
extern initcall_entry_t __initcall_0_start[];
extern initcall_entry_t __initcall_1_start[];
extern initcall_entry_t __initcall_2_start[];
extern initcall_entry_t __initcall_3_start[];
extern initcall_entry_t __initcall_4_start[];
extern initcall_entry_t __initcall_5_start[];
extern initcall_entry_t __initcall_6_start[];
extern initcall_entry_t __initcall_7_start[];
extern initcall_entry_t __initcall_end[];

static initcall_entry_t *initcall_levels[] __initdata = {
	__initcall_0_start,
	__initcall_1_start,
	__initcall_2_start,
	__initcall_3_start,
	__initcall_4_start,
	__initcall_5_start,
	__initcall_6_start,
	__initcall_7_start,
	__initcall_end,
};

static inline i32 __init do_one_initcall_(initcall_t func)
{
        i32 result = 0;

        result = func();
        return (result);
}

static inline i32 __init do_initcall_level_(i32 level)
{
        for (initcall_t *func = (initcall_t *)initcall_levels[level];
                func < (initcall_t *)initcall_levels[level+1]; func++) {
                if (*func) {
                        do_one_initcall_(*func);
                }
        }
        return (0);
}

static inline i32 __init do_initcalls_(void)
{
        for (i32 level = 0; level < ARRAY_SIZE(initcall_levels) - 1; level++) {
                do_initcall_level_(level);
        }
        return (0);
}

i32 __init init(void)
{
        i32 result = 0;

        result = do_initcalls_();
        return (result);
}
