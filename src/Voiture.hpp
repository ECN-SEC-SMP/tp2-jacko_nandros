#include "Vehicule.hpp"

// Classe voiture qui herite de la classe vehicule 
class Voiture : public Vehicule
{
   
    public:
        Voiture(int vitesseMax = 0, int nbPlaces = 1, int occupants = 0);
        ~Voiture();
        void demarrer() override;
        void arreter() override;
};