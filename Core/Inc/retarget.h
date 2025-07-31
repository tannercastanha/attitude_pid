/*
 * retarget.h
 *
 *  Created on: Jul 30, 2025
 *      Author: tcast
 */

#ifndef INC_RETARGET_H_
#define INC_RETARGET_H_

#include "stm32f4xx_hal.h"
#include <stdio.h>

void RetargetInit(UART_HandleTypeDef *huart);

#endif /* INC_RETARGET_H_ */
