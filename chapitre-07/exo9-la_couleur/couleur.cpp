#include <cstdio>

struct Couleur {
    unsigned char r, g, b, a;

    // Ajout de ce constructeur pour accepter les accolades {r, g, b, a}
    Couleur(unsigned char r_, unsigned char g_, unsigned char b_, unsigned char a_) 
        : r(r_), g(g_), b(b_), a(a_) {}

    // Le constructeur d'empaquetage (qui a cause l'erreur)
    Couleur(unsigned int rgba) {
        r = (rgba >> 24) & 0xFF;
        g = (rgba >> 16) & 0xFF;
        b = (rgba >> 8) & 0xFF;
        a = rgba & 0xFF;
    }

    static unsigned char saturer(double v) {
        if (v < 0.0) return 0;
        if (v > 255.0) return 255;
        return (unsigned char)v;
    }

    Couleur operator*(double k) const {
        return Couleur(saturer(r * k), saturer(g * k), saturer(b * k), a);
    }

    Couleur operator+(Couleur c) const {
        return Couleur(saturer(r + c.r), saturer(g + c.g), saturer(b + c.b), saturer(a + c.a));
    }

    unsigned int empaqueter() const {
        return ((unsigned int)r << 24) | ((unsigned int)g << 16) | ((unsigned int)b << 8) | (unsigned int)a;
    }

    void afficher() const {
        printf("r=%d, g=%d, b=%d, a=%d\n", r, g, b, a);
    }
};

Couleur lerp(Couleur c, Couleur d, double t) {
    return Couleur(
        Couleur::saturer(c.r + (d.r - c.r) * t),
        Couleur::saturer(c.g + (d.g - c.g) * t),
        Couleur::saturer(c.b + (d.b - c.b) * t),
        Couleur::saturer(c.a + (d.a - c.a) * t)
    );
}

int main() {
    printf("--- Essais ---\n");
    Couleur c1(200, 100, 50, 255);
    Couleur c2(100, 200, 50, 255);
    
    printf("c1 : "); c1.afficher();
    printf("c2 : "); c2.afficher();
    
    Couleur somme = c1 + c2;
    printf("c1 + c2 : "); somme.afficher();

    Couleur mult = c1 * 2.0;
    printf("c1 * 2.0 : "); mult.afficher();

    Couleur melange = lerp(c1, c2, 0.5);
    printf("lerp(c1, c2, 0.5) : "); melange.afficher();

    printf("\n--- Sans saturer ---\n");
    unsigned char sansSaturation = 200 + 200;
    printf("200 + 200 (sans saturer) = %d\n", sansSaturation);

    printf("\n--- Empaquetage ---\n");
    unsigned int hex = c1.empaqueter();
    printf("c1 empaquete : %08X\n", hex);

    Couleur c3(hex);
    printf("c3 (reconstruit) : "); c3.afficher();
    printf("Aller-retour ok ? %d\n", (c1.r == c3.r && c1.g == c3.g && c1.b == c3.b && c1.a == c3.a));

    return 0;
}
