#include <cstdio>

void deplier(int i, int largeur, int& x, int& y) {
    x = i % largeur;
    y = i / largeur;
}

void minMax(const int t[], int n, int& min, int& max) {
    if (n <= 0) return;

    min = t[0];
    max = t[0];

    for (int i = 1; i < n; i = i + 1) {
        if (t[i] < min) {
            min = t[i];
        }
        if (t[i] > max) {
            max = t[i];
        }
    }
}

bool diviser(int a, int b, int& quotient, int& reste) {
    if (b == 0) {
        return false;
    }
    quotient = a / b;
    reste = a % b;
    return true;
}

int main() {
    int x, y;

    // --- Test deplier ---
    printf("Test deplier (largeur 40) :\n");
    deplier(0, 40, x, y);
    printf("0 -> x=%d, y=%d\n", x, y);
    
    deplier(39, 40, x, y);
    printf("39 -> x=%d, y=%d\n", x, y);
    
    deplier(40, 40, x, y);
    printf("40 -> x=%d, y=%d\n", x, y);
    
    deplier(125, 40, x, y);
    printf("125 -> x=%d, y=%d\n", x, y);

    // --- Test minMax ---
    printf("\nTest minMax :\n");
    int tableau[5] = {12, 7, 19, 3, 15};
    int min, max;
    minMax(tableau, 5, min, max);
    printf("Tableau {12, 7, 19, 3, 15} -> min=%d, max=%d\n", min, max);

    // --- Test diviser ---
    printf("\nTest diviser :\n");
    int quotient, reste;
    
    bool ok1 = diviser(17, 5, quotient, reste);
    printf("17 / 5 -> ok=%d, quotient=%d, reste=%d\n", ok1, quotient, reste);
    
    bool ok2 = diviser(20, 4, quotient, reste);
    printf("20 / 4 -> ok=%d, quotient=%d, reste=%d\n", ok2, quotient, reste);

    // --- Test par zero ---
    printf("\nTest division par zero :\n");
    quotient = 999;
    reste = 888;
    printf("Avant appel : quotient=%d, reste=%d\n", quotient, reste);
    
    bool ok3 = diviser(10, 0, quotient, reste);
    printf("10 / 0 -> ok=%d\n", ok3);
    printf("Apres appel : quotient=%d, reste=%d\n", quotient, reste);

    return 0;
}