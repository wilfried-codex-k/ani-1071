#include <cstdio>
#include <cstdlib>

int pgcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

class Fraction {
private:
    int num;
    int den;

public:
    Fraction(int n, int d) {
        if (d == 0) {
            printf("Erreur : denominateur nul !\n");
            num = 0;
            den = 1;
            return;
        }
        if (d < 0) {
            n = -n;
            d = -d;
        }
        int p = pgcd(n, d);
        num = n / p;
        den = d / p;
    }

    Fraction operator+(Fraction b) const {
        return Fraction(num * b.den + b.num * den, den * b.den);
    }

    Fraction operator-(Fraction b) const {
        return Fraction(num * b.den - b.num * den, den * b.den);
    }

    Fraction operator*(Fraction b) const {
        return Fraction(num * b.num, den * b.den);
    }

    Fraction operator/(Fraction b) const {
        return Fraction(num * b.den, den * b.num);
    }

    bool operator==(Fraction b) const {
        return num == b.num && den == b.den;
    }

    void afficher() const {
        printf("%d/%d\n", num, den);
    }
};

int main() {
    printf("--- Essais ---\n");
    
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction somme = f1 + f2;
    printf("1/2 + 1/3 = "); somme.afficher();

    Fraction diff = f1 - f2;
    printf("1/2 - 1/3 = "); diff.afficher();

    Fraction prod = f1 * f2;
    printf("1/2 * 1/3 = "); prod.afficher();

    Fraction div = f1 / f2;
    printf("1/2 / 1/3 = "); div.afficher();

    Fraction neg(4, -6);
    printf("4/-6 = "); neg.afficher();

    printf("\n--- Egalites ---\n");
    Fraction a(1, 2);
    Fraction b(2, 4);
    printf("1/2 == 2/4 : %d\n", a == b);
    printf("1/2 == 1/3 : %d\n", a == Fraction(1, 3));

    printf("\n--- Denominateur nul ---\n");
    Fraction c(1, 0);
    printf("Resultat de 1/0 : "); c.afficher();
    
    Fraction d(1, 2);
    Fraction e = d / Fraction(0, 1);
    printf("(1/2) / (0/1) : "); e.afficher();

    return 0;
}