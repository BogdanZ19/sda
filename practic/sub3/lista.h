#ifndef _LISTA_
#define _LISTA_

struct Elem
{
	int data;
	Elem *next;
	Elem(int d = 0, Elem *n = nullptr) : data(d), next(n){};
};

void InitLista(Elem *&p);
void InsertFata(Elem *&p, int val);
void AfisLista(Elem *p);
void CitElemente(Elem *&p);
void CautaVal(Elem *p);
void DelElem(Elem *&p);
void StergeFata(Elem *p);
void StergeMijloc(Elem *p, int poz);

#endif