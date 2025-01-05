/*
 * GPIO_LED.h
 *
 *  Created on: Dec 4, 2024
 *      Author: chester
 */

#ifndef INC_GPIO_LED_H_
#define INC_GPIO_LED_H_

#define SENSOR_LED_TOGGLE()     HAL_GPIO_TogglePin(SENSOR_LED_GPIO_Port, SENSOR_LED_Pin);

#endif /* INC_GPIO_LED_H_ */
