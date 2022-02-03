#include "c_Directory.h"

int main()
{
    c_Directory* dr = new c_Directory();
    Firma fr("SDProject Red", "Ivanov Ivan Ivanich", "+380505588911", "Poland Warshawa st.Pruzn 15", "Game development");
    Firma fr1("Ubisoft", "Petrov Petr Petrovich", "+380987412815", "USA California Los Angeles st.Beech 55", "Gay development");
    Firma fr2("Rockstar", "Stepanov Stepan Spepanich", "+380715219685", "Norway Oslo st. Salmon 12","Game development");
    dr->add(fr);
    dr->add(fr1);
    dr->add(fr2);
    //remove
    /*dr->print();
    dr->remove("Ubisoft");
    std::cout << "\n";
    dr->print();*/
    //search
    /* dr->searchByName("Ubisoft");
    std::cout << "\n";
    dr->searchByNumber("+380715219685");
    std::cout << "\n";
    dr->searchByOccupation("Game development");
    std::cout << "\n";
    dr->searchByOwner("Petrov Petr Petrovich");*/
    //save load
    /*dr->saveToFile();
    //dr->loadFromFile();
    dr->print();*/
 
}