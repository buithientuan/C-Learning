#include <stdio.h> 
#include <stdint.h>

int main () {
    const uint16_t SAS_PIN = 3333;
    uint16_t USER_PIN;
    uint8_t attempts = 0;
    uint8_t has_sharp_turn = 0;
    uint8_t sas_dtc;
    uint8_t choice;
    float steering_angle;
    float total_angle = 0.0f;
    float avg_angle;

    while (attempts < 3) {
        printf("NHAP PIN CODE: ");
        scanf("%hu", &USER_PIN);

        if (USER_PIN == SAS_PIN) {
            printf("[ACCESS]: PIN CODE DUNG\n");
            break;
        }
        else {
            attempts++;
            printf("[DENIED]: PIN CODE KHONG DUNG!\n");
        }
    }

    if (USER_PIN != SAS_PIN) {
        printf("[FAILED]: DANG NHAP KHONG THANH CONG!\n");
        return 0;
    }

    for (uint8_t i = 1; i <= 3; i++) {
        printf("NHAP GOC DANH LAI LAN %d: ", i);
        scanf("%f", &steering_angle);

        if (-540.0f > steering_angle || steering_angle > 540.0f) {
            printf("DU LIEU BI LOI! VUI LONG NHAP LAI!\n ");
            i--;
            continue;
        }
        if (steering_angle > 90.0f || steering_angle < -90.0f) {
            has_sharp_turn = 1; 
        }

        total_angle += steering_angle;
    }

    avg_angle = total_angle / 3.0f;

    if (has_sharp_turn == 1) {
        printf("[WARNING SIGN]: CANH BAO DANH LAI GAP! KICH HOAT PHANH ABS/ESP\n");
        sas_dtc = 0xC1;
    }
    else if (avg_angle >= 15.0f || avg_angle <= -15.0f) {
        printf("[WARNING SIGN]: XE LECH HUONG HANH TRINH!\n");
        sas_dtc = 0xC2;
    }
    else if (avg_angle < 15.0f && avg_angle > -15.0f) {
        printf("[NORMAL SIGN]: GOC LAI TRONG NGUONG AN TOAN!\n");
        sas_dtc = 0x00;
    }

    do {
        printf("================\n");
        printf("===== MENU =====\n");
        printf("1. XEM GOC DANH LAI TRUNG BINH VAF MA HEX SAS_DTC: \n");
        printf("2. XEM DUNG LUONG RAM CUA AVG_ANGLE VA SAS_DTC\n");
        printf("3. THOAT CHUONG TRINH\n");
        printf("================\n");
        printf("NHAP LUA CHON (1-3): ");
        scanf("%hhu", &choice);

        switch (choice) {
            case 1: 
            printf("GOC DANH LAI TRUNG BINH: %.1f deg\n", avg_angle);
            printf("MA HEX CUA SAS_DTC: 0x%02X\n", sas_dtc);
            break;

            case 2: 
            printf("DUNG LUONG RAM CUA AVG_ANGLE: %zu bytes\n", sizeof(avg_angle));
            printf("DUNG LUONG RAM CUA SAS_DTC: %zu bytes\n", sizeof(sas_dtc));
            break;

            case 3: 
            printf("THOAT CHUONG TRINH\n");
            break;

            default: 
            printf("LUA CHON KHONG HOP LE: %d\n", choice);
            break;
        }
    } while (choice != 3);

    return 0;
}