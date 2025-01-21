/*
 * Sensor_SHT3x.h
 *
 *  Created on: Jan 5, 2025
 *      Author: chester
 */

#ifndef INC_SENSOR_SHT3X_H_
#define INC_SENSOR_SHT3X_H_

#include "main.h"

#define SHT30

/**
 * @brief Sensor SHT3x command
 */
typedef enum {
    SHT3x_RESET                     = 0x30A2,

    /* Single measurement mode */
    SHT3x_SINGLE_HIGH_ENABLED       = 0x2C06,
    SHT3x_SINGLE_MEDIUM_ENABLED     = 0x2C0D,
    SHT3x_SINGLE_LOW_ENABLED        = 0x2C10,
    SHT3x_SINGLE_HIGH_DISABLED      = 0x2400,
    SHT3x_SINGLE_MEDIUM_DISABLED    = 0x240B,
    SHT3x_SINGLE_LOW_DISABLED       = 0x2416,

    /* Period measurement mode */
    SHT3x_PERIODIC_HIGH_0_5         = 0x2032,
    SHT3x_PERIODIC_MIDIUM_0_5       = 0x2024,
    SHT3x_PERIODIC_LOW_0_5          = 0x202F,
    SHT3x_PERIODIC_HIGH_1           = 0x2130,
    SHT3x_PERIODIC_MIDIUM_1         = 0x2126,
    SHT3x_PERIODIC_LOW_1            = 0x212D,
    SHT3x_PERIODIC_HIGH_2           = 0x2236,
    SHT3x_PERIODIC_MEDIUM_2         = 0x2220,
    SHT3x_PERIODIC_LOW_2            = 0x222B,
    SHT3x_PERIODIC_HIGH_4           = 0x233B,
    SHT3x_PERIODIC_MEDIUM_4         = 0x2322,
    SHT3x_PERIODIC_LOW_4            = 0x2329,
    SHT3x_PERIODIC_HIGH_10          = 0x2737,
    SHT3x_PERIODIC_MEDIUM_10        = 0x2721,
    SHT3x_PERIODIC_LOW_10           = 0x272A,

    SHT3x_READOUT_FOR_PERIODIC_MODE = 0xE000,
} sht3x_cmd_t;

HAL_StatusTypeDef SHT3x_IsDeviceReady(void);
void SHT3x_Reset(void);
HAL_StatusTypeDef SHT3x_Init(void);
HAL_StatusTypeDef SHT3x_ReadSensorData(uint8_t* data);
HAL_StatusTypeDef SHT3x_GetTemperatureAndHumidity(uint8_t* data, float* temperature, float* humidity);

#endif /* INC_SENSOR_SHT3X_H_ */
