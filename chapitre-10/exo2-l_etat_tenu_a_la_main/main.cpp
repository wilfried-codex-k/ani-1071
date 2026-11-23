#include <cstdio>

const int MAXK = 2000;

char noms[MAXK][64];
bool enfoncee[MAXK];
int nbNoms = 0;

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

int chercher(const char* nom)
{
    for (int i = 0; i < nbNoms; i++)
    {
        if (memes(noms[i], nom)) return i;
    }
    if (nbNoms >= MAXK) return -1;

    int m = 0;
    while (nom[m] != '\0')
    {
        noms[nbNoms][m] = nom[m];
        m++;
    }
    noms[nbNoms][m] = '\0';
    enfoncee[nbNoms] = false;
    nbNoms++;
    return nbNoms - 1;
}

int main()
{
    int n = 0;
    int oublis = 0;

    if (scanf("%d", &n) != 1) n = 0;

    for (int i = 0; i < n; i++)
    {
        char type[64];
        char touche[64];
        if (scanf("%63s", type) != 1) break;

        if (memes(type, "FOCUS_PERDU"))
        {
            for (int k = 0; k < nbNoms; k++)
            {
                if (enfoncee[k])
                {
                    oublis++;
                    enfoncee[k] = false;
                }
            }
        }
        else
        {
            if (scanf("%63s", touche) != 1) break;
            int k = chercher(touche);
            if (k < 0) continue;

            if (memes(type, "BAS"))
            {
                enfoncee[k] = true;
            }
            else if (memes(type, "HAUT"))
            {
                enfoncee[k] = false;
            }
            else if (memes(type, "QUESTION"))
            {
                if (enfoncee[k]) printf("oui\n");
                else printf("non\n");
            }
        }
    }

    int total = 0;
    for (int k = 0; k < nbNoms; k++)
    {
        if (enfoncee[k]) total++;
    }

    printf("ENFONCEES %d\n", total);
    printf("OUBLIS %d\n", oublis);
    return 0;
}
