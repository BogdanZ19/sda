#ifndef _GRUPA_
#define _GRUPA_
#include "student.h"

struct Grupa
{
    Student *tab;
    int nr;
    int id;
};


void InitGrupa(Grupa&);
void AfisGrupa(Grupa);
void StergeGrupa(Grupa&);
void CautaDupaNume(Grupa, char*);
void AfisNotaMinMAx(Grupa);
void SortareGrupa(Grupa&);

#endif