#include <cstdio>
#include <cstdlib>

long long compteur = 0;

void selection(int t[], int n) {
    for (int i = 0; i < n - 1; i = i + 1) {
        int minIndex = i;
        for (int j = i + 1; j < n; j = j + 1) {
            compteur++;
            if (t[j] < t[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = t[i];
            t[i] = t[minIndex];
            t[minIndex] = temp;
        }
    }
}

void triRapide(int t[], int bas, int haut) {
    if (bas >= haut) return;

    // On prend le milieu comme pivot
    int milieu = bas + (haut - bas) / 2;
    int pivot = t[milieu];

    int i = bas;
    int j = haut;

    while (i <= j) {
        while (t[i] < pivot) {
            compteur++;
            i++;
        }
        compteur++;
        
        while (t[j] > pivot) {
            compteur++;
            j--;
        }
        compteur++;
        
        if (i <= j) {
            int temp = t[i];
            t[i] = t[j];
            t[j] = temp;
            i++;
            j--;
        }
    }

    if (bas < j) triRapide(t, bas, j);
    if (i < haut) triRapide(t, i, haut);
}

void copier(int source[], int dest[], int n) {
    for (int i = 0; i < n; i = i + 1) {
        dest[i] = source[i];
    }
}

int main() {
    int tailles[] = {100, 1000, 10000, 100000};
    int nb_tailles = 4;

    printf("Aleatoire :\n");
    for (int k = 0; k < nb_tailles; k = k + 1) {
        int n = tailles[k];
        int* t1 = new int[n];
        int* t2 = new int[n];

        for (int i = 0; i < n; i = i + 1) {
            t1[i] = rand() % 10000;
        }
        copier(t1, t2, n);

        compteur = 0;
        triRapide(t1, 0, n - 1);
        long long comp_rapide = compteur;

        compteur = 0;
        selection(t2, n);
        long long comp_selection = compteur;

        printf("Taille %d : rapide = %lld, selection = %lld\n", n, comp_rapide, comp_selection);

        delete[] t1;
        delete[] t2;
    }

    // Test sur tableau deja trie
    printf("\nDeja trie :\n");
    int n_trie = 10000;
    int* t_trie = new int[n_trie];
    for (int i = 0; i < n_trie; i = i + 1) {
        t_trie[i] = i;
    }
    
    compteur = 0;
    triRapide(t_trie, 0, n_trie - 1);
    printf("Taille %d (deja trie) : rapide = %lld\n", n_trie, compteur);
    
    delete[] t_trie;

    return 0;
}