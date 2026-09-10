#include <stdio.h>
#include <stdint.h>

int main (){
    uint8_t mode_choice;
    do {
        printf("================================\n");
        printf("=== ECU DRIVE MODE SELECTOR ===\n");
        printf("1. Che do ECO (Tiet kiem nhien lieu)\n");
        printf("2. Che do SPORT (Tang toc nhanh)\n");
        printf("3. Che do RACE (Hieu suat toi da)\n");
        printf("4. Thoat (EXIT)\n");
        printf("--------------------------------\n");

        printf("Nhap lua chon (1-4): ");
        scanf("%hhu", &mode_choice);

        switch (mode_choice) {
            case 1:
            printf("[ECU SETTING]: Da kich hoat che do ECO! Tiet kiem nhien lieu.\n");
            break;

            case 2: 
            printf("[ECU SETTING]: Da kich hoat che do SPORT! Nhay chan ga 100%.\n");
            break;

            case 3:
            printf("[ECU SETTING]: Da kich hoat che do RACE! Ngat kiem soat luc keo!\n");
            break;

            case 4: 
            printf("[SYSTEM]: LUU CAI DAT. THOAT HE THONG MENU!\n");
            break;

            default:
            printf("[ERROR]: Lua chon %d khong hop le! Vui long nhap 1-4.\n", mode_choice);
            break;
        }
    } while (mode_choice != 4);

    return 0;
}