#include <iostream>
#include "student.h"
#include <cstring>

void InitStudent(Student &s)
{
    char aux[100];
    char ws;

    std::cout << "nume = ";
    std::cin >> ws;
    std::cin.getline(aux, 100);

    s.nume = new char[strlen(aux) + 1];
    strcpy(s.nume, aux);

    std::cout << "nota = ";
    std::cin >> s.nota;
}
void AfisStudent(Student s)
{
    std::cout << "(nume, nota) = (" << s.nume << ", " << s.nota << ")" << std::endl;
}
void StergeStudent(Student &s)
{
    delete[] s.nume;
}