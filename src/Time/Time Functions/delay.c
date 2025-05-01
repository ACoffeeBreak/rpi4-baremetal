#include "system_timer.h"

void delay(uint64_t microseconds) {
    uint64_t start_time = read_timer();
    // ASM fonksiyonlarının isimleri ayrı olmalı.
    while (read_timer() - start_time < microseconds) {}
}