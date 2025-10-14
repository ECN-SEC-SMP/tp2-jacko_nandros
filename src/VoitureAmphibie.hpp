#ifndef VOITURE_AMPHIBIE_HPP
#define VOITURE_AMPHIBIE_HPP

#include "Voiture.hpp"
#include "Bateau.hpp"

class VoitureAmphibie : public Voiture, public Bateau
{
private:
    int vitesseMaxVoiture_;
    int vitesseMaxBateau_;

public:
    VoitureAmphibie(int vmaxVoiture = 0, int vmaxBateau = 0, int nbPlaces = 1, int nbOccupants = 0);

    void demarrer() override;
    void arreter() override;
    void afficherCaracteristiques();
};

#endif
