#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node *next;
    Node(int d = 0, Node *n = nullptr) : data(d), next(n){};
};

void inserareFata(Node *&head, int val);
void creareLista(Node *&head);
void afisareLista(Node *head);
void cautareVal(Node *head, int val);
void inserareLaPozitie(Node *&head, int val, int poz);

int main ()
{
    Node *head = nullptr;
    int search, toInsert, poz;

    creareLista(head);
    cout << "Am citit: ";
    afisareLista(head);

    cout << "Introduceti valoarea de cautat: ";
    cin >> search;
    cautareVal(head, search);

    cout << "Introduceti valoarea de inserat: ";
    cin >> toInsert;
    cout << "Introduceti pozitia: ";
    cin >> poz;

    inserareLaPozitie(head, toInsert, poz);

    cout << "Lista completa: ";
    afisareLista(head);
    return 0;
}


void inserareFata(Node *&head, int val)
{
    Node *p = new Node(val);
    if (!head)
    {
        head = p;
        return;
    }
    p->next = head;
    head = p;
}

void creareLista(Node *&head)
{
    int n;

    cout << "Introduceti elementele listei: ";
    cin >> n;
    
    while (n != 0)
    {
        inserareFata(head, n);
        cin >> n;
    }
}

void afisareLista(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void cautareVal(Node *head, int val)
{
    bool found = 0;
    while (head)
    {
        if (head->data == val)
        {
            found = 1;
            break;
        }
        head = head->next;
    }
    if (found)
        cout << "Valoarea " << val << " este in lista" << endl;
    else   
        cout << "Valoarea " << val << " nu este in lista" << endl;
}

void inserareLaPozitie(Node *&head, int val, int poz)
{
    if (poz == 1)
    {
        inserareFata(head, val);
        return;
    }
    
    int idx = 1;
    Node *p = new Node(val);
    Node *current = head;

    while (poz-1 != idx)
    {
        current = current->next;
        ++idx;
    }
    p->next = current->next;
    current->next = p;
}
// 5 3 7 10 4 9 1 0