#include "main.h"
#include "gpio.h"

uint8_t contador = 0;
//uint8_t display[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
uint8_t display[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};


void SystemClock_Config(void);
void Display_Port(uint8_t data);

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  while (1)
  {

	  Display_Port(display[contador]);

	  if(HAL_GPIO_ReadPin(BotonINC_GPIO_Port, BotonINC_Pin) == 1){
		  HAL_Delay(5);
		  while(HAL_GPIO_ReadPin(BotonINC_GPIO_Port, BotonINC_Pin) == 1);
		  HAL_Delay(5);

		  contador++;
		  if(contador > 9){
			  contador = 9;
		  }
	  }
	  if(HAL_GPIO_ReadPin(BotonDEC_GPIO_Port, BotonDEC_Pin) == 1){
		  HAL_Delay(5);
		  while(HAL_GPIO_ReadPin(BotonDEC_GPIO_Port, BotonDEC_Pin) == 1);
		  HAL_Delay(5);
		  /*
		  contador--;
		  if(contador <= 0){
			  contador = 0;
		  }*/
		  if (contador > 0){
			  contador--;
		  }
	  }
  }//while

}

void Display_Port(uint8_t data){
	HAL_GPIO_WritePin(PA_GPIO_Port, PA_Pin, (((data & 0x01) >> 0) & 0x01));
	HAL_GPIO_WritePin(PB_GPIO_Port, PB_Pin, (((data & 0x02) >> 1) & 0x01));
	HAL_GPIO_WritePin(PC_GPIO_Port, PC_Pin, (((data & 0x04) >> 2) & 0x01));
	HAL_GPIO_WritePin(PD_GPIO_Port, PD_Pin, (((data & 0x08) >> 3) & 0x01));
	HAL_GPIO_WritePin(PE_GPIO_Port, PE_Pin, (((data & 0x10) >> 4) & 0x01));
	HAL_GPIO_WritePin(PF_GPIO_Port, PF_Pin, (((data & 0x20) >> 5) & 0x01));
	HAL_GPIO_WritePin(PG_GPIO_Port, PG_Pin, (((data & 0x40) >> 6) & 0x01));
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

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
