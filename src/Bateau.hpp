#include "Vehicule.hpp"

// Classe voiture qui herite de la classe vehicule 
class Bateau : public Vehicule
{
   
    public:
        Bateau(int vitesseMax = 0, int nbPlaces = 1, int occupants = 0);
        ~Bateau();
        void demarrer() override;
        void arreter() override;
};