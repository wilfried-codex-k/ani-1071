#include <cstdio>
#include <cmath>

using Fonction = double (*)(double);

// Calcule la derivee de f en x
double derivee(Fonction f, double x) {
    double h = 1e-6;
    return (f(x + h) - f(x - h)) / (2.0 * h);
}

// Calcule l'integrale de f entre a et b par la methode des rectangles
double integrale(Fonction f, double a, double b) {
    double pas = (b - a) / 1000.0;
    double somme = 0.0;
    for (int i = 0; i < 1000; i = i + 1) {
        somme = somme + f(a + i * pas) * pas;
    }
    return somme;
}

// Trouve un zero de f entre a et b par dichotomie
double zero(Fonction f, double a, double b) {
    // On suppose que f(a) et f(b) sont de signes contraires
    double epsilon = 1e-7;
    while ((b - a) > epsilon) {
        double milieu = (a + b) / 2.0;
        if (f(milieu) * f(a) <= 0.0) {
            b = milieu;
        } else {
            a = milieu;
        }
    }
    return (a + b) / 2.0;
}

// Les fonctions a tester
double carre(double x) {
    return x * x;
}

double fonctionX2Moins2(double x) {
    return x * x - 2.0;
}

int main() {
    // --- Integrale ---
    double I_sin = integrale(sin, 0.0, 3.14159);
    double I_carre = integrale(carre, 0.0, 1.0);
    printf("Intégrale : sin=%.4f, carre=%.4f\n", I_sin, I_carre);

    // --- Derivee ---
    double D_sin = derivee(sin, 0.0);
    printf("Dérivée : sin'(0)=%.4f\n", D_sin);

    // --- Zero ---
    double Z = zero(fonctionX2Moins2, 1.0, 2.0);
    double vrai_sqrt2 = sqrt(2.0);
    double ecart = Z - vrai_sqrt2;
    if (ecart < 0) ecart = -ecart;
    printf("Zéro : %.6f (ecart avec sqrt(2) : %.6f)\n", Z, ecart);

    return 0;
}