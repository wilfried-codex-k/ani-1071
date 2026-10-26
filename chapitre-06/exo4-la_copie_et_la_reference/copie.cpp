#include <cstdio>
#include <cmath>

struct Vec2 {
    double x;
    double y;
};

void bougerCopie(Vec2 p) {
    p.x = p.x + 1;
}

void bougerRef(Vec2& p) {
    p.x = p.x + 1;
}

double longueurRef(const Vec2& p) {
    // p.x = 0; // LIGNE A DECOMMENTER POUR LE TEST D'ERREUR
    return sqrt(p.x * p.x + p.y * p.y);
}

int main() {
    Vec2 v = {3.0, 4.0};

    printf("Depart : {%.2f, %.2f}\n", v.x, v.y);

    bougerCopie(v);
    printf("Apres bougerCopie : {%.2f, %.2f}\n", v.x, v.y);

    bougerRef(v);
    printf("Apres bougerRef : {%.2f, %.2f}\n", v.x, v.y);

    double l = longueurRef(v);
    printf("Longueur : %.2f\n", l);

    return 0;
}