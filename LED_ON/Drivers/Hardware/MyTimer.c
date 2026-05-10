#include "gpio.h"
#include "tim.h"



uint32_t MyTimer_Getcount()
{
    return __HAL_TIM_GET_COUNTER(&htim2);
}