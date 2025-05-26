#include <iostream>
using namespace std;

void citireGraf(int **graf);
void afisareGraf(int **graf, int n);

int main()
{
    int n;
    cout << "Cate noduri are graful? ";
    cin >> n;

    int** graf = new int*[n];
    for (int i = 0; i < n; i++)
    {
        graf[i] = new int[n]{0};
    }

    citireGraf(graf);    
    afisareGraf(graf, n);


    return 0;
}

void citireGraf(int **graf)
{
    cout << "Introduceti legaturile grafului si costul in formatul: (Nod1 Nod2 cost) -> (-1 = exit)" << endl;   
    int nod1, nod2, cost;
    int k = 0;

    while(1)
    {    
        cout << "legatura: ";
        cin >> nod1;
        cin >> nod2; 
        cin >> cost;

        if (nod1 == -1 || nod2 == -1 || cost == -1)
            break;

        graf[nod1][nod2] = cost;
    }
}

void afisareGraf(int **graf, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graf[i][j] << "\t";
        }
        cout << endl;
    }
}