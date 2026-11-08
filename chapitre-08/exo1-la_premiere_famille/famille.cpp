#include <cstdio>

struct Vec2
{
    double x, y;
};

class Entite
{
protected:
    Vec2 position;
    const char* nom;

public:
    Entite(Vec2 p, const char* n) : position(p), nom(n) {}
};

class Ennemi : public Entite
{
public:
    Ennemi(Vec2 p, const char* n, int d) : Entite(p, n), degats(d) {}

    void deplacer(double dx, double dy)
    {
        position.x += dx;
        position.y += dy;
    }

    int lireDegats() const { return degats; }

private:
    int degats;
};

class Joueur : public Entite
{
public:
    Joueur(Vec2 p, const char* n, double v) : Entite(p, n), vie(v) {}

    double lireVie() const { return vie; }

private:
    double vie;
};

int main()
{
    Ennemi e({1.0, 2.0}, "ennemi", 5);
    Joueur j({0.0, 0.0}, "joueur", 100.0);

    e.deplacer(1.0, 1.0);
    // e.position.x = 5.0;

    printf("sizeof(Vec2) : %zu\n", sizeof(Vec2));
    printf("sizeof(const char*) : %zu\n", sizeof(const char*));
    printf("sizeof(Entite) : %zu\n", sizeof(Entite));
    printf("sizeof(Ennemi) : %zu\n", sizeof(Ennemi));
    printf("sizeof(Joueur) : %zu\n", sizeof(Joueur));
    printf("degats : %d, vie : %.1f\n", e.lireDegats(), j.lireVie());
    return 0;
}
