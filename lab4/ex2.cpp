#include <iostream>

struct Element
{
    int data;
    Element *succ, *pred;
};

void inserareFata(Element *&cap, int val);
void creareLista(Element *&cap);
void afisareLista(Element *cap);
void inserareSpate(Element *cap, int val);
Element *concat(Element *cap1, Element *cap2);
Element *interclasare(Element *cap1, Element *cap2);

int main()
{
    Element *cap1 = nullptr;
    Element *cap2 = nullptr;
    Element *cap3 = nullptr;
    Element *cap4 = nullptr;

    std::cout << "Prima lista:" << std::endl;
    creareLista(cap1);
    afisareLista(cap1);

    std::cout << std::endl << "A doua lista:" << std::endl;
    creareLista(cap2);
    afisareLista(cap2);

    std::cout << std::endl << "Dupa concatenare: " << std::endl;
    cap3 = concat(cap1, cap2);
    afisareLista(cap3);

    std::cout << std::endl << "Dupa interclasare: " << std::endl;
    cap4 = interclasare(cap1, cap2);
    afisareLista(cap4);

    return 0;
}


void inserareFata(Element *&cap, int val)
{
    Element *p = new Element{val};

    p->succ = cap;
    if (cap)
    {
        cap->pred = p;
    }
    p->pred = nullptr;
    cap = p;
}

void creareLista(Element *&cap)
{
    int n;

    std::cout << "Introduceti elementele listei: (0 = stop)" << std::endl;
    std::cin >> n;

    while (n)
    {
        inserareFata(cap, n);
        std::cin >> n;
    }
}

void afisareLista(Element *cap)
{
    while (cap)
    {
        std::cout << cap->data << "\t";
        cap = cap->succ;
    }
    std::cout << std::endl;
}

void inserareSpate(Element *cap, int val)
{
    Element *p = new Element{val};
    
    p->succ = nullptr;

    while (cap->succ != nullptr)
    {
        cap = cap->succ;
    }
    p->pred = cap;
    cap->succ = p;
}

Element *concat(Element *cap1, Element *cap2)
{
    Element *p = new Element;

    while (cap1)
    {
        inserareSpate(p, cap1->data);
        cap1 = cap1->succ;
    }

    while (cap2)
    {
        inserareSpate(p, cap2->data);
        cap2 = cap2->succ;
    }

    p = p->succ;

    return p;
}

Element *interclasare(Element *cap1, Element *cap2)
{
    Element *p = new Element;

    while (cap1 || cap2)
    {
        if (cap1)
        {
            inserareSpate(p, cap1->data);
            cap1 = cap1->succ;
        }

        if (cap2)
        {
            inserareSpate(p, cap2->data);
            cap2 = cap2->succ;
        }
    }

    p = p->succ;
    return p;
}
