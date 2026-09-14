#include <stdio.h> 
#include <stdint.h>

int main () {
    const uint16_t TPMS_PIN = 7777;
    uint16_t user_pin;
    uint8_t attempts = 0;
    uint8_t has_flat_tire = 0;
    uint8_t tpms_dtc;
    uint8_t choice;
    float tire_press; 
    float total_press = 0.0f;
    float avg_press; 

    while (attempts < 3) {
        printf("NHAP PIN CODE DE KICH HOAT: ");
        scanf("%hu", &user_pin);

        if (user_pin == TPMS_PIN) { 
            printf("[TPMS ECU]: ACCESS GRANTED!\n");
            break;
        }
        else {
            attempts++;
            if (attempts < 3) {
                printf("[DENIED]: PIN CODE SAI! VUI LONG NHAP LAI!\n");
            }
        }
    }

    if (user_pin != TPMS_PIN) {
        printf("[TPMS ECU]: KHOA HE THONG TECH!\n");
        return 0;
    }

    for (uint8_t i = 1; i <= 4; i++) {
        printf("NHAP AP SUAT LOP THU %d: ", i);
        scanf("%f", &tire_press);

        if (tire_press < 0.0f || 60.0f < tire_press) {
            printf("LOI DU LIEU! VUI LONG NHAP LAI\n");
            i--;
            continue;
        }

        if (tire_press <= 15.0f) {
            has_flat_tire = 1;
        }

        total_press += tire_press;
    }

    avg_press = total_press / 4.0f;

    if (has_flat_tire == 1 || avg_press < 25.0f) {
        printf("[WARNING SIGN]: CANH BAO LOP XI/ MEM KHAN CAP!\n");
        tpms_dtc = 0xEA;
    }
    else if (avg_press > 35.0f) {
        printf("[WARNING SIGN]: CANH BAO LOP QUA CANG!\n");
        tpms_dtc = 0xEB;
    }
    else if (25.0f <= avg_press && avg_press <= 35.0f) {
        printf("[NORMAL SIGN]: AP SUAT LOP DAT CHUAN!\n");
        tpms_dtc = 0x00;
    }

    do {
        printf("================\n");
        printf("===== MENU =====\n");
        printf("1. XEM AP SUAT TRUNG BINH VA MA  HEX CUA TPMS_DTC: \n");
        printf("2. XEM DUNG LUONG RAM CUA AVG_PRESS VA TPMS_DTC: \n");
        printf("3. THOAT CHUONG TRUONG\n");
        printf("================\n");
        printf("NHAP LUA CHON: ");
        scanf("%hhu", &choice);

        switch (choice) {
            case 1: 
            printf("AP SUAT TRUNG BINH: %.2f PSI\n", avg_press);
            printf("MA HEX CUA TPMS_DTC: 0x%02X\n", tpms_dtc);
            break;

            case 2: 
            printf("DUNG LUONG RAM CUA AVG_PRESS: %zu bytes\n", sizeof(avg_press));
            printf("DUNG LUONG RAM CUA TPMS_DTC: %zu bytes\n", sizeof(tpms_dtc));
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