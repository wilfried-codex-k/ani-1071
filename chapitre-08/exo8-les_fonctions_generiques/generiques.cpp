#include <cstdio>
#include <string>

struct Vec2
{
    double x, y;
};

template <typename T>
void echanger(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T maximum(T a, T b) { return (a > b) ? a : b; }

template <typename T>
T minimum(T a, T b) { return (a < b) ? a : b; }

template <typename T>
T clamp(T x, T bas, T haut)
{
    if (x < bas) return bas;
    if (x > haut) return haut;
    return x;
}

template <typename T>
void trier(T t[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int plusPetit = i;
        for (int j = i + 1; j < n; j++)
        {
            if (t[j] < t[plusPetit]) plusPetit = j;
        }
        echanger(t[i], t[plusPetit]);
    }
}

int main()
{
    int a = 3, b = 7;
    double c = 2.5, d = 1.5;

    printf("maximum(3, 7) = %d\n", maximum(a, b));
    printf("minimum(3, 7) = %d\n", minimum(a, b));
    printf("maximum(2.5, 1.5) = %.1f\n", maximum(c, d));
    printf("minimum(2.5, 1.5) = %.1f\n", minimum(c, d));
    printf("clamp(15, 0, 10) = %d\n", clamp(15, 0, 10));
    printf("clamp(-2.5, 0.0, 1.0) = %.1f\n", clamp(-2.5, 0.0, 1.0));

    echanger(a, b);
    printf("echanger sur int : a = %d, b = %d\n", a, b);
    echanger(c, d);
    printf("echanger sur double : c = %.1f, d = %.1f\n", c, d);

    Vec2 u = {1.0, 2.0};
    Vec2 v = {3.0, 4.0};
    echanger(u, v);
    printf("echanger sur Vec2 : u = (%.1f, %.1f), v = (%.1f, %.1f)\n", u.x, u.y, v.x, v.y);

    int nombres[5] = {9, 4, 7, 1, 5};
    trier(nombres, 5);
    printf("trier sur int :");
    for (int i = 0; i < 5; i++) printf(" %d", nombres[i]);
    printf("\n");

    std::string mots[5] = {"zebre", "Yaounde", "arbre", "Zoo", "abricot"};
    trier(mots, 5);
    printf("trier sur string :");
    for (int i = 0; i < 5; i++) printf(" %s", mots[i].c_str());
    printf("\n");

    // printf("%.1f\n", maximum(u, v).x);
    // printf("%.1f\n", maximum(3, 7.5));
    return 0;
}
