#include "Perso.h"    //on inclus le fichier de la classe
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h> 

Perso::Perso():nom_du_perso ("Luigi"), nb_pt_de_vie (100), vitesse (10), attaque(60), defense(10){};             //on définit le constructeur par défaut

Perso::Perso(const string& a, int b, int c, int d, int e)        //on définit le constructeur surchargé
{
    nom_du_perso = a;               //Affectation des attributs
    nb_pt_de_vie = b; 
    vitesse = c;    
    attaque = d;
    defense = e;
}

const string& Perso::getNomDuPerso() const {
        return nom_du_perso;
    }
int Perso::getNbPtVie() const {
        return nb_pt_de_vie;
    }
void Perso::setNbPtDeVie(int nouveauNbPtDeVie) {
        nb_pt_de_vie = nouveauNbPtDeVie;
    }    
int Perso::getVitesse(){
    return vitesse;
}    

//int Perso::ajouter_vie(int vie_bonus){
  // vie_bonus = res->getString("bonus_vie")
   //nb_pt_de_vie += vie_bonus;
   //return vie_bonus;
//}

int Perso::getattaque(int att)
{

    return attaque;
}

void Perso::equiper(const string& nom_equipement)
{
    sql::Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::ResultSet* res;
    driver = get_driver_instance();
    con = driver->connect("localhost", "student", "crif2024sn");
    con->setSchema("equipement");
    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT * FROM equipement where nom='" + nom_equipement + "'");
    while (res->next()) {
    string equipementbdd = res->getString("nom");
    int bonus_vie = res->getInt("bonus_vie");
    nb_pt_de_vie += bonus_vie;
    int bonus_attaque = res->getInt("bonus_attaque");
    attaque += bonus_attaque;
    int bonus_defense =  res->getInt("bonus_defense");
    defense += bonus_defense;
    int bonus_vitesse =  res->getInt("bonus_vitesse");
    vitesse += bonus_vitesse;    
    cout<< nom_du_perso<<" s'équipe de "<<equipementbdd<<"\n";
    if (bonus_vie>0){cout<< "Bonus vie = " <<bonus_vie<<"\n";}    
    if (bonus_attaque>0){cout<< "Bonus attaque = " <<bonus_attaque<<"\n";}
    if (bonus_defense>0){cout<< "Bonus defense =" <<bonus_defense<<"\n";}
    if (bonus_vitesse>0){cout<< "Bonus vitesse =" <<bonus_vitesse<<"\n";}    
    }
    
    delete res;
    delete stmt;
    delete con;
}

void Perso::frappe(Perso &a, int energie)   //on définit la méthode coup de poing avec un objet reference en parametre
{
    int pv_perso = a.getNbPtVie();
    cout<<"Frappe preventive\n";
    if (nb_pt_de_vie>0)
    {
    cout<<nom_du_perso<<" a "<<nb_pt_de_vie<<" points de vie\n";
    }
    else if (nb_pt_de_vie<0)
    {
    cout<<nom_du_perso<<" est mort \n";        
    }
    cout<<nom_du_perso<<" a "<<energie<<" energie\n";
    cout<<a.getNomDuPerso()<<" a "<<pv_perso<<" points de vie\n";
    cout<<a.getNomDuPerso()<<" a recu un degat de "<<attaque<<"\n";    //on affiche les dégats recu par le perso
    pv_perso = pv_perso - attaque;    //on enlève la valeur des degats aux point de vie
    cout<<a.getNomDuPerso()<<" a une defense de "<<defense<<"\n";
    nb_pt_de_vie += defense;
    a.setNbPtDeVie(pv_perso);
    if (pv_perso>0)
    {
    cout<<a.getNomDuPerso()<<" a "<<pv_perso<<" points de vie\n";
    }
    else if (pv_perso<0)
    {
    cout<<a.getNomDuPerso()<<" est mort \n";        
    }
    if (nb_pt_de_vie>0)
    {
    cout<<nom_du_perso<<" a "<<nb_pt_de_vie<<" points de vie\n";
    }
    else if (nb_pt_de_vie<0)
    {
    cout<<nom_du_perso<<" est mort \n";        
    }
    energie += 10;
    cout<<nom_du_perso<<" a "<<energie<<" energie\n";
}

