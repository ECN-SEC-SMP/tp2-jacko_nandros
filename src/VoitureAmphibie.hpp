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
    /**
     * @brief Construct a new VoitureAmphibie :: VoitureAmphibie object
     *
     * @param vitesseMax Vitesse maximale de la voiture
     * @param vitesseMaxBateau Vitesse maximale du bateau
     * @param nbPlaces Nombre de place dans la voiture
     * @param occupants Nombre d'occupants dans la voiture
     */
    VoitureAmphibie(int vmaxVoiture = 0, int vmaxBateau = 0, int nbPlaces = 1, int nbOccupants = 0);

    /**
     * @brief Destroy the Amphibious Vehicle object
     *
     */
    ~VoitureAmphibie();

    /**
     * @brief Démarre la VoitureAmphibie
     *
     */
    void demarrer() override;

    /**
     * @brief Arrête la VoitureAmphibie
     *
     */
    void arreter() override;

    /**
     * @brief Affiche les caractéristiques de la VoitureAmphibie
     *
     */
    void afficherCaracteristiques();
};

#endif
