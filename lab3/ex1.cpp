#include <iostream>

struct Element
{
    int data;
    Element *succ;
};

void inserareFata(Element *&cap, int val);
void creareLista(Element *&cap);
void afisareLista(const Element *cap);
void stergereElement(Element *&el);
void stergereLista(Element *&cap);
void cautaEl(const Element *cap, int x);
void inserareLaPoz(Element *cap);
void stergereLaPoz(Element *cap);
void inversareLista(Element *&cap);
void afisareElLaPozDesc(Element *cap, int poz);
void parcurgereDus(Element *cap);
void parcurgereIntors(Element *cap);
void parcurgereDusIntors(Element *cap);
void checkBucla(Element *cap);
void gasireMijloc(Element *cap);


int main()
{
    Element *cap = nullptr;
    creareLista(cap);               //a
    std::cout << std::endl << "Lista creata este: " << std::endl;
    afisareLista(cap);              //b
    cautaEl(cap, 4);                //c
 
    std::cout << std::endl << "Ex inserare element: " << std::endl;
    inserareLaPoz(cap);             //d
    afisareLista(cap); 
 
    std::cout << std::endl << "Ex stergere element: " << std::endl;
    stergereLaPoz(cap);             //e
    afisareLista(cap); 
 
    std::cout << std::endl << "Ex afisare element la pozitia x descrescator: " << std::endl;
    afisareElLaPozDesc(cap, 3);     //f
 
    std::cout << std::endl << "Ex parcurgere dus-intors:" << std::endl;
    parcurgereDusIntors(cap);       //g  Complexitate spatiu mai mare deoarece la fiecare apel
    //                                   recursiv se creeaza o noua stiva.

   
    //CREARE BUCLA:                 //h

    // Element *p = cap;
    // int k = 1;
    
    // while (k != 6)
    // {
    //     ++k;
    //     p = p->succ;
    // }
    
    // p->succ = cap;
    
    std::cout << std::endl << "Ex verificare bucla: " << std::endl;
    checkBucla(cap);

    std::cout << std::endl << "Gasire mijloc" << std::endl;
    gasireMijloc(cap);              //i

    std::cout << std::endl << "Ex inversare lista: " << std::endl;
    std::cout << "Lista initiala: " << std::endl;
    afisareLista(cap);
    std::cout << "Lista inversata: " << std::endl;
    inversareLista(cap);
    afisareLista(cap);

    //stergereLista(cap);           //randul trebuie comentat atunci cand se creeaza intentionat o bucla

    return 0;
}

void inserareFata(Element *&cap, int val)
{
    Element *p;
    p = new Element;

    p->data = val;
    p->succ = cap;
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

void afisareLista(const Element *el)
{
    while (el != 0 && el != nullptr)
    {
        std::cout << el->data << "\t";
        el = el->succ;
    }
    std::cout << std::endl;
}

void stergereElement(Element *&el)
{
    delete el;
    el = 0;
}

void stergereLista(Element *&cap)
{
    while (cap != 0 && cap != nullptr)
    {
        Element *p = cap;
        cap = cap->succ;
        stergereElement(p);
    }
}

void cautaEl(const Element *cap, int x)
{
    while (cap != nullptr && cap->data != x)
    {
        cap = cap->succ;
    }

    if (cap != nullptr)
    {
        if (cap->data == x)
        {
            std::cout << "Elementul " << x << " apartine listei" << std::endl;
        }
    }
    else
    {
        std::cout << "Elementul " << x << " nu apartine listei" << std::endl;
    }
}

void inserareLaPoz(Element *cap)
{
    int poz, el, k = 1;
    Element *p = cap;

    std::cout << "poz = ";
    std::cin >> poz;
    std::cout << "el = ";
    std::cin >> el;

    Element *q = new Element;

    while (k != poz - 1)
    {
        k++;
        p = p->succ;
    }
    q->data = el;
    q->succ = p->succ;
    p->succ = q;
}

void stergereLaPoz(Element *cap)
{
    int poz, k = 1;
    Element *p = cap;

    std::cout << "poz = ";
    std::cin >> poz;

    while (k != poz - 1)
    {
        k++;
        p = p->succ;
    }

    Element *temp = p->succ;

    p->succ = temp->succ;
    stergereElement(temp);
}

// p     p->succ     p->succ->succ
// p     temp        temp->succ

void inversareLista(Element *&cap)
{
    Element *p = nullptr;
    Element *q = cap;
    Element *r = nullptr;

    while (q != nullptr)
    {
        r = q->succ;
        q->succ = p;
        p = q;
        q = r;
    }

    cap = p;
}
// trecut    prezent     next        next2
// p         q           r
// 1         2           3           4           5           6

void afisareElLaPozDesc(Element *cap, int poz)
{
    inversareLista(cap);

    int index = 1;
    Element *p = cap;

    while (p != nullptr && index != poz)
    {
        index++;
        p = p->succ;
    }

    if (p != nullptr)
        std::cout << "Elementul cautat este: " << p->data << std::endl;
    else 
        std::cout << "Err" << std::endl;

    inversareLista(cap);
}

void parcurgereDus(Element *cap)
{
    if (cap == nullptr)
        return;

    std::cout << cap->data << std::endl;

    parcurgereDus(cap->succ);
}

void parcurgereIntors(Element *cap)
{
    if (cap == nullptr)
        return;
        
    parcurgereIntors(cap->succ);
    
    std::cout << cap->data << std::endl;

}

void parcurgereDusIntors(Element *cap)
{
    std::cout << "Parcurgere dus: " << std::endl;
    parcurgereDus(cap);
    std::cout << std::endl << "Parcurgere intors: " << std::endl;
    parcurgereIntors(cap);
}

void checkBucla(Element *cap)
{
    Element *p = cap;
    Element *q = cap;

    while (q != nullptr && q->succ != nullptr)
    {
        p = p->succ;
        q = q->succ->succ;
        if (p == q)
        {
            std::cout << "Lista contine o bucla" << std::endl;
            return;
        }
    }
    std::cout << "Lista nu contine o bucla" << std::endl;

}

void gasireMijloc(Element *cap)
{
    Element *p = cap;
    Element *q = cap;

    while (q != nullptr && q->succ != nullptr)
    {
        p = p->succ;
        q = q->succ->succ;
    }

    std::cout << "Mijlocul listei este elementul: " << p->data << std::endl;
}

//  1   2   3   4   5   6   7
// p/q  
//      p   q
//          p       q
//              p            q 
//          mijloc = 4