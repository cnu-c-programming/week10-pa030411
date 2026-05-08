#include <stdio.h>

union U {
    float f;
    unsigned char c[4];
};

int main() {
    union U u;

    u.f = 3.14;
    for (int i = 0; i < 4; i++) {
        printf("%x\n", (unsigned)u.c[i]);
    }

    return 0;
}
