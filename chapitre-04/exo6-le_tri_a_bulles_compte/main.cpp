#include <cstdio>

long long trierParBulles(int t[], int n) {
    long long echanges = 0;

    for (int i = 0; i < n - 1; i = i + 1) {
        for (int j = 0; j < n - 1 - i; j = j + 1) {
            if (t[j] > t[j + 1]) {
                int temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
                echanges = echanges + 1;
            }
        }
    }

    return echanges;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("AUCUN\n");
        return 0;
    }

    int t[1000];
    for (int i = 0; i < n; i = i + 1) {
        scanf("%d", &t[i]);
    }

    long long echanges = trierParBulles(t, n);

    for (int i = 0; i < n; i = i + 1) {
        printf("%d\n", t[i]);
    }

    printf("%lld\n", echanges);

    return 0;
}