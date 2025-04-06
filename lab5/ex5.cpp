#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Element
{
    string nume;
    Element *next;

    Element () : nume(""), next(nullptr){};
    Element (string n) : nume(n), next(nullptr){};
    Element (string n, Element *e) : nume(n), next(e){};
};

void creareLista(Element *&cap);
void afisareLista(Element *cap);
void executarePas(Element *&cap, int pas);
void salvarePersoana(Element *cap, int pas);


int main()
{
    Element *cap = nullptr;    
    Element *copyCap = nullptr;

    creareLista(cap);
    cout << "Lista introdusa: " << endl;
    afisareLista(cap);

    salvarePersoana(cap, 3);

    executarePas(cap, 3);
    cout << endl <<  "Persoana salvata: " << endl;
    afisareLista(cap);



    return 0;
}

void creareLista(Element *&cap)
{
    Element *p = nullptr;
    Element *first = cap;
    string n;

    cout << "Introduceti persoane in lista (0 = exit):"<< endl;
    cin >> n;

    while (n != "0")
    {
        p = new Element(n);
        if (!cap)
        {
            p->next = p;
            cap = p;
        }
        else
        {
            p->next = cap->next;
            cap->next = p;
            cap = p;
        }
        cin >> n;
    }
    cap = cap->next;
}

void afisareLista(Element *cap)
{
    Element *first = cap;

    do
    {
        cout << cap->nume << "\t";
        cap = cap->next;

    } while (cap != first);
    cout << endl;
}

void executarePas(Element *&cap, int pas)
{
    int n = 1;
    Element *copy = cap;
    
    while (copy->next != copy)
    {
        if ((n+1) % pas == 0)
        {
            Element *toDelete = copy->next;
            copy->next = toDelete->next;

            if (toDelete == cap)
                cap = cap->next;
            delete toDelete;
            n++;
        }
        n++;
        copy = copy->next;
    }
}
void salvarePersoana(Element *cap, int pas)
{
    Element *first = cap;
    int n = 0;
    int rez = 0;

    do
    {
        n++;
        cap = cap->next;
    } while (cap != first);
    
    for (int i = 1; i <= n; i++)
    {
        rez = (rez + pas) % i;
    }
    


    cout << endl << "Persoana salvata va fi pe pozitia: "<< endl << rez+1 << std::endl;
}
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 0
// raspuns: 2 (cu pas 3)
