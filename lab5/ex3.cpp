#include <iostream>

struct Element{
    int data;
    Element *next;

    Element(): data(0), next(nullptr){};
    Element(int d): data(d), next(nullptr){};
    Element(int d, Element *n): data(d), next(n){};
};

void creareLista(Element *&cap);
void afisareLista(Element *cap);
void afisarePermutari(Element *cap);
void inversareLegaturi(Element *&cap);

int main()
{
    Element *cap;

    creareLista(cap);
    afisarePermutari(cap);
    
    std::cout << std::endl << "Lista inversata:" << std::endl;
    inversareLegaturi(cap);
    afisareLista(cap);



    return 0;
}


void creareLista(Element *&cap)
{
    Element *p = nullptr;
    int n;
    std::cout << "Introduceti elementele listei (0 = exit):" << std::endl;
    std::cin >> n;


    while(n)
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
        std::cin >> n;
    }
    cap = cap->next;

}




void afisareLista(Element *cap)
{
    Element *p = cap;

    do
    {
        std::cout << p->data << "\t";
        p = p->next;
    } while (p != cap);
    std::cout << std::endl;
}


void afisarePermutari(Element *cap)
{
    Element *p = cap;
    do
    {
        afisareLista(p);
        p = p->next;
    } while (p != cap);
    
}

void inversareLegaturi(Element *&cap)
{
    Element *p = nullptr;
    Element *q = cap;
    Element *r = nullptr;

    do
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    } while (q != cap);

    q->next = p;
    cap = cap->next;
}

//  5 4 3 2 1
//        p q r
//          p
//  q r
