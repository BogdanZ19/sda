#include <iostream>

struct Element
{
    int data;
    Element *succ, *pred;
};

void inserareFata(Element *&cap, int val);
void creareLista(Element *&cap);
void afisareLista(Element *cap);
void inserareLaPoz(Element *&cap);
void stergeLaPoz(Element *&cap);


int main()
{
    Element *cap = nullptr;

    creareLista(cap);
    afisareLista(cap);

    inserareLaPoz(cap);
    afisareLista(cap);

    stergeLaPoz(cap);
    afisareLista(cap);
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

// cap   1   2   3
// p  cap  1  2  3

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

void inserareLaPoz(Element *&cap)
{
    int val, n, i = 0;
    Element *copy = cap;

    std::cout << "poz = ";
    std::cin >> n;

    std::cout << "element = ";
    std::cin >> val;

    Element *p = new Element{val};

    while (i != n)
    {
        copy = copy->succ;
        i++;
    }

    p->succ = copy;
    p->pred = nullptr;
    if (copy)
    {
        p->pred = copy->pred;
        copy->pred->succ = p;
        copy->pred = p;
    }
}

void stergeLaPoz(Element *&cap)
{
    int n, i = 0;
    Element *copy = cap;

    std::cout << ("Inaintea carei pozitii se sterge?") << std::endl;
    std::cin >> n;

    while (i != n)
    {
        copy = copy->succ;
        i++;
    }

    copy->pred->pred->succ = copy;
    copy->pred = copy->pred->pred;
}


