/**
 * @file can.h
 * @brief can
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-18
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-02-24
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

/**
 * @enum CAN_TYPE
 * @brief 定义不同类型的 CAN (Controller Area Network).
 * @details 此枚举列出了几种常见的 CAN 类型，用于区分不同的 CAN 总线协议或特性.
 */
enum CAN_TYPE {
        /**
         * @brief 经典 CAN
         * @details 代表经典 CAN 协议, 具有基本的功能和数据传输能力.
         */
        CAN_COM,
        /**
         * @brief CANFD
         * @details 这种类型的 CAN 具备更灵活的配置选项和更高的性能.
         */
        CANFD_COM,
        /**
         * @brief CANXL
         * @details 扩展 CAN 通常支持更多的功能和更大的数据传输量.
         */
        CANXL_COM,
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
        /**
         * @var CAN::name
         * @brief 名称
         * @details 用于存储 CAN 对象的名称, 方便在系统中识别和区分不同的 CAN 对象.
         */
        char name[20];

        /**
         * @var CAN::type
         * @brief 类型
         * @details 用于表示 CAN 对象的类型, 不同的类型可能对应不同的 CAN 协议版本或硬件特性.
         */
        u8 type;

        /**
         * @var CAN::send
         * @brief 发送
         * @details 用于通过 CAN 对象发送数据包的函数.
         * @param[in] self CAN 对象
         * @param[in] package 数据包
         * @return 结果
         * @retval 0 成功
         */
        i32 (*send)(struct CAN *self, struct CAN_PACKAGE *package);

        /**
         * @var CAN::receive
         * @brief 接收
         * @details 用于从 CAN 对象接收数据包的函数.
         * @param[in] self CAN 对象
         * @param[out] package 数据包
         * @return 结果
         * @retval 0 成功
         */
        i32 (*receive)(struct CAN *self, struct CAN_PACKAGE *package);
};

/**
 * @brief 发送
 * @param[in] self CAN 对象
 * @param[in] package 数据包
 * @return 结果
 * @retval 0 成功
 */
static __force_inline i32 can_send_(struct CAN *self, struct CAN_PACKAGE *package)
{
        return self->send(self, package);
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
        return self->receive(self, package);
}

/**
 * @brief 创建一个 CAN 对象
 * @details 该函数用于初始化一个 CAN 对象, 并为其指定名称.
 * @param[out] self CAN 对象
 * @param[in] name 名称
 * @param[in] type 类型
 * @return 结果
 * @retval 0 成功
 */
i32 can_create(struct CAN *self, char *name, u8 type);

#endif /* !defined CAN_H */
