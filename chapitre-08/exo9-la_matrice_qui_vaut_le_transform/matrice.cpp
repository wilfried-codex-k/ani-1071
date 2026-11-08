#include <cstdio>
#include <cmath>

const double pi = 3.14159265358979323846;

struct Vec2
{
    double x, y;
    Vec2() : x(0.0), y(0.0) {}
    Vec2(double x_, double y_) : x(x_), y(y_) {}
    Vec2& operator+=(Vec2 b) { x += b.x; y += b.y; return *this; }
};

Vec2 operator+(Vec2 a, Vec2 b)     { return {a.x + b.x, a.y + b.y}; }
Vec2 operator*(Vec2 a, double k)   { return {a.x * k, a.y * k}; }

Vec2 rotate(Vec2 a, double angle)
{
    double c = cos(angle), s = sin(angle);
    return {a.x * c - a.y * s, a.x * s + a.y * c};
}

struct Transform
{
    Vec2   position {0.0, 0.0};
    double rotation  = 0.0;
    Vec2   echelle  {1.0, 1.0};

    Vec2 appliquer(Vec2 local) const
    {
        Vec2 p = {local.x * echelle.x, local.y * echelle.y};
        p = rotate(p, rotation);
        return p + position;
    }

    Transform compose(const Transform& enfant) const
    {
        Transform t;
        t.echelle  = {echelle.x * enfant.echelle.x, echelle.y * enfant.echelle.y};
        t.rotation = rotation + enfant.rotation;
        t.position = appliquer(enfant.position);
        return t;
    }
};

struct Mat3
{
    double m[3][3];

    static Mat3 identite()
    {
        Mat3 r;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                r.m[i][j] = (i == j) ? 1.0 : 0.0;
        return r;
    }

    static Mat3 depuis(const Transform& t)
    {
        Mat3 r = identite();
        double c = cos(t.rotation), s = sin(t.rotation);
        r.m[0][0] = t.echelle.x * c;
        r.m[0][1] = -t.echelle.y * s;
        r.m[0][2] = t.position.x;
        r.m[1][0] = t.echelle.x * s;
        r.m[1][1] = t.echelle.y * c;
        r.m[1][2] = t.position.y;
        return r;
    }

    Vec2 appliquer(Vec2 p) const
    {
        double x = m[0][0] * p.x + m[0][1] * p.y + m[0][2];
        double y = m[1][0] * p.x + m[1][1] * p.y + m[1][2];
        return Vec2(x, y);
    }

    // this * b : applique d'abord b, puis this
    Mat3 operator*(const Mat3& b) const
    {
        Mat3 r;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                r.m[i][j] = 0.0;
                for (int k = 0; k < 3; k++)
                {
                    r.m[i][j] += m[i][k] * b.m[k][j];
                }
            }
        }
        return r;
    }
};

// Generateur pseudo-aleatoire simple, meme resultat partout
unsigned int graine = 12345;

double hasard(double bas, double haut)
{
    graine = graine * 1103515245u + 12345u;
    double u = ((graine >> 8) & 0xFFFF) / 65535.0;
    return bas + (haut - bas) * u;
}

Transform transformAleatoire(bool uniforme)
{
    Transform t;
    t.position = Vec2(hasard(-5.0, 5.0), hasard(-5.0, 5.0));
    t.rotation = hasard(0.0, 2.0 * pi);
    double sx = hasard(0.5, 2.0);
    double sy = uniforme ? sx : hasard(0.5, 2.0);
    t.echelle = Vec2(sx, sy);
    return t;
}

double ecartMax(const Mat3& a, const Mat3& b)
{
    double e = 0.0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            double d = fabs(a.m[i][j] - b.m[i][j]);
            if (d > e) e = d;
        }
    }
    return e;
}

int main()
{
    // 1. Appliquer : dix Transform, cent points
    double pire = 0.0;
    for (int i = 0; i < 10; i++)
    {
        Transform t = transformAleatoire(i % 2 == 0);
        Mat3 M = Mat3::depuis(t);
        for (int k = 0; k < 100; k++)
        {
            Vec2 p(hasard(-10.0, 10.0), hasard(-10.0, 10.0));
            Vec2 a = M.appliquer(p);
            Vec2 b = t.appliquer(p);
            double d = fabs(a.x - b.x);
            if (fabs(a.y - b.y) > d) d = fabs(a.y - b.y);
            if (d > pire) pire = d;
        }
    }
    printf("Ecart max appliquer : %.3e\n", pire);

    // 2. Composer : quatre combinaisons, dix couples chacune
    const char* noms[4] = {
        "parent uniforme, enfant uniforme",
        "parent uniforme, enfant non uniforme",
        "parent non uniforme, enfant uniforme",
        "parent non uniforme, enfant non uniforme"
    };
    for (int c = 0; c < 4; c++)
    {
        bool parentUniforme = (c == 0 || c == 1);
        bool enfantUniforme = (c == 0 || c == 2);
        double ecart = 0.0;
        for (int i = 0; i < 10; i++)
        {
            Transform a = transformAleatoire(parentUniforme);
            Transform b = transformAleatoire(enfantUniforme);
            double e = ecartMax(Mat3::depuis(a.compose(b)), Mat3::depuis(a) * Mat3::depuis(b));
            if (e > ecart) ecart = e;
        }
        printf("Ecart max compose, %s : %.3e\n", noms[c], ecart);
    }

    // 3. Le cas le plus simple
    Transform a;
    a.echelle = Vec2(2.0, 1.0);
    Transform b;
    b.rotation = pi / 2.0;

    Vec2 p(1.0, 0.0);
    Vec2 viaCompose = Mat3::depuis(a.compose(b)).appliquer(p);
    Vec2 viaProduit = (Mat3::depuis(a) * Mat3::depuis(b)).appliquer(p);
    Vec2 enchaine = a.appliquer(b.appliquer(p));

    printf("a : echelle (2, 1), rotation 0, position (0, 0)\n");
    printf("b : echelle (1, 1), rotation pi/2, position (0, 0)\n");
    printf("point (1, 0)\n");
    printf("compose de Transform : (%.3f, %.3f)\n", viaCompose.x, viaCompose.y);
    printf("produit de matrices  : (%.3f, %.3f)\n", viaProduit.x, viaProduit.y);
    printf("b puis a, un par un  : (%.3f, %.3f)\n", enchaine.x, enchaine.y);
    return 0;
}
