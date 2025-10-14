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
    test_vehiculeMettrePanne();
    test_vehiculeGetEtat();

    std::cout << "Class Vehicule: OK" << std::endl;
}

void test_vehiculeConstructeur(void)
{

    // Constructeur avec les valeurs par défauts
    Vehicule v1 = Vehicule();
    // Constructeur avec des valeurs qui fonctionent
    Vehicule v2 = Vehicule(1, 2, 2);

    // Test avec vitesseMax négatif
    try
    {
        Vehicule v3 = Vehicule(-1, 1, 1);
    }
    catch (std::invalid_argument const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }

    // Test avec nbPlaces négatif
    try
    {
        Vehicule v3 = Vehicule(1, -1, 1);
    }
    catch (std::invalid_argument const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }

    // Test avec nbOccupants négatif
    try
    {
        Vehicule v3 = Vehicule(1, 1, -1);
    }
    catch (std::invalid_argument const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }

    // Test avec nbOccupants > nbPlaces négatif
    try
    {
        Vehicule v3 = Vehicule(1, 2, 3);
    }
    catch (std::invalid_argument const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }
}

void test_vehiculeDemarrer(void)
{
    // Test cas fonctionnel
    Vehicule v1 = Vehicule(0, 1, 1);
    v1.demarrer();
    assert(v1.getEtat() == "MARCHE");

    // Test demarrage sans occupant
    Vehicule v2 = Vehicule(0, 1, 0);
    try
    {
        v2.demarrer();
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }
    assert(v2.getEtat() == "ARRET");

    // Test demarrage avec voiture en panne légère
    Vehicule v3 = Vehicule(0, 1, 1);
    v3.mettreEnPanne(0.4);
    try
    {
        v3.demarrer();
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }
    assert(v3.getEtat() == "PANNE_LEGERE");

    // Test demarrage avec voiture en panne sévère
    Vehicule v4 = Vehicule(0, 1, 1);
    v4.mettreEnPanne(0.6);
    try
    {
        v4.demarrer();
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }
    assert(v4.getEtat() == "PANNE_SEVERE");

    // Test demarrage avec voiture démarrer
    Vehicule v5 = Vehicule(0, 1, 1);
    v5.demarrer();
    try
    {
        v5.demarrer();
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }
    assert(v5.getEtat() == "MARCHE");
}

void test_vehiculeArreter(void)
{
    // Test d'arrêt un véhicule déjà arrêter
    Vehicule v1 = Vehicule(0, 1, 1);
    try
    {
        v1.arreter();
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }
    assert(v1.getEtat() == "ARRET");

    Vehicule v2 = Vehicule(0, 1, 1);
    v2.demarrer();
    assert(v2.getEtat() == "MARCHE");

    v2.arreter();
    assert(v2.getEtat() == "ARRET");
}

void test_vehiculeDepanner(void)
{
    // Test de dépannage d'un véhicule en marche
    Vehicule v1 = Vehicule(0, 1, 1);
    v1.demarrer();

    try
    {
        v1.depanner();
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }
    assert(v1.getEtat() == "MARCHE");

    // Test de dépannage d'un véhicule à l'arrêt
    Vehicule v2 = Vehicule(0, 1, 1);
    try
    {
        v2.depanner();
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }
    assert(v2.getEtat() == "ARRET");

    Vehicule v3 = Vehicule(0, 1, 1);
    v3.mettreEnPanne(0.3);
    v3.depanner();
    assert(v3.getEtat() == "ARRET");

    Vehicule v4 = Vehicule(0, 1, 1);
    v4.mettreEnPanne(0.6);
    v4.depanner();
    assert(v4.getEtat() == "ARRET");
}

