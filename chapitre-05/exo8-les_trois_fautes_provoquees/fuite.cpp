#include <cstdio>

int main() {
    for (int i = 0; i < 1000; i = i + 1) {
        int* t = new int[100];
        t[0] = i; // on écrit dedans pour que le compilateur ne supprime pas le new
    }
    printf("Fin du programme\n");
    return 0;
}