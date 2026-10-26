#include <cstdio>

int main() {
    int* t = new int[10];
    t[0] = 42;
    delete[] t;
    
    // On lit apres avoir rendu la memoire (erreur !)
    printf("Valeur lue apres delete : %d\n", t[0]);
    
    return 0;
}