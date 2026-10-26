#include <cstdio>
#include <cmath>

double scalaire(const double* a, const double* b, int n) {
    double somme = 0.0;
    for (int i = 0; i < n; i = i + 1) {
        somme = somme + a[i] * b[i];
    }
    return somme;
}

double norme(const double* v, int n) {
    return sqrt(scalaire(v, v, n));
}

void normaliser(double* v, int n) {
    double longueur = norme(v, n);
    if (longueur != 0.0) {
        for (int i = 0; i < n; i = i + 1) {
            v[i] = v[i] / longueur;
        }
    }
}

bool voit(const double* garde, const double* direction, const double* joueur) {
    // 1. Vecteur du garde vers le joueur
    double versJoueur[2];
    versJoueur[0] = joueur[0] - garde[0];
    versJoueur[1] = joueur[1] - garde[1];

    // Si le joueur est exactement sur le garde, le vecteur est nul (on dit non par securite)
    if (versJoueur[0] == 0.0 && versJoueur[1] == 0.0) {
        return false;
    }

    // 2. On normalise le vecteur vers le joueur
    normaliser(versJoueur, 2);

    // 3. Produit scalaire avec la direction du garde (qui est deja normalisee)
    double cosinus = scalaire(direction, versJoueur, 2);

    // 4. Cosinus de 30 degres. L'angle PI vaut 3.14159.
    // 30 degres = PI / 6
    double cos_30 = cos(3.14159 / 6.0);

    // 5. On compare
    return cosinus >= cos_30;
}

int main() {
    double garde[2] = {0.0, 0.0};
    double direction[2] = {1.0, 0.0}; // Le garde regarde vers la droite

    // Joueur 1 : Devant (sur l'axe du regard)
    double j_devant[2] = {10.0, 0.0};
    printf("Devant : (%g, %g) -> %s\n", j_devant[0], j_devant[1], voit(garde, direction, j_devant) ? "oui" : "non");

    // Joueur 2 : Sur le cote (a 90 degres)
    double j_cote[2] = {0.0, 10.0};
    printf("Cote : (%g, %g) -> %s\n", j_cote[0], j_cote[1], voit(garde, direction, j_cote) ? "oui" : "non");

    // Joueur 3 : Derriere
    double j_derriere[2] = {-10.0, 0.0};
    printf("Derriere : (%g, %g) -> %s\n", j_derriere[0], j_derriere[1], voit(garde, direction, j_derriere) ? "oui" : "non");

    // Joueur 4 : Pres du bord, juste dedans (angle de 29 degres)
    // cos(29) ~ 0.874, sin(29) ~ 0.484. On prend un point a distance 10.
    double j_bord_dedans[2] = {8.75, 4.84};
    printf("Bord dedans : (%g, %g) -> %s\n", j_bord_dedans[0], j_bord_dedans[1], voit(garde, direction, j_bord_dedans) ? "oui" : "non");

    // Joueur 5 : Pres du bord, juste dehors (angle de 31 degres)
    // cos(31) ~ 0.857, sin(31) ~ 0.515. On prend un point a distance 10.
    double j_bord_dehors[2] = {8.57, 5.15};
    printf("Bord dehors : (%g, %g) -> %s\n", j_bord_dehors[0], j_bord_dehors[1], voit(garde, direction, j_bord_dehors) ? "oui" : "non");

    return 0;
}