#include "VoitureAmphibie.hpp"
#include <iostream>

VoitureAmphibie::VoitureAmphibie(int vmaxVoiture, int vmaxBateau, int nbPlaces, int nbOccupants)
    : Vehicule(0, nbPlaces, nbOccupants),
      Voiture(vmaxVoiture, nbPlaces, nbOccupants),
      Bateau(vmaxBateau, nbPlaces, nbOccupants)
{
    this->vitesseMaxVoiture_ = vmaxVoiture;
    this->vitesseMaxBateau_ = vmaxBateau;
    this->vitesse_ = 0;
    this->etat_ = ARRET;
}

void VoitureAmphibie::demarrer()
{
    cout << "Démarrage d'une voiture amphibie" << endl;
    Vehicule::demarrer();
}

void VoitureAmphibie::arreter()
{
    cout << "Arrêt d'une voiture amphibie" << endl;
    Vehicule::arreter();
}

void VoitureAmphibie::afficherCaracteristiques()
{
    cout << "Mode voiture: " << vitesseMaxVoiture_ << " km/h" << endl;
    cout << "Mode bateau: " << vitesseMaxBateau_ << " noeuds" << endl;
    cout << "Places: " << nbPlaces_ << endl;
    cout << "Occupants: " << occupants_ << endl;
}
