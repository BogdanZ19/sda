#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> &maxHeap, int val);



int main()
{
    vector<int> maxHeap;


    return 0;
}


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