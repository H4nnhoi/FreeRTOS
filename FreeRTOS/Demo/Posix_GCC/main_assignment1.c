/* Assignment 1 - Basic Task Output
 * One task that prints student ID and name every 1 second.
 */

#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>

static void vPrintTask(void *pvParameters)
{
    (void)pvParameters;

    for (;;)
    {
        printf("2020202047 JEOGNHAN LEE\n");
        fflush(stdout);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void main_assignment1(void)
{
    xTaskCreate(vPrintTask,
                "PrintTask",
                configMINIMAL_STACK_SIZE,
                NULL,
                1,
                NULL);

    vTaskStartScheduler();
}
