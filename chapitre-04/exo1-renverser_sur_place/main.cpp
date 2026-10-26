#include <cstdio>

void renverser(int t[], int n) {
    for (int i = 0; i < n / 2; i = i + 1) {
        int temp = t[i];
        t[i] = t[n - 1 - i];
        t[n - 1 - i] = temp;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        printf("AUCUN\n");
        return 0;
    }

    if (n == 0) {
        printf("AUCUN\n");
        return 0;
    }

    int t[1000];
    for (int i = 0; i < n; i = i + 1) {
        scanf("%d", &t[i]);
    }

    renverser(t, n);

    for (int i = 0; i < n; i = i + 1) {
        printf("%d\n", t[i]);
    }

    return 0;
}