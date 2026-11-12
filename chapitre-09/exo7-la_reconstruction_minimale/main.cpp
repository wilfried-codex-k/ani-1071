#include <cstdio>

const int MAXC = 1000;

char noms[MAXC][64];
long long dates[MAXC];
bool aReconstruire[MAXC];

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

int main()
{
    int n = 0;
    int nbReconstruire = 0;
    int nbAJour = 0;

    if (scanf("%d", &n) != 1) n = 0;
    if (n > MAXC) n = MAXC;

    for (int i = 0; i < n; i++)
    {
        int k = 0;
        if (scanf("%63s %lld %d", noms[i], &dates[i], &k) != 3) break;

        bool refaire = (dates[i] == -1);

        for (int j = 0; j < k; j++)
        {
            char nom[64];
            if (scanf("%63s", nom) != 1) break;

            for (int d = 0; d < i; d++)
            {
                if (memes(noms[d], nom))
                {
                    if (dates[d] > dates[i]) refaire = true;
                    if (aReconstruire[d]) refaire = true;
                }
            }
        }

        aReconstruire[i] = refaire;
        if (refaire)
        {
            printf("%s A RECONSTRUIRE\n", noms[i]);
            nbReconstruire++;
        }
        else
        {
            printf("%s A JOUR\n", noms[i]);
            nbAJour++;
        }
    }

    printf("A RECONSTRUIRE %d\n", nbReconstruire);
    printf("A JOUR %d\n", nbAJour);
    return 0;
}
