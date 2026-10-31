#include <cstdio>
#include <cmath>

struct Vec2 {
    double x, y;

    // Constructeurs
    Vec2() : x(0.0), y(0.0) {}
    Vec2(double x_, double y_) : x(x_), y(y_) {}

    // Methodes qui lisent (const)
    double length() const {
        return sqrt(x * x + y * y);
    }

    double dot(Vec2 b) const {
        return x * b.x + y * b.y;
    }

    Vec2 normalized() const {
        double l = length();
        if (l == 0.0) return Vec2(0.0, 0.0);
        return Vec2(x / l, y / l);
    }

    // Methode qui modifie
    void normalize() {
        double l = length();
        if (l != 0.0) {
            x = x / l;
            y = y / l;
        }
    }

    // Operateurs de base
    Vec2 operator+(Vec2 b) const { return Vec2(x + b.x, y + b.y); }
    Vec2 operator-(Vec2 b) const { return Vec2(x - b.x, y - b.y); }
    Vec2 operator-() const { return Vec2(-x, -y); } // moins unaire
    Vec2 operator/(double k) const { return Vec2(x / k, y / k); }
    
    // Egalite
    bool operator==(Vec2 b) const { return x == b.x && y == b.y; }
    bool operator!=(Vec2 b) const { return !(*this == b); }

    // Multiplication par un reel
    Vec2 operator*(double k) const { return Vec2(x * k, y * k); }

    // Methodes qui modifient l'objet
    Vec2& operator+=(Vec2 b) { x += b.x; y += b.y; return *this; }
    Vec2& operator-=(Vec2 b) { x -= b.x; y -= b.y; return *this; }
    Vec2& operator*=(double k) { x *= k; y *= k; return *this; }

    // Acces par indice
    double& operator[](int i) { return (i == 0) ? x : y; }
    const double& operator[](int i) const { return (i == 0) ? x : y; }
};

// Multiplication dans l'autre sens (2.0 * v)
Vec2 operator*(double k, Vec2 v) {
    return Vec2(v.x * k, v.y * k);
}

void afficher(const char* nom, Vec2 v) {
    printf("%s = {%.2f, %.2f}\n", nom, v.x, v.y);
}

int main() {
    printf("--- Essais ---\n");
    
    Vec2 a;
    Vec2 b(3.0, 4.0);
    afficher("a (constructeur par defaut)", a);
    afficher("b (constructeur avec valeurs)", b);

    afficher("b.length()", Vec2(b.length(), 0)); // Bidouille pour afficher un double avec afficherVec
    printf("b.length() = %.2f\n", b.length());
    printf("b.dot(Vec2(1,2)) = %.2f\n", b.dot(Vec2(1, 2)));
    
    Vec2 c = b.normalized();
    afficher("b.normalized()", c);
    
    Vec2 d(3.0, 4.0);
    d.normalize();
    afficher("d apres normalize()", d);

    afficher("a + b", a + b);
    afficher("b - Vec2(1,1)", b - Vec2(1, 1));
    afficher("-b", -b);
    afficher("b / 2.0", b / 2.0);
    
    bool eq = (b == Vec2(3.0, 4.0));
    bool neq = (b != Vec2(3.0, 4.0));
    printf("b == {3,4} : %d\n", eq);
    printf("b != {3,4} : %d\n", neq);

    afficher("b * 2.0", b * 2.0);
    afficher("2.0 * b", 2.0 * b);

    Vec2 e(1.0, 1.0);
    e += b;
    afficher("e += b", e);
    
    e -= Vec2(1.0, 1.0);
    afficher("e -= {1,1}", e);

    e *= 3.0;
    afficher("e *= 3.0", e);

    e[1] = 5.0;
    afficher("e apres e[1] = 5.0", e);

    printf("\n--- Chute ---\n");
    Vec2 p(0.0, 10.0);
    Vec2 v(3.0, 0.0);
    Vec2 g(0.0, -9.81);
    double dt = 0.1;
    double t = 0.0;

    while (p.y >= 0.0) {
        printf("t = %.1f, p = {%.2f, %.2f}, v = {%.2f, %.2f}\n", t, p.x, p.y, v.x, v.y);
        v += g * dt;
        p += v * dt;
        t += dt;
    }
    
    // Une derniere ligne pour voir quand c'est negatif
    printf("t = %.1f, p = {%.2f, %.2f}, v = {%.2f, %.2f} (p.y negatif)\n", t, p.x, p.y, v.x, v.y);

    printf("\n--- Sol ---\n");
    // Formule : p.y = p0.y + v0.y * t + g.y * t * t / 2
    // 0 = 10 + 0 - 9.81 * t^2 / 2
    // 4.905 * t^2 = 10 => t^2 = 10 / 4.905 => t = sqrt(10 / 4.905)
    double t_sol = sqrt(10.0 / 4.905);
    printf("Instant exact (formule) : %.4f s\n", t_sol);

    return 0;
}