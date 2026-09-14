#include <stdio.h> 
#include <stdint.h>

int main () {
    //KHAI BAO CAC BIEN CAN THIET
    const uint16_t SMARTKEY_CODE = 5555;
    uint16_t USER_CODE;
    uint16_t bcm_dtc = 0x0000;
    uint8_t attempts = 0;
    uint8_t has_flat_tire = 0;
    uint8_t choice;
    float tire_press;
    float total_press = 0.0f;
    float avg_press;
    char gear_mode;

    // MODULE 1: SMARTKEY SECURITY SYSTEM 
    while (attempts < 3) {
        printf("ENTER SMARTKEY CODE: ");
        scanf("%hu", &USER_CODE);

        if (USER_CODE == SMARTKEY_CODE) {
            printf("[BCM SYSTEM]: SMARTKEY AUTHENTICATED! SYSTEM READY!\n");
            break;
        }
        else {
            attempts++;
            if (attempts < 3) {
                printf("[BCM SYSTEM]: FAILED! WRONG SMARTKEY CODE! PLEASE ENTER AGAIN!\n");
            }
        }
    }

    if (USER_CODE != SMARTKEY_CODE) {
        printf("[SECURITY ALARM]: UNAUTHORIZED ACCESS! SYSTEM LOCKED!\n");
        return 0;
    }

    // MODULE 2: TPMS SIGNAL FILTERING & PROCESSING
    for (uint8_t i = 1; i <= 4; i++) {
        printf("ENTER THE TIRE PRESS: ");
        scanf("%f", &tire_press);

        if (tire_press < 0.0f || tire_press > 60.0f) {
            printf("[SENSOR ERROR]: INVALID DATA!\n");
            i--;
            continue;
        }
        if (tire_press <= 15.0f) {
            has_flat_tire = 1;
        }
        total_press += tire_press;
    }
    avg_press = total_press / 4.0f;

    // MODULE 3: DIAGNOSTIC TROUBLE CODE (DTC) STATE MACHINE
    if(has_flat_tire == 1 || avg_press < 25.0f) {
        printf("[DIAGNOSTIC]: CRITICAL TIRE FAILURE DETECTED!\n");
        bcm_dtc = 0xE01A;
    }
    else if (avg_press > 35.0f) {
        printf("[DIAGNOSTIC]: OVER-INFLATED TIRE WARNING!\n");
        bcm_dtc = 0xE01B;
    }
    else if (25.0f <= avg_press && avg_press <= 35.0f) {
        printf("[DIAGNOSTIC]: ALL SYSTEMS NORMAL!\n");
        bcm_dtc = 0x0000;
    }

    // MODULE 4: GEAR SELECTOR & ACTUATOR ALARM
    printf("===== GEAR SELECTOR CONTROL SYSTEM =====\n");
    printf("SELECT THE GEAR POSITION (P, R, N, D): ");
    scanf(" %c", &gear_mode);

    switch (gear_mode) {
        case 'p': 
        case 'P':
        printf("PARK\n");
        break;

        case 'r':
        case 'R':
        printf("REVERSE\n");
        break;

        case 'n':
        case 'N':
        printf("NEUTRAL\n");
        break;

        case 'd':
        case 'D':
        printf("Drive\n");
        break;

        default: 
        printf("[GEAR ERROR]: INVALID GEAR POSITION!\n");
        break;
    }

    if (bcm_dtc == 0xE01A && (gear_mode == 'D' || gear_mode == 'd')) {
        printf("[BUZZER ALARM]: BIIIIIP! BIIIIIP! DANGER: DRIVING ON FLAT TIRE!\n");
    }

    // MODULE 5: INTERACTIVE DIAGNOSTIC MENU & RAM AUDIT
    do {
        printf("==========================\n");
        printf("===== SELECTION MENU =====\n");
        printf("1. LIVE DIAGNOSTIC DATA\n");
        printf("2. SYSTEM STATUS & FLAGS\n");
        printf("3. RAM MEMORY AUDIT\n");
        printf("4. SHUTDOWN\n");
        printf("==========================\n");
        printf("ENTER YOUR SELECTION (1-4): ");
        scanf("%hhu", &choice);

        switch (choice) {
            case 1: 
            printf("AVERAGE TIRE PRESSURE: %.2f PSI\n", avg_press);
            printf("DIAGNOSTIC TROUBLE CODE: 0x%04X\n", bcm_dtc);
            break;

            case 2: 
            printf("GEAR MODE AT THE MOMENT: %c\n", gear_mode);
            printf("FLAT TIRE FLAG: %u\n", has_flat_tire);
            break;

            case 3: 
            printf("RAM SIZE OF SMARTKEY: %zu bytes\n", sizeof(SMARTKEY_CODE));
            printf("RAM SIZE OF AVERAGE PRESSURE TIRE: %zu bytes\n", sizeof(avg_press));
            printf("RAM SIZE OF DIAGNOSTIC TROUBLE CODE: %zu bytes\n", sizeof(bcm_dtc));
            printf("RAM SIZE OF GEAR MODE: %zu bytes\n", sizeof(gear_mode));
            break;

            case 4: 
            printf("[BCM SYSTEM]: SHUTTING DOWN CENTRAL ECU...\n");
            break;

            default:
            printf("INVALID SELECTION\n");
            break;
        }
    } while (choice != 4);

    return 0;
}