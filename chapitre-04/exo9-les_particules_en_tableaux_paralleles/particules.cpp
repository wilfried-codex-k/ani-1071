#include <cstdio>
#include <chrono>

const int N = 10000;
const int TOURS = 1000;

struct Particule {
    double x;
    double y;
    double vx;
    double vy;
    int vie;
    int couleur;
};

int main() {
    // --- Version 1 : tableau de structures ---
    Particule particules[N];
    for (int i = 0; i < N; i = i + 1) {
        particules[i].x = 0.0;
        particules[i].y = 0.0;
        particules[i].vx = 1.0;
        particules[i].vy = 0.5;
        particules[i].vie = 1000;
        particules[i].couleur = i % 256;
    }

    // Boucle position, tableau de structures
    auto debut1 = std::chrono::steady_clock::now();
    for (int t = 0; t < TOURS; t = t + 1) {
        for (int i = 0; i < N; i = i + 1) {
            particules[i].x = particules[i].x + particules[i].vx;
            particules[i].y = particules[i].y + particules[i].vy;
        }
    }
    auto fin1 = std::chrono::steady_clock::now();
    long long duree1 = std::chrono::duration_cast<std::chrono::microseconds>(fin1 - debut1).count();

    // Boucle vie, tableau de structures
    auto debut2 = std::chrono::steady_clock::now();
    for (int t = 0; t < TOURS; t = t + 1) {
        for (int i = 0; i < N; i = i + 1) {
            particules[i].vie = particules[i].vie - 1;
        }
    }
    auto fin2 = std::chrono::steady_clock::now();
    long long duree2 = std::chrono::duration_cast<std::chrono::microseconds>(fin2 - debut2).count();

    // --- Version 2 : tableaux paralleles ---
    double px[N], py[N], pvx[N], pvy[N];
    int pvie[N], pcouleur[N];
    for (int i = 0; i < N; i = i + 1) {
        px[i] = 0.0;
        py[i] = 0.0;
        pvx[i] = 1.0;
        pvy[i] = 0.5;
        pvie[i] = 1000;
        pcouleur[i] = i % 256;
    }

    // Boucle position, tableaux paralleles
    auto debut3 = std::chrono::steady_clock::now();
    for (int t = 0; t < TOURS; t = t + 1) {
        for (int i = 0; i < N; i = i + 1) {
            px[i] = px[i] + pvx[i];
            py[i] = py[i] + pvy[i];
        }
    }
    auto fin3 = std::chrono::steady_clock::now();
    long long duree3 = std::chrono::duration_cast<std::chrono::microseconds>(fin3 - debut3).count();

    // Boucle vie, tableaux paralleles
    auto debut4 = std::chrono::steady_clock::now();
    for (int t = 0; t < TOURS; t = t + 1) {
        for (int i = 0; i < N; i = i + 1) {
            pvie[i] = pvie[i] - 1;
        }
    }
    auto fin4 = std::chrono::steady_clock::now();
    long long duree4 = std::chrono::duration_cast<std::chrono::microseconds>(fin4 - debut4).count();

    // Affichage des resultats
    printf("structures, position : %lld\n", duree1);
    printf("structures, vie      : %lld\n", duree2);
    printf("paralleles, position : %lld\n", duree3);
    printf("paralleles, vie      : %lld\n", duree4);

    // Empeche le compilateur de supprimer les boucles
    printf("temoin : %.2f %d\n", px[0] + particules[0].x, pvie[0]);

    return 0;
}