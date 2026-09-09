#include <stdio.h> 
#include <stdint.h>

int main(){
    float speed = 1.0f;
    while (speed > 0.0f) {
        printf("Nhap toc do xe hien tai (kn/h - Nhap 0 de dung): ");
        scanf("%f", &speed);
        
        if (speed < 0.0f) {
            printf("[CRITICAL]: LOI CAM BIEN AM! THOAT KHAN CAP!\n");
            break;
        }
        
        if (speed > 120.0f) {
            printf("[SPEED WARNING]: VUOT QUA TOC DO CHO PHEP (120KM/H)!\n");
        }
        else if (speed > 0.0f) {
            printf("[SPEED OK]: TOC DO AN TOAN.\n");
        }
    }
    printf("[SYSTEM]: XE DA DUNG HAN DUNG QUY DINH (0km/h).\n");
    return 0;
}