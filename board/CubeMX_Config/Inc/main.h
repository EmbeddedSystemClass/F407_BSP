/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal.h"

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
#define RS485_RE_Pin GPIO_PIN_1
#define RS485_RE_GPIO_Port GPIOA
#define AE_AD1_Pin GPIO_PIN_6
#define AE_AD1_GPIO_Port GPIOA
#define AE_AD2_Pin GPIO_PIN_7
#define AE_AD2_GPIO_Port GPIOA
#define WIFI_CON_Pin GPIO_PIN_11
#define WIFI_CON_GPIO_Port GPIOE
#define TEV_DAC_CS_Pin GPIO_PIN_12
#define TEV_DAC_CS_GPIO_Port GPIOE
#define TEV_DAC_SDI_Pin GPIO_PIN_13
#define TEV_DAC_SDI_GPIO_Port GPIOE
#define TEV_DAC_LD_Pin GPIO_PIN_14
#define TEV_DAC_LD_GPIO_Port GPIOE
#define TEV_DAC_SCK_Pin GPIO_PIN_15
#define TEV_DAC_SCK_GPIO_Port GPIOE
#define TEV_OUT_CTL0_Pin GPIO_PIN_8
#define TEV_OUT_CTL0_GPIO_Port GPIOD
#define TEV_OUT_CTL1_Pin GPIO_PIN_9
#define TEV_OUT_CTL1_GPIO_Port GPIOD
#define TEV_OUT_CTL2_Pin GPIO_PIN_10
#define TEV_OUT_CTL2_GPIO_Port GPIOD
#define AEO_CTL0_Pin GPIO_PIN_11
#define AEO_CTL0_GPIO_Port GPIOD
#define AEO_CTL1_Pin GPIO_PIN_12
#define AEO_CTL1_GPIO_Port GPIOD
#define SYS_LED_Pin GPIO_PIN_13
#define SYS_LED_GPIO_Port GPIOD
#define LED2_Pin GPIO_PIN_14
#define LED2_GPIO_Port GPIOD
#define LED1_Pin GPIO_PIN_15
#define LED1_GPIO_Port GPIOD
#define TEV_CTL_1A_Pin GPIO_PIN_10
#define TEV_CTL_1A_GPIO_Port GPIOC
#define TEV_CTL_1B_Pin GPIO_PIN_11
#define TEV_CTL_1B_GPIO_Port GPIOC
#define TEV_CTL_1C_Pin GPIO_PIN_12
#define TEV_CTL_1C_GPIO_Port GPIOC
#define TEV_CTL_2A_Pin GPIO_PIN_0
#define TEV_CTL_2A_GPIO_Port GPIOD
#define TEV_CTL_2B_Pin GPIO_PIN_1
#define TEV_CTL_2B_GPIO_Port GPIOD
#define TEV_CTL_2C_Pin GPIO_PIN_2
#define TEV_CTL_2C_GPIO_Port GPIOD
#define AE_CTL_1A_Pin GPIO_PIN_3
#define AE_CTL_1A_GPIO_Port GPIOD
#define AE_CTL_1B_Pin GPIO_PIN_4
#define AE_CTL_1B_GPIO_Port GPIOD
#define AE_CTL_1C_Pin GPIO_PIN_5
#define AE_CTL_1C_GPIO_Port GPIOD
#define AE_CTL_2A_Pin GPIO_PIN_6
#define AE_CTL_2A_GPIO_Port GPIOD
#define AE_CTL_2B_Pin GPIO_PIN_7
#define AE_CTL_2B_GPIO_Port GPIOD
#define AE_CTL_2C_Pin GPIO_PIN_3
#define AE_CTL_2C_GPIO_Port GPIOB
#define TEV_HOLD_Pin GPIO_PIN_0
#define TEV_HOLD_GPIO_Port GPIOE
#define TEV_F_Pin GPIO_PIN_1
#define TEV_F_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
