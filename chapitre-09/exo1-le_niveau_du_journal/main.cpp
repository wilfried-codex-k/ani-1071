#include <cstdio>

bool memes(const char* a, const char* b)
{
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i]) return false;
        i++;
    }
    return a[i] == b[i];
}

int niveau(const char* nom)
{
    if (memes(nom, "DEBUG")) return 0;
    if (memes(nom, "INFO")) return 1;
    if (memes(nom, "WARN")) return 2;
    if (memes(nom, "ERROR")) return 3;
    return -1;
}

int main()
{
    char seuilNom[256];
    char niv[256];
    char mot[256];
    int n = 0;
    int affiches = 0;
    int filtres = 0;

    seuilNom[0] = '\0';
    if (scanf("%255s", seuilNom) != 1) seuilNom[0] = '\0';
    if (scanf("%d", &n) != 1) n = 0;

    int seuil = niveau(seuilNom);

    for (int i = 0; i < n; i++)
    {
        if (scanf("%255s %255s", niv, mot) != 2) break;

        int lvl = niveau(niv);
        if (seuil >= 0 && lvl >= 0 && lvl >= seuil)
        {
            printf("%s %s\n", niv, mot);
            affiches++;
        }
        else
        {
            filtres++;
        }
    }

    printf("AFFICHES %d\n", affiches);
    printf("FILTRES %d\n", filtres);
    return 0;
}
