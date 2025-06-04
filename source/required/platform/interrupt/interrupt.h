/**
 * @file interrupt.h
 * @brief Interrupt Service Routines (ISRs).
 * @author ruleline (ruleline@outlook.com)
 * @since 2025-02-25
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
 *   0.00.001   | 2025-02-25 |    ruleline    | initial commit.
 * -----------------------------------------------------------------------------
 */

#if !defined INTERRUPT_H
#define INTERRUPT_H

#include "unisis.h"

/**
 * @brief system timer ISR.
 * @details
 * this function is called by the system timer interrupt to increment the
 * system timer tick. it is typically called at regular intervals to keep track
 * of time in the system.
 * @return void.
 */
void timer_isr(void);

/**
 * @brief get system timer tick.
 * @details
 * this function returns the current value of the system timer tick count.
 * @return the current system timer tick count.
 */
usize get_system_timer_tick(void);

#endif /* !defined INTERRUPT_H */
