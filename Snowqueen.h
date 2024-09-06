#include "Berserker.h"
class Snowqueen : public Perso
{
    public:
    Snowqueen();
    Snowqueen(const string&a, int b, int c, int d, int e);
    void javelot_glace(Perso &d, int energie);             //déclaration de la méthode
    void vent_glacial(Perso &e, int energie);      //déclaration de la méthode
    void LetItGo(Perso &f, int energie);
};