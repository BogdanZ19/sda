#include <iostream>
using namespace std;

struct Element
{
    int data;
    Element *next;
    Element(int d = 0, Element *n = nullptr) : data(d), next(n) {}
};



void addLaFinal(Element *&cap, int val);
void creareLista(Element *&cap);
void afisareLista(Element *cap);

int main()
{
    Element *cap = nullptr;
    int n;

    cout << "Introduceti elementele listei: " << endl;
    creareLista(cap);
    afisareLista(cap);

    return 0;
}

void addLaFinal(Element *&cap, int val)
{
    if (!cap)
    {
        cap = new Element(val);
    }
    else
    {
        addLaFinal(cap->next, val);
    }
}

void creareLista(Element *&cap)
{
    int val;
    cin >> val;

    if (val != 0)
    {
        addLaFinal(cap, val);
        creareLista(cap);
    }
}

void afisareLista(Element *cap)
{
    if(!cap)
        return;
    afisareLista(cap->next);
    cout << cap->data << "\t";
}
