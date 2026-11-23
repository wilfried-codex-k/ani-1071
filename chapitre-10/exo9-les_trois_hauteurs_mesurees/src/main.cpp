#include <cstdio>
#include <chrono>
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

using namespace nkentseu;

const double PAS = 1.0 / 120.0;
const double CRAN = 1.0;
const double PLAFOND = 0.25;

double maintenant()
{
    return std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count();
}

void dessinerCarre(NkWindow& fenetre, double x)
{
    (void)fenetre;
    (void)x;
    // A COMPLETER : dessiner un carre en (x, 300) avec l'appel de dessin du moteur
}

void ecrireMesures(const double distances[3])
{
    const char* noms[3] = {"par evenement", "par etat", "par axe"};
    FILE* f = fopen("mesures.txt", "w");
    if (f == nullptr) return;
    for (int i = 0; i < 3; i++)
    {
        if (distances[i] >= 0.0)
        {
            fprintf(f, "%s, 3 secondes : %d pixels\n", noms[i], (int)(distances[i] + 0.5));
        }
    }
    fclose(f);
}

int nkmain(const NkEntryState& state)
{
    (void)state;

    NkWindowConfig cfg;
    cfg.title = "Les trois hauteurs";
    cfg.width = 800;
    cfg.height = 600;

    NkWindow fenetre;
    if (!fenetre.Create(cfg)) return -1;

    auto& evenements = NkEvents();

    int mode = 0;
    double x = 100.0;
    double accumulateur = 0.0;
    double precedent = maintenant();
    double distances[3] = {-1.0, -1.0, -1.0};
    bool droiteAvant = false;
    double debutMaintien = 0.0;
    double xDebut = 0.0;

    while (fenetre.IsOpen())
    {
        double xDebutTour = x;

        evenements.PollEvents();
        NkEvent* ev = nullptr;
        while ((ev = evenements.PollEvent()) != nullptr)
        {
            if (ev->Is<NkWindowCloseEvent>()) fenetre.Close();

            if (auto* touche = ev->As<NkKeyPressEvent>())
            {
                if (touche->GetKey() == NkKey::NK_ESCAPE) fenetre.Close();
                if (touche->GetKey() == NkKey::NK_SPACE) mode = (mode + 1) % 3;
                if (touche->GetKey() == NkKey::NK_RIGHT && mode == 0) x = x + CRAN;
            }

            if (auto* repetee = ev->As<NkKeyRepeatEvent>())
            {
                if (repetee->GetKey() == NkKey::NK_RIGHT && mode == 0) x = x + CRAN;
            }
        }
        if (!fenetre.IsOpen()) break;

        double maintenantT = maintenant();
        double ecoule = maintenantT - precedent;
        precedent = maintenantT;
        if (ecoule > PLAFOND) ecoule = PLAFOND;
        accumulateur = accumulateur + ecoule;

        while (accumulateur >= PAS)
        {
            if (mode == 1)
            {
                if (NkInput.IsKeyDown(NkKey::NK_RIGHT)) x = x + CRAN;
            }
            else if (mode == 2)
            {
                double axe = 0.0;
                if (NkInput.IsKeyDown(NkKey::NK_RIGHT)) axe = axe + 1.0;
                if (NkInput.IsKeyDown(NkKey::NK_LEFT)) axe = axe - 1.0;
                x = x + axe * CRAN;
            }
            accumulateur = accumulateur - PAS;
        }

        bool droite = NkInput.IsKeyDown(NkKey::NK_RIGHT);
        if (droite && !droiteAvant)
        {
            debutMaintien = maintenantT;
            xDebut = xDebutTour;
        }
        if (droite && distances[mode] < 0.0 && maintenantT - debutMaintien >= 3.0)
        {
            distances[mode] = x - xDebut;
            ecrireMesures(distances);
        }
        droiteAvant = droite;

        dessinerCarre(fenetre, x);
    }

    return 0;
}
