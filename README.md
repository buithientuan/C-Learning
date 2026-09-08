**LỘ TRÌNH HỌC NGÔN NGỮ C**

**AUTOMOTIVE EMBEDDED & CLA CERTIFICATION**

Định hướng: Automotive Embedded Software Engineer + CLA Certification | Tỷ trọng: 70% Automotive — 30% CLA

\========================================================================

**MỤC I: C FUNDAMENTALS (Nền Tảng Căn Bản)**

**Mục tiêu: Làm chủ syntax, kiểu dữ liệu chuẩn ô tô, quản lý bộ nhớ cơ bản và toán tử.**

[x] Bài 1: Cấu trúc chương trình C: main(), #include, quy trình biên dịch (Preprocess -> Compile -> Assemble -> Link)

[x] Bài 2: Nhập và Xuất dữ liệu: printf(), scanf(), escape sequences (\n, \t)

[x] Bài 3: Biến & Kiểu dữ liệu Automotive: \<stdint.h> (int8\_t -> uint32\_t), float, double, char

[x] Bài 4: Mã định dạng (Format Specifiers): %hhd, %hhu, %hd, %hu, %d, %u, %zu (sizeof), %02X (Hex)

[x] Bài 5: Bản chất Bộ nhớ & Đo RAM: Khái niệm const, #define, toán tử sizeof đo dung lượng RAM

