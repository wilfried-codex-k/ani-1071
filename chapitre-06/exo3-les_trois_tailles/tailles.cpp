#include <cstdio>

struct Vec2 {
    double x;
    double y;
};

struct Particule1 {
    Vec2 position;
    Vec2 vitesse;
    double vie;
};

struct A { char c; int n; };
struct B { char c; double d; char e; };
struct C { double d; char c; char e; };

// Nouvelle particule demandee par l'enonce
struct Particule2 {
    double vie;
    char etat;
    Vec2 position;
    Vec2 vitesse;
};

// Deux autres essais
struct Particule3 {
    double vie;
    Vec2 position;
    Vec2 vitesse;
    char etat;
};

struct Particule4 {
    Vec2 position;
    double vie;
    Vec2 vitesse;
    char etat;
};

int main() {
    printf("Taille de Vec2 : %zu\n", sizeof(Vec2));
    printf("Taille de Particule1 (originale) : %zu\n", sizeof(Particule1));
    printf("Taille de A : %zu\n", sizeof(A));
    printf("Taille de B : %zu\n", sizeof(B));
    printf("Taille de C : %zu\n", sizeof(C));
    printf("Taille de Particule2 (vie, etat, pos, vit) : %zu\n", sizeof(Particule2));
    printf("Taille de Particule3 (vie, pos, vit, etat) : %zu\n", sizeof(Particule3));
    printf("Taille de Particule4 (pos, vie, vit, etat) : %zu\n", sizeof(Particule4));

    return 0;
}