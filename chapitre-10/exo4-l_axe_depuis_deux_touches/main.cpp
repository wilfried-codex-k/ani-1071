#include <cstdio>

int main()
{
    long long pas = 0;
    int n = 0;
    long long position = 0;
    long long deplacement = 0;
    int immobile = 0;

    if (scanf("%lld", &pas) != 1) pas = 0;
    if (scanf("%d", &n) != 1) n = 0;

    for (int i = 0; i < n; i++)
    {
        long long gauche = 0;
        long long droite = 0;
        if (scanf("%lld %lld", &gauche, &droite) != 2) break;

        long long axe = droite - gauche;
        long long delta = axe * pas;

        position = position + delta;
        if (delta < 0) deplacement = deplacement - delta;
        else deplacement = deplacement + delta;
        if (axe == 0) immobile++;

        printf("%lld %lld\n", axe, position);
    }

    printf("DEPLACEMENT %lld\n", deplacement);
    printf("IMMOBILE %d\n", immobile);
    return 0;
}
