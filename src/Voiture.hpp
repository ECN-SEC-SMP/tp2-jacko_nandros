#ifndef VOITURE_HPP
#define VOITURE_HPP

#include "Vehicule.hpp"

// Classe voiture qui herite de la classe vehicule
class Voiture : public virtual Vehicule
{

public:
    /**
     * @brief Construct a new Car :: Car object
     *
     * @param vitesseMax Vitesse maximale de la voiture
     * @param nbPlaces Nombre de place dans la voiture
     * @param occupants Nombre d'occupants dans la voiture
     */

    Voiture(int vitesseMax = 0, int nbPlaces = 1, int occupants = 0);

    /**
     * @brief Destroy the Car object
     *
     */
    ~Voiture();

    /**
     * @brief Start the Car object
     *
     */
    void demarrer() override;

    /**
     * @brief Stop the Car object
     *
     */
    void arreter() override;
};

#endif
