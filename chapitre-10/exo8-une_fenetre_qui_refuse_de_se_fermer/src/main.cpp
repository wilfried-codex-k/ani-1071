#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include <NKLogger/NkLog.h>

using namespace nkentseu;

int nkmain(const NkEntryState& state)
{
    (void)state;
    NkLog::Initialize("Ani1071");

    NkWindowConfig cfg;
    cfg.title = "Chapitre 10";
    cfg.width = 800;
    cfg.height = 600;

    NkWindow fenetre;
    if (!fenetre.Create(cfg))
    {
        logger.Error("Impossible de creer la fenetre");
        NkLog::Shutdown();
        return -1;
    }
    logger.Info("Fenetre creee : {0} x {1}", cfg.width, cfg.height);

    auto& evenements = NkEvents();
    int demandes = 0;

    while (fenetre.IsOpen())
    {
        evenements.PollEvents();

        NkEvent* ev = nullptr;
        while ((ev = evenements.PollEvent()) != nullptr)
        {
            if (ev->Is<NkWindowCloseEvent>())
            {
                demandes++;
                if (demandes == 1)
                {
                    logger.Info("fermeture refusee");
                }
                else
                {
                    logger.Info("fermeture acceptee, demande numero {0}", demandes);
                    fenetre.Close();
                }
            }
            else if (auto* touche = ev->As<NkKeyPressEvent>())
            {
                logger.Info("touche pressee : code {0}", static_cast<int>(touche->GetKey()));
            }
            else if (ev->Is<NkKeyRepeatEvent>())
            {
                logger.Info("touche repetee par le clavier");
            }
            else if (ev->Is<NkTextInputEvent>())
            {
                logger.Info("caractere saisi");
            }
            else
            {
                logger.Debug("autre evenement");
            }
        }
    }

    logger.Info("Fenetre fermee apres {0} demande(s)", demandes);
    NkLog::Shutdown();
    return 0;
}
