#include <iostream>
#include "grupa.h"

int main()
{
    Grupa g;
    char numeCautat[] = "marius";

    InitGrupa(g);
    std::cout << std::endl;
    AfisGrupa(g);

    CautaStudent(g, numeCautat);
    std::cout << std::endl;
    afisNotaMinMax(g);

    StergeGrupa(g);
    return 0;
}