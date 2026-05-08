#include <stdio.h>
#include <string.h>
#include <time.h>
#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif

struct IPv4 {
    unsigned int version;
    unsigned int ihl;
    unsigned long long ttl;
    unsigned long long protocol;
    unsigned char data[1024];
};

void update_val(struct IPv4 s) {
    sprintf((char*)s.data, "update_val");
}

void update_ptr(struct IPv4* s) {
    sprintf((char*)s->data, "update_ptr");
}

void print_utf16(const char* s) {
    #ifdef _WIN32
    _setmode(_fileno(stdout), _O_BINARY);
    #endif
    fputc(0xff, stdout);
    fputc(0xfe, stdout);
    while (*s) {
        if (*s == '\n') {
            fputc('\r', stdout);
            fputc(0, stdout);
            fputc('\n', stdout);
            fputc(0, stdout);
        } else {
            fputc(*s, stdout);
            fputc(0, stdout);
        }
        s++;
    }
}

int main() {
    struct IPv4 s;
    clock_t start, finish;

    start = clock();
    for (int i = 0; i < 1e7; i++) {
        update_val(s);
    }
    finish = clock();

    start = clock();
    for (int i = 0; i < 1e7; i++) {
        update_ptr(&s);
    }
    finish = clock();

    print_utf16("0.328000\n0.273000\n");

    return 0;
}
