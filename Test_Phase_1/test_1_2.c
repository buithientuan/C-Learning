#include <stdio.h>
#include <stdint.h>

int main(){
    // 1.Khai báo biến
    float pressure;
    float total_pressure = 0.0f;
    float avg_pressure;

    // 2. Dùng vòng lặp for chạy từ i = 1 đến 4:
    for ( uint8_t i = 1; i<=4; i++) {
        printf("Nhap ap suat lop lan %d (PSI): ", i);
        scanf("%f", &pressure);
        if (pressure < 0.0f || pressure >80.f){
            printf("[NOISE]: Tuyen tin hieu bi nhieu! Nhap lai.\n");
            i--;
            continue;
        }

        total_pressure += pressure;
    }

    // 3. Tính áp suất trung bình:
    avg_pressure = total_pressure / 4.0f;

    // 4. In ra avg_pressure lấy 2 chữ số thập phân:
    printf("Ap suat trung binh: %.2f\n", avg_pressure);

    // 5. Kiểm tra an toàn: 
    if (avg_pressure < 28.0f) {
        printf("[TPMS WARNING]: AP SUAT LOP THAP! CAN BOM THEM MANG AN TOAN.\n");
    }
    else if (avg_pressure > 38.0f) {
        printf("[TPMS WARNING]: AP SUAT LOP QUA CAO! CO NGUY CO CANG/NO LOP.\n");
    }
    else {
        printf("[TPMS OK]: AP SUAT LOP CHUAN DUG QUY DINH.\n");
    }
    return 0;
}