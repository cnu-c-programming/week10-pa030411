#include <stdio.h>
#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif

struct access_rights {
    unsigned char execute : 1;
    unsigned char write : 1;
    unsigned char read : 1;
};

union file_access_rights {
    unsigned int int_value;
    struct access_rights rights;
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
    union file_access_rights some_file = {0};
    char out[100];

    some_file.rights.read = 1;
    some_file.rights.write = 0;
    some_file.rights.execute = 1;
    sprintf(out, "current mode: %u\n", some_file.int_value);
    print_utf16(out);

    return 0;
}
