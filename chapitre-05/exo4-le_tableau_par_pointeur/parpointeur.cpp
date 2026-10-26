#include <cstdio>
#include <cstring>

int somme(const int* t, int n) {
    int total = 0;
    for (int i = 0; i < n; i = i + 1) {
        total = total + *(t + i);
    }
    return total;
}

int maximum(const int* t, int n) {
    if (n <= 0) return 0;
    int maxi = *t;
    for (int i = 1; i < n; i = i + 1) {
        int valeur = *(t + i);
        if (valeur > maxi) {
            maxi = valeur;
        }
    }
    return maxi;
}

void inverser(int* t, int n) {
    int* debut = t;
    int* fin = t + n - 1;
    while (debut < fin) {
        int temp = *debut;
        *debut = *fin;
        *fin = temp;
        debut++;
        fin--;
    }
}

int longueur(const char* s) {
    const char* p = s;
    while (*p != '\0') {
        p++;
    }
    return p - s;
}

int main() {
    int tableau[5] = {12, 7, 19, 3, 15};

    printf("somme : %d\n", somme(tableau, 5));
    printf("maximum : %d\n", maximum(tableau, 5));

    inverser(tableau, 5);
    printf("inverser : %d %d %d %d %d\n", tableau[0], tableau[1], tableau[2], tableau[3], tableau[4]);

    const char* mot1 = "bonjour";
    printf("longueur(%s) : %d\n", mot1, longueur(mot1));
    printf("strlen(%s) : %d\n", mot1, (int)strlen(mot1));

    const char* mot2 = "Yaoundé";
    printf("longueur(%s) : %d\n", mot2, longueur(mot2));
    printf("strlen(%s) : %d\n", mot2, (int)strlen(mot2));

    return 0;
}