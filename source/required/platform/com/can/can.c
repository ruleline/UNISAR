/**
 * @file can.c
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
 * @defgroup CAN-INIT CAN 设备初始化
 * @defgroup CAN-DEINIT CAN 设备反初始化
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-02-18 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#include "can.h"

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

enum CAN_NAME_LENGTH {
        CAN_COCKPIT_NAME_LENGTH = 20,
};

enum CAN_DATA_LENGTH {
        CLASSIC_CAN_DATA_LENGTH = 8,
        FLEXIBLE_CAN_DATA_LENGTH = 64,
};

/**
 * @brief 定义一个包含 1 个 CAN 对象的静态数组。
 * @details 可用于表示系统中的 1 个不同 CAN 对象.
 *          每个对象可以独立配置和操作, 以满足不同的 CAN 通信需求.
 */
static struct CAN can[CAN_MAX];

static i32 open_(struct CAN *self)
{
        self->is_open = 1;
        PRINTF("[CAN] open %s successfully", can_name_(self));
        return (0);
}

static i32 close_(struct CAN *self)
{
        self->is_open = 0;
        PRINTF("[CAN] close %s successfully", can_name_(self));
        return (0);
}

/**
 * @brief 发送经典 CAN 报文
 * @param[in] self CAN 对象
 * @param[in] package 数据包
 * @return 结果
 * @retval 0 成功
 */
static i32 send_classic_(struct CAN *self, struct CAN_PACKAGE *package)
{
        ASSERT(self->type == CAN_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->length <= CLASSIC_CAN_DATA_LENGTH);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[CAN] send %s successfully", can_name_(self));
        return (0);
}

/**
 * @brief 接收经典 CAN 报文
 * @param[in] self CAN 对象
 * @param[out] package 数据包
 * @return 结果
 * @retval 0 成功
 */
static i32 receive_classic_(struct CAN *self, struct CAN_PACKAGE *package)
{
        ASSERT(self->type == CAN_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[CAN] receive %s successfully", can_name_(self));
        return (0);
}

/**
 * @brief 发送 CANFD 报文
 * @param[in] self CAN 对象
 * @param[in] package 数据包
 * @return 结果
 * @retval 0 成功
 */
static i32 send_flexible_(struct CAN *self, struct CAN_PACKAGE *package)
{
        ASSERT(self->type == CANFD_COM);
        ASSERT(package);
        ASSERT(package->length);
        ASSERT(package->length <= FLEXIBLE_CAN_DATA_LENGTH);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[CAN] send %s successfully", can_name_(self));
        return (0);
}

/**
 * @brief 接收 CANFD 报文
 * @param[in] self CAN 对象
 * @param[out] package 数据包
 * @return 结果
 * @retval 0 成功
 */
static i32 receive_flexible_(struct CAN *self, struct CAN_PACKAGE *package)
{
        ASSERT(self->type == CANFD_COM);
        ASSERT(package);
        ASSERT(package->data);

        if (!self->is_open) {
                return (-1);
        }

        /* TODO */
        PRINTF("[CAN] receive %s successfully", can_name_(self));
        return (0);
}

/**
 * @brief 以 CAN1 的优先级执行初始化操作.
 * @details 使用 __ctor 机制, 会在程序启动阶段按照 CAN1_PRIORITY 指定的优先级执行初始化操作.
 *          主要用于对 CAN1 设备进行初始化, 可能包括设置波特率、配置寄存器、启用中断等操作.
 * @ingroup CAN-INIT
 */
static __ctor(CAN1_PRIORITY) void init1_(void)
{
        struct CAN *self = &can[CAN_COCKPIT];
        static char name[CAN_COCKPIT_NAME_LENGTH];
        static struct OBJECT super;

        /* TODO */

        memset(&name[0], '\0', sizeof(name));
        strncpy(&name[0], "can-cockpit", sizeof(name));
        super.name = &name[0];
        super.open = open_;
        super.close = close_;
        super.write = send_classic_;
        super.read = receive_classic_;
        self->super = &super;
        self->type = CAN_COM;
        self->is_open = 0;
        PRINTF("[CAN] init %s successfully", can_name_(self));
}

/**
 * @brief 以 CAN1 的优先级执行反初始化操作.
 * @details 利用 __dtor 机制, 会在程序结束阶段按照 CAN1_PRIORITY 指定的优先级执行反初始化操作.
 *          主要用于对 CAN1 设备进行反初始化, 可能包括停止数据传输、关闭相关中断、释放占用的资源等操作.
 * @ingroup CAN-DEINIT
 */
static __dtor(CAN1_PRIORITY) void deinit1_(void)
{
        struct CAN *self = &can[CAN_COCKPIT];

        /* TODO */
        PRINTF("[CAN] deinit %s successfully", can_name_(self));
}

/**
 * @brief 创建一个 CAN 对象
 * @details 该函数用于初始化一个 CAN 对象, 并为其指定名称.
 * @param[out] self CAN 对象
 * @param[in] id 标识符
 * @return 结果
 * @retval -1 CAN 对象已满
 * @retval 0 成功
 */
i32 can_create(struct CAN *self, u8 id)
{
        ASSERT(self);
        ASSERT(id < ARRAY_SIZE(can));

        self = &can[id];
        PRINTF("[CAN] create %s successfully", can_name_(self));
        return (0);
}
