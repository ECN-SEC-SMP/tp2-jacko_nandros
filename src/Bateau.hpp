#ifndef BATEAU_HPP
#define BATEAU_HPP

#include "Vehicule.hpp"

// Classe voiture qui herite de la classe vehicule 
class Bateau : public virtual Vehicule
{
   
    public:
        Bateau(int vitesseMax = 0, int nbPlaces = 1, int occupants = 0);
        ~Bateau();
        void demarrer() override;
        void arreter() override;
};

#endif