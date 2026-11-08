#include <cstdio>

class Base
{
public:
    int publique;

protected:
    int protegee;

private:
    int privee;

public:
    Base() : publique(1), protegee(2), privee(3) {}

    int lirePrivee() const { return privee; }
};

class Derivee : public Base
{
public:
    void tenter() const
    {
        printf("depuis Derivee, publique : %d\n", publique);
        printf("depuis Derivee, protegee : %d\n", protegee);
        // printf("depuis Derivee, privee : %d\n", privee);
    }
};

// void soigner(Base& b) { b.protegee = 10; }

int main()
{
    Derivee d;
    d.tenter();
    printf("depuis main, publique : %d\n", d.publique);
    // printf("depuis main, protegee : %d\n", d.protegee);
    // printf("depuis main, privee : %d\n", d.privee);
    printf("privee lue par la methode lirePrivee : %d\n", d.lirePrivee());
    return 0;
}
