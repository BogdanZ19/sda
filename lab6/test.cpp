#include <iostream>
#include <string>
using namespace std;

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

float solvePrefixRec(string &prefix)
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

int main()
{
    string x = "+5/+*234-64";
    cout << "rez = " << solvePrefixRec(x) << endl;
    return 0;
}