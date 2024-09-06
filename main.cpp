#include "Snowqueen.h" 
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>   //on inclus le fichier de la classe
using namespace std; //pour éviter de devoir écrire à chaque fois std::




int main(void)      //fonction principale
{
cout << endl; 

    cout << "Premier tour  \n";
    Perso Premier;       //on crée un objet Premier et on affecte des coordonnées  
    Berserker Deux("Berserker", 100, 4, 50, 10);   //on crée un objet Deux et on affecte des coordonnées   
    Snowqueen Trois("Snowqueen", 100, 3, 60, 5);    //on crée un objet Trois et on affecte des coordonnées  
    
    int jeu=0;
    int mort=0;   
    int equ =0;

        if (Premier.getVitesse() >= Deux.getVitesse() && Premier.getVitesse() >= Trois.getVitesse())
        { jeu = 1;
            cout << Premier.getNomDuPerso() << " joue en premier\n";
            cout<<"Choisir l'equipement (1=gants 2=bottes 3=gilet 4=heaume): ";    		    
    		cin >> equ;    
    		cout<<"\n";
    		if (equ==1) {Premier.equiper("gants");}
    		else if(equ==2) {Premier.equiper("bottes");}
    		else if(equ==3) {Premier.equiper("gilet");}       
    		else if(equ==4) {Premier.equiper("heaume");} 
            cout<<"\nChoisissez une action (1=frappe préventive 2=blast 3=delta): ";
            int action;
            cin >> action;
            if (action == 1) {Premier.frappe(Deux, 5);}
            else if (action == 2) {Premier.blast(Trois, 6);}
            else if (action == 3) {Premier.delta(Trois, 105);}
        } 
        else if (Deux.getVitesse() >= Trois.getVitesse()) 
        {jeu = 2;
            cout << Deux.getNomDuPerso() << " joue en premier\n";
            cout<<"Choisir l'equipement (1=gants 2=bottes 3=gilet 4=heaume): ";    
    		cin >> equ;    
    		cout<<"\n";
    		if (equ==1) {Deux.equiper("gants");}
    		else if(equ==2) {Deux.equiper("bottes");}
    		else if(equ==3) {Deux.equiper("gilet");}       
    		else if(equ==4) {Deux.equiper("heaume");} 
            cout<<"\nChoisissez une action (1=frappe punitive 2=coup dechaine 3=alpha): ";
            int act;
            cin >> act;
            if (act == 1) {Deux.frappe_punitive(Premier, 30);}
            else if (act == 2) {Deux.coup_dechaine(Premier, 20);}
            else if (act == 3) {Deux.alpha(Premier,110);}
        } 
        else 
        {jeu = 3;
            cout << Trois.getNomDuPerso() << " joue en premier\n";
            cout<<"Choisir l'equipement (1=gants 2=bottes 3=gilet 4=heaume): ";   		    
    		cin >> equ;    
    		cout<<"\n";
    		if (equ==1) {Deux.equiper("gants");}
    		else if(equ==2) {Deux.equiper("bottes");}
    		else if(equ==3) {Deux.equiper("gilet");}       
    		else if(equ==4) {Deux.equiper("heaume");} 
            cout<<"\nChoisissez une action (1=javelot de glace 2=vent glacial 3=LetItGo): ";
            int ac;
            cin >> ac;
            if (ac == 1) {Trois.javelot_glace(Premier, 30);}
            else if (ac == 2) {Trois.vent_glacial(Deux, 10);}
            else if (ac == 3) {Trois.LetItGo(Deux, 200);}
        }


        if (jeu == 1) 
        {
            if (Deux.getVitesse() >= Trois.getVitesse()) {cout << "\nC'est au tour de " << Deux.getNomDuPerso();
            cout<<"\nChoisir l'equipement (1=gants 2=bottes 3=gilet 4=heaume): ";   		    
    		cin >> equ;    
    		cout<<"\n";}
    		if (equ==1) {Deux.equiper("gants");}
    		else if(equ==2) {Deux.equiper("bottes");}
    		else if(equ==3) {Deux.equiper("gilet");}       
    		else if(equ==4) {Deux.equiper("heaume");} 
    		cout<<"\nChoisissez une action (1=frappe punitive 2=coup dechaine 3=alpha): ";
            int act;
            cin >> act;    
            if (act == 1) {Deux.frappe_punitive(Premier, 30);}
            else if (act == 2) {Deux.coup_dechaine(Premier, 20);}
            else if (act == 3) {Deux.alpha(Premier, 110);}
            cout << "\nC'est au tour de " << Trois.getNomDuPerso();
            cout<<"\nChoisir l'equipement (1=gants 2=bottes 3=gilet 4=heaume): ";   		    
    		cin >> equ;    
    		cout<<"\n";
    		if (equ==1) {Deux.equiper("gants");}
    		else if(equ==2) {Deux.equiper("bottes");}
    		else if(equ==3) {Deux.equiper("gilet");}       
    		else if(equ==4) {Deux.equiper("heaume");} 
            cout << "\nChoisissez une action (1=javelot de glace 2=vent glacial 3=LetItGo): ";
            int ac;
            cin >> ac;
            if (ac == 1) {Trois.javelot_glace(Premier, 30);}
            else if (ac == 2) {Trois.vent_glacial(Deux, 10);}
            else if (ac == 3) {Trois.LetItGo(Deux, 200);}            
        }
    
    do
    {
        if (Premier.getNbPtVie()<=0)
        {
            mort=1;
            cout<<Premier.getNomDuPerso()<<" est mort";
        }
        else if (Deux.getNbPtVie()<=0)
        {
            mort=1;
            cout<<Deux.getNomDuPerso()<<" est mort";
        }
            else if (Trois.getNbPtVie()<=0)
        {
            mort=1;
            cout<<Trois.getNomDuPerso()<<" est mort";
        }
        }  while (mort!=1);

        do
        {
            cout<<"\n";
            cout << "\nNouveau tour \n";    
         if (Premier.getVitesse() >= Deux.getVitesse() && Premier.getVitesse() >= Trois.getVitesse())
            { 
            jeu = 1;
            cout << Premier.getNomDuPerso() << " joue en premier\n";
            cout<<"\nChoisissez une action (1=frappe préventive 2=blast 3=delta): ";
            int action;
            cin >> action;
            if (action == 1) {Premier.frappe(Deux, 5);}
            else if (action == 2) {Premier.blast(Trois, 6);}
            else if (action == 3) {Premier.delta(Trois, 105);}
        } 
        else if (Deux.getVitesse() >= Trois.getVitesse())
        {
            jeu = 2;
            cout << Deux.getNomDuPerso() << " joue en premier\n";
            cout<<"\nChoisissez une action (1=frappe punitive 2=coup dechaine 3=alpha): ";
            int act;
            cin >> act;
            if (act == 1) {Deux.frappe_punitive(Premier, 30);}
            else if (act == 2) {Deux.coup_dechaine(Premier, 20);}
            else if (act == 3) {Deux.alpha(Premier,110);}
        }
        else 
        {
            jeu = 3;
            cout << Trois.getNomDuPerso() << " joue en premier\n";             
            cout<<"\nChoisissez une action (1=javelot de glace 2=vent glacial 3=LetItGo): ";
            int ac;
            cin >> ac;
            if (ac == 1) {Trois.javelot_glace(Premier, 30);}
            else if (ac == 2) {Trois.vent_glacial(Deux, 10);} 
            else if (ac == 3) {Trois.LetItGo(Deux, 200);}
        }


        if (jeu == 1) 
        {
            if (Deux.getVitesse() >= Trois.getVitesse()) 
            {
                cout << "\nC'est au tour de " << Deux.getNomDuPerso();
                cout << "\nChoisissez une action (1=frappe punitive 2=coup dechaine 3=alpha): ";
                int act;
                cin >> act;

                if (act == 1) {Deux.frappe_punitive(Premier, 30);}
                else if (act == 2) {Deux.coup_dechaine(Premier, 20);}
                else if (act == 3) {Deux.alpha(Premier, 110);}
                cout << "\nC'est au tour de " << Trois.getNomDuPerso();
                cout << "\nChoisissez une action (1=javelot de glace 2=vent glacial 3=LetItGo): ";
                int ac;
                cin >> ac;
                if (ac == 1) {Trois.javelot_glace(Premier, 30);}
                else if (ac == 2) {Trois.vent_glacial(Deux, 10);}
                else if (ac == 3) {Trois.LetItGo(Deux, 200);}
            }
        }
        
        if (Premier.getNbPtVie()<=0 && Deux.getNbPtVie()<=0)
        {
            mort=2;
            cout<<Trois.getNomDuPerso()<<" a gagne\n";
        }
        else if (Trois.getNbPtVie()<=0 && Deux.getNbPtVie()<=0)
        {
            mort=2;
            cout<<Premier.getNomDuPerso()<<" a gagne\n";
        }
        else if (Premier.getNbPtVie()<=0 && Trois.getNbPtVie()<=0)
        {
            mort=2;
            cout<<Deux.getNomDuPerso()<<" a gagne\n";
        }
    } while (mort!=2);
        
     
    return 0;       //on retourne la valeur 0
}
