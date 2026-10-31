#include <cstdio>

struct P {
    int a;
    P(int v) : a(v) {}
    // P() : a(0) {}
    P() = default;
};

int main() {
    P x;
    P t[10];
    printf("x.a = %d\n", x.a);
    return 0;
}