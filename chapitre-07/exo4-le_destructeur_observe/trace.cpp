#include <cstdio>

class Trace {
private:
    const char* nom;
public:
    Trace(const char* n) : nom(n) {
        printf("%s nait\n", nom);
    }
    ~Trace() {
        printf("%s meurt\n", nom);
    }
};

void fonction() {
    Trace t_fonction("t_fonction");
    printf("Fin de la fonction\n");
}

int main() {
    printf("Debut de main\n");
    
    Trace t_main("t_main");
    
    {
        Trace t_bloc1("t_bloc1");
        Trace t_bloc2("t_bloc2");
        printf("Fin du bloc\n");
    }

    Trace* t_new_sans_delete = new Trace("t_new_sans_delete");
    (void)t_new_sans_delete;

    Trace* t_new_avec_delete = new Trace("t_new_avec_delete");
    delete t_new_avec_delete;

    fonction();

    printf("Fin de main (avant return)\n");

    // Ligne ajoutee pour l'exercice
    t_main.~Trace();

    return 0;
}