#include "Snowqueen.h"
Snowqueen::Snowqueen():Perso(){};
Snowqueen::Snowqueen(const string& a, int b, int c, int d, int e)      //on définit le constructeur surchargé
{
    nom_du_perso = a;               //Affectation des attributs
    nb_pt_de_vie = b;  
    vitesse = c;
    attaque = d;
    defense = e;     
}

void Snowqueen::javelot_glace(Perso &g, int energie)    //on définit la méthode enrage
{
    int pv_perso = g.getNbPtVie();
    if (nb_pt_de_vie>0)
    {
    cout<<nom_du_perso<<" a "<<nb_pt_de_vie<<" points de vie\n";
    }
    else if (nb_pt_de_vie<0)
    {
    cout<<nom_du_perso<<" est mort \n";        
    }
    cout<<nom_du_perso<<" a "<<energie<<" energie\n";
    cout<<g.getNomDuPerso()<<" a "<<pv_perso<<" points de vie\n";
    attaque = 1.25 * attaque;
    cout<<g.getNomDuPerso()<<" a recu un degat de "<<attaque<<"\n";
    pv_perso -= attaque;
    cout<<g.getNomDuPerso()<<" a une defense de "<<defense<<"\n";
    nb_pt_de_vie += defense;
    g.setNbPtDeVie(pv_perso);
    if (pv_perso>0)
    {
    cout<<g.getNomDuPerso()<<" a "<<pv_perso<<" points de vie\n";
    }
    else if (pv_perso<0)
    {
    cout<<g.getNomDuPerso()<<" est mort \n";        
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

void Snowqueen::vent_glacial(Perso &h, int energie) //on définit la méthode attaque éclair avec un objet reference en parametre
{
    int pv_perso = h.getNbPtVie();
    cout<<"\nVent glacial\n";
    if (nb_pt_de_vie>0)
    {
    cout<<nom_du_perso<<" a "<<nb_pt_de_vie<<" points de vie\n";
    }
    else if (nb_pt_de_vie<0)
    {
    cout<<nom_du_perso<<" est mort \n";        
    }
    cout<<nom_du_perso<<" a "<<energie<<" energie\n";
    cout<<h.getNomDuPerso()<<" a "<<pv_perso<<" points de vie\n";
    attaque = 1.5 * attaque;
    cout<<h.getNomDuPerso()<<" a recu un degat de "<<attaque<<"\n";
    pv_perso -= attaque;
    cout<<h.getNomDuPerso()<<" a une defense de "<<defense<<"\n";
    nb_pt_de_vie += defense;
    h.setNbPtDeVie(pv_perso);
    if (pv_perso>0)
    {
    cout<<h.getNomDuPerso()<<" a "<<pv_perso<<" points de vie\n";
    }
    else if (pv_perso<0)
    {
    cout<<h.getNomDuPerso()<<" est mort \n";        
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

void Snowqueen::LetItGo(Perso &i, int energie)
{
    cout<<"\nLetItGo\n"<<nom_du_perso<<" a "<<energie<<" energie\n";
    if (energie>=100)
    {
    int pv_perso = i.getNbPtVie();
    if (nb_pt_de_vie>0)
    {
    cout<<nom_du_perso<<" a "<<nb_pt_de_vie<<" points de vie\n";
    }
    else if (nb_pt_de_vie<0)
    {
    cout<<nom_du_perso<<" est mort \n";        
    }
    cout<<i.getNomDuPerso()<<" a "<<pv_perso<<" points de vie\n";
    attaque = 1.75 * attaque;
    cout<<i.getNomDuPerso()<<" a recu un degat de "<<attaque<<"\n";
    pv_perso -= attaque;
    cout<<i.getNomDuPerso()<<" a une defense de "<<defense<<"\n";
    nb_pt_de_vie += defense;
    i.setNbPtDeVie(pv_perso);
    if (pv_perso>0)
    {
    cout<<i.getNomDuPerso()<<" a "<<pv_perso<<" points de vie\n";
    }
    else if (pv_perso<0)
    {
    cout<<i.getNomDuPerso()<<" est mort \n";        
    }
    nb_pt_de_vie = nb_pt_de_vie + (nb_pt_de_vie * 0.5);
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
}
