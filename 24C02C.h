#ifndef _24C02C_EEPROM_H_
#define _24C02C_EEPROM_H_

#include <stdint.h>
#include "stm32g0xx_hal.h"

typedef struct{
    uint8_t             address;
    I2C_HandleTypeDef * hi2c;
}eeprom24c02c_t;

typedef enum{
    EEPROM_24C02C_OK,
    EEPROM_24C02C_TIMEOUT,
    EEPROM_24C02C_BUSY,
    EEPROM_24C02C_ERROR
}eeprom24c02c_status_e;

eeprom24c02c_t EEPROM24C02C_New(uint8_t address, I2C_HandleTypeDef * hi2c);
eeprom24c02c_status_e EEPROM24C02C_Read(eeprom24c02c_t * handle, uint8_t address, uint8_t * data, uint8_t size);
eeprom24c02c_status_e EEPROM24C02C_Write(eeprom24c02c_t * handle, uint8_t address, uint8_t * data, uint8_t size);

#endif