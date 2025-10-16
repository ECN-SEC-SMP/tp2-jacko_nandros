#include "Bateau.hpp"


Bateau::Bateau(int vitesseMax, int nbPlaces, int occupants) : Vehicule(vitesseMax, nbPlaces, occupants)
{
}


void Bateau::demarrer()
{
    Vehicule::demarrer();
    cout << "Démarrage d'un bateau" << endl;
}


void Bateau::arreter()
{
    Vehicule::arreter();
    cout << "Arrêt d'un bateau" << endl;
}

Bateau::~Bateau()
{
}