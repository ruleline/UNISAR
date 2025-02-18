/**
 * @file init.c
 * @brief init
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-10
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-18
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
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

extern i32 __initcall_start[];          /**< 分区始端 */
extern i32 __initcall_0_start[];        /**< 分区 0 */
extern i32 __initcall_1_start[];        /**< 分区 1 */
extern i32 __initcall_2_start[];        /**< 分区 2 */
extern i32 __initcall_3_start[];        /**< 分区 3 */
extern i32 __initcall_4_start[];        /**< 分区 4 */
extern i32 __initcall_5_start[];        /**< 分区 5 */
extern i32 __initcall_6_start[];        /**< 分区 6 */
extern i32 __initcall_7_start[];        /**< 分区 7 */
extern i32 __initcall_end[];            /**< 分区末端 */

static i32 *initcall_levels[] __initdata = {
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

/**
 * @brief 初始化模块
 *
 * @param[in] func 模块
 * @return 结果
 * @retval 0 成功
 */
static inline i32 __init do_one_initcall_(initcall_t func)
{
        i32 result = 0;

        result = func();
        return (result);
}

/**
 * @brief 初始化分区
 *
 * @param[in] level 等级
 * @return 结果
 * @retval 0 成功
 */
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

/**
 * @brief 初始化所有分区
 *
 * @return 结果
 * @retval 0 成功
 */
static inline i32 __init do_initcalls_(void)
{
        for (i32 level = 0; level < ARRAY_SIZE(initcall_levels) - 1; level++) {
                do_initcall_level_(level);
        }
        return (0);
}

/**
 * @brief 初始化
 *
 * @return 结果
 * @retval 0 成功
 */
i32 __init init(void)
{
        i32 result = 0;

        result = do_initcalls_();
        return (result);
}
