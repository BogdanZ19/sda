#include <iostream>
#include <string>
using namespace std;

int main()
{
    string x = "e r a s e";
    x = erase(x, ' ');

    cout << x << endl;

    return 0;
}