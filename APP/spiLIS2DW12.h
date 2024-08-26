/* 
 * File:   spiLIS2DW12.h
 * Author: tushar.mali
 *
 * Created on 22 June, 2024, 12:09 PM
 */

#ifndef SPILIS2DW12_H
#define	SPILIS2DW12_H

#include "../BIOS/bios.h"

// LIS2DW12  Register Addresses
#define LIS2DW12_CTRL_REG1       0x20

#define LIS2DW12_REG_DATAX0      0x28
#define LIS2DW12_REG_DATAX1      0x29
#define LIS2DW12_REG_DATAY0      0x2A
#define LIS2DW12_REG_DATAY1      0x2B
#define LIS2DW12_REG_DATAZ0      0x2C
#define LIS2DW12_REG_DATAZ1      0x2D

#ifdef	__cplusplus
extern "C" {
#endif

    void initSPILIS2DW12();
    void LIS2DW12_WriteRegister(uint8_t iRegAddress, uint8_t iValue);
    uint8_t LIS2DW12_ReadRegister(uint8_t iRegAddress);

#ifdef	__cplusplus
}
#endif

#endif	/* SPILIS2DW12_H */

