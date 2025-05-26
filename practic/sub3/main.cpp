#include <iostream>
#include "lista.h"
using namespace std;

int main()
{
	Elem* p;

	InitLista(p);
	CitElemente(p);
	cout << "Am citit: ";
	AfisLista(p);
	CautaVal(p);
	DelElem(p);
	cout << "Lista actualizata: ";
	AfisLista(p);

	return 0;
}