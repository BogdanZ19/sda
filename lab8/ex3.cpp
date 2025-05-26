#include <iostream>
#include <string>
#include <vector>
#define M 23
using namespace std;

struct Node
{
    char key;
    Node *next;
    Node(char k = 0, Node *n = nullptr) : key(k), next(n) {}
};


int f(char key);
vector<char> getTerms(string str);
void insertNode(Node *hashTable[], char key);
void makeTable(vector<char> terms, Node *hashTable[]);
int countElements(Node *head, char key);
void printList(Node *head, char key);
void printTable(Node *hashTable[]);

//Lorem ipsum dolor sit amet

int main()
{
    string text;
    vector<char> terms;
    Node *hashTable[M] = {nullptr};

    cout << "Introduceti textul: ";
    getline(cin, text);

    terms = getTerms(text);
    
    makeTable(terms, hashTable);
    printTable(hashTable);

    return 0;
}

int f(char key)
{
    int h = 0;
    char c = tolower(key);
    
    h += c;
    
    return h % M;
}

vector<char> getTerms(string str)
{
    vector<char> terms;
    int i = 0;

    for (char c : str)
    {
        if (c == ' ')
            continue;
        terms.push_back(c);
    }
    return terms;
}

void insertNode(Node *hashTable[], char key)
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

void makeTable(vector<char> terms, Node *hashTable[])
{
    for(char c : terms)
    {
        insertNode(hashTable, c);
    }
}

int countElements(Node *head, char key)
{
    int count = 0;
    while (head)
    {
        if (head->key == key || head->key == toupper(key))
            count++;
        head = head->next;
    }
    return count;
}

void printList(Node *head, char key)
{
    int count = 0;
    count = countElements(head, key);

    if (count != 0)
        cout << key << (char)toupper(key) << " " << count << endl;
}

void printTable(Node *hashTable[])
{
    Node *current;
    for (char i = 'a'; i < 'z'; i++)
    {
        int x = f(i);
        if (hashTable[x] != nullptr)
        {
            printList(hashTable[x], i);
        }
    }
}