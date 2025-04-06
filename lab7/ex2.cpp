#include <iostream>
using namespace std;

struct Element
{
    int data;
    Element *next;    

    Element(int d = 0, Element* n = nullptr) : data(d), next(n) {};
    ~Element() {next = nullptr;}
};

class Queue
{
public:
    Element* head;
    Element* tail; 

    Queue(Element *h = nullptr, Element *t = nullptr) : head(h), tail(t) {}

    void initQ();
    void put(int x);
    int get(); 
    int front();
    bool isEmpty();
};


int main()
{
    Queue q;
    
    cout <<  (q.isEmpty()? "Coada este goala" : "Coada nu este goala") << endl;

    q.put(37);
    q.put(56);
    q.put(134);
    
    q.get();

    cout << "Primul el: " << q.front() << endl << "Ultimul el: " << q.tail->data << endl;

    return 0;
}

void Queue::initQ()
{
    head = nullptr;
    tail = nullptr;
}

void Queue::put(int x)
{
    Element *p = new Element(x);
    if (!head)
    {
        head = p;
        tail = p;          
    }
    else
    {
        p->next = head;
        tail->next = p;
        tail = p;
    }
}

int Queue::get()
{
    int toReturn = head->data;
    Element *toDelete = head;
    head = head->next;    

    delete toDelete;
    return toReturn;
}

int Queue::front()
{
   return head->data;
}

bool Queue::isEmpty()
{
    if (!head)
        return 1;
    return 0;        
}

