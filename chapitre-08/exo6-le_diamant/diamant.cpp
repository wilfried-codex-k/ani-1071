#include <cstdio>

struct Vec2
{
    double x, y;
};

struct Entite
{
    Vec2 position{0.0, 0.0};
};

// Version 1 : heritage ordinaire
struct Mobile : Entite
{
    Vec2 vitesse{0.0, 0.0};
};

struct Visible : Entite
{
    char glyphe = '#';
};

struct Ennemi : public Mobile, public Visible
{
};

// Version 2 : heritage virtuel
struct MobileV : virtual public Entite
{
    Vec2 vitesse{0.0, 0.0};
};

struct VisibleV : virtual public Entite
{
    char glyphe = '#';
};

struct EnnemiV : public MobileV, public VisibleV
{
};

int main()
{
    printf("Version 1 (heritage ordinaire)\n");
    printf("sizeof(Entite) : %zu\n", sizeof(Entite));
    printf("sizeof(Mobile) : %zu\n", sizeof(Mobile));
    printf("sizeof(Visible) : %zu\n", sizeof(Visible));
    printf("sizeof(Ennemi) : %zu\n", sizeof(Ennemi));

    Ennemi e;
    // e.position.x = 3.0;
    e.Mobile::position.x = 3.0;

    Mobile& m = e;
    Visible& v = e;
    printf("position vue par Mobile& : %.1f\n", m.position.x);
    printf("position vue par Visible& : %.1f\n", v.position.x);

    printf("Version 2 (heritage virtuel)\n");
    printf("sizeof(Entite) : %zu\n", sizeof(Entite));
    printf("sizeof(MobileV) : %zu\n", sizeof(MobileV));
    printf("sizeof(VisibleV) : %zu\n", sizeof(VisibleV));
    printf("sizeof(EnnemiV) : %zu\n", sizeof(EnnemiV));

    EnnemiV ev;
    ev.position.x = 3.0;

    MobileV& mv = ev;
    VisibleV& vv = ev;
    printf("position vue par MobileV& : %.1f\n", mv.position.x);
    printf("position vue par VisibleV& : %.1f\n", vv.position.x);
    return 0;
}
