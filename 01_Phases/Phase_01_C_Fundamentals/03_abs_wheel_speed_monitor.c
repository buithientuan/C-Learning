#include <stdio.h> 
#include <stdint.h> 

int main() {
    const uint16_t TECH_PIN = 9999;
    uint16_t user_pin;
    uint8_t attempts = 0;
    float wheel_speed;
    float avg_speed;
    float total_speed = 0.0f;
    uint8_t has_locked_wheel = 0;
    uint8_t abs_dtc;
    uint8_t choice;

    while (attempts < 3) {
        printf("ENTER PIN CODE: ");
        scanf("%hu", &user_pin);

        if (user_pin == TECH_PIN) {
            printf("[ACCESS]: DANG NHAP THANH CONG\n");
            break;
        }
        else {
            attempts++;
            if (attempts < 3) {
                printf("[DENIED]: PIN CODE KHONG DUNG! VUI LONG NHAP LAI!\n");
            }
        }
    }

    if (user_pin != TECH_PIN) {
        printf("[FAILED]: TRUY CAP KHONG THANH CONG!\n");
        return 0;
    }

    for (uint8_t i = 1; i <= 4; i++) {
        printf("NHAP TOC DO BANH THU %d: ", i);
        scanf("%f", &wheel_speed);

        if (wheel_speed < 0.0f || wheel_speed > 250.0f) {
            printf("[ERROR]: THONG TIN KHONG HOP LE\n");
            i--;
            continue;
        }

        if (wheel_speed <= 5.0f) {
            has_locked_wheel = 1;
        }
        total_speed += wheel_speed;
    }

    avg_speed = total_speed / 4.0f; 

    if (avg_speed > 100.0f && has_locked_wheel == 1) {
        printf("[WARNING]: PHAT HIEN BANH BO CUNG! KICH HOAT PHANH ABS!\n");
        abs_dtc = 0xA1;
    }
    else if(avg_speed > 0.0f) {
        printf("[NORMAL]: HE THONG HOAT DONG BINH THUONG!\n");
        abs_dtc = 0x00;
    }
    else if (avg_speed == 0.0f) {
        printf("XE DUNG YEN\n");
        abs_dtc = 0x05;
    }

    do {
        printf("=================\n");
        printf("===== MENU ======\n");
        printf("1. XEM TOC DO TRUNG BINH VA MA HEX CUA ABS_DTC: \n");
        printf("2. XEM DUNG LUONG RAM CUA AVG_SPEED VA ABS_DTC: \n");
        printf("3. EXIT: \n");
        printf("==================\n");
        printf("VUI LONG NHAP LUA CHON: ");
        scanf("%hhu", &choice);

        switch (choice) {
            case 1:
            printf("TOC DO TRUNG BINH: %.2f km/h\n", avg_speed);
            printf("MA HEX CUA ABS_DTC: 0x%02X\n", abs_dtc);
            break;

            case 2:
            printf("DUNG LUONG RAM CUA AVG_SPEED: %zu bytes\n", sizeof(avg_speed));
            printf("DUNG LUONG RAM CUA ABS_DTC: %zu bytes\n", sizeof(abs_dtc));
            break;

            case 3: 
            printf("THOAT CHUONG TRINH\n");
            break;

            default: 
            printf("LUA CHON KHON HOP LE: %d\n", choice);
            break;
        }
    } while (choice != 3);

    return 0;
}