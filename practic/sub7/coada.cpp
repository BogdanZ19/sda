#include "coada.h"
#include <iostream>
using namespace std;

void Init(Coada *&coada)
{
    coada = nullptr;
}

void Put(Coada *&coada, int val)
{
    Coada *p = new Coada(val);
    if (!coada)
    {
        coada = p;
    }
    else
    {
        Coada *current = coada;
        while(current->link)
        {            
            current = current->link;
        }
        current->link = p;
    }
}

bool IsEmpty(Coada *coada)
{
    return coada == nullptr;   
}

int Get(Coada *&coada)
{
    if (IsEmpty(coada))
    {
        cout << "coada este goala" << endl;
        return 0;
    }

    Coada *toDelete = coada;
    int toReturn = coada->data;
    coada = coada->link;

    delete toDelete;
    return toReturn;
}

bool areEqual(Coada *c1, Coada *c2)
{

    while (!IsEmpty(c1) && !IsEmpty(c2))
    {
        if (c1->data != c2->data)
        {
            return false;
        }
        c1 = c1->link;
        c2 = c2->link;
    }
    if (!IsEmpty(c1) || !IsEmpty(c2))
    {
        return false;
    }

    return areEqual;
}

void Display(Coada *c)
{
    if (IsEmpty(c))
    {
        cout << "Coada este goala" << endl;
        return;
    }
    while (c)
    {
        cout << c->data << " ";
        c = c->link;
    }
    cout << endl;
}

void Delete(Coada *&c)
{
    if (IsEmpty(c))
        return;
    
    while(c)
    {
        c = c->link;
    }
}
