# 🚀 Phase 1: Automotive C Fundamentals

Welcome to **Phase 1** of the Automotive Embedded C & CLA Certification Roadmap. This module focuses on establishing a rock-solid foundation in C programming syntax, hardware-friendly data types (`<stdint.h>`), boundary condition handling, and memory auditing tailored for Electronic Control Units (ECUs).

---

## 📊 Module Roadmap & Integration Matrix

| Lesson ID | Topic & Core Concept | Technical Specs & Standards | Practical Source File | Status |
| :--- | :--- | :--- | :--- | :---: |
| **Lesson 01** | C Program Structure & Compilation Workflow | GCC Pipeline (`.c` $\to$ `.i` $\to$ `.s` $\to$ `.o` $\to$ `.exe`) | `01_c_program_structure.c` | ✅ Pass |
| **Lesson 02** | Input/Output Operations | `printf()`, `scanf()`, Buffer handling | Integrated in ECU Modules | ✅ Pass |
| **Lesson 03** | Automotive Data Types | Fixed-width types (`<stdint.h>`: `uint8_t`, `uint16_t`) | Integrated in ECU Modules | ✅ Pass |
| **Lesson 04** | Format Specifiers | `%hu`, `%hhu`, `%02X`, `%04X` Hex formatting | Integrated in ECU Modules | ✅ Pass |
| **Lesson 05** | Memory Audit & Constants | `const`, `sizeof` RAM byte size verification | Integrated in ECU Modules | ✅ Pass |
| **Lesson 06** | Overflow & Signed Representation | Two's Complement, Unsigned/Signed boundaries | Integrated in ECU Modules | ✅ Pass |
| **Lesson 07** | Type Casting & Integer Division | Real-number casting (`total / 4.0f`), float precision | Integrated in ECU Modules | ✅ Pass |
| **Lesson 08** | Conditional Branching (`if-else`) | Continuous threshold monitoring, Temperature logic | `02_engine_thermal_management.c` | ✅ Pass |
| **Lesson 09** | Multi-way Branching (`switch-case`) | DTC Hex parsing, State evaluation, Gear states | `03_abs_wheel_speed_monitor.c` | ✅ Pass |
| **Lesson 10** | Iteration Controls (`for`, `while`) | Sensor noise filtering, Timeout handling, Flat tire flags | `04_tpms_tire_pressure_diagnostic.c` / `05_sas_steering_angle_control.c` | ✅ Pass |

> 💡 **Architectural Note (Project-Based Learning):**  
> To mirror industrial automotive software practice, theoretical topics from **Lessons 02 through 07** were directly embedded into functional ECU sub-system simulators (`02` to `05`) rather than kept as isolated, trivial code snippets.

---

## 🧠 Key Technical Knowledge Gained

* **Hardware-Aware Typing:** Standardized on ISO C99 fixed-width integers (`uint8_t`, `uint16_t`) to prevent platform-dependent architecture bugs across 8-bit, 16-bit, and 32-bit Automotive MCUs.
* **Input Noise Filtering:** Built robust sensor noise rejection logic using range validation (`tire_press < 0.0f || tire_press > 60.0f`) combined with loop index rollback (`i--`) for fault-tolerant data acquisition.
* **State & Alarm Flags:** Implemented event-driven state assertion using lightweight boolean flags (`has_flat_tire`, `has_sharp_turn`, `has_locked_wheel`) for fast ECU control loops.
* **Memory Footprint Audit:** Used `sizeof()` operator to inspect stack allocation bytes for safety-critical variables (`avg_press`, `bcm_dtc`).

---

## 🛠️ Practiced ECU Sub-System Modules

### 1. `01_c_program_structure.c` — GCC Build Target
* Basic C execution structure and standard output demonstration.

### 2. `02_engine_thermal_management.c` — Engine Thermal Management (ECU)
* Monitors engine coolant temperature; triggers ECU buzzer alarm upon overheating thresholds.

### 3. `03_abs_wheel_speed_monitor.c` — Anti-Lock Braking System (ABS ECU)
* Processes 4-wheel pulse signals continuously; detects wheel lockup using simultaneous condition evaluation (`&&`).

### 4. `04_tpms_tire_pressure_diagnostic.c` — Tire Pressure Monitoring System (TPMS ECU)
* Acquires 4-tire PSI values; filters sensor noise, asserts flat tire flags ($\le 15.0\text{ PSI}$), and evaluates diagnostic DTC codes.

### 5. `05_sas_steering_angle_control.c` — Steering Angle Sensor (SAS ECU)
* Evaluates signed steering angles ($-540.0^\circ$ to $+540.0^\circ$); detects rapid steering maneuvers ($|x| > 90.0^\circ$) to command ESP/ABS intervention.

---

## ⚙️ Compilation & Build Verification

All modules in Phase 1 comply with the **C99 Standard** and compile clean with zero warnings under `-Wall`:

```bash
# Compile module with GCC on Windows/Linux
gcc -Wall -std=c99 04_tpms_tire_pressure_diagnostic.c -o 04_tpms_tire_pressure_diagnostic.exe

# Run Executable (Windows PowerShell / CMD)
.\04_tpms_tire_pressure_diagnostic.exe