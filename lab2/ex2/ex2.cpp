#include <iostream>


void sumaPeSectiune(int x[], int n, int j);
void afisare(int x[], int n);

int main()
{
    int nr = 20;
    int x[nr];

    for (int i = 0; i < nr; i++) 
        x[i]= rand() % 100 + 1; 

    afisare(x, nr);

    sumaPeSectiune(x, nr, 4);


    return 0;
}

void sumaPeSectiune(int x[], int n, int j)
{
    int sumaMax = 0;
    int start = 0, end = 0;
    int k = 0;
    

    for(int i = 0; i < n; i = i + j - 1)
    {
        int suma = 0;
        int startAux = 0;
        int endAux = 0;
        for(k = i; k < i+j; k++)
        {
            suma += x[k];
        }
        endAux = k - 1;
        startAux = endAux - j + 1;
        if (suma > sumaMax)
        {
            sumaMax = suma;
            start = startAux;
            end = endAux;
        }
    }

    std::cout << "Suma maxima este: " << sumaMax << " si se afla pe sectiunea: (" << start << ", " << end << ")" << std::endl;
}

void afisare(int x[], int n)
{
    for (int i = 0; i < n; i ++)
    {
        std::cout << x[i] << "\t";
    }
    std::cout << std::endl;
}