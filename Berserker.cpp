#include "Berserker.h"  //on inclus le fichier de la classe 

Berserker::Berserker():Perso(){};//on définit le constructeur par défaut

Berserker::Berserker(const string& a, int b, int c, int d, int e)      //on définit le constructeur surchargé
{
    nom_du_perso = a;               //Affectation des attributs
    nb_pt_de_vie = b;  
    vitesse = c;      
    attaque = d;
    defense = e;    
}

void Berserker::frappe_punitive(Perso &d, int energie)    //on définit la méthode enrage
{
    int pv_perso = d.getNbPtVie();
    cout<<"\nFrappe punitive\n";
    if (nb_pt_de_vie>0)
    {
    cout<<nom_du_perso<<" a "<<nb_pt_de_vie<<" points de vie\n";
    }
    else if (nb_pt_de_vie<0)
    {
    cout<<nom_du_perso<<" est mort \n";        
    }
    cout<<nom_du_perso<<" a "<<energie<<" energie\n";
    cout<<d.getNomDuPerso()<<" a "<<pv_perso<<" points de vie\n";
    int pvmax = d.getNbPtVie();
    int attaque = 0.3 * pvmax;
    cout<<d.getNomDuPerso()<<" a recu un degat de "<<attaque<<"\n";
    pv_perso -= attaque;
    cout<<d.getNomDuPerso()<<" a une defense de "<<defense<<"\n";
    nb_pt_de_vie += defense;
    d.setNbPtDeVie(pv_perso);
    if (pv_perso>0)
    {
    cout<<d.getNomDuPerso()<<" a "<<pv_perso<<" points de vie\n";
    }
    else if (pv_perso<0)
    {
    cout<<d.getNomDuPerso()<<" est mort \n";        
    }
    nb_pt_de_vie = nb_pt_de_vie - (nb_pt_de_vie * 0.1);
    if (nb_pt_de_vie>0)
    {
    cout<<nom_du_perso<<" a "<<nb_pt_de_vie<<" points de vie\n";
    }
    else if (nb_pt_de_vie<0)
    {
    cout<<nom_du_perso<<" est mort \n";        
    }
    energie += 20;
    cout<<nom_du_perso<<" a "<<energie<<" energie\n";
}

void Berserker::coup_dechaine(Perso &e, int energie) //on définit la méthode attaque éclair avec un objet reference en parametre
{
    int pv_perso = e.getNbPtVie();
    cout<<"\nCoup dechaine\n";
    if (nb_pt_de_vie>0)
    {
    cout<<nom_du_perso<<" a "<<nb_pt_de_vie<<" points de vie\n";
    }
    else if (nb_pt_de_vie<0)
    {
    cout<<nom_du_perso<<" est mort \n";        
    }
    cout<<nom_du_perso<<" a "<<energie<<" energie\n";
    cout<<e.getNomDuPerso()<<" a "<<pv_perso<<" points de vie\n";
    int pvmax = e.getNbPtVie();
    int attaque = 0.5 * pvmax;
    cout<<e.getNomDuPerso()<<" a recu un degat de "<<attaque<<"\n";
    pv_perso -= attaque;
    cout<<e.getNomDuPerso()<<" a une defense de "<<defense<<"\n";
    nb_pt_de_vie += defense;
    e.setNbPtDeVie(pv_perso);
    if (pv_perso>0)
    {
    cout<<e.getNomDuPerso()<<" a "<<pv_perso<<" points de vie\n";
    }
    else if (pv_perso<0)
    {
    cout<<e.getNomDuPerso()<<" est mort \n";        
    }
    nb_pt_de_vie = nb_pt_de_vie - (nb_pt_de_vie * 0.15);
    if (nb_pt_de_vie>0)
    {
    cout<<nom_du_perso<<" a "<<nb_pt_de_vie<<" points de vie\n";
    }
    else if (nb_pt_de_vie<0)
    {
    cout<<nom_du_perso<<" est mort \n";        
    }
    energie += 30;
    cout<<nom_du_perso<<" a "<<energie<<" energie\n";
}

void Berserker::alpha(Perso &f, int energie)
{
    cout<<"\nAttaque Alpha\n"<<nom_du_perso<<" a "<<energie<<" energie\n";
    if (energie>=100)
    {
    int pv_perso = f.getNbPtVie();
    if (nb_pt_de_vie>0)
    {
    cout<<nom_du_perso<<" a "<<nb_pt_de_vie<<" points de vie\n";
    }
    else if (nb_pt_de_vie<0)
    {
    cout<<nom_du_perso<<" est mort \n";        
    }
    cout<<f.getNomDuPerso()<<" a "<<pv_perso<<" points de vie\n";
    int pvmax = f.getNbPtVie();
    int attaque = 0.75 * pvmax;
    cout<<f.getNomDuPerso()<<" a recu un degat de "<<attaque<<"\n";
    pv_perso -= attaque;
    cout<<f.getNomDuPerso()<<" a une defense de "<<defense<<"\n";
    nb_pt_de_vie += defense;
    f.setNbPtDeVie(pv_perso);
    if (pv_perso>0)
    {
    cout<<f.getNomDuPerso()<<" a "<<pv_perso<<" points de vie\n";
    }
    else if (pv_perso<0)
    {
    cout<<f.getNomDuPerso()<<" est mort \n";        
    }
    nb_pt_de_vie = nb_pt_de_vie + (nb_pt_de_vie * 0.5);
    if (nb_pt_de_vie>0)
    {
    cout<<nom_du_perso<< " a "<<nb_pt_de_vie<<" de point de vie \n";
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
}

