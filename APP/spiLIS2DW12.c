#include "spiLIS2DW12.h"

void initSPILIS2DW12()
{
    DO_LIS2DW12_CS = 0;
    timer1Delay(100);
    DO_LIS2DW12_CS = 1;

    // Configure ADXL345: Enable Measurement Mode
    LIS2DW12_WriteRegister(LIS2DW12_CTRL_REG1, 0x27);
}


// Function for writing data in ADXL345 accelerometer 

void LIS2DW12_WriteRegister(uint8_t iRegAddress, uint8_t iValue)
{
    DO_LIS2DW12_CS = 0; //LIS2DW12 Module Enabled
    SPI1_Write(iRegAddress);
    SPI1_Write(iValue);
    DO_LIS2DW12_CS = 1; //LIS2DW12 Module Enabled
}


// Function for reading LIS2DW12 accelerometer data

uint8_t LIS2DW12_ReadRegister(uint8_t iRegAddress)
{
    uint8_t iValue = 0;
    DO_LIS2DW12_CS = 0; //LIS2DW12 Module Enabled
    SPI1_Write(iRegAddress | 0x80); //Set MSB for read operation
    iValue = SPI1_Write(0x00);
    DO_LIS2DW12_CS = 1; //LIS2DW12 Module Enabled

    return iValue;
}