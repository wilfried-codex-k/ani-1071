#include <cstdio>
#include <cmath>

struct Vec2 {
    double x;
    double y;
};

Vec2 add(Vec2 a, Vec2 b) { return {a.x + b.x, a.y + b.y}; }
Vec2 sub(Vec2 a, Vec2 b) { return {a.x - b.x, a.y - b.y}; }
Vec2 scale(Vec2 a, double k) { return {a.x * k, a.y * k}; }
double dot(Vec2 a, Vec2 b) { return a.x * b.x + a.y * b.y; }
double length(Vec2 a) { return sqrt(dot(a, a)); }
Vec2 normalize(Vec2 a) { 
    double l = length(a); 
    return (l == 0) ? Vec2{0,0} : Vec2{a.x/l, a.y/l}; 
}

bool cerclesSeTouchent(Vec2 c1, double r1, Vec2 c2, double r2) {
    Vec2 d = sub(c2, c1);
    double somme_r = r1 + r2;
    return dot(d, d) < somme_r * somme_r;
}

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

double angleEntre(Vec2 v1, Vec2 v2) {
    double l1 = length(v1);
    double l2 = length(v2);
    if (l1 == 0 || l2 == 0) return 0.0;
    double cos_angle = dot(v1, v2) / (l1 * l2);
    if (cos_angle > 1.0) cos_angle = 1.0;
    if (cos_angle < -1.0) cos_angle = -1.0;
    return acos(cos_angle) * 180.0 / 3.141592653589793;
}

void simuler(double decalage, double& angle, Vec2& v1_final, Vec2& v2_final, bool dessiner = false) {
    double r = 1.0;
    Vec2 p1 = {0.0, 0.0};
    Vec2 v1 = {5.0, 0.0};
    Vec2 p2 = {10.0, decalage};
    Vec2 v2 = {0.0, 0.0};
    double dt = 0.01;
    
    if (dessiner) effacer();

    for (int i = 0; i < 1000; i++) {
        p1 = add(p1, scale(v1, dt));
        p2 = add(p2, scale(v2, dt));

        if (dessiner) {
            point((int)(p1.x * 2) + 5, (int)(p1.y * 2) + 10, 'A');
            point((int)(p2.x * 2) + 5, (int)(p2.y * 2) + 10, 'B');
        }

        if (cerclesSeTouchent(p1, r, p2, r)) {
            Vec2 n = normalize(sub(p2, p1));
            
            double chevauchement = (2 * r) - length(sub(p2, p1));
            p1 = sub(p1, scale(n, chevauchement / 2.0));
            p2 = add(p2, scale(n, chevauchement / 2.0));

            double v1n = dot(v1, n);
            double v2n = dot(v2, n);

            v1 = add(v1, scale(n, v2n - v1n));
            v2 = add(v2, scale(n, v1n - v2n));

            break;
        }
    }
    angle = angleEntre(v1, v2);
    v1_final = v1;
    v2_final = v2;
}

int main() {
    printf("--- Angles ---\n");
    double decalages[] = {0.5, 1.5, -1.0, 0.0}; // le dernier est le decalage nul
    
    for (int i = 0; i < 4; i++) {
        double angle, d = decalages[i];
        Vec2 v1f, v2f;
        simuler(d, angle, v1f, v2f);
        printf("Decalage %.1f : v1={%.2f, %.2f}, v2={%.2f, %.2f}, angle=%.2f deg\n", 
            d, v1f.x, v1f.y, v2f.x, v2f.y, angle);
    }

    printf("\n--- Dessin (decalage 0.5) ---\n");
    double angle; Vec2 v1f, v2f;
    simuler(0.5, angle, v1f, v2f, true);
    afficher();

    return 0;
}