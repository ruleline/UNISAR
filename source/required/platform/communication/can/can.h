/**
 * @file can.h
 * @brief can
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-18
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-27
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-02-18 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#if !defined CAN_H
#define CAN_H

#include "unisis.h"

enum CAN_ID {
        CAN_COCKPIT,
        CAN_MAX,
};

/**
 * @struct CAN_PACKAGE
 * @brief CAN 数据包
 * @details 用于封装 CAN 数据包的数据及其长度.
 */
struct CAN_PACKAGE {
        /**
         * @var CAN_PACKAGE::data
         * @brief 数据
         * @details 用于存储 CAN 数据包的实际数据.
         */
        u8 *data;

        /**
         * @var CAN_PACKAGE::length
         * @brief 数据长度
         * @details 用于存储 CAN 数据包的实际数据长度.
         */
        usize length;
};

/**
 * @struct CAN
 * @brief CAN 对象
 * @details 此结构体用于封装 CAN 对象的相关信息和操作函数,
 *          方便对 CAN 对象进行统一管理和操作.
 */
struct CAN {
        struct OBJECT *super;

        /**
         * @var CAN::type
         * @brief 类型
         * @details 用于表示 CAN 对象的类型, 不同的类型可能对应不同的 CAN 协议版本或硬件特性.
         */
        u8 type;

        bool is_open;
};

static __force_inline char *can_name_(struct CAN *self)
{
        return (object_name_(self));
}

static __force_inline i32 can_open_(struct CAN *self)
{
        return (object_open_(self));
}

static __force_inline i32 can_close_(struct CAN *self)
{
        return (object_close_(self));
}

/**
 * @brief 发送
 * @param[in] self CAN 对象
 * @param[in] package 数据包
 * @return 结果
 * @retval 0 成功
 */
static __force_inline i32 can_send_(struct CAN *self, struct CAN_PACKAGE *package)
{
        return (object_write_(self, package));
}

/**
 * @brief 接收
 * @param[in] self CAN 对象
 * @param[out] package 数据包
 * @return 结果
 * @retval 0 成功
 */
static __force_inline i32 can_receive_(struct CAN *self, struct CAN_PACKAGE *package)
{
        return (object_read_(self, package));
}

/**
 * @brief 创建一个 CAN 对象
 * @details 该函数用于初始化一个 CAN 对象, 并为其指定名称.
 * @param[out] self CAN 对象
 * @param[in] id 标识符
 * @return 结果
 * @retval 0 成功
 */
i32 can_create(struct CAN *self, u8 id);

#endif /* !defined CAN_H */
