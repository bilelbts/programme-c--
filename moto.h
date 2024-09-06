#include "vehicule.h"
#include <iostream>      //inclure la bibliotheque iostream
#include <string>
using namespace std;     //pour éviter de devoir écrire a chaque fois std::
class moto : public vehicule                                     //déclarer la classe
{   
    protected :                            //création des membres protégés            
    int prix;
    double m_vitesse;                           //déclaration des variable  
    public :                            //création des membres public
    moto();                        //déclaration du constructeur par défaut
    ~moto();  
    virtual void affiche();
    virtual int nbrRoues();
};    

