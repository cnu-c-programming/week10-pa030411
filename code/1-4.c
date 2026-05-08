#include <stdio.h>
#include <string.h>
#include <time.h>

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

int main() {
    struct IPv4 s;
    clock_t start, finish;

    start = clock();
    for (int i = 0; i < 1e7; i++) {
        update_val(s);
    }
    finish = clock();
    printf("%f\n", (double)(finish - start) / CLOCKS_PER_SEC);

    start = clock();
    for (int i = 0; i < 1e7; i++) {
        update_ptr(&s);
    }
    finish = clock();
    printf("%f\n", (double)(finish - start) / CLOCKS_PER_SEC);

    return 0;
}
