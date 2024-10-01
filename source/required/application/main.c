/**
 * @file main.c
 * @brief 主任务
 * @author ruleline (ruleline@outlook.com)
 * @since 2024-04-02
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2024-10-01
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

#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <timers.h>
#include <semphr.h>

#include <stdio.h>

static void exampleTask(void *parameters)
{
        /* Unused parameters. */
        (void)parameters;

        for (;;)
        {
                /* Example Task Code */
                vTaskDelay(100); /* delay 100 ticks */
        }
} /* exampleTask */

/**
 * @brief 主任务
 *
 * @retval 0
 */
int main(void)
{
        static StaticTask_t exampleTaskTCB;
        static StackType_t exampleTaskStack[configMINIMAL_STACK_SIZE];

        (void)printf("Example FreeRTOS Project\n");

        (void)xTaskCreateStatic(exampleTask, "example",
                                        configMINIMAL_STACK_SIZE, NULL,
                                        configMAX_PRIORITIES - 1U,
                                        &exampleTaskStack[0], &exampleTaskTCB);

        /* Start the scheduler. */
        vTaskStartScheduler();

        for (;;)
        {
                /* Should not reach here. */
        }

        return (0);
} /* main */
/*-----------------------------------------------------------*/

#if (configCHECK_FOR_STACK_OVERFLOW > 0)
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
        /* Check pcTaskName for the name of the offending task,
                * or pxCurrentTCB if pcTaskName has itself been corrupted. */
        (void)xTask;
        (void)pcTaskName;
} /* vApplicationStackOverflowHook */
#endif /* #if (configCHECK_FOR_STACK_OVERFLOW > 0) */
