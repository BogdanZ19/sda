#include <iostream>
using namespace std;

int f(int x)
{
    if(x <= 1)
        return 0;
    return f(x-2) + x;
}



int main()
{
    std::cout << f(6) << endl;
    return 0;
}