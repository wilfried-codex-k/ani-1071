#include <cstdio>

int imagesVivantes = 0;

class Image {
private:
    int largeur_;
    int hauteur_;
    char* pixels_;

public:
    Image(int l, int h) : largeur_(l), hauteur_(h), pixels_(new char[l * h]) {
        imagesVivantes++;
        for (int i = 0; i < largeur_ * hauteur_; i++) pixels_[i] = ' ';
    }

    Image(const Image& autre) : largeur_(autre.largeur_), hauteur_(autre.hauteur_), pixels_(new char[autre.largeur_ * autre.hauteur_]) {
        imagesVivantes++;
        for (int i = 0; i < largeur_ * hauteur_; i++) pixels_[i] = autre.pixels_[i];
    }

    Image& operator=(const Image& autre) {
        // if (this == &autre) return *this; // Ligne commentée pour le test
        
        if (this != &autre) {
            delete[] pixels_;
            largeur_ = autre.largeur_;
            hauteur_ = autre.hauteur_;
            pixels_ = new char[largeur_ * hauteur_];
            for (int i = 0; i < largeur_ * hauteur_; i++) pixels_[i] = autre.pixels_[i];
        }
        return *this;
    }

    ~Image() {
        delete[] pixels_;
        imagesVivantes--;
    }

    void point(int x, int y, char c = '#') {
        if (x < 0 || x >= largeur_ || y < 0 || y >= hauteur_) return;
        pixels_[y * largeur_ + x] = c;
    }

    void afficher() const {
        for (int y = 0; y < hauteur_; y++) {
            for (int x = 0; x < largeur_; x++) printf("%c", pixels_[y * largeur_ + x]);
            printf("\n");
        }
    }
    
    // Ajoute pour afficher l'adresse
    void* getPixels() const { return pixels_; }
};

int main() {
    {
        printf("--- Copie ---\n");
        Image a(5, 5);
        a.point(0, 0, 'A');
        
        Image b = a;
        b.point(4, 4, 'B');
        
        printf("Image a :\n"); a.afficher();
        printf("Image b :\n"); b.afficher();

        Image c(2, 2);
        c = a;
        c.point(2, 2, 'C');
        
        printf("Image a (apres c = a) :\n"); a.afficher();
        printf("Vivantes dans le bloc : %d\n", imagesVivantes);
    }
    printf("Vivantes apres le bloc : %d\n", imagesVivantes);

    printf("\n--- Sans le test ---\n");
    for (int i = 0; i < 3; i++) { // On lance 3 fois (mais le programme est 1 seul)
        Image a(5, 5);
        a.point(0, 0, 'A');
        printf("Lancement %d - Avant : %p\n", i+1, a.getPixels());
        
        a = a; // Auto-affectation dangereuse
        
        printf("Lancement %d - Apres : %p\n", i+1, a.getPixels());
        a.afficher();
    }

    return 0;
}