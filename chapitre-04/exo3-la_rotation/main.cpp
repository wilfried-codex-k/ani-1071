#include <cstdio>

void tourner(int t[], int n, int k) {
    if (n <= 0) return;

    int decalage = k % n;
    if (decalage < 0) {
        decalage = decalage + n;
    }
    decalage = decalage % n;

    if (decalage == 0) return;

    int copie[1000];
    for (int i = 0; i < n; i = i + 1) {
        copie[i] = t[i];
    }

    for (int i = 0; i < n; i = i + 1) {
        int source = (i + decalage) % n;
        t[i] = copie[source];
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    if (n == 0) {
        printf("AUCUN\n");
        return 0;
    }

    int t[1000];
    for (int i = 0; i < n; i = i + 1) {
        scanf("%d", &t[i]);
    }

    tourner(t, n, k);

    for (int i = 0; i < n; i = i + 1) {
        printf("%d\n", t[i]);
    }

    return 0;
}