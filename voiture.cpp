#include "voiture.h"

voiture::voiture():m_prix(10), portes(4){}
voiture::~voiture(){}
void voiture::affiche()
{
    cout<<"Ceci est une voiture\n";
}

int voiture::nbrRoues()
{
     cout<<"Ce vehicule a 4 roues\n";
}