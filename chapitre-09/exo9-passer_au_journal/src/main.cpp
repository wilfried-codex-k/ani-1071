#include <cstdio>
#include <NKLogger/NkLog.h>

int main()
{
    nkentseu::NkLog::Initialize("Ani1071");

    logger.Info("Demarrage du programme");

    int notes[5] = {12, 15, 9, 25, 7};
    int nb = 5;
    logger.Info("Lecture de {0} notes", nb);

    int somme = 0;
    int valides = 0;
    int meilleure = -1;
    for (int i = 0; i < nb; i++)
    {
        if (notes[i] > 20)
        {
            logger.Error("Note invalide : {0} (maximum {1})", notes[i], 20);
            continue;
        }
        if (notes[i] < 10)
        {
            logger.Warn("La note {0} est inferieure a {1}", notes[i], 10);
        }
        somme = somme + notes[i];
        valides++;
        if (notes[i] > meilleure) meilleure = notes[i];
        logger.Debug("Somme intermediaire : {0}", somme);
    }

    printf("Notes valides : %d\n", valides);
    printf("Somme : %d\n", somme);
    printf("Moyenne : %.2f\n", (double)somme / valides);
    printf("Meilleure note : %d\n", meilleure);

    logger.Info("Fin du programme");

    nkentseu::NkLog::Shutdown();
    return 0;
}
