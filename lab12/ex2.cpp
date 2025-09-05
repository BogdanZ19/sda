#include <iostream>
#include <vector>

using namespace std;

void citireGraf(int **graf);
void afisareGraf(int **graf, int n);
void dfsRecursiv(int **graf, int n, vector<int> &L, int *M, int i);

int main()
{
    int n, i;
    vector<int> L;
    cout << "Cate noduri are graful? ";
    cin >> n;
    n++;
    int *M = new int[n]{0};
    int **graf = new int *[n];

    for (int i = 0; i < n; i++)
    {
        graf[i] = new int[n]{0};
    }

    citireGraf(graf);

    cout << endl << "Nodul de la care incepe parcurgerea: ";
    cin >> i;
    dfsRecursiv(graf, n, L, M, 1);
    
    cout << endl;
    for (int i = 0; i < n-1; i++)
    {
        cout << L[i] << "\t";
    }
    cout << endl;
    

    return 0;
}

void citireGraf(int **graf)
{
    cout << "Introduceti legaturile grafului: (Nod1 Nod2) -> (-1 = exit)" << endl;
    int nod1, nod2;
    int k = 0;

    while (1)
    {
        cout << "legatura: ";
        cin >> nod1;
        if (nod1 == -1)
            break;
        cin >> nod2;
        if (nod2 == -1)
            break;

        graf[nod1][nod2] = 1;
    }
}

void dfsRecursiv(int **graf, int n, vector<int> &L, int *M, int i)
{
    L.push_back(i);
    M[i] = 1;
    
    for(int j = 1; j <= n; j++)
    {
        if (graf[i][j] != 0 && M[j] == 0)
        {
            dfsRecursiv(graf, n, L, M, j);
        }
    }
}


// 1 2 1 3 2 4 2 5 3 5 4 1 4 7 5 4 5 6 5 7 6 7 7 5 -1




























