#include <cstdio>

int noeudsVivants = 0;

struct Noeud {
    int valeur;
    Noeud* suivant;
};

Noeud* ajouterEnTete(Noeud* tete, int v) {
    Noeud* n = new Noeud;
    n->valeur = v;
    n->suivant = tete;
    noeudsVivants++;
    return n;
}

Noeud* ajouterEnQueue(Noeud* tete, int v) {
    Noeud* n = new Noeud;
    n->valeur = v;
    n->suivant = nullptr;
    noeudsVivants++;

    if (tete == nullptr) {
        return n;
    }

    Noeud* courant = tete;
    while (courant->suivant != nullptr) {
        courant = courant->suivant;
    }
    courant->suivant = n;
    return tete;
}

int compter(const Noeud* n) {
    int total = 0;
    while (n != nullptr) {
        total++;
        n = n->suivant;
    }
    return total;
}

bool contient(const Noeud* n, int v) {
    while (n != nullptr) {
        if (n->valeur == v) return true;
        n = n->suivant;
    }
    return false;
}

void afficher(const Noeud* n) {
    while (n != nullptr) {
        printf("%d -> ", n->valeur);
        n = n->suivant;
    }
    printf("nullptr\n");
}

Noeud* retirer(Noeud* tete, int v) {
    if (tete == nullptr) return nullptr;

    if (tete->valeur == v) {
        Noeud* aSupprimer = tete;
        tete = tete->suivant;
        delete aSupprimer;
        noeudsVivants--;
        return tete;
    }

    Noeud* courant = tete;
    while (courant->suivant != nullptr && courant->suivant->valeur != v) {
        courant = courant->suivant;
    }

    if (courant->suivant != nullptr) {
        Noeud* aSupprimer = courant->suivant;
        courant->suivant = aSupprimer->suivant;
        delete aSupprimer;
        noeudsVivants--;
    }
    return tete;
}

void liberer(Noeud* n) {
    while (n != nullptr) {
        Noeud* suivant = n->suivant;
        delete n;
        noeudsVivants--;
        n = suivant;
    }
}

Noeud* inverser(Noeud* tete) {
    Noeud* precedent = nullptr;
    Noeud* courant = tete;
    while (courant != nullptr) {
        Noeud* suivant = courant->suivant;
        courant->suivant = precedent;
        precedent = courant;
        courant = suivant;
    }
    return precedent;
}

int main() {
    Noeud* liste = nullptr;

    // Construction
    liste = ajouterEnTete(liste, 10);
    liste = ajouterEnTete(liste, 20);
    liste = ajouterEnQueue(liste, 30);
    liste = ajouterEnQueue(liste, 40);
    liste = ajouterEnTete(liste, 50);

    printf("Liste initiale : ");
    afficher(liste);
    printf("Nombre d'elements : %d\n", compter(liste));

    printf("\nContient 30 ? %s\n", contient(liste, 30) ? "oui" : "non");
    printf("Contient 99 ? %s\n", contient(liste, 99) ? "oui" : "non");

    // Test retirer
    printf("\n--- Retirer ---\n");
    liste = retirer(liste, 50); // tete
    printf("Apres retrait 50 (tete) : ");
    afficher(liste);

    liste = retirer(liste, 30); // milieu
    printf("Apres retrait 30 (milieu) : ");
    afficher(liste);

    liste = retirer(liste, 99); // absent
    printf("Apres retrait 99 (absent) : ");
    afficher(liste);

    // Test inverser
    printf("\n--- Inverser ---\n");
    liste = inverser(liste);
    printf("Apres inversion : ");
    afficher(liste);

    // Test liberer
    printf("\n--- Liberer ---\n");
    printf("Noeuds vivants avant liberer : %d\n", noeudsVivants);
    liberer(liste);
    liste = nullptr;
    printf("Noeuds vivants apres liberer : %d\n", noeudsVivants);

    return 0;
}