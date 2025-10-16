#ifndef BATEAU_HPP
#define BATEAU_HPP

#include "Vehicule.hpp"

// Classe Bateau qui herite de la classe vehicule
class Bateau : public virtual Vehicule
{

public:
    /**
     * @brief Construct a new Bateau:: Bateau object
     *
     * @param vitesseMax Vitesse maximale du bateau
     * @param nbPlaces Nombre de place dans le bateau
     * @param occupants Nombre d'occupants dans le bateau
     */
    Bateau(int vitesseMax = 0, int nbPlaces = 1, int occupants = 0);

    /**
     * @brief Destroy the Bateau object
     *
     */
    ~Bateau();

    /**
     * @brief Démarre le bateau
     *
     */
    void demarrer() override;
    
    /**
     * @brief Arrete le bateau
     *
     */
    void arreter() override;
};

#endif