#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void insert(vector<int> &maxHeap, int val);
void afisareOrdonata(vector<int> maxHeap);
int getRoot(vector<int> &maxHeap);

int main()
{
    vector<int> maxHeap = {45, 30, 20, 22, 13, 19, 2, 7, 1, 12};

    insert(maxHeap, 50);
    insert(maxHeap, 18);
    insert(maxHeap, 11);
    insert(maxHeap, 23);

    cout << "Afisare Max Heap: " << endl;
    afisareOrdonata(maxHeap);

    cout << "Afisare vector sortat: " << endl;
    while (!maxHeap.empty())
    {
        cout << getRoot(maxHeap) << "\t";
    }

    return 0;
}

// stergere: aduc cea mai mica valoare in root si o duc in jos cu switch-uri

void insert(vector<int> &maxHeap, int val)
{
    maxHeap.push_back(val);
    int current = maxHeap.size() - 1;
    int parent = ((current - 1) / 2);

    while (maxHeap[parent] < maxHeap[current] && parent >= 0)
    {
        swap(maxHeap[parent], maxHeap[current]);
        current = parent;
        parent = ((current - 1) / 2);
    }
}

int getRoot(vector<int> &maxHeap)
{
    int toReturn = maxHeap[0];

    maxHeap[0] = maxHeap[maxHeap.size() - 1];
    maxHeap.pop_back();
    int current = 0;
    int max = 0;
    int size = maxHeap.size();

    while (true)
    {
        int stg = 2 * (current + 1) - 1;
        int drt = 2 * (current + 1);
        max = current;

        if (stg < size && maxHeap[stg] > maxHeap[max])
        {
            max = stg;
        }
        if (drt < size && maxHeap[drt] > maxHeap[max])
        {
            max = drt;
        }

        if (current == max)
        {
            break;
        }

        swap(maxHeap[current], maxHeap[max]);
        current = max;
    }

    return toReturn;
}

void afisareOrdonata(vector<int> maxHeap)
{
    for (int i : maxHeap)
    {
        cout << i << "\t";
    }
    cout << endl;
}
