#include <cstdio>

void transposer(const int source[], int lignes, int colonnes, int destination[]) {
    for (int y = 0; y < lignes; y = y + 1) {
        for (int x = 0; x < colonnes; x = x + 1) {
            int valeur = source[y * colonnes + x];
            destination[x * lignes + y] = valeur;
        }
    }
}

int main() {
    int lignes, colonnes;
    scanf("%d %d", &lignes, &colonnes);

    int source[10000];
    for (int i = 0; i < lignes * colonnes; i = i + 1) {
        scanf("%d", &source[i]);
    }

    int destination[10000];
    transposer(source, lignes, colonnes, destination);

    for (int y = 0; y < colonnes; y = y + 1) {
        for (int x = 0; x < lignes; x = x + 1) {
            if (x > 0) {
                printf(" ");
            }
            printf("%d", destination[y * lignes + x]);
        }
        printf("\n");
    }

    return 0;
}