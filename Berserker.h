#include "Perso.h"      //inclure le fichier de la classe
class Berserker : public Perso      //déclarer la classe
{
    public :                         //création des membres public
    Berserker();                       //déclaration du constructeur par défaut
    Berserker(const string&a, int b, int c, int d, int e);         //déclaration du constructeur
    void frappe_punitive(Perso &d, int energie);             //déclaration de la méthode
    void coup_dechaine(Perso &e, int energie);      //déclaration de la méthode
    void alpha(Perso &f, int energie);
};

