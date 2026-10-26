#include <cstdio>

char tuile(const char carte[], int largeur, int x, int y) {
    return carte[y * largeur + x];
}

int compter(const char carte[], int largeur, int hauteur, char quoi) {
    int total = 0;
    for (int i = 0; i < largeur * hauteur; i = i + 1) {
        if (carte[i] == quoi) {
            total = total + 1;
        }
    }
    return total;
}

int main() {
    FILE *entree = fopen("carte.txt", "r");
    if (entree == NULL) {
        printf("carte.txt introuvable\n");
        return 1;
    }

    int largeur, hauteur;
    fscanf(entree, "%d %d", &largeur, &hauteur);

    char carte[10000];
    for (int i = 0; i < largeur * hauteur; i = i + 1) {
        carte[i] = '.';
    }

    for (int y = 0; y < hauteur; y = y + 1) {
        char ligne[200];
        fscanf(entree, "%199s", ligne);
        for (int x = 0; x < largeur; x = x + 1) {
            carte[y * largeur + x] = ligne[x];
        }
    }
    fclose(entree);

    FILE *sortie = fopen("sortie.txt", "w");
    if (sortie == NULL) {
        printf("sortie.txt impossible a ouvrir\n");
        return 1;
    }

    for (int y = 0; y < hauteur; y = y + 1) {
        for (int x = 0; x < largeur; x = x + 1) {
            fprintf(sortie, "%c", tuile(carte, largeur, x, y));
        }
        fprintf(sortie, "\n");
    }

    fprintf(sortie, "sol : %d\n", compter(carte, largeur, hauteur, '.'));
    fprintf(sortie, "mur : %d\n", compter(carte, largeur, hauteur, '#'));
    fprintf(sortie, "eau : %d\n", compter(carte, largeur, hauteur, '~'));

    fprintf(sortie, "tuile en 3, 2 : %c\n", tuile(carte, largeur, 3, 2));

    fclose(sortie);

    return 0;
}