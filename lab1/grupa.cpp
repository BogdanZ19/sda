#include <iostream>
#include <cstring>
#include "grupa.h"

void InitGrupa(Grupa &g)
{
    std::cout << "Nr grupa = ";
    std::cin >> g.id;
    std::cout << "Nr studenti = ";
    std::cin >> g.nr;

    g.tab = new Student[g.nr];
    for (unsigned i = 0; i < g.nr; i++)
    {
        InitStudent(g.tab[i]);
    }
}
void AfisGrupa(Grupa g)
{
    std::cout << "Grupa " << g.id << ": " << std::endl;
    for (unsigned i = 0; i < g.nr; i++)
    {
        AfisStudent(g.tab[i]);
    }
}
void StergeGrupa(Grupa &g)
{
    for (unsigned i = 0; i < g.nr; i++)
    {
        StergeStudent(g.tab[i]);
    }

    delete[] g.tab;
}

void CautaDupaNume(Grupa g, char* nume)
{
    bool gasit = 0;
    for (unsigned i = 0; i < g.nr; i++)
    {
        if (strcmp(g.tab[i].nume, nume) == 0)
        {
            std::cout << "Nota studentului cautat este: " << g.tab[i].nota << std::endl;
            bool gasit = 1;
        }
    }
    if(!gasit)
    {
        std::cout << "Numele cautat nu a fost gasit" << std::endl;
    }
}

void AfisNotaMinMAx(Grupa g)
{
    int min = g.tab[0].nota;
    int max = g.tab[0].nota;

    for (unsigned i = 0; i < g.nr; i++)
    {
        if (g.tab[i].nota < min)
            min = g.tab[i].nota;
        if (g.tab[i].nota > max)
            max = g.tab[i].nota;
    }

    std::cout << "Nota: (min, max) = (" << min << ", " << max << ")" << std::endl;
}

void SortareGrupa(Grupa &g)
{
    int n = g.nr;
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) 
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
         {
            if (g.tab[j].nota > g.tab[j + 1].nota) 
            {
                Student aux;
                aux = g.tab[j];
                g.tab[j] = g.tab[j+1];
                g.tab[j+1] = aux;

                swapped = true;
            }
        }
      
        if (!swapped)
            break;
    }
}
