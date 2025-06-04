/**
 * @file fixed_attribute.h
 * @brief fixed_attribute
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-19
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2025-06-04
 * @version 0.00.001
 *
 * @copyright ©2025 UNISAR
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |     author     |             comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2025-02-19 |    ruleline    | initial commit
 * -----------------------------------------------------------------------------
 */

#if !defined FIXED_ATTRIBUTE_H
#define FIXED_ATTRIBUTE_H

/**
 * @brief mark a symbol as weak to allow overriding it in other translation units.
 * @details
 * this macro can be used to mark variables or functions that are intended to be
 * overridden in other translation units. when a symbol is marked as weak, it can
 * be overridden by a symbol with the same name in a different translation unit.
 */
#define __weak          __attribute__((__weak__))
/**
 * @brief mark a symbol as used to prevent the compiler from optimizing out unused symbols.
 * @details
 * in some cases, a symbol may not be directly referenced in the code but could
 * be used at runtime. compiler optimizations may remove them, and this macro
 * can be used to keep the symbol. for example, in a plugin system, the plugin
 * entry function may not be explicitly referenced at compile time, and this
 * macro can be used to keep it.
 */
#define __used          __attribute__((__used__))
/**
 * @brief mark a symbol as unused to prevent compiler warnings about unused symbols.
 * @details
 * this macro can be used to mark variables or functions that are intentionally
 * not used in the code, preventing compiler warnings about unused symbols.
 */
#define __unused        __attribute__((__unused__))
/**
 * @brief mark a symbol as weak to allow overriding it in other translation units.
 * @details
 * this macro can be used to mark variables or functions that are intended to be
 * overridden in other translation units. when a symbol is marked as weak, it can
 * be overridden by a symbol with the same name in a different translation unit.
 */
#define __packed        __attribute__((__packed__))
/**
 * @brief mark a symbol as aligned to a specific boundary.
 * @details
 * this macro can be used to mark variables or functions that are aligned to a
 * specific boundary. the boundary is specified as an argument to the macro. for
 * example, __aligned(4) can be used to mark a variable as aligned to a 4-byte
 * boundary.
 * @param[in] x the alignment boundary in bytes.
 */
#define __aligned(x)    __attribute__((aligned(x)))
/**
 * @brief mark a function as always inline to suggest the compiler to inline it.
 * @details
 * this macro can be used to suggest the compiler to inline a function, meaning
 * that the function's code will be inserted at each call site instead of being
 * called through a function call. this can improve performance by eliminating
 * the overhead of a function call.
 */
#define __force_inline  __attribute__((__always_inline__))
/**
 * @brief mark a symbol as section to specify the section in which it should be placed.
 * @details
 * this macro can be used to specify the section in which a symbol should be placed.
 * the section is specified as an argument to the macro. for example, __section(".text")
 * can be used to place a symbol in the ".text" section.
 * @param[in] x the section name.
 */
#define __section(x)    __attribute__((__section__(x)))
/**
 * @brief mark a function to be called before the main function.
 * @details
 * this macro can be used to mark a function that should be called before the main
 * function is executed. this is useful for initialization code that needs to run
 * before the main program starts.
 */
#define __first         __attribute__((constructor))
/**
 * @brief mark a function to be called after the main function.
 * @details
 * this macro can be used to mark a function that should be called after the main
 * function has completed. this is useful for cleanup code that needs to run
 * after the main program has finished executing.
 */
#define __last          __attribute__((destructor))
/**
 * @brief mark a symbol as constructor to specify the order in which it should be executed.
 * @details
 * this macro can be used to specify the order in which a symbol should be executed.
 * the order is specified as an argument to the macro. for example, __ctor(100)
 * can be used to specify that a symbol should be executed before other symbols
 * with a higher order. this is useful for initialization functions that need to
 * be executed before other functions in the same translation unit.
 * @param[in] x the order of execution.
 */
#define __ctor(x)       __attribute__((constructor(x)))
/**
 * @brief mark a symbol as destructor to specify the order in which it should be executed.
 * @details
 * this macro can be used to specify the order in which a symbol should be executed.
 * the order is specified as an argument to the macro. for example, __dtor(100)
 * can be used to specify that a symbol should be executed after other symbols
 * with a lower order. this is useful for cleanup functions that need to be
 * executed after other functions in the same translation unit.
 * @param[in] x the order of execution.
 */
#define __dtor(x)       __attribute__((destructor(x)))

#endif /* !defined FIXED_ATTRIBUTE_H */
