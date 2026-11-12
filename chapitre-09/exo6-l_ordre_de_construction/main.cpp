#include <cstdio>

const int MAXP = 1000;
const int MAXD = 20000;

char noms[MAXP][64];
int depOwner[MAXD];
char depNom[MAXD][64];
int nbDeps = 0;
int n = 0;

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

int trouver(const char* nom)
{
    for (int i = 0; i < n; i++)
    {
        if (memes(noms[i], nom)) return i;
    }
    return -1;
}

int main()
{
    int ordre[MAXP];
    bool construit[MAXP];
    int nbOrdre = 0;

    if (scanf("%d", &n) != 1) n = 0;
    if (n > MAXP) n = MAXP;

    for (int i = 0; i < n; i++)
    {
        int k = 0;
        construit[i] = false;
        if (scanf("%63s %d", noms[i], &k) != 2) break;
        for (int j = 0; j < k; j++)
        {
            char nom[64];
            if (scanf("%63s", nom) != 1) break;
            if (nbDeps < MAXD)
            {
                depOwner[nbDeps] = i;
                int m = 0;
                while (nom[m] != '\0')
                {
                    depNom[nbDeps][m] = nom[m];
                    m++;
                }
                depNom[nbDeps][m] = '\0';
                nbDeps++;
            }
        }
    }

    int depCible[MAXD];
    for (int e = 0; e < nbDeps; e++) depCible[e] = trouver(depNom[e]);

    bool cycle = false;
    while (nbOrdre < n && !cycle)
    {
        int choisi = -1;
        for (int p = 0; p < n && choisi < 0; p++)
        {
            if (construit[p]) continue;

            bool pret = true;
            for (int e = 0; e < nbDeps; e++)
            {
                if (depOwner[e] == p && depCible[e] >= 0 && !construit[depCible[e]]) pret = false;
            }
            if (pret) choisi = p;
        }

        if (choisi < 0)
        {
            cycle = true;
        }
        else
        {
            construit[choisi] = true;
            ordre[nbOrdre] = choisi;
            nbOrdre++;
        }
    }

    if (cycle)
    {
        printf("CYCLE\n");
        printf("PROJETS 0\n");
        return 0;
    }

    for (int i = 0; i < nbOrdre; i++) printf("%s\n", noms[ordre[i]]);
    printf("PROJETS %d\n", nbOrdre);
    return 0;
}
