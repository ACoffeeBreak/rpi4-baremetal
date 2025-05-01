#include "system_timer.h"

extern uint64_t read_timer();

void see_time() {
    // Just terminal gets? void -> char for program, for systems.
    /* Kendi ekrana yazma işini burada yapmak yerine değer döndürmek,
    bize daha kaliteli ve yönetimi kolay bir sistem sağlayabilir.
    */
    uint64_t time = read_timer();
    printf("System Time: %llu microseconds", time);
}