/**
 * @file can.c
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

#include "can.h"

/**
 * @brief 定义一个包含 1 个 CAN 对象的静态数组。
 * @details 可用于表示系统中的 1 个不同 CAN 对象.
 *          每个对象可以独立配置和操作, 以满足不同的 CAN 通信需求.
 */
static struct CAN can[1];

/**
 * @defgroup CANInitialization CAN 设备初始化
 * @brief 包含用于初始化 CAN 设备的函数.
 * @details 在系统启动阶段被调用, 用于对 CAN 设备进行必要的配置和初始化操作.
 */

/**
 * @defgroup CANDeinitialization CAN 设备反初始化
 * @brief 包含用于对 CAN 设备进行反初始化操作的函数.
 * @details 在系统关闭或不再需要使用 CAN 设备时被调用, 用于释放资源、恢复默认设置等.
 */

/**
 * @brief 以 CAN1 的优先级执行初始化操作.
 * @details 使用 __ctor 机制, 会在程序启动阶段按照 CAN1_PRIORITY 指定的优先级执行初始化操作.
 *          主要用于对 CAN1 设备进行初始化, 可能包括设置波特率、配置寄存器、启用中断等操作.
 * @ingroup CANInitialization
 */
static __ctor(CAN1_PRIORITY) void init1_(void)
{
        /* TODO */
}

/**
 * @brief 以 CAN1 的优先级执行反初始化操作.
 * @details 利用 __dtor 机制, 会在程序结束阶段按照 CAN1_PRIORITY 指定的优先级执行反初始化操作.
 *          主要用于对 CAN1 设备进行反初始化, 可能包括停止数据传输、关闭相关中断、释放占用的资源等操作.
 * @ingroup CANDeinitialization
 */
static __dtor(CAN1_PRIORITY) void deinit1_(void)
{
        /* TODO */
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
        ASSERT(package->length <= 8);
        ASSERT(package->data);

        /* TODO */
        return 0;
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

        /* TODO */
        return 0;
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
        ASSERT(package->length <= 64);
        ASSERT(package->data);

        /* TODO */
        return 0;
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

        /* TODO */
        return 0;
}


/**
 * @brief 创建一个 CAN 对象
 * @details 该函数用于初始化一个 CAN 对象, 并为其指定名称.
 * @param[out] self CAN 对象
 * @param[in] name 名称
 * @param[in] type 类型
 * @return 结果
 * @retval -1 CAN 对象已满
 * @retval 0 成功
 */
i32 can_create(struct CAN *self, char *name, u8 type)
{
        ASSERT(self);
        ASSERT(name);
        ASSERT(strlen(name));
        ASSERT(strlen(name) < sizeof(self->name));
        ASSERT((type == CAN_COM) || (type == CANFD_COM));

        for (u8 i = 0; i < ARRAY_SIZE(can); i++) {
                if (can[i].name[0]) {
                        continue;
                }
                strcpy(&can[i].name[0], name);
                can[i].type = type;
                if (type == CAN_COM) {
                        can[i].send = send_classic_;
                        can[i].receive = receive_classic_;
                } else {
                        can[i].send = send_flexible_;
                        can[i].receive = receive_flexible_;
                }
                self = &can[i];
                PRINTF("[CAN] create %s success.", self->name);
                return 0;
        }
        return -1;
}
