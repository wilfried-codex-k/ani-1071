#include <cstdio>

int main()
{
    printf("=== SIMULATION : LE SEAU DU PAS FIXE ===\n\n");

    const double PAS = 1.0 / 120.0; // 120 pas par seconde
    const double PLAFOND = 0.25;    // 1/4 de seconde
    
    double seau = 0.0;
    double position = 0.0;
    double positionPrecedente = 0.0;
    double vitesse = 0.0;
    double gravite = 9.81;

    // On simule 10 images.
    // Les 9 premières durent 0.016s, la 10eme dure 1.0s (l'a-coup)
    double durees[10] = {0.016, 0.016, 0.016, 0.016, 0.016, 
                         0.016, 0.016, 0.016, 0.016, 1.0};
    
    printf("image | pas faits | alpha (milliemes)\n");
    printf("------+-----------+------------------\n");

    for (int i = 1; i <= 10; i++)
    {
        double ecoule = durees[i - 1];
        
        // 1. LE PLAFOND (contre la spirale de la mort)
        if (ecoule > PLAFOND) {
            ecoule = PLAFOND;
        }
        
        // 2. ON REMPLIT LE SEAU
        seau += ecoule;
        
        // 3. ON VIDE LE SEAU PAR PAS FIXES
        int pasFaits = 0;
        positionPrecedente = position;
        
        while (seau >= PAS) {
            // Un pas de physique
            vitesse += gravite * PAS;
            position += vitesse * PAS;
            
            seau -= PAS;
            pasFaits++;
        }
        
        // 4. INTERPOLATION (pour l'affichage uniquement)
        // alpha = ce qu'il reste dans le seau / taille d'un pas
        double alpha = seau / PAS;
        double positionAffichee = positionPrecedente + (position - positionPrecedente) * alpha;
        
        // Affichage pour les mesures
        printf("%5d | %9d | %16d\n", i, pasFaits, (int)(alpha * 1000));
    }

    printf("\n=== EXPERIENCE : RANGER L'INTERPOLATION DANS L'ETAT ===\n");
    printf("Si on range la position affichee dans la position du monde,\n");
    printf("la balle ralentit ou accelere de facon imprevisible, car on\n");
    printf("applique la gravite sur une position deja interpolee.\n");

    return 0;
}