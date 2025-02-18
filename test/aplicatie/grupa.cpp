#include <iostream>
#include <cstring>
#include "grupa.h"
#include "student.h"

void InitGrupa (Grupa &g)
{
    std::cout << "nr grupa = ";
    std::cin >> g.id;

    std::cout << "nr studenti = ";
    std::cin >> g.nr;

    g.tab = new Student[g.nr];

    for(unsigned i = 0; i  < g.nr; i++)
    {
        InitStudent(g.tab[i]);
    }

}

void AfisGrupa (Grupa g)
{
    std::cout << "Grupa " << g.id << ":" << std::endl;
    for(unsigned i = 0; i < g.nr; i++)
    {
        AfisStudent(g.tab[i]);
    }
    std::cout << std::endl;
}

void StergeGrupa (Grupa &g)
{
    for(unsigned i = 0; i < g.nr; i++)
    {
        StergeStudent(g.tab[i]);
    }

    delete[] g.tab;
}

void CautaStudent(Grupa g, char *numeCautat)
{
    bool gasit = 0;
    for(unsigned i = 0; i < g.nr; i++)
    {
        if(strcmp(g.tab[i].nume, numeCautat) == 0)
        {
            std::cout << "Studentul cautat are nota: " << g.tab[i].nota << std::endl;
            gasit = 1;
        }   
    }

    if(!gasit)
        std::cout << "Numele cautat nu a fost gasit" << std::endl;
}

void afisNotaMinMax(Grupa g)
{
    int min = g.tab[0].nota;
    int max = g.tab[0].nota;

    for(unsigned i = 1; i < g.nr; i++)
    {
        if(g.tab[i].nota < min)
        {
            min = g.tab[i].nota;
        }
        if(g.tab[i].nota > max)
        {
            max = g.tab[i].nota;
        } 
    }
    std::cout << "nota minima = " << min << std::endl << "nota maxima = " << max << std::endl;
}