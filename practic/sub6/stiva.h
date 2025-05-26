#ifndef _STIVA_
#define _STIVA_

typedef int Atom;

struct Stiva
{
	Atom data;
	Stiva *link;
	Stiva(Atom d = 0, Stiva *l = nullptr) : data(d), link(l){};
};

bool isEmpty(Stiva *&p);
void PushElem(Stiva *&p, Atom data);
Atom PopElem(Stiva *&p);
Atom TopElem(Stiva *&p);
void initStiva(Stiva *&p);
Stiva *copy(Stiva *p);
void DeleteStiva(Stiva *&p);
void AfisStiva(Stiva *p);

#endif
