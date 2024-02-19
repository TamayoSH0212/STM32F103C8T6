/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define Disp1_Pin GPIO_PIN_0
#define Disp1_GPIO_Port GPIOB
#define Disp2_Pin GPIO_PIN_1
#define Disp2_GPIO_Port GPIOB
#define PA_Pin GPIO_PIN_3
#define PA_GPIO_Port GPIOB
#define PB_Pin GPIO_PIN_4
#define PB_GPIO_Port GPIOB
#define PC_Pin GPIO_PIN_5
#define PC_GPIO_Port GPIOB
#define PD_Pin GPIO_PIN_6
#define PD_GPIO_Port GPIOB
#define PE_Pin GPIO_PIN_7
#define PE_GPIO_Port GPIOB
#define PF_Pin GPIO_PIN_8
#define PF_GPIO_Port GPIOB
#define PG_Pin GPIO_PIN_9
#define PG_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */