#include "gpio.h"
#include "usart.h"
#include "string.h"
#include "stdio.h"

void Mobaxterm_SendBuff(char* SendData)
{
    HAL_UART_Transmit(&huart6, (uint8_t*)SendData, strlen(SendData), HAL_MAX_DELAY);
    HAL_Delay(1000);
}

void Mobaxterm_SendData(uint32_t Data)
{
    char str[16];
    sprintf(str, "%u\r\n", Data);
    HAL_UART_Transmit(&huart6, (uint8_t*)str, strlen(str), HAL_MAX_DELAY);
    HAL_Delay(1000);
}