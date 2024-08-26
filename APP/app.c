#include "app.h"


//Global Variables
uint16_t buf[200] = {};
int16_t X_out = 0, Y_out = 0, Z_out = 0;

void runApp()
{
    initSPILIS2DW12();

    while (1)
    {
        //Read LIS2DW12 Accelerometer Data through SPI Function
        X_out = (int16_t) (LIS2DW12_ReadRegister(LIS2DW12_REG_DATAX0) | LIS2DW12_ReadRegister(LIS2DW12_REG_DATAX1) << 8);
        Y_out = (int16_t) (LIS2DW12_ReadRegister(LIS2DW12_REG_DATAY0) | LIS2DW12_ReadRegister(LIS2DW12_REG_DATAY1) << 8);
        Z_out = (int16_t) (LIS2DW12_ReadRegister(LIS2DW12_REG_DATAZ0) | LIS2DW12_ReadRegister(LIS2DW12_REG_DATAZ1) << 8);

        // Print Value
        sprintf(buf, "X axis: %d, Y axis: %d, Z axis: %d\r\n", X_out, Y_out, Z_out);
        
        UART1WriteString(buf);
    }
}


