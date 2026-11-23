#include <cstdio>
#include <chrono>
#include <thread>
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

using namespace nkentseu;

const double PAS = 1.0 / 120.0;
const double PLAFOND = 0.25;
const bool PLAFOND_ACTIF = true;
const bool RANGER_INTERPOLEE = false;
const double GRAVITE = 500.0;
const double SOL = 500.0;
const double REBOND = 0.8;

struct Balle
{
    double y;
    double v;
};

double maintenant()
{
    return std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count();
}

double lerp(double a, double b, double t)
{
    return a + (b - a) * t;
}

void mettreAJour(Balle& b, double dt)
{
    b.v = b.v + GRAVITE * dt;
    b.y = b.y + b.v * dt;
    if (b.y > SOL)
    {
        b.y = SOL;
        b.v = -b.v * REBOND;
    }
}

void dessinerBalle(NkWindow& fenetre, double y)
{
    (void)fenetre;
    (void)y;
    // A COMPLETER : dessiner la balle en (400, y) avec l'appel de dessin du moteur
}

int nkmain(const NkEntryState& state)
{
    (void)state;

    NkWindowConfig cfg;
    cfg.title = "Le pas fixe";
    cfg.width = 800;
    cfg.height = 600;

    NkWindow fenetre;
    if (!fenetre.Create(cfg)) return -1;

    auto& evenements = NkEvents();

    Balle actuelle = {50.0, 0.0};
    Balle precedente = actuelle;
    double accumulateur = 0.0;
    double precedent = maintenant();
    int tour = 0;

    int alphaMilli[10];
    int pasFaits[10];

    while (fenetre.IsOpen())
    {
        tour++;

        evenements.PollEvents();
        NkEvent* ev = nullptr;
        while ((ev = evenements.PollEvent()) != nullptr)
        {
            if (ev->Is<NkWindowCloseEvent>()) fenetre.Close();
            if (auto* touche = ev->As<NkKeyPressEvent>())
            {
                if (touche->GetKey() == NkKey::NK_ESCAPE) fenetre.Close();
            }
        }
        if (!fenetre.IsOpen()) break;

        if (tour == 10) std::this_thread::sleep_for(std::chrono::seconds(1));

        double maintenantT = maintenant();
        double ecoule = maintenantT - precedent;
        precedent = maintenantT;
        if (PLAFOND_ACTIF && ecoule > PLAFOND) ecoule = PLAFOND;
        accumulateur = accumulateur + ecoule;

        int faits = 0;
        while (accumulateur >= PAS)
        {
            precedente = actuelle;
            mettreAJour(actuelle, PAS);
            accumulateur = accumulateur - PAS;
            faits++;
        }

        double alpha = accumulateur / PAS;
        double affichee = lerp(precedente.y, actuelle.y, alpha);
        if (RANGER_INTERPOLEE) actuelle.y = affichee;

        if (tour <= 10)
        {
            alphaMilli[tour - 1] = (int)(alpha * 1000.0);
            pasFaits[tour - 1] = faits;
            if (tour == 10)
            {
                FILE* f = fopen("mesures.txt", "w");
                if (f != nullptr)
                {
                    for (int i = 0; i < 10; i++)
                    {
                        fprintf(f, "image %d, alpha en milliemes : %d, pas faits : %d\n", i + 1, alphaMilli[i], pasFaits[i]);
                    }
                    fclose(f);
                }
            }
        }

        dessinerBalle(fenetre, affichee);
        std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }

    return 0;
}
