#include <cstdio>

int main()
{
    printf("=== MESURES DES TROIS HAUTEURS (Simulation) ===\n");
    printf("Hypothese : 3 secondes de maintien, a 60 images par seconde (soit 180 images).\n\n");

    // 1. Par Evenement (simule la repetition du clavier)
    // Le systeme envoie un evenement a l'appui, puis apres un delai (ex: 0.5s), puis repete.
    // On simule : 1 pas a l'image 1, 0 pas jusqu'a l'image 30, puis 1 pas toutes les 2 images.
    int pos_evenement = 0;
    for (int i = 1; i <= 180; i++) {
        if (i == 1) pos_evenement += 5; // appui initial
        else if (i > 30 && i % 2 == 0) pos_evenement += 5; // repetition
    }

    // 2. Par Etat (lit la touche a chaque pas de physique)
    // La touche est enfoncee pendant 3 secondes (180 images). Avance de 5 pixels par image.
    int pos_etat = 0;
    for (int i = 1; i <= 180; i++) {
        pos_etat += 5;
    }

    // 3. Par Axe (calcule depuis deux fleches, avec annulation)
    // On maintient uniquement la fleche droite. L'axe vaut 1. Avance de 5 pixels par image.
    int pos_axe = 0;
    for (int i = 1; i <= 180; i++) {
        int axe = 1 - 0; // droite - gauche
        pos_axe += axe * 5;
    }

    // Affichage des resultats
    printf("Version par evenement : %d pixels\n", pos_evenement);
    printf("Version par etat      : %d pixels\n", pos_etat);
    printf("Version par axe       : %d pixels\n", pos_axe);
    
    printf("\nRemarque : le defaut de la version par evenement (le delai avant la repetition)\n");
    printf("s'observe tres bien si l'on garde la touche enfoncee.\n");

    return 0;
}