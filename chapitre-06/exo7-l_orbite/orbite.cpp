#include <cstdio>
#include <cmath>

struct Vec2 {
    double x;
    double y;
};

// Fonctions de base pour les vecteurs
Vec2 add(Vec2 a, Vec2 b) { return {a.x + b.x, a.y + b.y}; }
Vec2 sub(Vec2 a, Vec2 b) { return {a.x - b.x, a.y - b.y}; }
Vec2 scale(Vec2 a, double k) { return {a.x * k, a.y * k}; }
double dot(Vec2 a, Vec2 b) { return a.x * b.x + a.y * b.y; }
double length(Vec2 a) { return sqrt(dot(a, a)); }

Vec2 acceleration(Vec2 p) {
    double mu = 100.0;
    double dist = length(p);
    // a = -mu * p / |p|³
    double facteur = -mu / (dist * dist * dist);
    return scale(p, facteur);
}

void eulerExplicite(Vec2& p, Vec2& v, Vec2 a, double dt) {
    p = add(p, scale(v, dt)); // Position avec l'ancienne vitesse
    v = add(v, scale(a, dt)); // Vitesse mise à jour après
}

void eulerSemiImplicite(Vec2& p, Vec2& v, Vec2 a, double dt) {
    v = add(v, scale(a, dt)); // Vitesse d'abord
    p = add(p, scale(v, dt)); // Position avec la nouvelle vitesse
}

// Pour l'image
const int H = 20, L = 40;
char image[H][L];

void effacer(char c = ' ') {
    for (int y = 0; y < H; y++)
        for (int x = 0; x < L; x++)
            image[y][x] = c;
}

void point(int x, int y, char c = '#') {
    if (x < 0 || x >= L || y < 0 || y >= H) return;
    image[y][x] = c;
}

void afficher() {
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < L; x++) printf("%c", image[y][x]);
        printf("\n");
    }
}

int main() {
    // Test 1 : Pas de 0.01
    double dt = 0.01;
    Vec2 p_expl = {100.0, 0.0};
    Vec2 v_expl = {0.0, 1.0};
    Vec2 p_semi = {100.0, 0.0};
    Vec2 v_semi = {0.0, 1.0};

    printf("--- Distances (dt = 0.01) ---\n");
    for (int i = 0; i <= 10000; i = i + 1) {
        if (i % 500 == 0) {
            printf("Pas %5d : expl = %.4f, semi = %.4f\n", i, length(p_expl), length(p_semi));
        }
        Vec2 a_expl = acceleration(p_expl);
        Vec2 a_semi = acceleration(p_semi);
        eulerExplicite(p_expl, v_expl, a_expl, dt);
        eulerSemiImplicite(p_semi, v_semi, a_semi, dt);
    }

    // Test 2 : Pas dix fois plus petit (0.001)
    dt = 0.001;
    p_expl = {100.0, 0.0};
    v_expl = {0.0, 1.0};
    p_semi = {100.0, 0.0};
    v_semi = {0.0, 1.0};

    for (int i = 0; i <= 10000; i = i + 1) {
        Vec2 a_expl = acceleration(p_expl);
        Vec2 a_semi = acceleration(p_semi);
        eulerExplicite(p_expl, v_expl, a_expl, dt);
        eulerSemiImplicite(p_semi, v_semi, a_semi, dt);
    }
    printf("\n--- Apres 10000 pas (dt = 0.001) ---\n");
    printf("expl = %.4f, semi = %.4f\n", length(p_expl), length(p_semi));

    // --- Dessin des orbites (avec dt = 0.01) ---
    effacer();
    dt = 0.01;
    p_expl = {100.0, 0.0};
    v_expl = {0.0, 1.0};
    p_semi = {100.0, 0.0};
    v_semi = {0.0, 1.0};

    for (int i = 0; i <= 10000; i = i + 1) {
        // Échelle : le rayon 100 doit tenir dans l'image. 
        // Milieu de l'image : x=20, y=10. Rayon max ~8 cases.
        // 1 case = 100 / 8 = 12.5 unites.
        
        int ex = (int)(p_expl.x / 12.5) + 20;
        int ey = 10 - (int)(p_expl.y / 12.5);
        point(ex, ey, 'E');

        int sx = (int)(p_semi.x / 12.5) + 20;
        int sy = 10 - (int)(p_semi.y / 12.5);
        point(sx, sy, 'S');

        Vec2 a_expl = acceleration(p_expl);
        Vec2 a_semi = acceleration(p_semi);
        eulerExplicite(p_expl, v_expl, a_expl, dt);
        eulerSemiImplicite(p_semi, v_semi, a_semi, dt);
    }

    printf("\n--- Dessin des orbites ---\n");
    afficher();

    return 0;
}