#include <iostream>
using namespace std;
#define DIMMAX 5

struct Queue {
    int head, tail;
    int data[DIMMAX] = {};
};

void initQueue(Queue &q);
int nextPoz(int index);
void put(Queue &q, int d);
int get(Queue &q);
int front(const Queue &q);
bool isEmpty(const Queue &q);
bool isFull(const Queue &q);

int main()
{
    Queue q1;
    initQueue(q1);
    cout << (isEmpty(q1)? "coada este goala" : "coada nu este goala") << endl;
    put(q1, 5);
    put(q1, 6);
    put(q1, 7);
    put(q1, 8);
    put(q1, 9);
    cout << (isFull(q1)? "coada este plina" : "coada nu este plina") << endl;
    get(q1);
    cout << "Primul la coada este: " << front(q1) << endl;
    return 0;
}

void initQueue(Queue &q)
{
    q.head = 0;
    q.tail = 0;
}

int nextPoz(int index)
{
    if (index < DIMMAX-1)
        return ++index;
    else
        return 0;
}


void put(Queue &q, int d)
{
    if (q.data[q.tail] == 0)
    {
        q.data[q.tail] = d;
    }
    q.tail = nextPoz(q.tail);
}

int get(Queue &q)
{
    int rez = q.data[q.head];
    q.data[q.head] = 0;
    q.head++;

    return rez;
}

int front(const Queue &q)
{
    return q.data[q.head];
}

bool isEmpty(const Queue &q)
{
    if(q.head == q.tail)
        return 1;
    return 0;
}

bool isFull(const Queue &q)
{
    if (nextPoz(q.tail) == q.head)
    {
        return 1;
    }  
    return 0;
}