[x] Bài 6: Tràn số & Biểu diễn Số âm: Overflow Signed/Unsigned, Mã bù 2 (Two's Complement)

[x] Bài 7: Toán tử, Ép kiểu & Bẫy lập trình: Type casting, bẫy chia số nguyên (int/int), bẫy tràn phép nhân ECU

[x] Bài 8: Cấu trúc rẽ nhánh if / else (ĐANG HỌC): Toán tử so sánh (==, !=, >), logic (&&, ||, !), kiểm tra nhiệt độ động cơ

[x] Bài 9: Cấu trúc rẽ nhánh switch / case: switch, case, default, break, xử lý mã lỗi DTC, trạng thái P-R-N-D

[ ] Bài 10: Vòng lặp for, while, do-while: Vòng lặp, break, continue, đọc cảm biến liên tục, xử lý Timeout ECU

**MỤC II: C CORE (Lõi Ngôn Ngữ C & Con Trỏ)**

**Mục tiêu: Hiểu sâu mối quan hệ Biến -> Bộ nhớ -> Địa chỉ -> Con trỏ -> Thanh ghi.**

[ ] Bài 11: Mảng 1 chiều (1D Array): Khai báo, duyệt mảng, lưu chuỗi 10 giá trị xung cảm biến tốc độ bánh xe

[ ] Bài 12: Mảng 2 chiều (2D Array): Ma trận dữ liệu 2D, ECU Lookup Table / Engine Map

[ ] Bài 13: Chuỗi ký tự (String): Mảng char, ký tự \0, string.h (strlen, strcpy, strcmp, strcat)

[ ] Bài 14: Hàm (Functions): Prototype, return, truyền tham số, tách file .c và .h chuẩn C nhúng

[ ] Bài 15: Phạm vi biến & Storage Classes: Biến local vs global, từ khóa static và extern

[ ] Bài 16: Con trỏ cơ bản (Pointer): Địa chỉ &, giải tham chiếu \*, NULL pointer

[ ] Bài 17: Con trỏ & Mảng: Pointer arithmetic (ptr++, ptr + i), duyệt mảng bằng con trỏ

[ ] Bài 18: Con trỏ & Hàm: Pass-by-value vs Pass-by-reference, thay đổi biến qua con trỏ

**MỤC III: C ADVANCED FOR AUTOMOTIVE**

**Mục tiêu: Thao tác bit phần cứng thanh ghi, đóng/giải gói dữ liệu mạng CAN Bus.**

[ ] Bài 19: Toán tử Bitwise căn bản: Dịch bit << >>, Bitwise AND (&), OR (|), XOR (^), NOT (\~)

[ ] Bài 20: Thao tác Bit chuyên sâu ECU: Set bit, Clear bit, Toggle bit, Check bit thanh ghi vi điều khiển

[ ] Bài 21: Packing & Unpacking CAN Bus: Tách/Ghép dữ liệu 16-bit/32-bit thành mảng Byte (uint8\_t) gửi qua CAN

[ ] Bài 22: Cấu trúc (Struct): struct, typedef, gom nhóm thông số xe (Speed, RPM, Temp, Voltage)

[ ] Bài 23: Con trỏ Struct & Con trỏ ->: Truy cập member qua con trỏ (ptr->member), tối ưu RAM

[ ] Bài 24: Struct Padding & Memory Alignment: Cơ chế đệm bộ nhớ, \_\_attribute\_\_((packed)) trong mạng CAN

[ ] Bài 25: Tập hợp Hằng số (Enum): Enum trạng thái xe: Động cơ (OFF/START/RUN), Cần số (P/R/N/D)

[ ] Bài 26: Kiểu dữ liệu Dùng chung Bộ nhớ (Union): Khái niệm union, chia sẻ bộ nhớ, trích xuất dữ liệu CAN

**MỤC IV: MEMORY MANAGEMENT & CLA PREPARATION**

**Mục tiêu: Quản lý phân vùng bộ nhớ, an toàn bộ nhớ và luyện đề thi chứng chỉ CLA.**

[ ] Bài 27: Phân vùng Bộ nhớ: Stack, Heap, Data Segment, BSS Segment

[ ] Bài 28: Quản lý Bộ nhớ Động: malloc, calloc, realloc, free, Memory Leak, Dangling Pointer, Memory Safety

[ ] Bài 29: Từ khóa đặc biệt (const & volatile): const bảo vệ dữ liệu, volatile khai báo thanh ghi phần cứng & ngắt (ISR)

[ ] Bài 30: Debugging & Đọc lỗi Trình biên dịch: Đọc Compiler errors/warnings, dùng Debugger (Breakpoint, Watch, Step)

[ ] Bài 31: Ôn tập & Luyện đề Thi CLA: Giải mock test thi chứng chỉ CLA (C Certified Associate Programmer)

**MỤC VI: BONUS MODULES (BÀI HỌC BỔ TRỢ & NÂNG CAO)**

**Mục tiêu: Mở rộng tư duy kỹ sư nhúng chuyên nghiệp, chuẩn bị làm dự án lớn.**

[ ] Bonus 1: Con trỏ Hàm (Function Pointer): Callback mechanism, Jump Table / Event Driver trong ECU

[ ] Bonus 2: Máy trạng thái Hữu hạn (FSM): Finite State Machine cho Cửa sổ điện, Chế độ Lái, Sạc xe điện (EV)

[ ] Bonus 3: Cấu trúc Dữ liệu Nhúng: Circular Buffer / Ring Buffer cho UART/CAN, Hàng chờ FIFO Queue

[ ] Bonus 4: Thuật toán Kiểm tra Lỗi (CRC/Checksum): CRC-8 / CRC-16 bảo đảm toàn vẹn dữ liệu mạng CAN/LIN

[ ] Bonus 5: Tiêu chuẩn Lập trình Ô tô MISRA C: Tập quy tắc viết code C an toàn tuyệt đối trong ngành công nghiệp ô tô

[ ] Bonus 6: Thao tác File trong C (File I/O): Đọc/ghi file log (.txt, .csv) giả lập ECU Data Logger hành trình xe

[ ] Bonus 7: Build code với GCC & Makefile: Dùng lệnh gcc, viết Makefile tự động hóa biên dịch dự án nhiều file

[ ] Bonus 8: Quản lý Mã nguồn với Git & GitHub: Lệnh Git cơ bản (init, commit, push, branch), tạo Portfolio GitHub

**MỤC V: NỀN TẢNG TIẾP THEO (SAU C CORE)**

**Chuyển tiếp sang phần cứng và giao tiếp mạng ô tô thực tế.**

-> Phase 6: Embedded C & STM32: GPIO, Timer, PWM, ADC, UART, SPI, I2C, Interrupt, DMA

-> Phase 7: Giao tiếp Mạng CAN / CAN FD: CAN Frame, Arbitration, Baudrate, STM32 CAN Project

-> Phase 8: Kiến trúc Chuyên sâu ECU: Kiến trúc AUTOSAR, Tiêu chuẩn An toàn Chức năng ISO 26262
