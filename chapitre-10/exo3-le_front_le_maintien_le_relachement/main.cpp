#include <cstdio>

int main()
{
    int n = 0;
    int appuis = 0;
    int relaches = 0;
    bool avant = false;

    if (scanf("%d", &n) != 1) n = 0;

    for (int i = 1; i <= n; i++)
    {
        int valeur = 0;
        if (scanf("%d", &valeur) != 1) break;

        bool maintenant = (valeur != 0);

        if (maintenant && !avant)
        {
            printf("%d APPUYE\n", i);
            appuis++;
        }
        else if (maintenant && avant)
        {
            printf("%d MAINTENU\n", i);
        }
        else if (!maintenant && avant)
        {
            printf("%d RELACHE\n", i);
            relaches++;
        }
        else
        {
            printf("%d RIEN\n", i);
        }

        avant = maintenant;
    }

    printf("APPUIS %d\n", appuis);
    printf("RELACHES %d\n", relaches);
    return 0;
}
