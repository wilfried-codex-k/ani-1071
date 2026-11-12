#include <cstdio>

const int MAXS = 5000;

char defNom[MAXS][64];
int defStatic[MAXS];
int defFichier[MAXS];
int nbDef = 0;

char useNom[MAXS][64];
int useFichier[MAXS];
int nbUse = 0;

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

void copier(char* dest, const char* src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main()
{
    int n = 0;
    if (scanf("%d", &n) != 1) n = 0;

    for (int f = 0; f < n; f++)
    {
        char nomFichier[64];
        int nd = 0;
        int nu = 0;

        if (scanf("%63s %d", nomFichier, &nd) != 2) break;
        for (int i = 0; i < nd; i++)
        {
            char nom[64];
            int drapeau = 0;
            if (scanf("%63s %d", nom, &drapeau) != 2) break;
            if (nbDef < MAXS)
            {
                copier(defNom[nbDef], nom);
                defStatic[nbDef] = drapeau;
                defFichier[nbDef] = f;
                nbDef++;
            }
        }

        if (scanf("%d", &nu) != 1) break;
        for (int i = 0; i < nu; i++)
        {
            char nom[64];
            if (scanf("%63s", nom) != 1) break;
            if (nbUse < MAXS)
            {
                copier(useNom[nbUse], nom);
                useFichier[nbUse] = f;
                nbUse++;
            }
        }
    }

    int indefinis = 0;
    char signales[MAXS][64];

    for (int u = 0; u < nbUse; u++)
    {
        bool trouve = false;
        for (int d = 0; d < nbDef; d++)
        {
            if (memes(defNom[d], useNom[u]))
            {
                if (defStatic[d] == 0 || defFichier[d] == useFichier[u]) trouve = true;
            }
        }
        if (!trouve)
        {
            bool dejaSignale = false;
            for (int s = 0; s < indefinis; s++)
            {
                if (memes(signales[s], useNom[u])) dejaSignale = true;
            }
            if (!dejaSignale)
            {
                printf("INDEFINI %s\n", useNom[u]);
                copier(signales[indefinis], useNom[u]);
                indefinis++;
            }
        }
    }

    int doubles = 0;
    for (int d = 0; d < nbDef; d++)
    {
        if (defStatic[d] != 0) continue;

        bool premiere = true;
        int total = 0;
        for (int e = 0; e < nbDef; e++)
        {
            if (defStatic[e] == 0 && memes(defNom[e], defNom[d]))
            {
                total++;
                if (e < d) premiere = false;
            }
        }
        if (premiere && total >= 2)
        {
            printf("DOUBLE %s\n", defNom[d]);
            doubles++;
        }
    }

    printf("INDEFINIS %d\n", indefinis);
    printf("DOUBLES %d\n", doubles);
    if (indefinis == 0 && doubles == 0) printf("VERDICT LIE\n");
    else printf("VERDICT ECHEC\n");
    return 0;
}
