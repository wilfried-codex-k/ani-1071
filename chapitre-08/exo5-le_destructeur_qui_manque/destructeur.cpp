#include <cstdio>
#include <vector>

struct Trace
{
    ~Trace() { printf("~Trace\n"); }
};

class Ennemi
{
public:
    virtual void deplacer() {}
    ~Ennemi() { printf("~Ennemi\n"); }
};

class Fantome : public Ennemi
{
public:
    Fantome() : donnees(1000) {}

    void deplacer() override {}

    ~Fantome()
    {
        printf("~Fantome, taille du vecteur : %zu\n", donnees.size());
    }

private:
    std::vector<int> donnees;
    Trace trace;
};

int main()
{
    printf("Par un Ennemi* :\n");
    Ennemi* e = new Fantome;
    delete e;

    printf("Par un Fantome* :\n");
    Fantome* f = new Fantome;
    delete f;
    return 0;
}
