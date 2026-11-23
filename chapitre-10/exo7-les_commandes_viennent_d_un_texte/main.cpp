#include <cstdio>

const int MAXL = 200;
const int MAXT = 500;

char nomLiaison[MAXL][64];
int estAxe[MAXL];
char toucheA[MAXL][64];
char toucheB[MAXL][64];

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

bool enfoncee(char touches[][64], int nb, const char* nom)
{
    for (int i = 0; i < nb; i++)
    {
        if (memes(touches[i], nom)) return true;
    }
    return false;
}

int main()
{
    int nbLiaisons = 0;
    int nbImages = 0;
    int activations = 0;
    int axesNonNuls = 0;

    if (scanf("%d", &nbLiaisons) != 1) nbLiaisons = 0;
    if (nbLiaisons > MAXL) nbLiaisons = MAXL;

    for (int i = 0; i < nbLiaisons; i++)
    {
        char type[64];
        if (scanf("%63s %63s", nomLiaison[i], type) != 2) break;

        if (memes(type, "AXE"))
        {
            estAxe[i] = 1;
            if (scanf("%63s %63s", toucheA[i], toucheB[i]) != 2) break;
        }
        else
        {
            estAxe[i] = 0;
            if (scanf("%63s", toucheA[i]) != 1) break;
            toucheB[i][0] = '\0';
        }
    }

    if (scanf("%d", &nbImages) != 1) nbImages = 0;

    for (int image = 1; image <= nbImages; image++)
    {
        char touches[MAXT][64];
        int k = 0;
        if (scanf("%d", &k) != 1) break;
        if (k > MAXT) k = MAXT;
        for (int t = 0; t < k; t++)
        {
            if (scanf("%63s", touches[t]) != 1) break;
        }

        printf("image %d\n", image);
        for (int i = 0; i < nbLiaisons; i++)
        {
            int valeur = 0;
            if (estAxe[i] == 1)
            {
                if (enfoncee(touches, k, toucheB[i])) valeur = valeur + 1;
                if (enfoncee(touches, k, toucheA[i])) valeur = valeur - 1;
                if (valeur != 0) axesNonNuls++;
            }
            else
            {
                if (enfoncee(touches, k, toucheA[i])) valeur = 1;
                if (valeur == 1) activations++;
            }
            printf("%s %d\n", nomLiaison[i], valeur);
        }
    }

    printf("ACTIVATIONS %d\n", activations);
    printf("AXES NON NULS %d\n", axesNonNuls);
    return 0;
}
