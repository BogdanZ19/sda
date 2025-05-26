#include <iostream>
using namespace std;

static int x[50];

void permutari(int n, int k)
{
    if (n == k)
    {
        for (int i = 0; i < n; i++)
            cout << x[i] << " ";
        cout << endl;
    }
    else
    {
        for (int i = k; i < n; i++)
        {
            swap(x[k], x[i]);
            permutari(n, k + 1);
            swap(x[k], x[i]);
        }
    }
}

int main()
{
    int n;
    cout << "Introduceti numarul de elemente: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        x[i] = i + 1;

    permutari(n, 0);

    return 0;
}