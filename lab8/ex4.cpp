#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define M 23
using namespace std;

struct Node
{
    string key;
    Node *next;
    Node(string k = "", Node *n = nullptr) : key(k), next(n) {}
};


int f(string key);
vector<string> getTerms(string str);
void insertNode(Node *hashTable[], string key);
void makeTable(vector<string> terms, Node *hashTable[]);
int countElements(Node *head, string key);
void printList(Node *head, char key);
void printTable(Node *hashTable[], vector<string> uniqueTerms);


//Lorem ipsum dolor sit amet

int main()
{
    string text;
    vector<string> terms;
    vector<string> uniqueTerms;
    Node *hashTable[M] = {nullptr};
    

    cout << "Introduceti textul: ";
    getline(cin, text);
    //carte carte mouse mouse telefon mouse carte laptop monitor tastatura monitor carte telefon
    terms = getTerms(text);
    makeTable(terms, hashTable);

    uniqueTerms = terms;
    sort(uniqueTerms.begin(), uniqueTerms.end());
    auto it = unique(uniqueTerms.begin(), uniqueTerms.end());
    uniqueTerms.resize(distance(uniqueTerms.begin(), it));

    printTable(hashTable, uniqueTerms);

    return 0;
}

int f(string key)
{
    int h = 0;
    
    for (char c : key)
    {
        h += tolower(c);
    }
    
    return h % M;
}

vector<string> getTerms(string str)
{
    vector<string> terms;
    string word;
    int i = 0;

    for (char c : str)
    {
        if (c == ' ')
        {
            terms.push_back(word);
            word = "";
        }
        else
        {
            word += tolower(c);
        }
    }
    return terms;
}

void insertNode(Node *hashTable[], string key)
{
    Node *newNode = new Node(key);
    int idx = f(key);
    Node* current = hashTable[idx];

    if (hashTable[idx] == nullptr)
    {
        hashTable[idx] = newNode;
    }
    else
    {
        while(current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void makeTable(vector<string> terms, Node *hashTable[])
{
    for(string word : terms)
    {
        insertNode(hashTable, word);
    }
}

int countElements(Node *head, string key)
{
    int count = 0;
    while (head)
    {
        if (head->key == key)
            count++;
        head = head->next;
    }
    return count;
}

void printList(Node *head, string key)
{
    int count = 0;
    count = countElements(head, key);

    if (count != 0)
        cout << key << " " << count << endl;
}

void printTable(Node *hashTable[], vector<string> uniqueTerms)
{
    Node *current;
    for (string word : uniqueTerms)
    {
        int x = f(word);
        if (hashTable[x] != nullptr)
        {
            printList(hashTable[x], word);
        }
    }
}