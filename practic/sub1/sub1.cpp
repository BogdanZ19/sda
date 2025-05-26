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
void searchNode(Node *head, int val);
void inserareOrdonata(Node *&head, int val);
Node* ordonareLista(Node *head);

int main()
{
    Node *head = nullptr;
    int val;

    creareLista(head);
    cout << "Am citit: ";
    afisareLista(head);

    cout << "Valoarea cautata: ";
    cin >> val;
    searchNode(head, val);

    head = ordonareLista(head);
    cout << "Lista ordonata: ";
    afisareLista(head);

    return 0;
}

void inserareFata(Node *&head, int val)
{
    Node *newHead = new Node(val);

    newHead->next = head;
    head = newHead;
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

void searchNode(Node *head, int val)
{
    bool found = 0;
    while (head)
    {
        if (head->data == val)
        {
            found = 1;
            break;
        }
        else 
            head = head->next;
    }
    if (found)
        cout << "Valoarea " << val << " este in lista!" << endl;
    else
        cout << "Valoarea " << val << " nu este in lista!" << endl;
}

void inserareOrdonata(Node *&head, int val)
{
    
    if (!head || head->data > val)
    {
        inserareFata(head, val);
        return;
    }

    Node *p = new Node(val);
    Node *current = head;
    while (current->next && current->next->data < val)
    {
        current = current->next;
    }
    
    p->next = current->next;
    current->next = p;
}

Node* ordonareLista(Node *head)
{
    Node *newHead = nullptr;

    while(head)
    {
        inserareOrdonata(newHead, head->data);
        head = head->next;
    }

    return newHead;
}
