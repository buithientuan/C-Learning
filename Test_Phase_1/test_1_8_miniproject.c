#include <stdio.h> 
#include <stdint.h> 

int main(){
    const uint16_t TECH_PIN = 9999;
    uint16_t user_pin;
    uint8_t attempts = 0;
    uint8_t has_locked_wheel = 0;
    float wheel_speed;
    float total_speed = 0.0f;
    float avg_speed;
    uint8_t abs_dtc;
    uint8_t choice;

    while (attempts < 3) {
        printf("Nhap ma PIN lan %d: ", attempts + 1 );
        scanf("%hu", &user_pin);

        if (user_pin == TECH_PIN) {
            printf("[ABS ECU]: DANG NHAP THANH CONG!\n");
            break;
        }
        else {
            attempts++;
            if (attempts < 3) {
                printf("[DENIED]: MA PIN SAI! VUI LONG NHAP LAI!\n");
            }
        }
    }

    if (user_pin != TECH_PIN) {
        printf("[ABS ECU]: KHOA HE THONG TECH\n");
        return 0;
    }

    for (uint8_t i =1; i <= 4; i++) {
        printf("Nhap toc do banh xe lan %d: ", i);
        scanf("%f", &wheel_speed);

        if (wheel_speed < 0.0f || wheel_speed > 250.0f) {
            printf("[SENSOR ERROR]: TOC DO BANH %d KHONG HOP LE! NHAP LAI.\n", i);
            i--;
            continue;
        }
        else if (wheel_speed <= 5.0f) {
            has_locked_wheel = 1;
        }
        total_speed += wheel_speed;
    }

    avg_speed = total_speed / 4.0f;

    if (avg_speed > 100.0f && has_locked_wheel == 1) {
        printf("[ABS CRITICAL]: PHANH BO CUNG! KICH HOAT PHANH ABS!\n");
        abs_dtc = 0xA1;
    }
    else if (avg_speed > 0.0f) {
        printf("[ABS NORMAL]: HE THONG HOAT DONG BINH THUONG.\n");
        abs_dtc = 0x00;
    }
    else if (avg_speed == 0.0f) {
        printf("[ABS STANDBY]: XE DANG DUNG YEN.\n");
        abs_dtc = 0x05;
    }

    do {
        printf("=== MENU DIEU KHIEN ===\n");
        printf("1. In avg_speed vaf dang HEX cua abs_dtc: \n");
        printf("2. In kich thuoc bo nho RAM cua avg_speed va abs_dtc: \n");
        printf("3. Thoat chuong trinh: \n");
        printf("=========================================\n");
        printf("Vui long nhap so (1-3): ");
        scanf("%hhu", &choice);

        switch (choice) {
            case 1: 
            printf("Toc do trung binh: %.1f\n", avg_speed);
            printf("Ma HEX cua abs_dtc: 0x%02X\n", abs_dtc);
            break;

            case 2: 
            printf("Kich thuoc bo nho RAM cua avg_speed: %zu\n", sizeof(avg_speed));
            printf("Kich thuoc bo nho RAAM cua abs_dtc: %zu\n", sizeof(abs_dtc));
            break;

            case 3: 
            printf("[ABS ECU]: THOAT CHUONG TRINH\n");
            break;

            default: 
            printf("Lua chon khong hop le: %d\n", choice);

        }    
    } while (choice != 3);

    return 0;
}