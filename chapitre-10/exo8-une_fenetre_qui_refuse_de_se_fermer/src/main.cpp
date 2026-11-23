#include <cstdio>

int main()
{
    printf("Simulation de la fenetre\n");
    printf("Tapez 1 pour cliquer sur la croix, -1 pour quitter.\n\n");

    int demandesFermeture = 0;
    int evenement = 0;

    while (evenement != -1)
    {
        scanf("%d", &evenement);

        if (evenement == 1)
        {
            demandesFermeture++;
            if (demandesFermeture == 1)
            {
                printf("fermeture refusee\n");
            }
            else
            {
                printf("fermeture acceptee\n");
                evenement = -1; // On ferme le programme
            }
        }
    }

    return 0;
}