#include <stdio.h>
#include <stdint.h>

int main(){
    const uint16_t TPMS_PIN = 7777;
    uint8_t attempts = 0;
    uint16_t  user_pin;
    uint8_t has_flat_tire = 0;
    float tire_press;
    float total_press = 0.0f;
    float avg_press;
    uint8_t tpms_dtc;
    uint8_t choice;

    while (attempts < 3) {
        printf("NHAP MA PIN DE KICH HOAT LAN THU %d: ", attempts + 1);
        scanf("%hu", &user_pin);

        if (user_pin == TPMS_PIN) {
            printf("[TPMS ECU]: ACCESS GRANTED! \n");
            break;
        }
        else {
            attempts++;
            if(attempts < 3) {
                printf("[DENIED]: MA PIN SAI! VUI LONG NHAP LAI!\n");
            }
        }
    }

    if (user_pin != TPMS_PIN) {
        printf("[TPMS ECU]: KHOA HE THONG TECH!\n");
        return 0;
    }

    for (uint8_t i = 1; i <= 4; i++) {
        printf("NHAP AP SUAT BANH THU %d: ", i);
        scanf("%f", &tire_press);
        
        if (tire_press < 0.0f || tire_press > 60.0f) {
            printf("[SENSOR ERROR]: TIN HIEU LOP %d BI NHIEU! NHAP LAI!\n", i);
            i--;
            continue;
        }
        if (tire_press <= 15.0f) {
            has_flat_tire = 1;
        }

        total_press += tire_press;
    }

    avg_press = total_press / 4.0f;

    if (has_flat_tire == 1 || avg_press < 25.0f){
        printf("[WARNING DANGER]: PHAT HIEN LOP NON/XI HOI KHAN CAP!\n");
        tpms_dtc = 0xEA;
    }
    else if (avg_press > 35.0f) {
        printf("[WARNING]: AP SUAT LOP QUA CANG!\n");
        tpms_dtc = 0xEB;
    }
    else if (25.0f <= avg_press && avg_press <= 35.0f) {
        printf("[TPMS 0K]: AP SUAT LOP DAT CHUAN AN TOAN\n");
        tpms_dtc = 0x00;
    }

    do {
        printf("=== TPMS DASHBOARD MENU ===\n");
        printf("1. Xem ap suat trung binh & Ma DTC Code (Hex)\n");
        printf("2. Kiem tra dung luong RAM cua bien (sizeof)\n");
        printf("3. Thoat chuong trinh");
        printf("============================\n");
        printf("Nhap lua chon (1-3): ");
        scanf("%hhu", &choice);

        switch (choice) {
            case 1: 
            printf("Ap suat trung binh la: %.2f\n", avg_press);
            printf("Dang HEX cua tpms_dtc: 0x%02X\n", tpms_dtc);
            break;

            case 2: 
            printf("Kich thuoc bytes cua avg_press: %zu bytes\n", sizeof(avg_press));
            printf("Kich thuoc bytes cua tpms_dtc: %zu bytes\n", sizeof(tpms_dtc));
            break;

            case 3: 
            printf("[TPMS ECU]: THOAT CHUONG TRINH");
            break;

            default: 
            printf("LUA CHON KHONG HOP LE: %d\n", choice);
        }       
    } while (choice != 3);

    return 0;
}