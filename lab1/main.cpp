#include <iostream>
#include "grupa.h"

int main()
{
    char nume[] = "Zainia Bogdan";
    Grupa g;

    InitGrupa(g); 
    std::cout << std::endl;  

    AfisGrupa(g);   
    std::cout << std::endl;

    CautaDupaNume(g, nume);
    std::cout << std::endl;

    AfisNotaMinMAx(g);
    std::cout << std::endl;
    
    SortareGrupa(g);

    AfisGrupa(g);
    
    StergeGrupa(g); 

    return 0;
}