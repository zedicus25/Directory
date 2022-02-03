#include "c_Directory.h"

int main()
{
    c_Directory* dr = new c_Directory();
    Firma fr("SDProject Red", "Ivanov Ivan Ivanich", "+380505588911", "Poland Warshawa st.Pruzn 15", "Game development");
    Firma fr1("Ubisoft", "Petrov Petr Petrovich", "+380987412815", "USA California Los Angeles st.Beech 55", "Gay development");
    Firma fr2("Rockstar", "Stepanov Stepan Spepanich", "+380715219685", "Norway Oslo st. Salmon 12","Game development");
   /* dr->add(fr);
    dr->add(fr1);
    dr->add(fr2);*/
    //dr->print();
    dr->loadFromFile();
    dr->print();
}