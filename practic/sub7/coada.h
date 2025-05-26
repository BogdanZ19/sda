#ifndef _COADA_H_
#define _COADA_H_

struct Coada
{
    int data;
    Coada *link;
    Coada(int d = 0, Coada *l = nullptr) : data(d), link(l){};
};

void Init(Coada *&coada);
void Put(Coada *&coada, int val);
bool IsEmpty(Coada *coada);
int Get(Coada *&coada);
bool areEqual(Coada *c1, Coada *c2);
void Display(Coada *c);
void Delete(Coada *&c);

#endif