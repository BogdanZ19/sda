#include <iostream>
#include "agenda.cpp"


int main()
{
	Agenda* p;

	InitAgenda(p);
	CitAgenda(p);
	AfisAgenda(p);
	CautaPers(p);

	return 0;
}
