/*
 * Sensor_SHT3x.c
 *
 *  Created on: Jan 5, 2025
 *      Author: chester
 */

#include "../Inc/Sensor_SHT3x.h"

const uint16_t SHT3x_ADDRESS = 0x44;
// const uint16_t SHT3x_ADDRESS = 0x45;

const uint16_t SHT3x_ADDR_WRITE = (SHT3x_ADDRESS<<1);
const uint16_t SHT3x_ADDR_READ = (SHT3x_ADDRESS<<1) + 1;

I2C_HandleTypeDef *I2C_HANDLE;
const uint32_t SHT3x_TIMEOUT = 200;

static HAL_StatusTypeDef SHT3x_SendCmd(sht3x_cmd_t cmd) {
	uint8_t buffer[2];
	buffer[0] = cmd >> 8;
	buffer[1] = cmd;

	return HAL_I2C_Master_Transmit(I2C_HANDLE, SHT3x_ADDR_WRITE, buffer, 2, SHT3x_TIMEOUT);
}

const uint8_t CRC8_POLYNOMIAL = 0x31;

static uint8_t checkCrc8(uint8_t* data, uint8_t length) {
	uint8_t crc8 = 0x00;

	while (length--) {
		crc8 ^= *data++;

		for (uint8_t i = 8; i > 0; i--) {
			crc8 = (crc8 & 0x80)? (crc8<<1)^CRC8_POLYNOMIAL : (crc8<<1);
		}
	}

	return crc8;
}


HAL_StatusTypeDef SHT3x_IsDeviceReady(void) {
	return HAL_I2C_IsDeviceReady(I2C_HANDLE, SHT3x_ADDRESS, 10, SHT3x_TIMEOUT);
}

void SHT3x_Reset(void) {
	*I2C_HANDLE = hi2c1;
	SHT3x_SendCmd(SHT3x_RESET);
	HAL_Delay(20);
}

HAL_StatusTypeDef SHT3x_Init(void) {
	*I2C_HANDLE = hi2c1;
	return SHT3x_SendCmd(SHT3x_PERIODIC_MEDIUM_2);
}

HAL_StatusTypeDef SHT3x_ReadSensorData(uint8_t* data) {
	SHT3x_SendCmd(SHT3x_READOUT_FOR_PERIODIC_MODE);
	return HAL_I2C_Master_Receive(I2C_HANDLE, SHT3x_ADDR_READ, data, 6, SHT3x_TIMEOUT);
}

HAL_StatusTypeDef SHT3x_GetTemperatureAndHumidity(uint8_t* data, float* temperature, float* humidity) {
	uint16_t recvTemperature = 0;
	uint16_t recvHumidity = 0;

	if (checkCrc8(data, 2) != data[2] || checkCrc8(&data[3], 2) != data[5]) {
		return HAL_ERROR;
	}

	recvTemperature = ((uint16_t)data[0]<<8) | data[1];
	*temperature = -45 + 175 * ((float)recvTemperature/65535);

	recvHumidity = ((uint16_t)data[3]<<8) | data[4];
	*humidity = 100 * ((float)recvHumidity/65535);

	return HAL_OK;
}
