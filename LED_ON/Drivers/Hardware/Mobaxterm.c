#include "gpio.h"
#include "usart.h"
#include "string.h"

void Mobaxterm_Send(char* SendData)
{
    HAL_UART_Transmit(&huart6, SendData, strlen(SendData), HAL_MAX_DELAY);
    HAL_Delay(1000);
}
