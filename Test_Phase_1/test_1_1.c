#include <stdio.h> 
#include <stdint.h>

int main(){
    // 1.Khai báo & Khởi tạo biến:
    float distance;
    float total_distance = 0.0f;
    float avg_distance;
    uint8_t alert_level; 
    // 2. Vòng lặp for & Lọc nhiễu:
    for (uint8_t i = 1; i <= 3; i++ ){
        printf("Nhap khoang cach do lan %d (cm): ", i);
        scanf("%f", &distance);
        if (distance < 0.0f || distance > 500.0f) {
            printf("[NOISE]: Tin hieu cam bien nhieu! Nhap lai.\n");
            i--;
            continue;
        }
        total_distance += distance;
    }

    // 3.Xử lý khoảng cách trung bình & Phân mức Cảnh báo:
    avg_distance = total_distance / 3.0f;
    printf("Khoang cach trung binh: %.2f (cm).\n", avg_distance);
    if (avg_distance < 30.0f) {
        printf("[CRITICAL]: DUNG XE KHAN CAP! SAP VA CHAM!.\n");
        alert_level = 3;
    }
    else if (avg_distance <= 100.0f) {
        printf("[WARNING]: KHOANG CACH GAN! CHU Y PHANH.\n");
        alert_level = 2;
    }
    else {
        printf("[SAFE]: KHOANG CACH AN TOAN.");
        alert_level = 1;
    }

    // 4. Xử lý âm thanh cảnh báo:
    switch (alert_level) {
        case 1: 
        printf("[BUZZER]: Bip... Bip... (Cham)\n");
        break;

        case 2: 
        printf("[BUZZER]: Bip! Bip! Bip! (Nhanh)\n");
        break;

        case 3:
        printf("[BUZZER]: BIIIIIIP! (Keu lien tuc!)\n");
        break;

        default:
        printf("[BUZZER ERROR]: Loi chuong canh bao!\n");
        break;
    }

    // 5. Xuat thong so RAM & Dinh dang HEX:
    printf("Thong so RAM: %zu bytes | HEX: 0x%02X\n", sizeof(alert_level), alert_level);
    return 0;
}