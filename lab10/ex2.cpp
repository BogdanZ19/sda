#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *lChild;
    Node *rChild;
    Node(int d = 0, Node *lc = nullptr, Node *rc = nullptr) : data(d), lChild(lc), rChild(rc) {}
};

void insertNode(Node *&root, int a);
void readBST(Node *&root);
void afisareInordine(Node *root);
bool searchBST(Node *root, int val);
Node *removeGreatest(Node *&root);
void deleteNode(Node *&root, int d);

int main()
{
    Node *root = nullptr;
    int x, y;

    readBST(root);
    cout << endl << "Inordine: ";
    afisareInordine(root);
    cout << endl;

    cout << endl << "Ce valoare cautati? ";
    cin >> x;
    cout << (searchBST(root, x) ? "Nr cautat apartine arborelui" : "Numarul cautat nu apartine arborelui") << endl << endl;

    cout << "Ce valoare eliminati? ";
    cin >> y;
    deleteNode(root, y);
    cout << "Inordine dupa delete: ";
    afisareInordine(root);
    cout << endl;

    return 0;
    // 20 13 45 5 17 33 90 15 40 0
}

void insertNode(Node *&root, int a)
{
    if (root == nullptr)
    {
        root = new Node(a);
        return;
    }
    Node *p = root;
    Node *current = nullptr;
    while (p != nullptr)
    {
        current = p;
        if (a < p->data)
        {
            p = p->lChild;
        }
        else if (a > p->data)
        {
            p = p->rChild;
        }
    }

    if (a < current->data)
    {
        current->lChild = new Node(a);
    }
    else if (a > current->data)
    {
        current->rChild = new Node(a);
    }
}

void readBST(Node *&root)
{
    int d;

    cout << "Introduceti arborele (0 = exit):" << endl;
    cin >> d;

    while (d != 0)
    {
        insertNode(root, d);
        cin >> d;
    }
}

void afisareInordine(Node *root)
{
    if (!root)
        return;
    afisareInordine(root->lChild);
    cout << root->data << "   ";
    afisareInordine(root->rChild);
}

bool searchBST(Node *root, int val)
{
    while (root != nullptr && root->data != val)
    {
        if (val < root->data)
        {
            root = root->lChild;
        }
        if (root != nullptr && val > root->data)
            root = root->rChild;
    }
    if (root != nullptr && root->data == val)
        return 1;
    return 0;
}

Node *removeGreatest(Node *&root)
{
    Node *current = root;
    Node *p = nullptr;
    Node *parent = nullptr;

    while (current->rChild != nullptr)
    {
        parent = current;
        current = current->rChild;
    }

    p = current;
    parent->rChild = current->lChild;

    return p;
}
void deleteNode(Node *&root, int d)
{
    Node *current = root;
    Node *toDelete = nullptr;
    Node *parent = nullptr;

    while (current != nullptr && current->data != d)
    {
        parent = current;    
        if (d < current->data)
            current = current->lChild;
        if (current != nullptr && d > current->data)
            current = current->rChild;
    }

    if (current != nullptr && current->data == d)
    {
        if (current->lChild == nullptr)
        {
            current = current->rChild;
        }
        else if (current->rChild == nullptr)
        {
            current = current->lChild;
        }
        else
        {
            toDelete = current;
            current = removeGreatest(current->lChild);
            current->lChild = toDelete->lChild;
            current->rChild = toDelete->rChild;
        }

        delete toDelete;
        if (current->data < parent->data)
        {
            parent->lChild = current;
        }
        else if (current->data > parent->data)
        {
            parent->rChild = current;
        }
    }
    else
    {
        cout << "valoarea de sters nu a fost gasita" << endl;
        return;
    }
}