#include <iostream>
#include <assert.h>

#include "Vehicule.hpp"

void test_vehicule(void);
void test_vehiculeConstructeur(void);
void test_vehiculeDemarrer(void);
void test_vehiculeArreter(void);
void test_vehiculeDepanner(void);
void test_vehiculeAccelerer(void);
void test_vehiculeMonter(void);
void test_vehiculeDescendre(void);
void test_vehiculeMettrePanne(void);
void test_vehiculeGetEtat(void);

int main()
{

    test_vehicule();

    return 0;
}

void test_vehicule(void)
{

    test_vehiculeConstructeur();
    test_vehiculeDemarrer();
    test_vehiculeArreter();
    test_vehiculeDepanner();
    test_vehiculeAccelerer();
    test_vehiculeMonter();
    test_vehiculeDescendre();
    // test_vehiculeMettrePanne();
    test_vehiculeGetEtat();

    std::cout << "Class Vehicule: OK" << std::endl;
}

void test_vehiculeConstructeur(void) {
    
    // Constructeur avec les valeurs par défauts
    Vehicule v1 = Vehicule();
    // Constructeur avec des valeurs qui fonctionent
    Vehicule v2 = Vehicule(1, 2, 2);

        

}

void test_vehiculeMettrePanne(void)
{

    Vehicule v1 = Vehicule();
    Vehicule v2 = Vehicule();

    // Test avec une valeur inférieur à 0
    try
    {
        v1.mettreEnPanne(-0.1);
    }
    catch (std::invalid_argument const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }
    assert(v1.getEtat() == "ARRET");

    // Test avec une valeur supérieur à 1
    try
    {
        v1.mettreEnPanne(1.1);
    }
    catch (std::invalid_argument const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }
    assert(v1.getEtat() == "ARRET");

    v1.mettreEnPanne(0.2);
    assert(v1.getEtat() == "PANNE_LEGERE");

    v2.mettreEnPanne(0.6);
    assert(v2.getEtat() == "PANNE_SEVERE");

    // Test sur des véhicules déjà en panne
    try
    {
        v1.mettreEnPanne(0.6);
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }
    assert(v1.getEtat() == "PANNE_LEGERE");

    try
    {
        v2.mettreEnPanne(0.4);
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }
    assert(v2.getEtat() == "PANNE_SEVERE");
}