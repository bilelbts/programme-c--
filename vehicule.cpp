#include "vehicule.h"

vehicule::vehicule():m_prix(10){}
vehicule::~vehicule(){}
vehicule::vehicule(int prix, int portes){}

void vehicule::affiche()
{
    cout<<"Ceci est un vehicule\n";
}

int vehicule::nbrRoues()
{
    cout<<"Ce vehicule a 4 roues\n";
}