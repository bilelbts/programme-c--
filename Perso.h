#include <iostream>      //inclure la bibliotheque iostream
#include <string>
using namespace std;     //pour éviter de devoir écrire a chaque fois std::
class Perso                                     //déclarer la classe
{   
    protected :                            //création des membres protégés
    string nom_du_perso;               //déclaration des variable  
    int nb_pt_de_vie;
    int vitesse;
    int energie;
    int attaque;
    int defense;
    public :                            //création des membres public
    Perso();                        //déclaration du constructeur par défaut
    Perso(const string&a, int b, int c, int d, int e);                    //déclaration du constructeur
    const string& getNomDuPerso() const;
    int getNbPtVie() const;
    void setNbPtDeVie(int nouveauNbPtDeVie);
    int getVitesse();
    int ajouter_vie(int vie_bonus);
    void equiper(const string& nom_equipement);
    int getattaque(int att);
    void frappe(Perso &a, int energie);             //déclaration de la méthode
    //void monter_vie(int montant_vie);
    void blast(Perso &b, int energie);
    void delta(Perso &c, int energie);
    //void equipement(res->getString("nom"),res->getString("bonus_vie"),res->getString("bonus_attaque"),res->getString("bonus_defense"),res->getString("bonus_vitesse"));
};    


