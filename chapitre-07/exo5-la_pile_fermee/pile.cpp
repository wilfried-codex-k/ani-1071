#include <cstdio>

struct Pile {
private:
    static const int CAPACITE = 100;
    int elements[CAPACITE];
    int nombre;

public:
    Pile() : nombre(0) {}

    void empiler(int v) {
        if (nombre < CAPACITE) {
            elements[nombre] = v;
            nombre++;
        }
    }

    int depiler() {
        if (nombre > 0) {
            nombre--;
            return elements[nombre];
        }
        return -1;
    }

    int sommet() const {
        if (nombre > 0) return elements[nombre - 1];
        return -1;
    }

    bool vide() const { return nombre == 0; }
    bool pleine() const { return nombre == CAPACITE; }
    int taille() const { return nombre; }
};

class File {
private:
    static const int CAPACITE = 100;
    int elements[CAPACITE];
    int tete;
    int queue;
    int nombre;

public:
    File() : tete(0), queue(0), nombre(0) {}

    void enfiler(int v) {
        if (nombre < CAPACITE) {
            elements[queue] = v;
            queue = (queue + 1) % CAPACITE;
            nombre++;
        }
    }

    int defiler() {
        if (nombre > 0) {
            int v = elements[tete];
            tete = (tete + 1) % CAPACITE;
            nombre--;
            return v;
        }
        return -1;
    }

    bool pleine() const { return nombre == CAPACITE; }
    int taille() const { return nombre; }
};

int main() {
    Pile p;
    File f;

    // --- Test erreur d'acces ---
    p.nombre = -5; // Décommente pour tester l'erreur
    // f.tete = 7;    // Décommente pour tester l'erreur

    // --- Test debordement Pile ---
    for (int i = 0; i < 150; i++) p.empiler(i);
    printf("Pile apres 150 empiler : taille = %d, pleine = %d\n", p.taille(), p.pleine());
    for (int i = 0; i < 200; i++) p.depiler();
    printf("Pile apres 200 depiler : taille = %d, vide = %d\n", p.taille(), p.vide());

    // --- Test debordement File ---
    for (int i = 0; i < 150; i++) f.enfiler(i);
    printf("File apres 150 enfiler : taille = %d, pleine = %d\n", f.taille(), f.pleine());
    for (int i = 0; i < 5; i++) f.defiler();
    for (int i = 0; i < 10; i++) f.enfiler(i);
    printf("File apres 5 defiler et 10 enfiler : taille = %d\n", f.taille());

    return 0;
}