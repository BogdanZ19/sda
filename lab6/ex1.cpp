#include <iostream>

#define DIM_MAX 10

struct Stiva
{
    int vf;
    int vect[DIM_MAX] = {0};
};

void init(Stiva &s);
void push(Stiva &s, int el);
void pop(Stiva &s);
int top(const Stiva &s);
bool isEmpty(const Stiva &s);
bool isFull(const Stiva &s);
void afisareStiva(const Stiva &s);

int main()
{
    Stiva s;

    init(s);

    std::cout << (isEmpty(s)? "Stiva este goala" : "Stiva nu este goala") << std::endl;
    push(s, 13);
    push(s, 27);
    push(s, 19);

    std::cout << "In varful listei este el: " << top(s) << std::endl;
    pop(s);

    afisareStiva(s);

    push(s, 24);
    push(s, 83);
    push(s, 56);
    push(s, 31);
    push(s, 14);
    push(s, 73);
    push(s, 91);
    push(s, 38);

    std::cout << (isFull(s)? "Stiva este plina" : "Stiva nu este plina") << std::endl;
    return 0;
}

void init(Stiva &s)
{
    s.vf = 0;
}

void push(Stiva &s, int el)
{
    if (s.vect[s.vf] == 0)
    {
        s.vect[s.vf] = el;   
            return;
    }
    s.vf++;
    s.vect[s.vf] = el;
}

//13 0 0 0 0

void pop(Stiva &s)
{
    s.vect[s.vf] = 0;
    s.vf--;
}

int top(const Stiva &s)
{
    return s.vect[s.vf];
}

bool isEmpty(const Stiva &s)
{
    if(s.vect[0] == 0)
        return 1;
    return 0; 
}

bool isFull(const Stiva &s)
{
    if(s.vect[DIM_MAX-1] != 0)
        return 1;
    return 0;
}

void afisareStiva(const Stiva &s)
{
    int i = 0;
    while (s.vect[i] != 0)
    {
        std::cout << s.vect[i] << "\t";
        i++;
    }
    std::cout << std::endl;
}
