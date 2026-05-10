#include "gpio.h"


uint8_t Read_KeyNum()
{
    uint8_t Key_Num = 0;
    if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == GPIO_PIN_RESET)
    {
        HAL_Delay(20);
        if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == GPIO_PIN_RESET)
        {
            Key_Num = 2;
            while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == GPIO_PIN_RESET);
        }
    }
    return Key_Num;
}