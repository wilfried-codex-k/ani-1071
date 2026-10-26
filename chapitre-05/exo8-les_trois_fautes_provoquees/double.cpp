#include <cstdio>

int main() {
    int* t = new int[10];
    t[0] = 42;
    
    delete[] t;
    printf("Premiere liberation faite\n");
    
    delete[] t; // Deuxieme liberation sur le meme pointeur (erreur !)
    printf("Deuxieme liberation faite\n");

    return 0;
}