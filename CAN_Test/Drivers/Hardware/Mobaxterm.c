#include "usart.h"
#include <string.h>
#include <stdio.h>

void Mobaxterm_SendChar(char* sendbuff)
{
    HAL_UART_Transmit(&huart6, (uint8_t*)sendbuff, strlen(sendbuff), HAL_MAX_DELAY);
}

void Mobaxterm_SendData(uint8_t Data)
{
    char tmp[20];
    sprintf(tmp, "%02X\r\n", Data);
    HAL_UART_Transmit(&huart6, (uint8_t*)tmp, strlen(tmp), HAL_MAX_DELAY);
}