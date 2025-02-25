#include <iostream>
#include "sortingAlg.h"

void bubbleSort(int x[], int n, int& k)
{
    bool swapped = true;
    k = 0;

    for (int i = 0; i < n - 1; i++)
    {
        k++;
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            k++;
            if (x[j] > x[j + 1])
            {
                int aux = x[j];
                x[j] = x[j + 1];
                x[j + 1] = aux;

                swapped = true;
            }
        }

        if (!swapped )
        {
            break;
        }
    }
}


void selectionSort(int x[], int n, int& k)
{
    k = 0;
    for (int i = 0; i < n - 1; i ++)
    {
        k++;
        int min = i;
        for (int j = i + 1; j < n ; j++)
        {
            k++;
            if (x[j] < x[min])
            {
                min = j;
            }
        }

        int aux = x[i];
        x[i] = x[min];
        x[min] = aux;
    }
}

void insertionSort(int x[], int n, int &k)
{
    k = 0;
    for (int i = 1; i < n; i++)
    {
        k++;
        int key = x[i];
        int j = i - 1;

        while (j >= 0 && x[j] > key)
        {
            k++;
            x[j + 1] = x[j];
            --j;
        }
        x[j + 1] = key;
    }
}

bool bruteForceSrch(int x[], int n, int src, int &k)
{
    int i = 0;
    k = 0;

    while(i < n)
    {
        k++;
        i++;
        if (x[i] == src)
            return true;
        
    }
    return false;
}

int binarySrch(int x[], int n, int src, int &k)
{
    int low = 0;
    int high = n-1;
    k = 0;

    while (low <= high)
    {
        k++;
        int mid = low + (high - low) / 2;

        if (x[mid] == src)
        {
            return mid;
        }
        else if (src < x[mid])
        {
            high = mid-1;
        }
        else
            low = mid + 1;
    }
    
    return -1;
}

void afisare(int x[], int n)
{
    for (int i = 0; i < n; i ++)
    {
        std::cout << x[i] << "\t";
    }
    std::cout << std::endl;
}

int *copyArr(int x[], int n)
{
    int* newArr = new int[n];

    for(int i = 0; i < n; i++)
    {
        newArr[i] = x[i];
    }

    return newArr;
}