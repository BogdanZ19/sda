#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec = {1,1,1,2,2,2,3,4,5,6,1,1,2,3,4,5,6};

    sort(vec.begin(), vec.end());
    auto it = unique(vec.begin(), vec.end());

    vec.resize(distance(vec.begin(), it));

    for (auto el : vec)
    {
        cout << el << "\t";
    }
    cout << endl;

    return 0;
}