#include <stdio.h> 
#include <stdint.h> 
#define ROWS 3
#define COLS 3

int main(void) {
    uint16_t adas_matrix[ROWS][COLS] = {0};
    uint16_t diag_main_diff = 0;
    uint16_t diag_sub_diff = 0;
    uint16_t min_dist = 65535; 
    uint16_t col_avg[COLS] = {0};
    uint8_t emergency_brake = 0;
    uint8_t adas_dtc = 0x00;
    uint8_t has_sensor_error = 0;

    // PHASE 1: NHẬP DỮ LIỆU & LỌC BOUNDARY CHECK 
    for (uint8_t i = 0; i < ROWS; i++) {
        for (uint8_t j = 0; j < COLS; j++) {
            printf("ENTER SAMPLE AT ROW %u COL %u: ", i + 1, j + 1);
            scanf("%hu", &adas_matrix[i][j]);

            if (adas_matrix[i][j] < 20 || adas_matrix[i][j] > 1500) {
                printf("[ADAS ERROR AT ROW %u COL %u]: INVALID DISTANCE (%hu cm)\n", i + 1, j + 1, adas_matrix[i][j]);
                has_sensor_error = 1; 
                continue;
            }
        }
    }

    // PHASE 2: QUÉT TÌM MIN TOÀN MA TRẬN (VẬT CẢN GẦN NHẤT)
    for (uint8_t i = 0; i < ROWS; i++) {
        for (uint8_t j = 0; j < COLS; j++) {
            if (adas_matrix[i][j] >= 20 && adas_matrix[i][j] <= 1500) {
                if (min_dist > adas_matrix[i][j]) {
                    min_dist = adas_matrix[i][j];
                }
            }
        }
    }
    if (min_dist < 50 && min_dist >= 20 && min_dist <= 1500) {
        emergency_brake = 1;
    }

    // PHASE 3: GOM TỔNG & TRUNG BÌNH THEO CỘT (COLUMN-MAJOR) 
    for (uint8_t j = 0; j < COLS; j++) {
        uint8_t count = 0;
        uint32_t sum_col = 0;
        for (uint8_t i = 0; i < ROWS; i++) {
            if (adas_matrix[i][j] >= 20 && adas_matrix[i][j] <= 1500) {
                sum_col += adas_matrix[i][j];
                count++;
            }
        }

        if (count > 0) {
            col_avg[j] = sum_col / count;
        }
        else if (count == 0) {
            col_avg[j] = 0;
        }
    }

    // PHASE 4: THAO TÁC 2 ĐƯỜNG CHÉO (DIAGONAL & ANTI-DIAGONAL)
    if (adas_matrix[0][0] >= 20 && adas_matrix[0][0] <= 1500 && adas_matrix[2][2] >= 20 && adas_matrix[2][2] <= 1500) {
        if (adas_matrix[0][0] >= adas_matrix[2][2]) {
            diag_main_diff = adas_matrix[0][0] - adas_matrix[2][2];
        }
        else {
            diag_main_diff = adas_matrix[2][2] - adas_matrix[0][0];
        }
    }

    if (adas_matrix[0][2] >= 20 && adas_matrix[0][2] <= 1500 && adas_matrix[2][0] >= 20 && adas_matrix[2][0] <= 1500) {
        if (adas_matrix[0][2] >= adas_matrix[2][0]) {
            diag_sub_diff = adas_matrix[0][2] - adas_matrix[2][0];
        }
        else {
            diag_sub_diff = adas_matrix[2][0] - adas_matrix[0][2];
        }
    }

    // PHASE 5: PHÂN LOẠI MÃ LỖI DTC & IN BÁO CÁO
    // MÃ LỖI DTC
    if (has_sensor_error == 1) {
        adas_dtc = 0xFF;
    }
    else if (emergency_brake == 1 && has_sensor_error == 0) {
        adas_dtc = 0xE1;
    }
    else {
        adas_dtc = 0x00;
    }
    // BÁO CÁO
    printf("==========================================================\n");
    printf("-------------------- ADAS MATRIX 3x3 --------------------\n");
    printf("ROWS\\COLS\t\tCOL 1\t\tCOL 2\t\tCOL 3\n");
    for (uint8_t i = 0; i < ROWS; i++) {
        printf("ROW %u\t\t\t", i + 1);
        for (uint8_t j = 0; j < COLS; j++) {
            printf("%hu\t\t", adas_matrix[i][j]);
        }
        printf("\n");
    }
    printf("AVGERAGE DISTANCE\t");
    for (uint8_t j = 0; j < COLS; j++) {
        if (col_avg[j] > 0) {
            printf("%hu\t\t", col_avg[j]);
        }
    }
    printf("\n");
    printf("==========================================================\n");
    if (min_dist != 65535) {
        printf("MIN DISTANCE: %hu (cm)\n", min_dist);
    }
    else {
        printf("MIN DISTANCE: NOISE\n");
    }

    if (diag_main_diff > 0) {
        printf("DIAG MAIN DIFF: %hu (cm)\n", diag_main_diff);
    }
    else {
        printf("DIAG MAIN DIFF: NOISE\n");
    }

    if (diag_sub_diff > 0) {
        printf("DIAG SUB DIFF: %hu (cm)\n", diag_sub_diff);
    }
    else {
        printf("DIAG SUB DIFF: NOISE\n");
    }
    printf("ADAS DTC: 0x%02X\n", adas_dtc);
    return 0;
}