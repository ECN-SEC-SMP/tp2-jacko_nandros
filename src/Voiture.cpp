#include "Voiture.hpp"

Voiture::Voiture(int vitesseMax, int nbPlaces, int occupants) : Vehicule(vitesseMax, nbPlaces, occupants)
{
}

void Voiture::demarrer()
{
    Vehicule::demarrer();
    cout << "Démarrage d'une voiture" << endl;
}

void Voiture::arreter()
{
    Vehicule::arreter();
    cout << "Arrêt d'une voiture" << endl;
}

Voiture::~Voiture()
{
}