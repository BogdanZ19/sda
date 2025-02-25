#include <iostream>

void afisarePoz(int *a, int nc, int coordLin, int coordCol);
void afisare(int *a, int nl, int nc);
void coordElMax(int *a, int nl, int nc);

int main()
{
    int nl = 3, nc = 4;
    int a[nl*nc];

    for (int i = 0; i < nl; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            a[i * nc + j] = rand() % 100 + 1;
        }
    }

    std::cout << std::endl;
    afisare(a, nl, nc);

    std::cout << std::endl << "Exemplu afisare pozitie: a[1][2] = ";
    afisarePoz(a, nc, 1, 2);

    std::cout << std::endl;
    coordElMax(a, nl, nc);
    

    return 0;
}


void afisarePoz(int *a, int nc, int coordLin, int coordCol)
{
    std::cout << a[coordLin * nc + coordCol] << std::endl;   
}

void afisare(int *a, int nl, int nc)
{
    for (int i = 0; i < nl; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            std::cout << a[i * nc + j] << "\t"; //*(a + (i * nc + j))
        }
        std::cout << std::endl;
    }
}

void coordElMax(int *a, int nl, int nc)
{
    int max = a[0];
    int coordL = 0, coordC = 0;

    for(int i = 0; i < nl; i++)
    {
        for(int j = 0; j < nc; j++)
        {
            if (a[i * nc + j] > max)
            {
                max = a[i * nc + j];
                coordL = i;
                coordC = j;
            }
        }
    }

    std::cout << "Elementul maxim este: a[" << coordL << "][" << coordC << "] = " << max << std::endl;
}