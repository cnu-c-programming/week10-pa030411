#include <stdio.h>
#include <string.h>

struct IPv4 {
    unsigned int version;
    unsigned int ihl;
    unsigned long long ttl;
    unsigned long long protocol;
    unsigned char data[1024];
};

int main() {
    struct IPv4 s;

    s.version = 0;
    s.ihl = 0;
    s.ttl = 256;
    s.protocol = 0;
    sprintf((char*)s.data, "hello world");

    printf("version: %u, size: %zu\n", s.version, sizeof(s.version));
    printf("ihl: %u, size: %zu\n", s.ihl, sizeof(s.ihl));
    printf("ttl: %llu, size: %zu\n", s.ttl, sizeof(s.ttl));
    printf("protocol: %llu, size: %zu\n", s.protocol, sizeof(s.protocol));
    printf("data: %s, size: %zu\n", s.data, sizeof(s.data));

    return 0;
}
