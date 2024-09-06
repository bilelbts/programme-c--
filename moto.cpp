#include "moto.h"

moto::moto():m_vitesse(10){}
moto::~moto(){}
void moto::affiche()
{
    cout<<"Ceci est une moto\n";
}

int moto::nbrRoues()
{
     cout<<"Ce vehicule a 2 roues\n";
}