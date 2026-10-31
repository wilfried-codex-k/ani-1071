#include <cstdio>
#include <cmath>

struct Vec2 {
    double x, y;
};

Vec2 operator+(Vec2 a, Vec2 b) { return {a.x + b.x, a.y + b.y}; }

Vec2 rotate(Vec2 a, double angle) {
    double c = cos(angle), s = sin(angle);
    return {a.x * c - a.y * s, a.x * s + a.y * c};
}

struct Transform {
    Vec2 position {0.0, 0.0};
    double rotation = 0.0;
    Vec2 echelle {1.0, 1.0};

    // 1. Ordre normal : Echelle, Rotation, Translation
    Vec2 appliquer(Vec2 local) const {
        Vec2 p = {local.x * echelle.x, local.y * echelle.y};
        p = rotate(p, rotation);
        return p + position;
    }

    // 2. Rotation avant Echelle
    Vec2 appliquer2(Vec2 local) const {
        Vec2 p = rotate(local, rotation);
        p = {p.x * echelle.x, p.y * echelle.y};
        return p + position;
    }

    // 3. Translation avant Rotation
    Vec2 appliquer3(Vec2 local) const {
        Vec2 p = {local.x * echelle.x, local.y * echelle.y};
        p = p + position;
        return rotate(p, rotation);
    }
};

double lerp(double a, double b, double t) { return a + (b - a) * t; }

const int H = 20, L = 40;
char image[H][L];

void effacer(char c = ' ') {
    for (int y = 0; y < H; y++)
        for (int x = 0; x < L; x++) image[y][x] = c;
}

void point(int x, int y, char c = '#') {
    if (x < 0 || x >= L || y < 0 || y >= H) return;
    image[y][x] = c;
}

void segment(double x0, double y0, double x1, double y1, char c = '#') {
    int pas = 60;
    for (int i = 0; i <= pas; i++) {
        double t = i / (double)pas;
        point((int)(lerp(x0, x1, t) + 0.5), (int)(lerp(y0, y1, t) + 0.5), c);
    }
}

void afficher() {
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < L; x++) printf("%c", image[y][x]);
        printf("\n");
    }
}

void dessinerCarre(const Transform& t, int methode) {
    Vec2 coins[4] = {{-0.5, -0.5}, {0.5, -0.5}, {0.5, 0.5}, {-0.5, 0.5}};
    for (int i = 0; i < 4; i++) {
        Vec2 p = (methode == 1) ? t.appliquer(coins[i]) : 
                 (methode == 2) ? t.appliquer2(coins[i]) : t.appliquer3(coins[i]);
        coins[i] = p;
    }
    // On dessine entre les coins (echelle : 2 colonnes par unite, 1 ligne par unite, origine au milieu)
    int ox = L / 2, oy = H / 2;
    for (int i = 0; i < 4; i++) {
        int j = (i + 1) % 4;
        segment(coins[i].x * 2 + ox, -coins[i].y + oy, coins[j].x * 2 + ox, -coins[j].y + oy, '#');
    }
}

int main() {
    Transform t;
    t.echelle = {2.0, 1.0};
    t.rotation = 3.1415926535 / 4.0; // 45 degres
    t.position = {10.0, 5.0};

    Vec2 coins[4] = {{-0.5, -0.5}, {0.5, -0.5}, {0.5, 0.5}, {-0.5, 0.5}};
    
    printf("--- Points ---\n");
    for (int i = 0; i < 4; i++) {
        Vec2 p1 = t.appliquer(coins[i]);
        Vec2 p2 = t.appliquer2(coins[i]);
        Vec2 p3 = t.appliquer3(coins[i]);
        printf("Coin %d : Normal(%.2f, %.2f) | Rot-Ech(%.2f, %.2f) | Trans-Rot(%.2f, %.2f)\n", 
            i, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
    }

    printf("\n--- Dessin 1 (Normal) ---\n");
    effacer(); dessinerCarre(t, 1); afficher();

    printf("\n--- Dessin 2 (Rotation avant Echelle) ---\n");
    effacer(); dessinerCarre(t, 2); afficher();

    printf("\n--- Dessin 3 (Translation avant Rotation) ---\n");
    effacer(); dessinerCarre(t, 3); afficher();

    return 0;
}