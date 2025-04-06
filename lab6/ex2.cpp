#include <iostream>
using namespace std;

struct Element
{
    int data;
    Element* next;

    Element() : data(0), next(nullptr){};
    Element(int d) : data(d), next(nullptr){};
    Element(int d, Element *n) : data(d), next(n){};
};

void init(Element *&cap);
void push(Element *&cap, int val);
void pop(Element *&cap);
void top(Element *cap);
bool isEmpty(Element *cap); 
void afisareStiva(Element *cap);
void afisareRecursiva(Element *cap);

int main()
{
    Element *s;
    init(s);

    std::cout << (isEmpty(s)? "Stiva este goala" : "Stiva nu este goala") << std::endl;

    push(s, 13);
    push(s, 27);
    push(s, 19);

    top(s);

    pop(s);

    afisareStiva(s);

    afisareRecursiva(s);
    cout << endl;
    return 0;
}

void init(Element *&cap)
{
    cap = nullptr;
}

void push(Element *&cap, int val)
{
    Element *p = new Element(val);
    if (!cap)
    {
        cap = p;
        return;
    }

    p->next = cap;
    cap = p;
}

void pop(Element *&cap)
{
    Element *toDelete = cap;
    cap = cap->next;
    delete toDelete;
}

void top(Element *cap)
{
    std::cout << "valTop = " << cap->data << std::endl;
}

bool isEmpty(Element *cap)
{
    if (!cap)
    {
        return 1;
    }

    return 0;
}

void afisareStiva(Element *cap)
{
    while(cap)
    {
        cout << cap->data << "\t";
        cap = cap->next;
    }    
    cout << endl;
}

void afisareRecursiva(Element *cap)
{
    if(!cap)
        return;
    
    
    afisareRecursiva(cap->next);
    std::cout << cap->data << "\t";
}