void Perso::blast(Perso &b, int energie)
{
    int pv_perso = b.getNbPtVie();
    cout<<"\nBlast\n";
    if (nb_pt_de_vie>0)
    {
    cout<<nom_du_perso<<" a "<<nb_pt_de_vie<<" points de vie\n";
    }
    else if (nb_pt_de_vie<0)
    {
    cout<<nom_du_perso<<" est mort \n";        
    }
    cout<<nom_du_perso<<" a "<<energie<<" energie\n";
    if (pv_perso>0)
    {
    cout<<b.getNomDuPerso()<<" a "<<pv_perso<<" points de vie\n";
    }
    else if (pv_perso<0)
    {
    cout<<b.getNomDuPerso()<<" est mort \n";        
    }
    cout<<b.getNomDuPerso()<<" a recu un degat de "<<attaque<<"\n";
    attaque = attaque * 1.5;
    cout<<b.nom_du_perso<<" a recu un degat de "<<attaque<<"\n";    //on affiche les dégats recu par le perso
    pv_perso = pv_perso - attaque;    //on enlève la valeur des degats aux point de vie
    cout<<b.getNomDuPerso()<<" a une defense de "<<defense<<"\n";
    nb_pt_de_vie = nb_pt_de_vie + defense;
    b.setNbPtDeVie(pv_perso);
    if (pv_perso>0)
    {
    cout<<b.getNomDuPerso()<<" a "<<pv_perso<<" points de vie\n";
    }
    else if (pv_perso<0)
    {
    cout<<b.getNomDuPerso()<<" est mort \n";        
    }
    if (nb_pt_de_vie>0)
    {
    cout<<nom_du_perso<<" a "<<nb_pt_de_vie<<" points de vie\n";
    }
    else if (nb_pt_de_vie<0)
    {
    cout<<nom_du_perso<<" est mort \n";        
    }
    cout<<nom_du_perso<<" a "<<energie<<" energie\n";

}

void Perso::delta(Perso &c, int energie)
{
    int pv_perso = c.getNbPtVie();
    cout<<"\nAttaque Delta\n"<<nom_du_perso<<" a "<<energie<<" energie\n";
    if (energie>=100)
    {
    if (nb_pt_de_vie>0)
    {
    cout<<nom_du_perso<<" a "<<nb_pt_de_vie<<" points de vie\n";
    }
    else if (nb_pt_de_vie<0)
    {
    cout<<nom_du_perso<<" est mort \n";        
    }
    if (pv_perso>0)
    {
    cout<<c.getNomDuPerso()<<" a "<<pv_perso<<" points de vie\n";
    }
    else if (pv_perso<0)
    {
    cout<<c.getNomDuPerso()<<" est mort \n";
    }
    cout<<c.getNomDuPerso()<<" a recu un degat de "<<attaque<<"\n";    //on affiche les dégats recu par le perso
    pv_perso = pv_perso - attaque;    //on enlève la valeur des degats aux point de vie
    cout<<c.getNomDuPerso()<<" a une defense de "<<defense<<"\n";
    nb_pt_de_vie = nb_pt_de_vie + defense;
    c.setNbPtDeVie(pv_perso);
    if (pv_perso>0)
    {
    cout<<c.getNomDuPerso()<<" a "<<pv_perso<<" points de vie\n";
    }
    else if (pv_perso<0)
    {
    cout<<c.getNomDuPerso()<<" est mort \n";        
    }
    if (nb_pt_de_vie>0)
    {
    cout<<nom_du_perso<<" a "<<nb_pt_de_vie<<" points de vie\n";
    }
    else if (nb_pt_de_vie<0)
    {
    cout<<nom_du_perso<<" est mort \n";        
    }
    energie -= 100;
    cout<<nom_du_perso<<" a "<<energie<<" energie\n";
    }
    else if (energie<100)
    {
        cout<<"L'energie n'est pas suffisante\n";
    }

    //void Perso::equipement(res->getString("nom"),res->getString("bonus_vie"),res->getString("bonus_attaque"),res->getString("bonus_defense"),res->getString("bonus_vitesse"));    
    {

    }
}

