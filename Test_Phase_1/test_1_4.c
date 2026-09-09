#include <stdio.h>
#include <stdint.h>

int main(){
    float voltage = 10.0f;
    while (voltage < 14.4f) {
        printf("Nhap dien ap pin hien tai (v - Sacc den 14.4V): ");
        scanf("%f", &voltage);

        if (voltage > 16.0f) {
            printf("[DANGER]: QUA AP! NGAT AN TOAN KHAN CAP!\n");
            break;
        }
        else if (voltage  >= 14.4f) {
            printf("[CHARGING COMPLETE]: BINH DA DAY DIEN (>= 14.4V)\n");
        }
        else if (voltage > 0.0f) {
            printf("[CHARGING]: DANG SAC PIN...\n");
        }
    }
    if (voltage >= 14.4f && voltage <= 16.0f) {
        printf("[BMS SYSTEM]: DUNG DONG SAC THUONG DUNG QUY DINH\n");
    }
    return 0;
}