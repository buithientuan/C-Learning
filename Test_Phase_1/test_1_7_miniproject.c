#include <stdio.h>
#include <stdint.h>

int main(){
    const uint16_t ACCESS_PIN = 8888;
    uint16_t user_pin;
    uint8_t attempts = 0;
    float temp;
    float total_temp = 0.0f;
    float avg_temp;
    uint8_t dtc_code;
    uint8_t choice;

    while (attempts < 3) {
        printf("Nhap ma PIN de duoc vao he thong (lan %d): ", attempts + 1);
        scanf("%hu", &user_pin);

        if (user_pin == ACCESS_PIN) {
            printf("[SECURITY OK]: ACCESS GRANTED!\n");
            break;
        }
        else {
            attempts++;
            if (attempts < 3) {
                printf("[DENIED]: MA PIN SAI! VUI LONG NHAP LAI.\n");
            }
        }
    }

    if (user_pin != ACCESS_PIN) {
        printf("[SYSTEM LOCKED]: KHOA HE THONG DO SAI PIN 3 LAN!\n");
        return 0;
    }

    for (uint8_t i = 1; i <= 3; i++) {
        printf("Nhap nhiet do lan %d: ", i);
        scanf("%f", &temp);

        if (temp < 0.0f || temp > 200.0f) {
            printf("[NOISE FILTER]: Tin hieu cam bien nhieu! Nhap lai.\n");
            i--;
            continue;
        }
        total_temp += temp;
    }

    avg_temp = total_temp / 3.0f;

    if (avg_temp > 115.0f) {
        printf("[DANGER]: DONG CO QUA NHIET!\n");
        dtc_code = 0xE1;
    }
    else if (avg_temp >= 80.0f) {
        printf("[NORMAL]: NHIET DO DONG CO HOAN HAO.\n");
        dtc_code = 0x00;
    }
    else if (avg_temp < 80.0f) {
        printf("[WARNING]: DONG CO CHUA DAT NHIET DO HOAT DONG!\n");
        dtc_code = 0xE2;
    }

    do {
        printf("=== DIAGNOSTIC ECU MENU ===\n");
        printf("1. Xem nhiet do trung binh & Ma loi DTC (Hex)\n");
        printf("2. Kiem tra am thanh canh bao Buzzer\n");
        printf("3. Xuat thong so RAM he thong\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon (1-4): ");
        scanf("%hhu", &choice);

        switch (choice) {
        case 1: 
        printf("Nhiet do trung binh la: %.2f\n", avg_temp);
        printf("Ma HEX cua DTC: 0x%02X\n", dtc_code);
        break;

        case 2:
        if (dtc_code == 0xE1) {
            printf("[BUZZER]: BIIIIIIIIP! (Coi reo lien tuc)\n");
        }
        else if (dtc_code == 0xE2) {
            printf("[BUZZER]: Bip...Bip... (Coi reo cham)\n");
        }
        else if (dtc_code == 0x00) {
            printf("[BUZZER]: (Tat coi - He thong binh thuong)\n");
        }
        break;

        case 3:
        printf("Kich thuoc bo nho DTC: %zu\n", sizeof(dtc_code));
        printf("Kich thuoc bo nho avg_temp: %zu\n", sizeof(avg_temp));
        break;

        case 4:
        printf("[SYSTEM]: KET THUC QUY TRINH CHAN DOAN!\n");
        break;

        default:
        printf("Lua chon khong hop le: %d\n", choice);
        }

    } while ( choice !=4 );

    return 0;
}