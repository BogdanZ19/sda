#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

template <typename T>
class Element
{
public:
    T data;
    Element *next;

    Element(T d = 0, Element *n = nullptr) : data(d), next(n) {}
    ~Element() { next = nullptr; }
};

template <typename T>
class stack
{
public:
    Element<T> *cap;
    stack() : cap(nullptr) {}

    void push(T data);
    void pop();
    T top();
    bool isEmpty();
};

double solvePrefixRec(string &prefix);
string postToPrefix(string postfix);
double solvePrefix(string prefix);


int main()
{
    string prefix, postfix;

    //a
    cout << "a)" << endl << "Introduceti o forma prefixata pentru calcul recursiv: ";
    getline(cin, prefix);
    // prefix = "+5/+*234-64";
    //rez = 10
    cout << "Rezultatul formei prefixate este: " << solvePrefixRec(prefix) << endl;

    //b
    cout << "b)" << endl << "Introduceti o forma postfixata: ";
    getline(cin, postfix);
    // postfix = "523*4+64-/+";
    cout << "Rezultatul transformarii in forma prefixata este: " << postToPrefix(postfix) << endl;

    //c
    cout << "c)" << endl << "Introduceti o forma prefixata: ";
    getline(cin, prefix);
    // prefix = "+5/+*234-64";
    cout << "Rezultatul formei prefixate este: " << solvePrefix(prefix) << endl;
    
    return 0;
}

template <typename T>
void stack<T>::push(T data)
{
    Element<T> *p = new Element(data);

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
        return 1;
    return 0;
}

bool isOp(char x)
{
    string ops = "+-*/";
    for (int i = 0; i < ops.length(); i++)
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

double solvePrefixRec(string &prefix)
{
    if (prefix.empty()) 
        return 0;
    char ch = prefix[0];

    prefix = prefix.substr(1);

    if (isdigit(ch))
        return ch - '0';

    if (isOp(ch))
    {
        double x = solvePrefixRec(prefix);
        double y = solvePrefixRec(prefix);
        double aux;
        switch (ch)
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
        return aux;
    }
    return 0;
}


string postToPrefix(string postfix)
{
    string prefix;
    stack<string> s;

    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOp(postfix[i]))
        {
            string y = s.top();
            s.pop();
            string x = s.top();
            s.pop();
            string aux = postfix[i] + x + y;
            s.push(aux);
        }
        else
        {
            s.push(string(1, postfix[i]));
        }
    }

    while (s.cap)
    {
        prefix += s.top();
        s.pop();
    }

    return prefix;
}

double solvePrefix(string prefix)
{
    stack<double> rez;

    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isdigit(prefix[i]))
        {
            rez.push(prefix[i] - '0');
        }
        else if (isOp(prefix[i]))
        {
            double x = rez.top();
            rez.pop();
            double y = rez.top();
            rez.pop();
            double aux;

            switch (prefix[i])
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

