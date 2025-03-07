#include <iostream>

struct Element
{
    int data;
    Element *succ;
};

void inserareFata(Element *&cap, int x);
void inserareSpate(Element *cap, int x);
void creareLista(Element *&cap);
void afisareLista(Element *cap);
Element *concat(Element *cap1, Element *cap2);
Element *interclasare(Element *cap1, Element *cap2);

int main()
{
    Element *cap1 = nullptr;
    Element *cap2 = nullptr;
    Element *cap3 = nullptr;
    Element *cap4 = nullptr;


    std::cout << "Introduceti elementele listei 1: (0 = stop)" << std::endl;
    creareLista(cap1);
    std::cout << "Introduceti elementele listei 2: (0 = stop)" << std::endl;
    creareLista(cap2);

    std::cout << std::endl << "Lista 1: " << std::endl;
    afisareLista(cap1);
    std::cout << std::endl << "Lista 2: " << std::endl;
    afisareLista(cap2);

    std::cout << std::endl << "Lista concatenata: " << std::endl;
    cap3 = concat(cap1, cap2);
    afisareLista(cap3);


    std::cout << std::endl << "Lista interclasata: " << std::endl;
    cap4 = interclasare(cap1, cap2);
    afisareLista(cap4);


    return 0;
}

void inserareFata(Element *&cap, int x)
{
    Element *el = new Element;
    el->data = x;
    el->succ = cap;
    cap = el;
}

void creareLista(Element *&cap)
{
    int x;
    std::cin >> x;

    while (x)
    {
        inserareFata(cap, x);
        std::cin >> x;
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

void inserareSpate(Element *cap, int x)
{
    Element *el = new Element;
    el->data = x;
    el->succ = nullptr;


    while (cap->succ != nullptr)
    {
        cap = cap->succ;
    }
    cap->succ = el;
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
        if (cap1 != nullptr)
        {
            inserareSpate(p, cap1->data);
            cap1 = cap1->succ;
        }

        if (cap2 != nullptr)
        {
            inserareSpate(p, cap2->data);
            cap2 = cap2->succ;
        }
    }

    p = p->succ;

    return p;
}