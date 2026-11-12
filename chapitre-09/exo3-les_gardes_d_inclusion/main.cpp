#include <cstdio>

const int MAXF = 500;
const int MAXE = 20000;

char noms[MAXF][64];
int garde[MAXF];
int mult[MAXF][MAXF];

int arOwner[MAXE];
char arNom[MAXE][64];

int n = 0;

long long insSans[MAXF];
bool faitSans[MAXF];
long long insAvec[MAXF];
bool faitAvec[MAXF];

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

long long calculerSans(int f)
{
    if (faitSans[f]) return insSans[f];
    long long total = (f == 0) ? 1 : 0;
    for (int p = 0; p < n; p++)
    {
        if (mult[p][f] > 0) total += mult[p][f] * calculerSans(p);
    }
    faitSans[f] = true;
    insSans[f] = total;
    return total;
}

long long calculerAvec(int f)
{
    if (faitAvec[f]) return insAvec[f];
    long long rencontres = (f == 0) ? 1 : 0;
    for (int p = 0; p < n; p++)
    {
        if (mult[p][f] > 0) rencontres += mult[p][f] * calculerAvec(p);
    }
    long long total = rencontres;
    if (f != 0 && garde[f] == 1 && rencontres > 1) total = 1;
    faitAvec[f] = true;
    insAvec[f] = total;
    return total;
}

int main()
{
    int nbAretes = 0;

    if (scanf("%d", &n) != 1) n = 0;
    if (n > MAXF) n = MAXF;

    for (int i = 0; i < n; i++)
    {
        int k = 0;
        if (scanf("%63s %d %d", noms[i], &garde[i], &k) != 3) break;
        for (int j = 0; j < k; j++)
        {
            char nom[64];
            if (scanf("%63s", nom) != 1) break;
            if (nbAretes < MAXE)
            {
                arOwner[nbAretes] = i;
                int m = 0;
                while (nom[m] != '\0')
                {
                    arNom[nbAretes][m] = nom[m];
                    m++;
                }
                arNom[nbAretes][m] = '\0';
                nbAretes++;
            }
        }
    }

    for (int e = 0; e < nbAretes; e++)
    {
        int cible = trouver(arNom[e]);
        if (cible >= 0) mult[arOwner[e]][cible]++;
    }

    long long totalSans = 0;
    long long totalAvec = 0;
    for (int i = 1; i < n; i++)
    {
        long long s = calculerSans(i);
        long long a = calculerAvec(i);
        printf("%s %lld %lld\n", noms[i], s, a);
        totalSans += s;
        totalAvec += a;
    }

    printf("TOTAL SANS %lld\n", totalSans);
    printf("TOTAL AVEC %lld\n", totalAvec);
    return 0;
}
