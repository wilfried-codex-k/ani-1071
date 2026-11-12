#include <cstdio>
#include <vec2.h>

int main()
{
    ani::Vec2 a = {3.0, 4.0};
    ani::Vec2 b = {1.0, 2.0};

    ani::Vec2 s = ani::add(a, b);
    printf("somme : (%.1f, %.1f)\n", s.x, s.y);
    printf("produit scalaire : %.1f\n", ani::dot(a, b));
    printf("longueur de a : %.1f\n", ani::length(a));

    // printf("%.1f\n", carre(2.0));
    return 0;
}
