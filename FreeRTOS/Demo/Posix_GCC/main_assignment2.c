/* Assignment 2 - Multiple Tasks
 * Two tasks printing at different periods (same priority).
 * Task A: every 1000 ms, Task B: every 500 ms.
 */

#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>

static void vTaskA(void *pvParameters)
{
    (void)pvParameters;

    for (;;)
    {
        printf("Task A\n");
        fflush(stdout);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

static void vTaskB(void *pvParameters)
{
    (void)pvParameters;

    for (;;)
    {
        printf("Task B\n");
        fflush(stdout);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void main_assignment2(void)
{
    xTaskCreate(vTaskA,
                "TaskA",
                configMINIMAL_STACK_SIZE,
                NULL,
                1,
                NULL);

    xTaskCreate(vTaskB,
                "TaskB",
                configMINIMAL_STACK_SIZE,
                NULL,
                1,
                NULL);

    vTaskStartScheduler();
}
