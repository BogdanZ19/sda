#include <iostream>
#include <chrono>

using namespace std;
static int v[50];

int Fibonnaci(int n)
{
    if (n < 2)
        return n;
    return Fibonnaci(n - 1) + Fibonnaci(n - 2);
}

int FibTablou(int n, int arr[])
{
    if (n < 2)
    {
        return n;
    }

    arr[n] = FibTablou(n - 1, arr) + FibTablou(n - 2, arr);

    return arr[n];
}

int FibIterativ(int n)
{
    int v[50] = {};
    int i;

    for (i = 0; i < n; i++)
    {
        if (i < 2)
            v[i] = 1;
        else
            v[i] = v[i-1] + v[i-2];
    }
    
    return v[i-1];
}

int main()
{
    int arr[50] = {};
    chrono::time_point<chrono::system_clock> start, end;

    cout << "Fibonnaci recursiv" << endl;
    start = chrono::system_clock::now();
    cout << Fibonnaci(35) << endl;
    end = chrono::system_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl << endl;

    cout << "Fibonnaci recursiv optimizat cu array" << endl;
    start = chrono::system_clock::now();
    cout << FibTablou(35, arr) << endl;
    end = chrono::system_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl << endl;
    
    
    
    cout << "Fibonnaci iterativ" << endl;
    start = chrono::system_clock::now();
    cout << FibIterativ(35) << endl;
    end = chrono::system_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end - start).count() << " us" << endl << endl;

    return 0;
}