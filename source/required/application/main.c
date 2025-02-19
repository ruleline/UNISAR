/**
 * @file main.c
 * @brief main
 * @author ruleline (ruleline@outlook.com)
 * @since 2024-04-02
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-19
 * @version 0.00.001
 *
 * @copyright ©2024 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |       by       |              comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2024-08-18 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#include "unisis.h"

/**
 * @brief 程序的入口函数.
 * @details 此函数作为程序执行的起始点.
 *          调用 kernel_start_ 函数启动内核, 然后返回 0 表示程序正常结束.
 * @return 始终返回 0, 表示程序成功执行.
 */
int main(void)
{
        kernel_start_();
        return (0);
}
