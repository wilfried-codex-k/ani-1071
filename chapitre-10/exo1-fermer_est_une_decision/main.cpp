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

int main()
{
    int n = 0;
    int demandes = 0;
    int ignores = 0;
    bool modifie = false;
    bool fermee = false;

    if (scanf("%d", &n) != 1) n = 0;

    for (int i = 0; i < n; i++)
    {
        char evenement[64];
        if (scanf("%63s", evenement) != 1) break;

        if (fermee)
        {
            ignores++;
        }
        else if (memes(evenement, "MODIF"))
        {
            modifie = true;
            printf("modifie\n");
        }
        else if (memes(evenement, "SAUVE"))
        {
            modifie = false;
            printf("enregistre\n");
        }
        else if (memes(evenement, "FERMETURE"))
        {
            demandes++;
            if (modifie)
            {
                printf("fermeture refusee\n");
            }
            else
            {
                printf("fermeture acceptee\n");
                fermee = true;
            }
        }
    }

    printf("DEMANDES %d\n", demandes);
    printf("IGNORES %d\n", ignores);
    if (fermee) printf("FERMEE oui\n");
    else printf("FERMEE non\n");
    return 0;
}