void test_vehiculeAccelerer(void)
{
    // Test cas normal
    Vehicule v1 = Vehicule(10, 1, 1);
    v1.demarrer();
    v1.accelerer(1);
    v1.accelerer(2);

    // Test d'atteinte de la limite
    Vehicule v2 = Vehicule(4, 1, 1);
    v2.demarrer();
    v2.accelerer(4);

    // Test de dépassement
    Vehicule v3 = Vehicule(3, 1, 1);
    v3.demarrer();

    try
    {
        v3.accelerer(4);
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }

    // Test d'une valeur négative
    Vehicule v4 = Vehicule(3, 1, 1);
    v4.demarrer();

    try
    {
        v4.accelerer(-1);
    }
    catch (std::invalid_argument const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }

    // Test sur un véhicule à l'arrêt
    Vehicule v5 = Vehicule(3, 1, 1);

    try
    {
        v3.accelerer(1);
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }

    // Test sur un véhicule en panne légère
    Vehicule v6 = Vehicule(3, 1, 1);
    v6.mettreEnPanne(0.3);
    try
    {
        v6.accelerer(1);
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }

    // Test sur un véhicule en panne sévère
    Vehicule v7 = Vehicule(3, 1, 1);
    v7.mettreEnPanne(0.6);

    try
    {
        v7.accelerer(1);
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }
}

void test_vehiculeMonter(void)
{
    // Test normal et atteinte de limite
    Vehicule v1 = Vehicule(0, 2, 0);
    v1.monter(1);

    Vehicule v2 = Vehicule(0, 2, 0);
    v2.monter(2);

    Vehicule v10 = Vehicule(0, 2, 1);
    v10.demarrer();
    v10.monter(1);

    // Test d'une valeur négative
    Vehicule v3 = Vehicule(0, 2, 0);

    try
    {
        v3.monter(-1);
    }
    catch (std::invalid_argument const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }

    // Test de dépassement de la limite
    Vehicule v4 = Vehicule(0, 3, 1);

    try
    {
        v4.monter(3);
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }

    // Test de monter lors d'en marche et roule
    Vehicule v5 = Vehicule(0, 3, 1);
    v5.demarrer();
    try
    {
        v5.monter(1);
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }

    // Test de monter lors d'une panne légère
    Vehicule v6 = Vehicule(0, 3, 1);
    v6.mettreEnPanne(0.3);
    try
    {
        v6.monter(1);
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }

    // Test de monter lors d'une panne sévère
    Vehicule v7 = Vehicule(0, 3, 1);
    v7.mettreEnPanne(0.7);
    try
    {
        v7.monter(1);
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }
}

void test_vehiculeDescendre(void)
{

    // Descente d'une personne
    Vehicule v1 = Vehicule(1, 3, 2);
    v1.descendre(1);

    // Descente de tout le monde
    Vehicule v2 = Vehicule(1, 3, 3);
    v2.descendre(3);

    // Descente lors d'un véhicule en marche mais à l'arrêt (vitesse = 0)
    Vehicule v3 = Vehicule(1, 2, 2);
    v3.demarrer();
    v3.descendre(1);

    // Descente lors d'un véhicule en marche mais qui roule
    Vehicule v4 = Vehicule(1, 2, 2);
    v4.demarrer();
    v4.accelerer(1);

    try
    {
        v4.descendre(1);
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }

    // Descente de plus de personne que d'occupant
    Vehicule v5 = Vehicule(1, 2, 2);
    try
    {
        v5.descendre(3);
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }

    // Descente d'un nombre négatif d'occupants
    Vehicule v6 = Vehicule(1, 2, 2);
    try
    {
        v6.descendre(-1);
    }
    catch (std::invalid_argument const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }
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

void test_vehiculeGetEtat(void)
{
    Vehicule v1 = Vehicule();
    assert(v1.getEtat() == "ARRET");

    Vehicule v2 = Vehicule(0, 1, 1);
    v2.demarrer();
    assert(v2.getEtat() == "MARCHE");

    Vehicule v3 = Vehicule();
    v3.mettreEnPanne(0.3);
    assert(v3.getEtat() == "PANNE_LEGERE");

    Vehicule v4 = Vehicule();
    v4.mettreEnPanne(0.6);
    assert(v4.getEtat() == "PANNE_SEVERE");
}