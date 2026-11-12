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

bool verifie(const char* type, long long attendu, long long obtenu)
{
    if (memes(type, "EQUAL")) return attendu == obtenu;
    if (memes(type, "NOT_EQUAL")) return attendu != obtenu;
    if (memes(type, "LESS")) return attendu < obtenu;
    if (memes(type, "GREATER")) return attendu > obtenu;
    if (memes(type, "LESS_EQUAL")) return attendu <= obtenu;
    if (memes(type, "GREATER_EQUAL")) return attendu >= obtenu;
    return false;
}

int main()
{
    int n = 0;
    int reussis = 0;
    int echoues = 0;

    if (scanf("%d", &n) != 1) n = 0;

    for (int k = 1; k <= n; k++)
    {
        char type[64];
        long long attendu = 0;
        long long obtenu = 0;

        if (scanf("%63s %lld %lld", type, &attendu, &obtenu) != 3) break;

        if (verifie(type, attendu, obtenu))
        {
            printf("cas %d OK\n", k);
            reussis++;
        }
        else
        {
            printf("cas %d ECHEC attendu %lld obtenu %lld\n", k, attendu, obtenu);
            echoues++;
        }
    }

    printf("REUSSIS %d\n", reussis);
    printf("ECHOUES %d\n", echoues);
    if (echoues == 0) printf("VERDICT VERT\n");
    else printf("VERDICT ROUGE\n");
    return 0;
}
