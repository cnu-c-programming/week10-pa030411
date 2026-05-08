#include <stdio.h>

struct access_rights {
    unsigned char execute : 1;
    unsigned char write : 1;
    unsigned char read : 1;
};

union file_access_rights {
    unsigned int int_value;
    struct access_rights rights;
};

int main() {
    union file_access_rights some_file = {0};

    some_file.rights.read = 1;
    some_file.rights.write = 0;
    some_file.rights.execute = 1;
    printf("current mode: %u\n", some_file.int_value);

    return 0;
}
