#include "can.h"
#include "Mobaxterm.h"



void MyCAN_SendData(uint8_t* Send_Can)
{
    uint32_t TxMailbox;
    CAN_TxHeaderTypeDef TxHeader;
    TxHeader.DLC = 4;
    TxHeader.ExtId = 0;
    TxHeader.IDE = 0;
    TxHeader.RTR = 0;
    TxHeader.StdId = 0x123;
    TxHeader.TransmitGlobalTime = 0;
    HAL_CAN_AddTxMessage(&hcan1, &TxHeader, Send_Can, &TxMailbox);
}

void MyCAN_Filter()
{
    CAN_FilterTypeDef Can_Filter;
    Can_Filter.FilterActivation = CAN_FILTER_ENABLE;
    Can_Filter.FilterBank = 14;
    Can_Filter.FilterFIFOAssignment = CAN_RX_FIFO0 ;
    Can_Filter.FilterIdHigh = 0x00000;
    Can_Filter.FilterIdLow = 0x0000;
    Can_Filter.FilterMaskIdHigh = 0x0000;
    Can_Filter.FilterMaskIdLow = 0x0000;
    Can_Filter.FilterMode = CAN_FILTERMODE_IDLIST;
    Can_Filter.FilterScale = CAN_FILTERSCALE_16BIT;
    Can_Filter.SlaveStartFilterBank = 14;
    HAL_CAN_ConfigFilter(&hcan1, &Can_Filter);
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    uint8_t Receive_Can[8];
    CAN_RxHeaderTypeDef RxHeader;

    HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &RxHeader, Receive_Can);

    Mobaxterm_SendData(Receive_Can[0]);
    Mobaxterm_SendData(Receive_Can[1]);
    Mobaxterm_SendData(Receive_Can[2]);
    Mobaxterm_SendData(Receive_Can[3]);
}

