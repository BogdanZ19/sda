#include <iostream>
using namespace std;

struct Element
{
    int data;
    Element* next;
    Element(int d = 0, Element *n = nullptr) : data(d), next(n) {};
};

class List
{    
public:
    Element *head;
    List(Element *h = nullptr) : head(h) {}
    ~List() {head = nullptr;}

    void addElement(int val);
    void createList();
    void printList();
    void reverseList();
};



int main()
{
    List l;

    l.createList();
    l.printList();
    l.reverseList();
    cout << "Dupa inversare: " << endl;
    l.printList();

    return 0;
}

void List::addElement(int val)
{
    Element *newEl = new Element(val);
    if(head)
    {
        newEl->next = head;
        head = newEl;
    }
    else    
        head = newEl;
}

void List::createList()
{
    int n = 0;
    cout << "Introduceti elemente pt lista: (0 = exit)" << endl;
    cin >> n;
    while (n)
    {
        addElement(n);
        cin >> n;
    }
}

void List::printList()
{
    Element *temp = head;    

    while (temp)
    {
        cout << temp->data << "\t";    
        temp = temp->next;
    }
    cout << endl;
}

void List::reverseList()
{
    Element *current = head;
    Element *previous = nullptr;
    Element *following = head;

    while (current)
    {
        following = current->next;
        current->next = previous;
        
        previous = current;
        current = following;
    }
    head = previous;
}
