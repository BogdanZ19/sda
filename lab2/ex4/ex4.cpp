#include <iostream>

void bubbleSort(int x[], int n);
int* binarySearch(int x[], int nl, int nc, int src);
void afisare(int *a, int nl, int nc);

int main()
{
    int nrL = 5, nrC = 7;
    int a[nrL * nrC];
    int *rez;

    for (int i = 0; i < nrL; i++)
    {
        for (int j = 0; j < nrC; j++)
        {
            a[i * nrC + j] = rand() % 100 + 1;
        }
    }

    bubbleSort(a, nrL * nrC);
    afisare(a, nrL, nrC);
    std::cout << std::endl;

    int deCautat = 63;
    rez = binarySearch(a, nrL, nrC, deCautat);

    if (rez != nullptr)
        std::cout << deCautat << " s-a gasit prima data in matrice pe pozitia: a[" << rez[0] << "]" << "[" << rez[1] << "]" << std::endl;
    else
        std::cout << deCautat << " nu s-a gasit in matrice" << std::endl;

    delete[] rez;
    return 0;
}

void bubbleSort(int x[], int n)
{
    bool swapped = true;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (x[j] > x[j + 1])
            {
                int aux = x[j];
                x[j] = x[j + 1];
                x[j + 1] = aux;

                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

// a[i * nrc + j]
// 0 1 2
// 3 4 5
// 6 7 8

// 00 01 02
// 10 11 12
// 20 21 22

// mid = index nu valoare

// mid = i * nc + j;

int* binarySearch(int x[], int nl, int nc, int src)
{
    int low = 0, mid = 0, high = nl * nc;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        int i = mid / nc; 
        int j = mid % nc; 

        if (src == x[mid])
        {
            int *rez = new int[2];

            rez[0] = i;
            rez[1] = j;

            return rez;
        }
        else if (src > x[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return nullptr;
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

