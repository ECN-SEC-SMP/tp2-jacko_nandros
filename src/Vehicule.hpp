//
//  Vehicule.hpp
//  TP_HM_Exc
//
//  Created by Myriam Servières on 28/11/2021.
//

#ifndef Vehicule_hpp
#define Vehicule_hpp

#include <stdexcept>
#include <iostream>

using namespace std;

class Vehicule
{
protected:
    int        vitesse_;
    int        vitesseMax_;
    int        nbPlaces_;
    int        occupants_;
    int        etat_;
    
public:
    enum EtatVehicule {ARRET, MARCHE, PANNE_LEGERE, PANNE_SEVERE};
    
    Vehicule(int vitesseMax=0, int nbPlaces=1, int occupants=0);
    
    virtual void demarrer();
    
    virtual void arreter();
    
    virtual void depanner();
    
    virtual void accelerer(int increment);
    
    virtual void monter(int nbOcc);

    virtual void descendre(int nbOcc);

    virtual void mettreEnPanne(double random);
    
    virtual string getEtat() const;
    
    virtual ~Vehicule();
    friend ostream& operator<<(ostream& s,Vehicule const& v);

};

// opérateur d'affichage
ostream& operator<<(ostream& s,Vehicule const& v);

#endif /* Vehicule_hpp */
