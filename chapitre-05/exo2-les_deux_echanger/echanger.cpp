#include <cstdio>

// 1. Version par pointeurs
void echanger(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 2. Version par references (surcharge)
void echanger(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 3. Version pour les doubles (references)
void echangerDouble(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

// 4. Version pour les chars (references)
void echangerChar(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 1, y = 2;

    printf("Avant pointeurs : %d %d\n", x, y);
    echanger(&x, &y); // L'appel avec des adresses
    printf("Apres pointeurs : %d %d\n", x, y);

    printf("Avant references : %d %d\n", x, y);
    echanger(x, y);   // L'appel sans adresses
    printf("Apres references : %d %d\n", x, y);

    double d1 = 3.14, d2 = 1.59;
    printf("Avant double : %.2f %.2f\n", d1, d2);
    echangerDouble(d1, d2);
    printf("Apres double : %.2f %.2f\n", d1, d2);

    char c1 = 'A', c2 = 'B';
    printf("Avant char : %c %c\n", c1, c2);
    echangerChar(c1, c2);
    printf("Apres char : %c %c\n", c1, c2);

    return 0;
}