#include "usart.h"



void Mobaxterm_SendChar(char* sendbuff)
{
    HAL_UART_Transmit(&huart6, (uint8_t*)sendbuff, strlen(sendbuff), HAL_MAX_DELAY);
    HAL_Delay(500);
}