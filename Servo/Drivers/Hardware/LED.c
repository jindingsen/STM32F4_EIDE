#include "gpio.h"


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
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
}
