#include <stdio.h>
#include <stdint.h>

int main () {
    const uint16_t ECU_ID = 0x1F2A;
    float battery_voltage = 12.6f;
    uint8_t cylinders = 4;

    //In giá trị của biến 
    printf("BATTERY VOLTAGE: %.2f V\n", battery_voltage);
    printf("HEX OF ECU ID: 0x%04X\n", ECU_ID);
    printf("CYLINDERS: %hhu \n", cylinders);

    //In kích thước RAM của biến 
    printf("RAM OF ECU ID: %zu bytes\n", sizeof(ECU_ID));
    printf("RAM OF BATTERY VOLTAGE: %zu bytes\n", sizeof(battery_voltage));
    printf("RAM OF CYLINDERS: %zu bytes\n", sizeof(cylinders));

    return 0;
}