/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "stepper_manual.h"
#include <stdio.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

uint8_t Rx_Data[6];     //. array for data from display

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_TIM3_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim3);	//. interrupt

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


	 int  LX_to_back  = 0;	  int  LZ_go_in  = 0;	 int  RX_to_back  = 0;		int  RZ_go_in  = 0;
	 int  LX_to_front = 0;	  int  LZ_go_out = 0;	 int  RX_to_front = 0;		int  RZ_go_out = 0;
	 int  LY_to_top   = 0;	  int  LW_cw     = 0;	 int  RY_to_top   = 0;		int  RW_cw     = 0;
	 int  LY_to_below = 0;	  int  LW_ccw    = 0;	 int  RY_to_below = 0;		int  RW_ccw    = 0;

	 HAL_UART_Receive(&huart1, Rx_Data, 6, 1000);                          //. 1000 = time delay

	 if ((Rx_Data[1] == 0x30) && (Rx_Data[2] == 0x34) && (Rx_Data[3] == 0x30) && (Rx_Data[4] == 0x33))  LX_to_back  = 1;	//. if manual LX to back  = pressed (page 04 button 03)
	 if ((Rx_Data[1] == 0x30) && (Rx_Data[2] == 0x34) && (Rx_Data[3] == 0x30) && (Rx_Data[4] == 0x34))  LX_to_front = 1;	//. if manual LX to front = pressed (page 04 button 04)
	 if ((Rx_Data[1] == 0x30) && (Rx_Data[2] == 0x35) && (Rx_Data[3] == 0x30) && (Rx_Data[4] == 0x33))  LY_to_top   = 1;	//. if manual LY to top   = pressed (page 05 button 03)
	 if ((Rx_Data[1] == 0x30) && (Rx_Data[2] == 0x35) && (Rx_Data[3] == 0x30) && (Rx_Data[4] == 0x34))  LY_to_below = 1;	//. if manual LY to BELOW = pressed (page 05 button 04)
	 if ((Rx_Data[1] == 0x30) && (Rx_Data[2] == 0x36) && (Rx_Data[3] == 0x30) && (Rx_Data[4] == 0x33))  LZ_go_in    = 1;	//. if manual LZ go in    = pressed (page 06 button 03)
	 if ((Rx_Data[1] == 0x30) && (Rx_Data[2] == 0x36) && (Rx_Data[3] == 0x30) && (Rx_Data[4] == 0x34))  LZ_go_out   = 1;	//. if manual LZ go out   = pressed (page 06 button 04)
	 if ((Rx_Data[1] == 0x30) && (Rx_Data[2] == 0x37) && (Rx_Data[3] == 0x30) && (Rx_Data[4] == 0x33))  LW_cw       = 1;	//. if manual LW cw       = pressed (page 07 button 03)
	 if ((Rx_Data[1] == 0x30) && (Rx_Data[2] == 0x37) && (Rx_Data[3] == 0x30) && (Rx_Data[4] == 0x34))  LW_ccw      = 1;	//. if manual LW ccw      = pressed (page 07 button 04)

	 if ((Rx_Data[1] == 0x30) && (Rx_Data[2] == 0x38) && (Rx_Data[3] == 0x30) && (Rx_Data[4] == 0x33))  RX_to_back  = 1;	//. if manual RX to back  = pressed (page 08 button 03)
	 if ((Rx_Data[1] == 0x30) && (Rx_Data[2] == 0x38) && (Rx_Data[3] == 0x30) && (Rx_Data[4] == 0x34))  RX_to_front = 1;	//. if manual RX to front = pressed (page 08 button 04)
	 if ((Rx_Data[1] == 0x30) && (Rx_Data[2] == 0x39) && (Rx_Data[3] == 0x30) && (Rx_Data[4] == 0x33))  RY_to_top   = 1;	//. if manual RY to top   = pressed (page 09 button 03)
	 if ((Rx_Data[1] == 0x30) && (Rx_Data[2] == 0x39) && (Rx_Data[3] == 0x30) && (Rx_Data[4] == 0x34))  RY_to_below = 1;	//. if manual RY to BELOW = pressed (page 09 button 04)
	 if ((Rx_Data[1] == 0x31) && (Rx_Data[2] == 0x30) && (Rx_Data[3] == 0x30) && (Rx_Data[4] == 0x33))  RZ_go_in    = 1;	//. if manual RZ go in    = pressed (page 10 button 03)
	 if ((Rx_Data[1] == 0x31) && (Rx_Data[2] == 0x30) && (Rx_Data[3] == 0x30) && (Rx_Data[4] == 0x34))  RZ_go_out   = 1;	//. if manual RZ go out   = pressed (page 10 button 04)
	 if ((Rx_Data[1] == 0x31) && (Rx_Data[2] == 0x31) && (Rx_Data[3] == 0x30) && (Rx_Data[4] == 0x33))  RW_cw       = 1;	//. if manual RW cw       = pressed (page 11 button 03)
	 if ((Rx_Data[1] == 0x31) && (Rx_Data[2] == 0x31) && (Rx_Data[3] == 0x30) && (Rx_Data[4] == 0x34))  RW_ccw      = 1;	//. if manual RW ccw      = pressed (page 11 button 04)

	 stepper_manual(LX_to_back, LX_to_front, LY_to_top, LY_to_below, LZ_go_in, LZ_go_out, LW_cw, LW_ccw,
	 	 		    RX_to_back, RX_to_front, RY_to_top, RY_to_below, RZ_go_in, RZ_go_out, RW_cw, RW_ccw  ); //. function call

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 64;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) //. interrupt timer3
{
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
//	HAL_Delay(1);
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);

	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

