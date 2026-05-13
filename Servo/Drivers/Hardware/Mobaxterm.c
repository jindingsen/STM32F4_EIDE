#include "usart.h"



void Mobaxterm_SendChar(char* sendbuff)
{
    HAL_UART_Transmit(&huart6, sendbuff, strlen(sendbuff), HAL_MAX_DELAY);
}