#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

template <typename T>
class Element
{
    public:
    T data;
    Element<T> *next;

    Element(T d = 0, Element *n = nullptr) : data(d), next(n){}
    ~Element() {next = nullptr;}
};

template <typename T>
class stack
{
public:
    Element<T> *cap;
    stack() : cap(nullptr){}

    void push(T c);
    void pop();
    T top();
    bool isEmpty();
    void printStack();
};


string infixToPostfix(string infix);
bool isOp(char x);
bool isOpLow(char x);
bool isOpHigh(char x);
double solvePostfix(string expresie);

int main()
{
    string infix, postfix;
    
    cout << "Introduceti expresia infixata: ";
    getline(cin, infix);
    //infix = "5+(2*3+4)/(6-4)";
    //raspuns corect postfix: 523*4+64-/+
    //rez calcul: 10

    postfix = infixToPostfix(infix);
    cout << endl << "Expresia postfixata este: " << postfix << endl;

    double rez = solvePostfix(postfix);

    cout << "Rezultatul calculului este: " << rez << endl;

    return 0;
}


template <typename T>
void stack<T>::push(T c)
{
    Element<T> *p = new Element(c);
    if (!cap)
    {
        cap = p;
    }
    else
    {
        p->next = cap;
        cap = p;
    }
}

template <typename T>
void stack<T>::pop()
{
    Element<T> *toDelete = cap;
    cap = cap->next;
    delete toDelete;
    if(!cap)
        cap = nullptr;
}

template <typename T>
T stack<T>::top()
{
    return cap->data;
}

template <typename T>
bool stack<T>::isEmpty()
{
    if (!cap)
    {
        return 1;
    }
    return 0;
}

template <typename T>
void stack<T>::printStack()
{
    Element<T> *temp = cap;
    while(temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}

string infixToPostfix(string infix)
{
    string postfix;
    stack<char> operatori;


    for (int i = 0; i < infix.length(); i++)
    {
        if (isdigit(infix[i]))
        {
            postfix += infix[i];
        }
        else if(infix[i] == ')')
        {
            while (operatori.cap)
            {
                if (operatori.top() == '(')
                {
                    operatori.pop();
                    break;
                }
                postfix += operatori.top();
                operatori.pop();
            }
        }
        else if (isOpLow(infix[i]))
        {
            while (operatori.cap && (isOpHigh(operatori.top()) || isOpLow(operatori.top())))
            {
                postfix += operatori.top();
                operatori.pop();
            }
            operatori.push(infix[i]);
        }
        else if (isOpHigh(infix[i]))
        {
            while (operatori.cap && isOpHigh(operatori.top()))
            {
                postfix += operatori.top();
                operatori.pop();
            }
            operatori.push(infix[i]);
        }
        else    
            operatori.push(infix[i]);
    }
    while (operatori.cap)
    {
        postfix += operatori.top();
        operatori.pop();
    }

    return postfix;
}

bool isOp(char x)
{
    string ops = "+-*/";
    for(int i = 0; i < ops.length(); i++)
    {
        if (x == ops[i])
            return 1;
    }
    return 0;
}

bool isOpLow(char x)
{
    string ops = "+-";
    for (int i = 0; i < ops.length(); i++)
    {
        if (x == ops[i])
            return 1;
    }
    return 0;
}

bool isOpHigh(char x)
{
    string ops = "*/";
    for (int i = 0; i < ops.length(); i++)
    {
        if (x == ops[i])
            return 1;
    }
    return 0;
}


double solvePostfix(string expresie)
{
    stack<double> rez;

    for(int i = 0; i < expresie.length(); i++)
    {
        if(isdigit(expresie[i]))
        {
            rez.push(expresie[i] - '0');
        }
        else if (isOp(expresie[i]))
        {
            double y = rez.top();
            rez.pop();
            double x = rez.top();
            rez.pop();
            double aux;

            switch (expresie[i])
            {
            case '+':
                aux = x + y;
                break;          
            case '-':           
                aux = x - y;
                break;        
            case '*':                
                aux = x * y;
                break;            
            case '/':                
                aux = x / y;
                break;                        
            default:
                break;
            }
            
            rez.push(aux);
        }
    }

    return rez.top();
}
