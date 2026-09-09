#include <stdio.h> 
#include <stdint.h>

int main(){
    const uint16_t SECRET_PIN = 1234;
    uint16_t user_pin; 
    uint8_t attempts = 0;
    while (attempts < 3) {
        printf("Nhap ma PIN de khoi dong xe (Lan %d/3): ", attempts+1);
        scanf("%hu", &user_pin);
        attempts++;

        if (user_pin == SECRET_PIN) {
            printf("[IMMOBILIZER OK]: XAC NHAN MA PIN DUNG! CHO PHEP NO MAY!\n");
            break;
        }
        else {
            if (attempts < 3) {
                printf("[DENIED]: MA PIN SAI! VUI LONG NHAP LAI.\n");
            }
        }
    }
    if (attempts == 3 && user_pin != SECRET_PIN) {
        printf("[SECRET ALERT]: SAI MA PIN 3 LAN! KHOA HE THONG XE!\n");
    }

    return 0;
}