#include <iostream>
using namespace std;

struct Element
{
    int data;
    Element *next;

    Element() : data(0), next(nullptr) {};
    Element(int d) : data(d), next(nullptr) {};
    Element(int d, Element *n) : data(d), next(n) {};
};

void creareLista(Element *&cap);
void afisareLista(Element *cap);
void inserareSpate(Element *&cap, Element *&p);
Element *concat(Element *cap1, Element *cap2);
Element *interclasare(Element *cap1, Element *cap2);

int main()
{
    Element *cap1 = nullptr, *cap2 = nullptr, *cap3 = nullptr, *cap4 = nullptr;

    cout << "Lista 1:" << endl;
    creareLista(cap1);

    cout << "Lista 2:" << endl;
    creareLista(cap2);

    cout << "Listele introduse" << endl;
    afisareLista(cap1);
    afisareLista(cap2);


    cout << "Dupa concatenare: " << endl;
    cap3 = concat(cap1, cap2);
    afisareLista(cap3);

    cout << "Dupa interclasare: " << endl;
    cap4 = interclasare(cap1, cap2);
    afisareLista(cap4);

    return 0;
}

void creareLista(Element *&cap)
{
    Element *p;
    int n;

    cout << "Introduceti elementele listei (0 = exit):" << endl;
    cin >> n;

    while (n)
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
    Element *p = cap;

    do
    {
        cout << p->data << "\t";
        p = p->next;
    } while (p != cap);

    cout << endl;
}

void inserareSpate(Element *&cap, Element *&p)
{
    p->next = cap->next;
    cap->next = p;
    cap = p;
}

Element *concat(Element *cap1, Element *cap2)
{
    Element *newCap = nullptr;
    Element *start1 = cap1;
    Element *start2 = cap2;
    Element *p = nullptr;

    do
    {
        p = new Element(cap1->data);
        if (!newCap)
        {
            p->next = p;
            newCap = p;
        }
        else
        {
            inserareSpate(newCap, p);
        }

        cap1 = cap1->next;

    } while (cap1 != start1);
               

    do
    {
        p = new Element(cap2->data);
        if (!newCap)
        {
            p->next = p;
            newCap = p;
        }
        else
        {
            inserareSpate(newCap, p);
        }
        
        cap2 = cap2->next;

    } while (cap2 != start2);

    return newCap->next;
}

Element *interclasare(Element *cap1, Element *cap2)
{
    Element *p = nullptr;
    Element *newCap = nullptr;
    Element *start1 = cap1;
    Element *start2 = cap2;
    bool first = true;
    do
    {
        if (cap1 != start1 || first)
        {
            p = new Element(cap1->data);
            if (!newCap)
            {
                p->next = p;
                newCap = p;
            }
            else
            {
                inserareSpate(newCap, p);
            }
            cap1 = cap1->next;
        }
        if (cap2 != start2 || first)
        {
            p = new Element(cap2->data);
            if (!newCap)
            {
                p->next = p;
                newCap = p;
            }
            else
            {
                inserareSpate(newCap, p);
            }
            cap2 = cap2->next;
        }
        first = false;
    }   while (cap1 != start1 || cap2 != start2);
    
    return newCap->next;
}



