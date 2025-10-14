#include <iostream>
#include <assert.h>

#include "Vehicule.hpp"

void test_vehicule(void);
void test_vehiculeMettrePanne(void);

int main()
{

    test_vehicule();

    return 0;
}

void test_vehicule(void)
{

    test_vehiculeMettrePanne();

    std::cout << "Class Vehicule: OK" << std::endl;
}

void test_vehiculeMettreEnPanne(void)
{
    Vehicule v1 = Vehicule();

    // Ensure we do not go below double 0.0
    try
    {
        v1.mettreEnPanne(-0.1);
    }
    catch (std::invalid_argument const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }
    assert(v1.getEtat() == "ARRET");

    // Ensure we do not exceed double 1.0
    try
    {
        v1.mettreEnPanne(1.1);
    }
    catch (std::invalid_argument const &ex)
    {
        std::cout << "Catched error: " << ex.what() << std::endl;
    }
    assert(v1.getEtat() == "ARRET");


}