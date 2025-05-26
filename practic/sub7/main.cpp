#include <iostream>
#include "coada.h"
using namespace std;

int main(void)
{
    Coada *c1, *c2; 
    Init(c1);
    Init(c2);
    
    for (int i = 1; i <= 10; i++)
    {
        int n;
        cout << "Introduceti numarul " << i << ": ";
        cin >> n;

        if(n > 0)
        {
            Put(c1, n);
        }
        else if (n < 0)
        {
            Put(c2, abs(n));
        }
        else if (n == 0)
        {
            Get(c1);
            Get(c2);
        }

        cout << "c1" << ": ";
        Display(c1);
        cout << "c2" << ": ";
        Display(c2);

        if (areEqual(c1, c2))
        {
            cout << "*************** Cozi egale! ***************" << endl;
        }
    }

    return 0;
}