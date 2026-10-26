#include <cstdio>

char* creerImage(int l, int h) {
    char* img = new char[l * h];
    for (int i = 0; i < l * h; i = i + 1) {
        img[i] = ' ';
    }
    return img;
}

void detruireImage(char* img) {
    delete[] img;
}

void point(char* img, int l, int h, int x, int y, char c) {
    if (x < 0 || x >= l || y < 0 || y >= h) {
        return;
    }
    img[y * l + x] = c;
}

void afficher(const char* img, int l, int h) {
    for (int y = 0; y < h; y = y + 1) {
        for (int x = 0; x < l; x = x + 1) {
            printf("%c", img[y * l + x]);
        }
        printf("\n");
    }
}

void dessinerCercle(char* img, int l, int h) {
    int cx = l / 2;
    int cy = h / 2;
    int rayon = h / 2 - 1;

    for (int y = 0; y < h; y = y + 1) {
        for (int x = 0; x < l; x = x + 1) {
            int dx = x - cx;
            int dy = y - cy;
            if (dx * dx + dy * dy <= rayon * rayon) {
                point(img, l, h, x, y, '#');
            }
        }
    }
}

int main() {
    int l1 = 30, h1 = 10;
    char* image1 = creerImage(l1, h1);
    dessinerCercle(image1, l1, h1);
    printf("--- Image 30 x 10 ---\n");
    afficher(image1, l1, h1);
    detruireImage(image1);

    int l2 = 80, h2 = 24;
    char* image2 = creerImage(l2, h2);
    dessinerCercle(image2, l2, h2);
    printf("\n--- Image 80 x 24 ---\n");
    afficher(image2, l2, h2);
    detruireImage(image2);

    return 0;
}