#include <cstdio>

double lerp(double a, double b, double t) {
    return a + (b - a) * t;
}

class Image {
private:
    int largeur_;
    int hauteur_;
    char* pixels_;

public:
    static int vivantes;

    Image(int l, int h) : largeur_(l), hauteur_(h), pixels_(new char[l * h]) {
        vivantes++;
        for (int i = 0; i < largeur_ * hauteur_; i++) pixels_[i] = ' ';
    }

    ~Image() {
        delete[] pixels_;
        vivantes--;
    }

    Image(const Image&) = delete;
    Image& operator=(const Image&) = delete;

    void effacer(char c = ' ') {
        for (int i = 0; i < largeur_ * hauteur_; i++) pixels_[i] = c;
    }

    void point(int x, int y, char c = '#') {
        if (x < 0 || x >= largeur_ || y < 0 || y >= hauteur_) return;
        pixels_[y * largeur_ + x] = c;
    }

    void segment(double x0, double y0, double x1, double y1, char c = '#') {
        int pas = 60;
        for (int i = 0; i <= pas; i++) {
            double t = i / (double)pas;
            point((int)(lerp(x0, x1, t) + 0.5), (int)(lerp(y0, y1, t) + 0.5), c);
        }
    }

    void afficher() const {
        for (int y = 0; y < hauteur_; y++) {
            for (int x = 0; x < largeur_; x++) {
                printf("%c", pixels_[y * largeur_ + x]);
            }
            printf("\n");
        }
    }

    int largeur() const { return largeur_; }
    int hauteur() const { return hauteur_; }
};

int Image::vivantes = 0;

int main() {
    printf("--- Vivantes ---\n");
    printf("Avant la boucle : %d\n", Image::vivantes);

    for (int i = 0; i < 10; i++) {
        Image img(10, 5);
        img.segment(0, 0, 9, 4);
        printf("Tour %d : %d image(s) vivante(s)\n", i + 1, Image::vivantes);
    }

    printf("Apres la boucle : %d\n", Image::vivantes);

    printf("\n--- Dessin ---\n");
    Image a(20, 10);
    a.segment(0, 0, 19, 9, 'X');
    a.segment(0, 9, 19, 0, 'O');
    a.afficher();

    printf("\n--- Copie ---\n");
    // Image b = a; // Décommente pour tester l'erreur

    return 0;
}