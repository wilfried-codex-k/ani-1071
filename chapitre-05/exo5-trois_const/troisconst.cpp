#include <cstdio>

int main() {
    int x = 1, y = 2;

    // 1. const int* a
    const int* a = &x;
    // *a = 5;  // ERREUR
    a = &y;     // OK
    
    // 2. int* const b
    int* const b = &x;
    *b = 5;     // OK
    // b = &y;  // ERREUR

    // 3. const int* const c
    const int* const c = &x;
    // *c = 5;  // ERREUR
    // c = &y;  // ERREUR

    return 0;
}