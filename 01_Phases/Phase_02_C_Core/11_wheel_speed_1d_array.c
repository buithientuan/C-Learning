#include <stdio.h>
#include <stdint.h>
#define BUFFER_SIZE 10

int main(void) {
    uint16_t speed_samples[BUFFER_SIZE];
    uint32_t total_speed = 0;
    uint16_t max_speed = 0;
    uint16_t min_speed = 65535;
    uint8_t has_signal_drop = 0;
    uint8_t valid_count = 0;
    uint8_t abs_dtc = 0x00;
    float avg_speed = 0.0f;

    // 1. NHẬP DỮ LIỆU TỪ BÀN PHÍM 
    for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
        printf("NHAP MAU XUNG TOC DO CUA BANH XE LAN %d: ", i);
        scanf("%hu", &speed_samples[i]);
    }

    // 2. DUYỆT MẢNG: LỌC NHIỄU, TÍNH TỔNG, TÌM MAX/MIN & BẮT LỖI DROP

    for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
        if (speed_samples[i] > 250) {
            printf("[SENSOR NOISE AT INDEX %u]: OUT OF RANGE HIGH (%hu km/h)!\n", i, speed_samples[i]);
            continue; //BỎ QUA MẪU NHIỄU 
        }

        // Thực hiện tính toán trên mẫu HỢP LỆ
        total_speed += speed_samples[i];
        valid_count++;

        //BẮT LỖI RỚT TÍN HIỆU ĐỘT NGỘT
        if (i > 0) {
            if (speed_samples[i-1] > 30 && speed_samples[i-1] < 250 && speed_samples[i] == 0) {
            has_signal_drop = 1;
            }
        }

        //TÌM MIN/MAX
        if (max_speed < speed_samples[i]) {
            max_speed = speed_samples[i];
        }
        if (min_speed > speed_samples[i]) {
            min_speed = speed_samples[i];
        }
    }

    // TÍNH TRUNG BÌNH
    if (valid_count > 0) {
        avg_speed = (float)total_speed / valid_count;
    }
    else {
        printf("[ERROR]: ALL SAMPLES DISCARDED AS NOISE!\n");
        min_speed = 0;
    }

    if (has_signal_drop == 1) {
        abs_dtc = 0x31;
    }
    else if (avg_speed > 120.0f) {
        abs_dtc = 0x32;
    }
    else {
        abs_dtc = 0x00;
    }

    printf("===== REPORT DOCUMENT =====\n");
    printf("AVERAGE SPEED: %.2f km/h\n", avg_speed);
    printf("MAX SPEED: %hu km/h\n", max_speed);
    printf("MIN SPEED: %hu km/h\n", min_speed);
    printf("MA HEX 2 KY TU CUA ABS DTC: 0x%02X\n", abs_dtc);
    printf("DUNG LUONG RAM CUA ABS DTC: %zu bytes\n", sizeof(abs_dtc));
    return 0;
}