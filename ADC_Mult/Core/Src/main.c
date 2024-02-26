/*Autor: Hector Tamayo*/

#include "main.h"
#include "adc.h"
#include "dma.h"
#include "i2c.h"
#include "gpio.h"
#include "Anglas_LCD_I2C.h"
#include <stdio.h>

uint32_t adc_buf[3];
uint16_t valor_adc[3];
char buff_lcd[18];


void SystemClock_Config(void);

int main(void)
{
  HAL_Init();
  SystemClock_Config();

  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_I2C1_Init();
  LCD_I2C_Init();
  HAL_ADC_Start_DMA(&hadc1,adc_buf,3);//inicia el módulo DMA, con los parametros del adc, el bufer de 32 bits y la cantidad de puertos.
  HAL_ADC_Start_IT(&hadc1);//Inicia la interrupcion del ADC


  while (1)
  {
	  HAL_ADC_Start_IT(&hadc1);

	  //LCD_I2C_ClearText();
	  sprintf(buff_lcd,"c1: %u ",valor_adc[0]);
	  LCD_I2C_WriteText(1,1,buff_lcd);
	  sprintf(buff_lcd,"c2: %u ",valor_adc[1]);
	  LCD_I2C_WriteText(1,9,buff_lcd);
	  sprintf(buff_lcd,"c3: %u ",valor_adc[2]);
	  LCD_I2C_WriteText(2,1,buff_lcd);
	  HAL_Delay(150);
  }

}
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
	if(hadc->Instance == ADC1){
		valor_adc[0] = (uint16_t)adc_buf[0];
		valor_adc[1] = (uint16_t)adc_buf[1];
		valor_adc[2] = (uint16_t)adc_buf[2];
	}
}
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

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
