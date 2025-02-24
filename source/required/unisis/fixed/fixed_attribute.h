/**
 * @file fixed_attribute.h
 * @brief fixed_attribute
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-19
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
 *   0.00.001   | 2025-02-19 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#if !defined FIXED_ATTRIBUTE_H
#define FIXED_ATTRIBUTE_H

/**
 * @def __used
 * @brief 标记符号为已使用，防止编译器优化掉未显式引用的符号。
 * @details 在某些情况，代码中符号虽未直接引用，但可能运行时使用。 编译器优化可能移除它们，
 *          用此宏可保留符号。如插件系统，插件入口函数编译时未显式引用，可用此宏保留。
 */
#define __used          __attribute__((__used__))

/**
 * @def __unused
 * @brief 标记符号为未使用，避免编译器产生未使用变量或参数的警告。
 * @details 开发中可能有暂未使用的变量或参数，编译器会警告。使用此宏可抑制警告，
 *          如回调函数某些参数未用，用此宏避免警告。
 */
#define __unused        __attribute__((__unused__))

/**
 * @def __packed
 * @brief 指示编译器对结构体或联合体进行紧凑打包，取消字节对齐。
 * @details 为提高内存访问效率，编译器通常对结构体成员字节对齐，会增加内存占用。
 *          用此宏取消对齐，节省内存，但可能降低访问效率。
 */
#define __packed        __attribute__((__packed__))

/**
 * @def __aligned(x)
 * @brief 指定变量、结构体或联合体的内存对齐字节数。
 * @details 内存对齐可提高访问效率，不同处理器要求不同。用此宏可手动指定对齐字节数，
 *          参数 `x` 表示期望字节数。如高性能计算场景，需特定对齐。
 */
#define __aligned(x)    __attribute__((aligned(x)))

/**
 * @def __force_inline
 * @brief 强制编译器将函数内联展开。
 * @details 函数调用有开销，编译器会按需内联。用此宏可强制展开，减少调用开销，但会增加代码体积。
 */
#define __force_inline  __attribute__((__always_inline__))

/**
 * @def __section(x)
 * @brief 将变量或函数放置到指定的节（section）中。
 * @details 链接时目标文件代码和数据会组织到不同节。用此宏可将变量或函数放到指定节 `x` 中，
 *          如嵌入式系统编程或自定义加载器场景。
 */
#define __section(x)    __attribute__((__section__(x)))

/**
 * @def __first
 * @brief 标记函数为构造函数，在程序初始化时优先执行。
 * @details 程序启动时，有些全局初始化操作需在 `main` 前完成。
 *          用此宏标记的函数会在初始化阶段优先执行，可进行全局变量或硬件设备初始化。
 *          早于__ctor(x)执行。
 */
#define __first         __attribute__((constructor))

/**
 * @def __last
 * @brief 标记函数为析构函数，在程序退出时执行。
 * @details 程序正常退出时，需进行资源清理操作。用此宏标记的函数会在退出时执行，确保资源正确释放。
 *          晚于__dtor(x)执行。
 */
#define __last          __attribute__((destructor))

/**
 * @def __ctor(x)
 * @brief 标记函数为具有特定优先级的构造函数。
 * @details 复杂程序中多个构造函数可能有执行顺序要求。此宏参数 `x` 表示优先级，值越小越先执行，
 *          可精确控制初始化顺序。x越小越早执行,x=[101,65535]。
 */
#define __ctor(x)       __attribute__((constructor(x)))

/**
 * @def __dtor(x)
 * @brief 标记函数为具有特定优先级的析构函数。
 * @details 程序退出时多个析构函数可能有执行顺序要求。此宏参数 `x` 表示优先级，值越小越先执行，
 *          确保资源按顺序释放。x越小越晚执行,x=[101,65535]。
 */
#define __dtor(x)       __attribute__((destructor(x)))

#endif /* !defined FIXED_ATTRIBUTE_H */
