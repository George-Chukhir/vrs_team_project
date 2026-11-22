/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "stm32f3xx_ll_i2c.h"
#include "stm32f3xx_ll_rcc.h"
#include "stm32f3xx_ll_bus.h"
#include "stm32f3xx_ll_system.h"
#include "stm32f3xx_ll_exti.h"
#include "stm32f3xx_ll_cortex.h"
#include "stm32f3xx_ll_utils.h"
#include "stm32f3xx_ll_pwr.h"
#include "stm32f3xx_ll_dma.h"
#include "stm32f3xx_ll_tim.h"
#include "stm32f3xx_ll_usart.h"
#include "stm32f3xx_ll_gpio.h"

#if defined(USE_FULL_ASSERT)
#include "stm32_assert.h"
#endif /* USE_FULL_ASSERT */

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define IR1_A_Pin LL_GPIO_PIN_0
#define IR1_A_GPIO_Port GPIOA
#define IR1_B_Pin LL_GPIO_PIN_1
#define IR1_B_GPIO_Port GPIOA
#define IR2_A_Pin LL_GPIO_PIN_3
#define IR2_A_GPIO_Port GPIOA
#define IR2_B_Pin LL_GPIO_PIN_4
#define IR2_B_GPIO_Port GPIOA
#define RF_DISABLE_Pin LL_GPIO_PIN_7
#define RF_DISABLE_GPIO_Port GPIOA
#define LED2_G_Pin LL_GPIO_PIN_0
#define LED2_G_GPIO_Port GPIOB
#define LED2_R_Pin LL_GPIO_PIN_1
#define LED2_R_GPIO_Port GPIOB
#define NFC_GPO_Pin LL_GPIO_PIN_8
#define NFC_GPO_GPIO_Port GPIOA
#define NFC_GPO_EXTI_IRQn EXTI9_5_IRQn
#define LED1_G_Pin LL_GPIO_PIN_9
#define LED1_G_GPIO_Port GPIOA
#define LED1_R_Pin LL_GPIO_PIN_10
#define LED1_R_GPIO_Port GPIOA
#define REED1_Pin LL_GPIO_PIN_11
#define REED1_GPIO_Port GPIOA
#define REED2_Pin LL_GPIO_PIN_12
#define REED2_GPIO_Port GPIOA
#define STATUS_Pin LL_GPIO_PIN_3
#define STATUS_GPIO_Port GPIOB
#ifndef NVIC_PRIORITYGROUP_0
#define NVIC_PRIORITYGROUP_0         ((uint32_t)0x00000007) /*!< 0 bit  for pre-emption priority,
                                                                 4 bits for subpriority */
#define NVIC_PRIORITYGROUP_1         ((uint32_t)0x00000006) /*!< 1 bit  for pre-emption priority,
                                                                 3 bits for subpriority */
#define NVIC_PRIORITYGROUP_2         ((uint32_t)0x00000005) /*!< 2 bits for pre-emption priority,
                                                                 2 bits for subpriority */
#define NVIC_PRIORITYGROUP_3         ((uint32_t)0x00000004) /*!< 3 bits for pre-emption priority,
                                                                 1 bit  for subpriority */
#define NVIC_PRIORITYGROUP_4         ((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority,
                                                                 0 bit  for subpriority */
#endif

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
