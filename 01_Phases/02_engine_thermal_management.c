#include <stdio.h> 
#include <stdint.h> 

int main() {
    const uint16_t ACCESS_PIN = 8888;
    uint16_t user_pin;
    uint8_t attempts = 0;
    float temp;
    float total_temp = 0.0;
    float avg_temp; 
    uint8_t dtc_code;
    uint8_t choice;

    while (attempts < 3) {
        printf("NHAP MA PIN: ");
        scanf("%hu", &user_pin);

        if (user_pin == ACCESS_PIN) {
            printf("[SUCCESS]: MA PIN DUNG! DANG NHAP THANH CONG\n");
            break;
        }
        else {
            attempts++;
            if (attempts < 3) {
                printf("[DENIED]: MA PIN SAI! VUI LONG NHAP LAI!\n");
            }
        }
    }

    if (user_pin != ACCESS_PIN) {
        printf("[FAILED]: DANG NHAP KHONG THANH CONG!\n");
        return 0;
    }
    
    for (uint8_t i =1; i <= 3; i++) {
        printf("NHAP NHIET DO LAN THU %d: ", i);
        scanf("%f", &temp);
        if (temp < 0.0f || temp > 200.0f) {
            printf("LOI NHIEU!!!\n");
            i--;
            continue;
        }
        total_temp += temp;
    }

    avg_temp = total_temp / 3.0f;

    if (avg_temp > 115.0f) {
        printf("[WARNING SIGN]: DONG CO QUA NHIET!\n");
        dtc_code = 0xE1;
    }
    else if (avg_temp >= 80.0f) {
        printf("[NORMAL SIGN]: NHIET DO HOAN HAO!\n");
        dtc_code = 0x00;
    }
    else if (avg_temp < 80.0f) {
        printf("[WARNING SIGN]: CHUA DAT NHIET DO HOAT DONG!\n");
        dtc_code = 0xE2;
    }

    do {
        printf("=============\n");
        printf("=== MENU ===\n");
        printf("1. XEM NHIET DO TRUNG BINH VA XEM MA HEX CUA DTC: \n");
        printf("2. KIEM TRA COI CANH BAO BUZZER: \n");
        printf("3. AUDIT RAM: \n");
        printf("4. EXIT \n");
        printf("==============\n");
        printf("SELECT CHOICE: ");
        scanf("%hhu", &choice);

        switch (choice) {
            case 1: 
            printf("NHIET DO TRUNG BINH: %.2f\n", avg_temp);
            printf("MA HEX CUA DTC: 0x%02X\n", dtc_code);
            break;

            case 2: 
            if (dtc_code == 0xE1) {
                printf("[WARNING SOUND]: BIPPPPP! BIPPPPP! BIPPPPP! (DONG CO QUA NHIET)\n");
            }
            else if (dtc_code == 0x00) {
                printf("[NORMAL]: KHONG CO COI (NHIET DO HOAN HAO)\n");
            }
            else if (dtc_code == 0xE2) {
                printf("[WARNING SOUND]: Bip...!Bip...!Bip... (CHUA DAT NHIET DO HOAT DONG)\n");
            }
            break;

            case 3: 
            printf("AUDIT RAM OF AVERAGE TEMPERATURE: %zu bytes\n", sizeof(avg_temp));
            printf("AUDIT RAM OF DTC CODE: %zu bytes\n", sizeof(dtc_code));
            break;

            case 4:
            printf("EXIT\n");
            break;

            default: 
            printf("LUA CHON KHONG HOP LE: %d\n", choice);
            break;
        }
    } while (choice != 4);

    return 0;
}