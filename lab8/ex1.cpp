#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#define M 47

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
void printList(Node *head);
void printHashTable(Node *hashTable[]);
bool isMember(string str, Node *hashTable[]);
void testText(string text, Node *hashTable[]);
string toLowerStr(string s);

int main()
{
    Node *hashTable[M];
    ifstream termDict("dictionar_termeni_PC.txt");
    vector<string> terms = getTerms(termDict);
    string deTestat;

    double fi = 87 / 47.0;
    cout << fi << endl;

    makeTable(terms, hashTable);
    printHashTable(hashTable);

    cout << "Introduceti propozitia de testat: " << endl;
    getline(cin, deTestat);

    testText(deTestat, hashTable);
    
    return 0;
}

// factor incarcare = N / M
// fi apartine [0.5, 2]

int f(string key)
{
    int sum = 0;

    for (int i = 0; i < key.length(); i++)
    {
        key[i] = tolower(key[i]);
    }

    for (int i = 0; i < key.length(); i++)
    {
        if (key[i] == ' ')
            continue;
        sum = sum + key[i];
    }
    return sum % M;
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
            line = toLowerStr(line);
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

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->key << "   ";
        head = head->next;
    }
    cout << endl;
}

void printHashTable(Node *hashTable[])
{
    for (int i = 0; i < M; i++)
    {
        if (hashTable[i] != nullptr)
        {
            printList(hashTable[i]);
        }
    }
}

bool isMember(string str, Node *hashTable[])
{
    int idx = f(str);
    Node *temp = hashTable[idx];

    if (!temp)
        return 0;

    while (temp)
    {
        if (temp->key == str)
        {
            return 1;
        }
        temp = temp->next;
    }
    
    return 0;
}

void testText(string text, Node *hashTable[])
{
    string word;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ')
            word += tolower(text[i]);
        else if (text[i] == ' ')
        {
            cout << "Cuvantul \"" << word << (isMember(word, hashTable)? "\" apartine " : "\" nu apartine ") 
            << "dictionarului" << endl;
            word = "";
        }
    }
    if(!word.empty())
    {
        cout << "Cuvantul \"" << word << (isMember(word, hashTable)? "\" apartine " : "\" nu apartine ") 
        << "dictionarului" << endl;
        word = "";
    }
}

string toLowerStr(string s)
{
    string str;
    for (char c : s)
    {
        str += tolower(c);
    }
    return str;
}
