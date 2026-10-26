#include <cstdio>

int longueur(const char s[]) {
    int n = 0;
    while (s[n] != '\0') {
        n = n + 1;
    }
    return n;
}

bool estPalindrome(const char s[]) {
    int n = longueur(s);
    for (int i = 0; i < n / 2; i = i + 1) {
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

void renverserTexte(char s[]) {
    int n = longueur(s);
    for (int i = 0; i < n / 2; i = i + 1) {
        char temp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = temp;
    }
}

int main() {
    char s[201];
    scanf("%200s", s);

    if (estPalindrome(s)) {
        printf("oui\n");
    } else {
        printf("non\n");
    }

    renverserTexte(s);
    printf("%s\n", s);

    return 0;
}