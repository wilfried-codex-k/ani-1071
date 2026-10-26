#include <chrono>
#include <cstdio>

double maintenant() {
    using namespace std::chrono;
    auto t = steady_clock::now().time_since_epoch();
    return duration<double>(t).count(); // en secondes
}

int main() {
    // --- Partie 1 : La boucle ---
    long long total = 0;
    double debut = maintenant();

    for (int i = 1; i <= 1000000; i = i + 1) {
        total = total + i;
    }

    double fin = maintenant();
    double duree = fin - debut;

    printf("Boucle : total = %lld, duree = %.6f s\n", total, duree);

    // --- Partie 2 : Cinq printf ---
    double durees_printf[5];

    for (int i = 0; i < 5; i = i + 1) {
        double d1 = maintenant();
        printf("Ligne de test %d\n", i);
        double d2 = maintenant();
        durees_printf[i] = d2 - d1;
    }

    printf("\nDurees des 5 printf :\n");
    for (int i = 0; i < 5; i = i + 1) {
        printf("printf %d : %.6f s\n", i, durees_printf[i]);
    }

    return 0;
}