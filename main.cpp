#include "voiture.h"
const void presenter(vehicule &v, vehicule &m)
{
    v.affiche();
    m.affiche();
}

int main()
{
//vehicule ve;
voiture ve;
moto mo;
voiture vo;

vehicule *v2(0);
v2=&ve;
vehicule *v3(0);
v3=&mo;

//vehicule veh(1000, 4);
//vehicule mot(2000, 2);

//presenter(v1) ;

ve.affiche();
mo.affiche();
vo.affiche();
presenter(vo, mo);
ve.nbrRoues();
mo.nbrRoues();
vo.nbrRoues();

//veh.affiche();
//presenter(veh, mot);

v2->affiche();
v3->affiche();
return 0;
}
