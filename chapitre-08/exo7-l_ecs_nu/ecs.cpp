#include <cstdio>

struct Vec2
{
    double x, y;
    Vec2() : x(0.0), y(0.0) {}
    Vec2(double x_, double y_) : x(x_), y(y_) {}
    Vec2& operator+=(Vec2 b) { x += b.x; y += b.y; return *this; }
};

Vec2 operator+(Vec2 a, Vec2 b)     { return {a.x + b.x, a.y + b.y}; }
Vec2 operator*(Vec2 a, double k)   { return {a.x * k, a.y * k}; }

const int MAX = 1000;
using Entite = int;

struct Transform  { Vec2 position; double rotation; Vec2 echelle; };
struct Corps      { Vec2 vitesse; double masse; };
struct Sprite     { char glyphe; };

Transform transforms[MAX];  bool aTransform[MAX] = {};
Corps     corps[MAX];       bool aCorps[MAX]     = {};
Sprite    sprites[MAX];     bool aSprite[MAX]    = {};

// Free list des numeros d'entite
int suivante[MAX];
int premiereLibre = 0;

void initialiser()
{
    for (int i = 0; i < MAX - 1; i++) suivante[i] = i + 1;
    suivante[MAX - 1] = -1;
}

int allouer()
{
    if (premiereLibre == -1) return -1;
    int i = premiereLibre;
    premiereLibre = suivante[i];
    return i;
}

void liberer(int i)
{
    suivante[i] = premiereLibre;
    premiereLibre = i;
}

Entite creerEntite()
{
    return allouer();
}

void detruireEntite(Entite e)
{
    aTransform[e] = false;
    aCorps[e] = false;
    aSprite[e] = false;
    liberer(e);
}

// Tampon d'image
const int H = 20, L = 40;
char image[H][L];

void effacer(char c = ' ')
{
    for (int y = 0; y < H; y++)
        for (int x = 0; x < L; x++)
            image[y][x] = c;
}

void point(int x, int y, char c = '#')
{
    if (x < 0 || x >= L || y < 0 || y >= H) return;
    image[y][x] = c;
}

void afficher()
{
    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < L; x++) printf("%c", image[y][x]);
        printf("\n");
    }
}

// Systemes
int systemePhysique(double dt)
{
    int compte = 0;
    for (Entite e = 0; e < MAX; e++)
    {
        if (aCorps[e] && aTransform[e])
        {
            corps[e].vitesse += Vec2(0.0, -9.81) * dt;
            transforms[e].position += corps[e].vitesse * dt;
            compte++;
        }
    }
    return compte;
}

int systemeRendu()
{
    int compte = 0;
    for (Entite e = 0; e < MAX; e++)
    {
        if (aSprite[e] && aTransform[e])
        {
            int x = (int)transforms[e].position.x;
            int y = (int)transforms[e].position.y;
            point(x, H - 1 - y, sprites[e].glyphe);
            compte++;
        }
    }
    return compte;
}

// Aides pour fabriquer les entites
void ajouterTransform(Entite e, double x, double y)
{
    transforms[e].position = Vec2(x, y);
    transforms[e].rotation = 0.0;
    transforms[e].echelle = Vec2(1.0, 1.0);
    aTransform[e] = true;
}

void ajouterCorps(Entite e)
{
    corps[e].vitesse = Vec2(0.0, 0.0);
    corps[e].masse = 1.0;
    aCorps[e] = true;
}

void ajouterSprite(Entite e, char g)
{
    sprites[e].glyphe = g;
    aSprite[e] = true;
}

void pas(int numero)
{
    int p = systemePhysique(0.1);
    effacer();
    int r = systemeRendu();
    printf("Pas %d : physique = %d, rendu = %d\n", numero, p, r);
}

int main()
{
    initialiser();

    for (int i = 0; i < 40; i++)
    {
        Entite e = creerEntite();
        ajouterTransform(e, i, 0.0);
        ajouterSprite(e, '#');
    }
    for (int i = 0; i < 40; i++)
    {
        Entite e = creerEntite();
        ajouterTransform(e, i, 10.0);
        ajouterCorps(e);
        ajouterSprite(e, 'o');
    }
    for (int i = 0; i < 20; i++)
    {
        Entite e = creerEntite();
        ajouterTransform(e, i * 2, 5.0);
        ajouterCorps(e);
        ajouterSprite(e, 'E');
    }

    for (int i = 1; i <= 5; i++) pas(i);

    for (Entite e = 5; e <= 50; e += 5) detruireEntite(e);

    printf("Nouvelles entites :");
    for (int i = 0; i < 5; i++)
    {
        Entite e = creerEntite();
        printf(" %d", e);
        ajouterTransform(e, 30 + i, 15.0);
        ajouterCorps(e);
        ajouterSprite(e, '@');
    }
    printf("\n");

    pas(6);
    afficher();
    return 0;
}
