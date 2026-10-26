#include <cstdio>

void cribler(bool premier[], int n) {
    for (int i = 0; i <= n; i = i + 1) {
        premier[i] = true;
    }
    if (n >= 0) premier[0] = false;
    if (n >= 1) premier[1] = false;

    for (int i = 2; (long long)i * i <= n; i = i + 1) {
        if (premier[i]) {
            for (int j = i * i; j <= n; j = j + i) {
                premier[j] = false;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    if (n < 2) {
        printf("AUCUN\n");
        return 0;
    }

    bool premier[100001];
    cribler(premier, n);

    for (int i = 2; i <= n; i = i + 1) {
        if (premier[i]) {
            printf("%d\n", i);
        }
    }

    return 0;
}