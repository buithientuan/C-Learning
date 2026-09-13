#include <stdio.h>
#include <stdint.h>

int main() {
    const uint16_t SAS_PIN = 3333;
    uint16_t user_pin;
    uint8_t attempts = 0;
    uint8_t has_sharp_turn = 0;
    float steering_angle;
    float total_angle = 0.0;
    float avg_angle;
    uint8_t sas_dtc;
    uint8_t choice;

    while (attempts < 3) {
        printf("ENTER PIN CODE: ");
        scanf("%hu", &user_pin);
        if (user_pin == SAS_PIN) {
            printf("[SAS ECU]: ACCESS GRANTED!\n");
            break;
        }
        else {
            attempts++;
            if (attempts < 3) {
                printf("[DENIED]: PLEASE ENTER PIN CODE AGAIN\n");
            }
        }
    }

    if (user_pin != SAS_PIN) {
        printf("[SAS ECU]: KHOA HE THONG TECH\n");
        return 0;
    }

    for (uint8_t i = 1; i <= 3; i++) {
        printf("NHAP GOC DO DANH LAI LAN %d: ", i);
        scanf("%f", &steering_angle);

        if (steering_angle < -540.0f || steering_angle > 540.0f) {
            printf("[SENSOR ERROR]: TIN HIEU GOC LAI LAN %d BI NHIEU! NHAP LAI\n", i);
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
        printf("[WARNING DANGER]: PHAT HIEN DANH LAI GAP UNG PHANH ABS/ESP!\n");
        sas_dtc = 0xC1;
    }
    else if (avg_angle > 15.0f || avg_angle < -15.0f) {
        printf("[WARNING]: XE DANG LECH HUONG HANH TRINH!\n");
        sas_dtc = 0xC2;
    }
    else if (-15.0f <= avg_angle && avg_angle <= 15.0f) {
        printf("[SAS OK]: GOC LAI TRONG NGUONG AN TOAN.\n");
        sas_dtc = 0x00;
    }

    do {
        printf("=== SAS DASHBOARD MENU ===\n");
        printf("1. Xem goc lai trung binh & Ma DTC Code (HEX)\n");
        printf("2. Kiem tra dung luong RAM cua bien (sizeof)\n");
        printf("3. Thoat chuong trinh\n");
        printf("==========================\n");
        printf("Nhap lua chon (1-3): ");
        scanf("%hhu", &choice);

        switch (choice) {
            case 1: 
            printf("Goc lai trung binh la: %.1f deg\n", avg_angle);
            printf("Ma DTC Code: 0x%02X\n", sas_dtc);
            break;

            case 2: 
            printf("Dung luong RAM cua bien avg_angle: %zu\n", sizeof(avg_angle));
            printf("Dung luong RAM cua bien sas_dtc: %zu\n", sizeof(sas_dtc));
            break;

            case 3: 
            printf("[SAS ECU]: THOAT CHUONG TRINH!\n");
            break;

            default:
            printf("LUA CHON KHONG HOP LE: %d\n", choice);
        }

    } while (choice != 3);

    return 0;
}