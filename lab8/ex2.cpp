#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#define M 41

using namespace std;
struct Node
{
    string key;
    Node *next;
    Node(string k = "", Node *n = nullptr) : key(k), next(n) {}
};

int f(string key);
vector<string> getTerms(ifstream &termDict);
void insertNode(Node *hashTable[], string key);
void makeTable(vector<string> dictVect, Node *hashTable[]);
double gradClusterizare(Node *hashTable[], int nr);

int main()
{
    Node *hashTable[M] = {nullptr};
    ifstream termDict("dictionar_termeni_PC.txt");
    vector<string> terms = getTerms(termDict);

    makeTable(terms, hashTable);

    cout << "Gradul de clusterizare = " << gradClusterizare(hashTable, 87.0) << endl;

    return 0;
}

// factor incarcare = N / M
// fi apartine [0.5, 2]

int f(string key)
{ 
    // // MODUL
    // int sum = 0;

    for (int i = 0; i < key.length(); i++)
    {
        key[i] = tolower(key[i]);
    }

    // for (int i = 0; i < key.length(); i++)
    // {
    //     if (key[i] == ' ')
    //         continue;
    //     sum = sum + key[i];
    // }
    // return sum % M;

    // INMULTIRE
    unsigned long long h = 5381;
    for (char c : key)
    {
        h = h * 33 + c; 
    }
    return h % M; 


    // // DEPLASARE PE BITI
    // int h = 0;

    // for (int i = 0; i < key.length(); i++)
    // {
    //     int highorder = h & 0xf8000000;
    //     h << 5;
    //     h = (h ^ highorder >> 27);

    //     h = h ^ key[i];
    // }

    // return h % M;
}

vector<string> getTerms(ifstream &termDict)
{
    vector<string> dictVect;
    string line;
    int i = 0;
    if (termDict.is_open())
    {
        while (getline(termDict, line))
        {
            line.pop_back();
            dictVect.push_back(line);
        }
        termDict.close();
    }
    else
        cout << "EROARE DESCHIDERE FISIER" << endl;

    return dictVect;
}

void insertNode(Node *hashTable[], string key)
{
    Node *newNode = new Node(key);
    int idx = f(key);
    Node *temp = hashTable[idx];

    if (hashTable[idx] == nullptr)
    {
        hashTable[idx] = newNode;
    }
    else
    {
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void makeTable(vector<string> dictVect, Node *hashTable[])
{
    for (auto key : dictVect)
    {
        key.erase(remove(key.begin(), key.end(), ' '), key.end());
        insertNode(hashTable, key);
    }
}

// REMote hardware save run tasK nu stiu ce sa mai zic

double gradClusterizare(Node *hashTable[], int nr)
{
    double alpha = (double)nr / M;
    int count;
    double rez = 0.0;
    for (int i = 0; i < M; i++)
    {
        count = 0;
        while (hashTable[i])
        {
            hashTable[i] = hashTable[i]->next;
            count++;
        }
        rez += ((count * count) / (double)nr);
    }
    return rez - alpha;
}
