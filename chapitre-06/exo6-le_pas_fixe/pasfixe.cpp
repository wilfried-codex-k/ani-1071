#include <chrono>
#include <cstdio>
#include <cstdlib>

double maintenant() {
    using namespace std::chrono;
    auto t = steady_clock::now().time_since_epoch();
    return duration<double>(t).count();
}

int appelsMiseAJour = 0;

void mettreAJour(double dt) {
    (void)dt; // Pour dire au compilateur qu'on sait que dt n'est pas utilise
    appelsMiseAJour++;
}

int main() {
    const double PAS = 1.0 / 120.0;
    double accumulateur = 0.0;
    
    int tours = 0;
    double precedent = maintenant();
    double debut = precedent;
    
    printf("--- Attentes courtes ---\n");
    while (maintenant() - debut < 10.0) {
        double actuel = maintenant();
        accumulateur += actuel - precedent;
        precedent = actuel;
        
        while (accumulateur >= PAS) {
            mettreAJour(PAS);
            accumulateur -= PAS;
        }
        
        double duree_attente = (rand() % 1000) / 1000000.0; 
        double fin_attente = maintenant() + duree_attente;
        while (maintenant() < fin_attente) {} 
        
        tours++;
    }
    printf("Attente max : 0.001 s\n");
    printf("Tours : %d\n", tours);
    printf("Appels a mettreAJour : %d\n", appelsMiseAJour);

    appelsMiseAJour = 0;
    tours = 0;
    accumulateur = 0.0;
    precedent = maintenant();
    debut = precedent;

    printf("\n--- Attentes longues ---\n");
    while (maintenant() - debut < 10.0) {
        double actuel = maintenant();
        accumulateur += actuel - precedent;
        precedent = actuel;
        
        while (accumulateur >= PAS) {
            mettreAJour(PAS);
            accumulateur -= PAS;
        }
        
        double duree_attente = (rand() % 50000) / 1000000.0; 
        double fin_attente = maintenant() + duree_attente;
        while (maintenant() < fin_attente) {}
        
        tours++;
    }
    printf("Attente max : 0.050 s\n");
    printf("Tours : %d\n", tours);
    printf("Appels a mettreAJour : %d\n", appelsMiseAJour);

    return 0;
}