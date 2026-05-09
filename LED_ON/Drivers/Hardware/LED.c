#include"gpio.h"

void LED_ON()
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
}

void LED_OFF()
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
}

void LED_Turn()
{
    LED_ON();
    HAL_Delay(500);
    LED_OFF();
    HAL_Delay(500);
}