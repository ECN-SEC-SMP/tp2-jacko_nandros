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
    int vitesse_;
    int vitesseMax_;
    int nbPlaces_;
    int occupants_;
    int etat_;

public:
    enum EtatVehicule
    {
        ARRET,
        MARCHE,
        PANNE_LEGERE,
        PANNE_SEVERE
    };

     /**
     * @brief Construct a new Vehicule :: Vehicule object
     *
     * @param vitesseMax Vitesse maximale du Vehicule
     * @param nbPlaces Nombre de place dans le Vehicule
     * @param occupants Nombre d'occupants dans le Vehicule
     */
    Vehicule(int vitesseMax = 0, int nbPlaces = 1, int occupants = 0);

    /**
     * @brief Start the Vehicule object
     *
     */
    virtual void demarrer();

    /**
     * @brief Stop the Vehicule object
     *
     */
    virtual void arreter();

    /**
     * @brief Dépanne le Vehicule object
     *
     */
    virtual void depanner();

    /**
     * @brief Fait accélerer le Vehicule object
     *
     */
    virtual void accelerer(int increment);

    /**
     * @brief Fais monter le Vehicule object
     *
     */
    virtual void monter(int nbOcc);

    /**
     * @brief Fais descendre le Vehicule object
     *
     */
    virtual void descendre(int nbOcc);

    /**
     * @brief Met en panne le Vehicule object
     *
     */
    virtual void mettreEnPanne(double random);

    /**
     * @brief Renvoi l'état du Vehicule object
     *
     */
    virtual string getEtat() const;

    /**
     * @brief Destroy the Vehicule object
     *
     */
    virtual ~Vehicule();

    /**
     * @brief opérateur d'affichage
     *
     */
    friend ostream &operator<<(ostream &s, Vehicule const &v);
};

// opérateur d'affichage
ostream &operator<<(ostream &s, Vehicule const &v);

#endif /* Vehicule_hpp */
