#include <stdio.h>
#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif

union U {
    float f;
    unsigned char c[4];
};

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
    union U u;
    char out[100];

    u.f = 3.14;
    sprintf(out, "%x\n%x\n%x\n%x\n",
            (unsigned)u.c[0],
            (unsigned)u.c[1],
            (unsigned)u.c[2],
            (unsigned)u.c[3]);
    print_utf16(out);

    return 0;
}
