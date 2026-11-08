#include <cstdio>

int gEnnemi = 0;
int gFantome = 0;
int gRobot = 0;

class Ennemi
{
public:
    Ennemi() : x(0.0) {}

    virtual void deplacer(double dt)
    {
        x += dt;
        gEnnemi++;
    }

    virtual ~Ennemi() {}

protected:
    double x;
};

class Fantome : public Ennemi
{
public:
    void deplacer(double dt) override
    {
        x += dt * 2.0;
        gFantome++;
    }
};

class Robot : public Ennemi
{
public:
    void deplacer(double dt) override
    {
        x += dt * 0.5;
        gRobot++;
    }
};

int main()
{
    Ennemi* ennemis[6] = {
        new Ennemi,
        new Robot,
        new Robot,
        new Fantome,
        new Fantome,
        new Fantome
    };

    for (Ennemi* e : ennemis)
    {
        for (int i = 0; i < 10; i++)
        {
            e->deplacer(0.1);
        }
    }

    printf("gEnnemi : %d\n", gEnnemi);
    printf("gFantome : %d\n", gFantome);
    printf("gRobot : %d\n", gRobot);

    for (Ennemi* e : ennemis)
    {
        delete e;
    }
    return 0;
}
