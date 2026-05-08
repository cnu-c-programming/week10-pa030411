#include <stdio.h>

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

int main() {
    struct S1 s1;
    struct S2 s2;

    printf("%zu %zu\n", sizeof(s1), sizeof(s2));

    return 0;
}
