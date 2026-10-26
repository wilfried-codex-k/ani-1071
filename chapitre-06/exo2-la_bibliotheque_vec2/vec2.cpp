#include <cstdio>
#include <cmath>

struct Vec2 {
    double x;
    double y;
};

Vec2 add(Vec2 a, Vec2 b) {
    return {a.x + b.x, a.y + b.y};
}

Vec2 sub(Vec2 a, Vec2 b) {
    return {a.x - b.x, a.y - b.y};
}

Vec2 scale(Vec2 a, double k) {
    return {a.x * k, a.y * k};
}

double dot(Vec2 a, Vec2 b) {
    return a.x * b.x + a.y * b.y;
}

double length(Vec2 a) {
    return sqrt(dot(a, a));
}

Vec2 normalize(Vec2 a) {
    double l = length(a);
    if (l == 0.0) {
        return {0.0, 0.0};
    }
    return {a.x / l, a.y / l};
}

Vec2 lerp(Vec2 a, Vec2 b, double t) {
    return add(a, scale(sub(b, a), t));
}

Vec2 perp(Vec2 a) {
    return {-a.y, a.x};
}

Vec2 rotate(Vec2 a, double angle) {
    double c = cos(angle);
    double s = sin(angle);
    return {a.x * c - a.y * s, a.x * s + a.y * c};
}

Vec2 reflect(Vec2 v, Vec2 n) {
    double d = dot(v, n);
    return sub(v, scale(n, 2.0 * d));
}

double radians(double degres) {
    return degres * 3.141592653589793 / 180.0;
}

void afficherVec2(const char* nom, Vec2 v) {
    printf("%s = {%.17g, %.17g}\n", nom, v.x, v.y);
}

int main() {
    // --- Les quatre vérifications imposées ---
    printf("--- Les quatre ---\n");
    printf("length({3, 4}) = %g\n", length({3, 4}));
    printf("dot({1, 0}, {0, 1}) = %g\n", dot({1, 0}, {0, 1}));
    
    Vec2 rot = rotate({1, 0}, radians(90));
    printf("rotate({1, 0}, 90) = {%.17g, %.17g}\n", rot.x, rot.y);
    
    Vec2 ref = reflect({1, -1}, {0, 1});
    printf("reflect({1, -1}, {0, 1}) = {%g, %g}\n", ref.x, ref.y);

    // --- Mes propres essais ---
    printf("\n--- Mes essais ---\n");
    
    afficherVec2("add({1, 2}, {3, 4})", add({1, 2}, {3, 4}));
    afficherVec2("sub({5, 5}, {2, 3})", sub({5, 5}, {2, 3}));
    afficherVec2("scale({2, 3}, 2.0)", scale({2, 3}, 2.0));
    afficherVec2("normalize({3, 4})", normalize({3, 4}));
    afficherVec2("lerp({0, 0}, {10, 20}, 0.5)", lerp({0, 0}, {10, 20}, 0.5));
    afficherVec2("perp({2, 3})", perp({2, 3}));

    return 0;
}