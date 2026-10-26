#include <cstdio>
#include <cmath>

struct Vec2 {
    double x;
    double y;
};

Vec2 add(Vec2 a, Vec2 b) {
    return {a.x + b.x, a.y + b.y};
}

Vec2 scale(Vec2 a, double k) {
    return {a.x * k, a.y * k};
}

void eulerSemiImplicite(Vec2& p, Vec2& v, Vec2 a, double dt) {
    v = add(v, scale(a, dt));
    p = add(p, scale(v, dt));
}

double simulerSaut(double dt) {
    double g = 9.81;
    double h_voulue = 3.0;
    double v0 = sqrt(2.0 * g * h_voulue);

    Vec2 p = {0.0, 0.0};
    Vec2 v = {0.0, v0};
    Vec2 a = {0.0, -g};

    double hauteur_max = 0.0;
    bool enLair = true;

    // On simule jusqu'a ce que le personnage retombe
    while (enLair) {
        eulerSemiImplicite(p, v, a, dt);
        if (p.y > hauteur_max) {
            hauteur_max = p.y;
        }
        if (p.y <= 0.0 && v.y < 0.0) {
            enLair = false;
        }
    }

    return hauteur_max;
}

int main() {
    double g = 9.81;
    double h_voulue = 3.0;
    double v0 = sqrt(2.0 * g * h_voulue);

    printf("v0 : %.6f\n", v0);
    printf("1/120 : %.6f\n", simulerSaut(1.0 / 120.0));
    printf("1/30 : %.6f\n", simulerSaut(1.0 / 30.0));
    printf("Mon pas (1/1000) : %.6f\n", simulerSaut(1.0 / 1000.0));

    return 0;
}