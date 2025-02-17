#include <iostream>
#include "student.h"
#include <cstring>


void InitStudent (Student &s)
{
    char aux[100];

    std::cout << "nume: ";
    std:: cin >> aux;

    s.nume = new char[strlen(aux) + 1];
    strcpy(s.nume, aux);
    
    std::cout << "nota = ";
    std::cin >> s.nota;

}

void AfisStudent (Student s)
{
    std::cout << "(nume, nota) = (" << s.nume << ", " << s.nota << ")" << std::endl;
}

void StergeStudent (Student &s) 
{
    delete[] s.nume;
}
