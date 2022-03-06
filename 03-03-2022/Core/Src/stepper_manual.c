/*
 * stepper_manual.c
 *
 *  Created on: Feb 20, 2022
 *      Author: 31610
 *
 */

//#include "tim.h"
#include "stepper_manual.h"

void stepper_manual(LX_to_back, LX_to_front, LY_to_top, LY_to_below, LZ_go_in, LZ_go_out, LW_cw, LW_ccw,
                    RX_to_back, RX_to_front, RY_to_top, RY_to_below, RZ_go_in, RZ_go_out, RW_cw, RW_ccw  )
{

								if (LX_to_back == 1)
	 							{
	 								 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
	 								 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);

	 								 RX_to_back = 0;
	 							}

	 							if (LX_to_front == 1)
	 							{
	 								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
	 								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);

	 								RX_to_front = 0;
	 							}

	 							if (LY_to_top == 1)
	 							{
	 								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
	 								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);

	 								RY_to_top = 0;
	 							}

	 							if (LY_to_below == 1)
	 							{
	 								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
	 								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);

	 								RY_to_below = 0;
	 							}

}
