#include <cstdio>
#include <chrono>

double maintenant() {
    using namespace std::chrono;
    auto t = steady_clock::now().time_since_epoch();
    return duration<double>(t).count();
}

class Chrono {
private:
    double instantDepart;

public:
    Chrono() {
        instantDepart = maintenant();
    }

    double ecoule() const {
        return maintenant() - instantDepart;
    }

    void redemarrer() {
        instantDepart = maintenant();
    }
};

int main() {
    // --- Partie 1 : La boucle ---
    long long total = 0;
    
    Chrono c; // Demarre ici
    
    for (long long i = 0; i < 100000000; i++) {
        total += i;
    }
    
    double duree = c.ecoule(); // Mesure ici
    printf("Boucle : total = %lld, duree = %.6f s\n", total, duree);

    // --- Partie 2 : Le plus court ---
    printf("\n--- Le plus court ---\n");
    for (int i = 0; i < 5; i++) {
        c.redemarrer();
        double d = c.ecoule();
        printf("Essai %d : %.9f s\n", i + 1, d);
    }

    // --- Partie 3 : Le message d'erreur ---
    // Décommente les deux lignes ci-dessous pour voir l'erreur
    //const Chrono k;
    //k.redemarrer();

    return 0;
}