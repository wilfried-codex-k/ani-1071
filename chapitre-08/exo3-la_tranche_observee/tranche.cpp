#include <cstdio>

class Entite
{
public:
    virtual const char* nom() const { return "entite"; }
    virtual ~Entite() {}
};

class Ennemi : public Entite
{
public:
    Ennemi() : degats(5) {}

    const char* nom() const override { return "ennemi"; }

    int lireDegats() const { return degats; }

private:
    int degats;
};

void f(Entite e)
{
    printf("f (par valeur) : %s\n", e.nom());
}

void g(Entite& e)
{
    printf("g (par reference) : %s\n", e.nom());
}

void h(Entite* e)
{
    printf("h (par pointeur) : %s\n", e->nom());
}

int main()
{
    Ennemi robot;

    f(robot);
    g(robot);
    h(&robot);

    printf("sizeof(Entite) : %zu\n", sizeof(Entite));
    printf("sizeof(Ennemi) : %zu\n", sizeof(Ennemi));
    printf("degats : %d\n", robot.lireDegats());
    return 0;
}
