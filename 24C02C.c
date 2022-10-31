#include "24C02C.h"

eeprom24c02c_t EEPROM24C02C_New(uint8_t address, I2C_HandleTypeDef * hi2c){
    eeprom24c02c_t instance = {
        .address = (0b10100000) | (address & 0b00001110),
        .hi2c = hi2c
    };

    return instance;
}

eeprom24c02c_status_e EEPROM24C02C_Read(eeprom24c02c_t * handle, uint8_t address, uint8_t * data, uint8_t size){
    if (HAL_I2C_IsDeviceReady(handle->hi2c, handle->address, 1, HAL_MAX_DELAY) != HAL_OK)
        return EEPROM_24C02C_BUSY;

    if (HAL_I2C_Mem_Read(handle->hi2c, handle->address, address, I2C_MEMADD_SIZE_8BIT, data, size, 100) != HAL_OK)
        return EEPROM_24C02C_TIMEOUT;

    return EEPROM_24C02C_OK;
}

eeprom24c02c_status_e EEPROM24C02C_Write(eeprom24c02c_t * handle, uint8_t address, uint8_t * data, uint8_t size){
    if (HAL_I2C_IsDeviceReady(handle->hi2c, handle->address, 1, HAL_MAX_DELAY) != HAL_OK)
        return EEPROM_24C02C_BUSY;

    if (HAL_I2C_Mem_Write(handle->hi2c, handle->address, address, I2C_MEMADD_SIZE_8BIT, data, size, 100) != HAL_OK)
        return EEPROM_24C02C_TIMEOUT;

    return EEPROM_24C02C_OK;
}
