#include "moto.h"
#include <iostream>      //inclure la bibliotheque iostream
#include <string>
using namespace std;     //pour éviter de devoir écrire a chaque fois std::
class voiture : public vehicule                                   //déclarer la classe
{   
    protected :                            //création des membres protégés            
    int m_prix;                           //déclaration des variable  
    int portes;
    public :                            //création des membres public
    voiture();                        //déclaration du constructeur par défaut
    ~voiture();  
    virtual void affiche();
    virtual int nbrRoues() ;    
};    

