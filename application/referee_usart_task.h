/**
  ****************************(C) COPYRIGHT 2019 DJI****************************
  * @file       referee_usart_task.c/h
  * @brief      RM referee system data solve. RM裁判系统数据处理
  * @note
  * @history
  *  Version    Date            Author          Modification
  *  V1.0.0     Nov-11-2019     RM              1. done
  *
  @verbatim
  ==============================================================================

  ==============================================================================
  @endverbatim
  ****************************(C) COPYRIGHT 2019 DJI****************************
  */
#ifndef REFEREE_USART_TASK_H
#define REFEREE_USART_TASK_H
#include "main.h"

#define USART_RX_BUF_LENGHT 512
#define REFEREE_FIFO_BUF_LENGTH 1024
#define CV_PACKET_LENGTH 14

typedef struct
{
  float yaw;
  float pitch;
  float depth;
  char find_target;
  char new_cv_data_flag;

} cv_Data_TypeDef;
extern cv_Data_TypeDef cv_Data;

// 用于将4字节十六进制转换为float的联合体
// Union used to convert 4-byte hexadecimal to float
typedef union
{
  uint32_t hex;
  float floatValue;
} HexToFloat;

/**
 * @brief          referee task
 * @param[in]      pvParameters: NULL
 * @retval         none
 */
/**
 * @brief          裁判系统任务
 * @param[in]      pvParameters: NULL
 * @retval         none
 */
extern void referee_usart_task(void const *argument);
extern void UART7_CommandRoute(void);
#endif
