#include <cstdio>

enum class TypeEvenement : unsigned char {
    Touche,
    Souris,
    Redimension
};

struct Evenement {
    TypeEvenement type; // L'etiquette (1 octet)
    union {
        struct { char code; bool pressee; } touche;
        struct { int x, y; int bouton; } souris;
        struct { int largeur, hauteur; } redimension;
    };
};

struct File {
    Evenement elements[100];
    int tete;
    int queue;
    int nombre;
};

void initialiserFile(File& f) {
    f.tete = 0;
    f.queue = 0;
    f.nombre = 0;
}

void enfiler(File& f, Evenement e) {
    if (f.nombre == 100) return;
    f.elements[f.queue] = e;
    f.queue = (f.queue + 1) % 100;
    f.nombre++;
}

Evenement defiler(File& f, bool& succes) {
    if (f.nombre == 0) {
        succes = false;
        Evenement vide = {};
        return vide;
    }
    Evenement e = f.elements[f.tete];
    f.tete = (f.tete + 1) % 100;
    f.nombre--;
    succes = true;
    return e;
}

void traiter(const Evenement& e) {
    switch (e.type) {
        case TypeEvenement::Touche:
            printf("Touche : code='%c', pressee=%d\n", e.touche.code, e.touche.pressee);
            break;
        case TypeEvenement::Souris:
            printf("Souris : x=%d, y=%d, bouton=%d\n", e.souris.x, e.souris.y, e.souris.bouton);
            break;
        case TypeEvenement::Redimension:
            printf("Redimension : largeur=%d, hauteur=%d\n", e.redimension.largeur, e.redimension.hauteur);
            break;
    }
}

void simulerClavier(File& f) {
    Evenement e1;
    e1.type = TypeEvenement::Touche;
    e1.touche.code = 'A';
    e1.touche.pressee = true;
    enfiler(f, e1);

    Evenement e2;
    e2.type = TypeEvenement::Souris;
    e2.souris.x = 100;
    e2.souris.y = 200;
    e2.souris.bouton = 1;
    enfiler(f, e2);

    Evenement e3;
    e3.type = TypeEvenement::Redimension;
    e3.redimension.largeur = 800;
    e3.redimension.hauteur = 600;
    enfiler(f, e3);

    for (int i = 0; i < 7; i++) {
        Evenement e;
        e.type = TypeEvenement::Touche;
        e.touche.code = (char)('a' + i);
        e.touche.pressee = (i % 2 == 0);
        enfiler(f, e);
    }
}

int main() {
    File f;
    initialiserFile(f);
    simulerClavier(f);

    printf("--- Traitement de la file ---\n");
    bool ok;
    for (int i = 0; i < 10; i++) {
        Evenement e = defiler(f, ok);
        if (ok) {
            traiter(e);
        }
    }

    printf("\n--- Tailles ---\n");
    Evenement e;
    printf("Taille de Evenement : %zu\n", sizeof(Evenement));
    printf("Taille de touche : %zu\n", sizeof(e.touche));
    printf("Taille de souris : %zu\n", sizeof(e.souris));
    printf("Taille de redimension : %zu\n", sizeof(e.redimension));

    printf("\n--- Lecture fautive ---\n");
    Evenement evtFautif;
    evtFautif.type = TypeEvenement::Touche;
    evtFautif.touche.code = 'X';
    evtFautif.touche.pressee = true;
    
    int xFautif = evtFautif.souris.x;
    printf("Valeur lue (decimal) : %d\n", xFautif);
    printf("Valeur lue (hexadecimal) : %x\n", xFautif);

    return 0;
}
