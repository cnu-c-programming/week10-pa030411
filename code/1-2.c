#include <stdio.h>
#include <string.h>
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
    char out[2048];

    s.version = 0;
    s.ihl = 0;
    s.ttl = 256;
    s.protocol = 0;
    sprintf((char*)s.data, "hello world");

    sprintf(out,
            "version: %u, size: %zu\n"
            "ihl: %u, size: %zu\n"
            "ttl: %llu, size: %zu\n"
            "protocol: %llu, size: %zu\n"
            "data: %s, size: %zu\n",
            s.version, sizeof(s.version),
            s.ihl, sizeof(s.ihl),
            s.ttl, sizeof(s.ttl),
            s.protocol, sizeof(s.protocol),
            s.data, sizeof(s.data));
    print_utf16(out);

    return 0;
}
