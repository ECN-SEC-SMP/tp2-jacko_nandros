#include "Vehicule.hpp"

Vehicule::Vehicule(int vitesseMax, int nbPlaces, int occupants){
    // La vitesse ne depasse pas la limite max
    if (vitesseMax < 0){
        throw new invalid_argument("Le véhicule doit avoir une vitesse max positive ");
    }

    // Le vehicule possède au moins une place
    if (nbPlaces <= 0){
        throw new invalid_argument("Le véhicule doit avoir au moins une place");
    }

    // occupants doit être positif
    if (occupants < 0){
        throw new invalid_argument("Le nombre d'occupant ne peut pas être négatif");
    }

    // nbPlace ne peut pas etre inf à occupants
    if (occupants > nbPlaces){
        throw new invalid_argument("Les occupants doivent avoir une place");
    }

    this->vitesseMax_ = vitesseMax;
    this->nbPlaces_ = nbPlaces;
    this -> occupants_ = occupants;

    this->etat_ = this->ARRET;
    this->vitesse_ = 0;
}

void Vehicule::demarrer() 
{
    // au moins 1 occupant
    if (this->occupants_ <= 0 ) {
        throw new invalid_argument("Le véhicule doit avoir au moins un occupant.");
    }

    // si panne demarage impossible 
    if(this->etat_ != this->ARRET) 
    {
        throw new invalid_argument("Le véhicule est dans un mauvais état: " + this->getEtat());        
    }
    
    // Etat vehicule => Marche     
    this->etat_ = this->MARCHE;

    // initialiser la vitesse à 0
    this->vitesse_ = 0;
    
}


void Vehicule::arreter(){

    // Quelqu'un dans la caisse
    if (this->occupants_ <= 0 ) {
        throw new invalid_argument("Le véhicule doit avoir au moins un occupant.");
    }

    // Etat du vehicule autre que en marche
    if(this->etat_ != this->MARCHE) 
    {
        throw new invalid_argument("Le véhicule est dans un mauvais état: " + this->getEtat());        
    }

    // Etat vehicule => ARRET     
    this->etat_ = this->ARRET;

    // mettre la vitesse à 0 
    this->vitesse_ = 0;
}


void Vehicule::depanner(){

    // Etat du vehicule anormal
    if(this->etat_ == this->MARCHE || this->etat_ == this->ARRET) 
    {
        throw new invalid_argument("Le véhiculedoit être en panne or: " + this->getEtat());        
    }

    // Etat vehicule => ARRET     
    this->etat_ = this->ARRET;

};

void Vehicule::accelerer(int increment){

    // au moins 1 occupant
    if (this->occupants_ <= 0 ) {
        throw new invalid_argument("Le véhicule doit avoir au moins un occupant.");
    }

    // Vehicule en etat MARCHE 
    if(this->etat_ != this->MARCHE) 
    {
        throw new invalid_argument("Le véhicule est dans un mauvais état: " + this->getEtat());        
    }

    // La vitesse ne depasse pas la limite max
    if ((this->vitesse_ +  increment) > this->vitesseMax_){
        throw new invalid_argument("Le véhicule depasse la vitesse max de " + this->vitesseMax_);
    }

    // Incrementation de la vitesse
    this->vitesse_ += increment;
}

void Vehicule::monter(int nbOcc)
{
    //Il n'y a pas de place dispo dans la voiture 
    if ((this->occupants_ +  nbOcc) > this->nbPlaces_){
        throw new invalid_argument("Il n'y a plus de place dans le véhicule ");
    }

    // Le vehicule est à l'arret
    if (this->etat_ != this->ARRET){
         throw new invalid_argument("Le véhicule est dans un mauvais état: " + this->getEtat());  
    }

    this->occupants_ += nbOcc;
}

void Vehicule::descendre(int nbOcc)
{
    //Il y a trop d'occupant dans la voiture 
    if ((this->occupants_ - nbOcc) < this->nbPlaces_){
        throw new invalid_argument("Il n'y a trop de monde dans le véhicule ");
    }

    // Le vehicule est à l'arret
    if (this->etat_ == this->MARCHE){
         throw new invalid_argument("Le véhicule est dans un mauvais état: " + this->getEtat());  
    }

    this->occupants_ -= nbOcc;
}

void Vehicule::mettreEnPanne(double random){

    //Le vehicule est déjà en panne
    if(this->etat_ == this->PANNE_LEGERE || this->etat_ == this->PANNE_SEVERE) {
        throw new invalid_argument("Le véhicule est dans un mauvais état: " + this->getEtat());  
    }

    // Si random n'est pas compris entre 0 et 1
    if (random > 1) {
        throw new invalid_argument(" la valeure de random depasse 1");
    }
    if (random < 0) {
        throw new invalid_argument(" la valeure de random est inférieure à 0");
    }


    // Si random est inférieur à 0.5 la panne sera légère, sinon elle sera sévère
    if(random < 0,5) { 
        this->etat_ = this->PANNE_LEGERE;
    }
    
    if (random >= 0,5)
    {
        this->etat_ = this->PANNE_SEVERE;   
    }

    this->vitesse_ = 0;

}

string Vehicule::getEtat() const {
    string res = "";
    if(this->etat_ == this->MARCHE) { res = "MARCHE";}
    else if(this->etat_ == this->PANNE_LEGERE) { res = "PANNE_LEGERE";}
    else if(this->etat_ == this->PANNE_SEVERE) { res = "PANNE_SEVERE";}
    else if(this->etat_ == this->ARRET) { res = "ARRET";}
    
    return res;
}

Vehicule::~Vehicule(){
    // destructeur
}