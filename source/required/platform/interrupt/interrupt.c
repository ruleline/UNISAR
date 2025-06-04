/**
 * @file interrupt.c
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

#include "interrupt.h"

/**
 * @brief system timer tick.
 */
static volatile usize system_timer_tick;

/**
 * @brief system timer ISR.
 * @details
 * this function is called by the system timer interrupt to increment the
 * system timer tick. it is typically called at regular intervals to keep track
 * of time in the system.
 * @return void.
 */
void timer_isr(void)
{
        system_timer_tick++;
}

/**
 * @brief get system timer tick.
 * @details
 * this function returns the current value of the system timer tick count.
 * @return the current system timer tick count.
 */
usize get_system_timer_tick(void)
{
        return (system_timer_tick);
}
