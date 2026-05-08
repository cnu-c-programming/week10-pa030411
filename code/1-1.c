#include <stdio.h>
#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif

struct S1 {
    char c;
    int i;
    long long l;
};

struct S2 {
    char c;
    int i;
    long long l;
} __attribute__((packed));

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
    struct S1 s1;
    struct S2 s2;
    char out[100];

    sprintf(out, "%zu %zu\n", sizeof(s1), sizeof(s2));
    print_utf16(out);

    return 0;
}
