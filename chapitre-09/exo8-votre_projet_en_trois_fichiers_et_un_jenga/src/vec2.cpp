#include <vec2.h>
#include <cmath>

namespace
{
    double carre(double x)
    {
        return x * x;
    }
}

namespace ani
{
    Vec2 add(Vec2 a, Vec2 b)
    {
        return {a.x + b.x, a.y + b.y};
    }

    double dot(Vec2 a, Vec2 b)
    {
        return a.x * b.x + a.y * b.y;
    }

    double length(Vec2 v)
    {
        return sqrt(carre(v.x) + carre(v.y));
    }
}
