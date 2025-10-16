# Compte Rendu TP-2 
### Jack HASCOET & Annabelle GOTER

L’objectif de ce TP était d'utiliser des classes et d’appliquer les principes d’héritage multiple, tout en créant des exceptions. Ce compte rendu est composé de 4 parties, la classe Vehicule, nos 2 sous classes, la classe VoitureAmphibie et enfin nos jeux de tests. Vous pourez aussi trouver dans nos .hpp de la documentation.

## 1- Classe Vehicule :

Après analyse des exigeances du TP concernant la classe bateau, nous avons réalisé le code suivant.

```C
#include "Vehicule.hpp"

// Création de l'objet véhicule 
Vehicule::Vehicule(int vitesseMax, int nbPlaces, int occupants)
{
    // La vitesse ne depasse pas la limite max
    if (vitesseMax < 0)
    {
        throw invalid_argument("Le véhicule doit avoir une vitesse max positive ");
    }

    // Le vehicule possède au moins une place
    if (nbPlaces <= 0)
    {
        throw invalid_argument("Le véhicule doit avoir au moins une place");
    }

    // occupants doit être positif
    if (occupants < 0)
    {
        throw invalid_argument("Le nombre d'occupant ne peut pas être négatif");
    }

    // nbPlace ne peut pas etre inf à occupants
    if (occupants > nbPlaces)
    {
        throw invalid_argument("Les occupants doivent avoir une place");
    }

    this->vitesseMax_ = vitesseMax;
    this->nbPlaces_ = nbPlaces;
    this->occupants_ = occupants;

    this->etat_ = this->ARRET;
    this->vitesse_ = 0;
}

void Vehicule::demarrer()
{
    // au moins 1 occupant
    if (this->occupants_ <= 0)
    {
        throw runtime_error("Le véhicule doit avoir au moins un occupant.");
    }

    // si panne demarage impossible
    if (this->etat_ != this->ARRET)
    {
        throw runtime_error("Le véhicule est dans un mauvais état: " + this->getEtat());
    }

    // Etat vehicule => Marche
    this->etat_ = this->MARCHE;

    // initialiser la vitesse à 0
    this->vitesse_ = 0;
}

void Vehicule::arreter()
{
    // Quelqu'un dans la voiture
    if (this->occupants_ <= 0)
    {
        throw runtime_error("Le véhicule doit avoir au moins un occupant.");
    }

    // Etat du vehicule autre que en marche
    if (this->etat_ != this->MARCHE)
    {
        throw runtime_error("Le véhicule est dans un mauvais état: " + this->getEtat());
    }

    // Etat vehicule => ARRET
    this->etat_ = this->ARRET;

    // mettre la vitesse à 0
    this->vitesse_ = 0;
}

void Vehicule::depanner()
{

    // Etat du vehicule anormal
    if (this->etat_ == this->MARCHE || this->etat_ == this->ARRET)
    {
        throw runtime_error("Le véhicule doit être en panne or: " + this->getEtat());
    }

    // Etat vehicule => ARRET
    this->etat_ = this->ARRET;
};

void Vehicule::accelerer(int increment)
{
    if (increment <= 0)
    {
        throw invalid_argument("L'incrément d'accelération doit être strictement positive");
    }

    // vérification qu'il y a au moins 1 occupant
    if (this->occupants_ <= 0)
    {
        throw runtime_error("Le véhicule doit avoir au moins un occupant.");
    }

    // Vehicule en etat MARCHE
    if (this->etat_ != this->MARCHE)
    {
        throw runtime_error("Le véhicule est dans un mauvais état: " + this->getEtat());
    }

    // La vitesse ne depasse pas la limite max
    if ((this->vitesse_ + increment) > this->vitesseMax_)
    {
        throw runtime_error("Le véhicule depasse la vitesse max de " + to_string(this->vitesseMax_));
    }

    // Incrementation de la vitesse
    this->vitesse_ += increment;
}

void Vehicule::monter(int nbOcc)
{

    if (nbOcc <= 0)
    {
        throw invalid_argument("Le nombre de personnes qui montent doit être strictement positif");
    }

    // Il n'y a pas de place dispo dans la voiture
    if ((this->occupants_ + nbOcc) > this->nbPlaces_)
    {
        throw runtime_error("Il n'y a plus de place dans le véhicule ");
    }

    if (this->etat_ == this->MARCHE && this->vitesse_ > 0)
    {
        throw runtime_error("Le véhicule est en marche et roule");
    }
    // Le vehicule est en panne
    if (this->etat_ == this->PANNE_LEGERE || this->etat_ == this->PANNE_SEVERE)
    {
        throw runtime_error("Le véhicule est dans un mauvais état: " + this->getEtat());
    }

    this->occupants_ += nbOcc;
}

void Vehicule::descendre(int nbOcc)
{
    if (nbOcc <= 0)
    {
        throw invalid_argument("Le nombre de personnes qui descendent doit être strictement positif");
    }

    // On regarde s'il y a assez de personne dans le vehicule pour faire descendre nb0cc personne
    if ((this->occupants_ - nbOcc) < 0)
    {
        throw runtime_error("Il n'y a pas assé de monde dans le véhicule ");
    }

    // Le vehicule est à l'arret
    if (this->etat_ == this->MARCHE && this->vitesse_ > 0)
    {
        throw runtime_error("Le véhicule est dans un mauvais état: " + this->getEtat());
    }

    this->occupants_ -= nbOcc;
}

void Vehicule::mettreEnPanne(double random)
{

    // Si random n'est pas compris entre 0 et 1
    if (random > 1)
    {
        throw invalid_argument("La valeur du nombre aléatoire depasse 1");
    }
    if (random < 0)
    {
        throw invalid_argument("La valeur du nombre aléatoire est inférieure à 0");
    }

    // Le vehicule est déjà en panne
    if (this->etat_ == this->PANNE_LEGERE || this->etat_ == this->PANNE_SEVERE)
    {
        throw runtime_error("Le véhicule est dans un mauvais état: " + this->getEtat());
    }

    // Si random est inférieur à 0.5 la panne sera légère, sinon elle sera sévère
    if (random < 0.5)
    {
        this->etat_ = this->PANNE_LEGERE;
    }

    if (random >= 0.5)
    {
        this->etat_ = this->PANNE_SEVERE;
    }

    this->vitesse_ = 0;
}

// Permet de recupérer l'état actuel du vehicule
string Vehicule::getEtat() const
{
    string res = "";
    if (this->etat_ == this->MARCHE)
    {
        res = "MARCHE";
    }
    else if (this->etat_ == this->PANNE_LEGERE)
    {
        res = "PANNE_LEGERE";
    }
    else if (this->etat_ == this->PANNE_SEVERE)
    {
        res = "PANNE_SEVERE";
    }
    else if (this->etat_ == this->ARRET)
    {
        res = "ARRET";
    }

    return res;
}

Vehicule::~Vehicule()
{
    // destructeur
}

// Affichage
ostream &operator<<(ostream &s, Vehicule const &v)
{
    s << "Etat: " << v.etat_ << "\n";
    s << "Nombre de place: " << v.nbPlaces_ << "\n";
    s << "Nombre d'occupants: " << v.occupants_ << "\n";
    s << "Vitesse maximale: " << v.vitesseMax_ << "\n";
    s << "Vitesse courrante: " << v.vitesse_ << "\n";
    return s;
}
```

## 2- Sous classes Bateau et Voiture :

C'est sous classes heritent de la classe vehicule, elles ont une structure simple. On retrouve dans notre .hpp l'idication de l'héritage par ce marqueur : 
```
class Bateau : public virtual Vehicule
```


```C
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
````

```C
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
```

## 3- Voiture amphibie :
Classe amphibie qui hérite des classes Bateau et Voiture

```C
class VoitureAmphibie : public Voiture, public Bateau
{
private:
    int vitesseMaxVoiture_;
    int vitesseMaxBateau_;

public:
    VoitureAmphibie(int vmaxVoiture = 0, int vmaxBateau = 0, int nbPlaces = 1, int nbOccupants = 0);

    void demarrer() override;
    void arreter() override;
    void afficherCaracteristiques();
};
```

```C
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
```


## Jeux de tests :

Dans notre fichier main nous avons réalisé un ensemble de jeux de tests, pour s'assurer que notre code était fonctionnel.

```C
int main()
{
    std::cout << "*** DEBUT DES TESTS ***" << std::endl;

    test_vehicule();
    test_voiture();
    test_bateau();
    test_voitureAmphibie();

    std::cout << "*** FIN DES TESTS ***" << std::endl;
    return 0;
}
```