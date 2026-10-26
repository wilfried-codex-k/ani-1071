#include <cstdio>

const int LARGEUR = 20;
const int HAUTEUR = 20;

int voisinsVivants(const char g[], int largeur, int hauteur, int x, int y) {
    int compte = 0;
    for (int dy = -1; dy <= 1; dy = dy + 1) {
        for (int dx = -1; dx <= 1; dx = dx + 1) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= largeur) continue;
            if (ny < 0 || ny >= hauteur) continue;
            if (g[ny * largeur + nx] == '#') {
                compte = compte + 1;
            }
        }
    }
    return compte;
}

void afficher(const char g[], int largeur, int hauteur, FILE *sortie) {
    for (int y = 0; y < hauteur; y = y + 1) {
        for (int x = 0; x < largeur; x = x + 1) {
            fprintf(sortie, "%c", g[y * largeur + x]);
        }
        fprintf(sortie, "\n");
    }
}

int main() {
    char grille[LARGEUR * HAUTEUR];
    char suivante[LARGEUR * HAUTEUR];

    for (int i = 0; i < LARGEUR * HAUTEUR; i = i + 1) {
        grille[i] = '.';
    }

    // Planeur en haut a gauche
    grille[1 * LARGEUR + 2] = '#';
    grille[2 * LARGEUR + 3] = '#';
    grille[3 * LARGEUR + 1] = '#';
    grille[3 * LARGEUR + 2] = '#';
    grille[3 * LARGEUR + 3] = '#';

    FILE *sortie = fopen("generations.txt", "w");
    if (sortie == NULL) {
        printf("impossible d'ouvrir generations.txt\n");
        return 1;
    }

    for (int gen = 0; gen < 10; gen = gen + 1) {
        fprintf(sortie, "generation %d\n", gen);
        afficher(grille, LARGEUR, HAUTEUR, sortie);
        fprintf(sortie, "\n");

        for (int y = 0; y < HAUTEUR; y = y + 1) {
            for (int x = 0; x < LARGEUR; x = x + 1) {
                int v = voisinsVivants(grille, LARGEUR, HAUTEUR, x, y);
                char etat = grille[y * LARGEUR + x];

                if (etat == '#') {
                    if (v == 2 || v == 3) {
                        suivante[y * LARGEUR + x] = '#';
                    } else {
                        suivante[y * LARGEUR + x] = '.';
                    }
                } else {
                    if (v == 3) {
                        suivante[y * LARGEUR + x] = '#';
                    } else {
                        suivante[y * LARGEUR + x] = '.';
                    }
                }
            }
        }

        for (int i = 0; i < LARGEUR * HAUTEUR; i = i + 1) {
            grille[i] = suivante[i];
        }
    }

    fclose(sortie);

    return 0;
}