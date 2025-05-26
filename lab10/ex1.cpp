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
void afisarePreordine(Node *root);
void afisarePostordine(Node *root);
bool searchBST(Node *root, int d);
Node *removeGreatest(Node *&root);
void deleteNode(Node *&root, int d);

int main()
{
    Node *root = nullptr;
    int x, y;

    readBST(root);
    cout << "Preordine: ";
    afisarePreordine(root);
    cout << endl << "Inordine: ";
    afisareInordine(root);
    cout << endl << "Postordine: ";
    afisarePostordine(root);
    cout << endl;

    cout << endl << "Ce valoare cautati? ";
    cin >> x;
    cout << (searchBST(root, x)? "Nr cautat apartine arborelui" :
    "Numarul cautat nu apartine arborelui") << endl << endl;

    cout << "Ce valoare eliminati? ";
    cin >> y;
    deleteNode(root, y);
    cout << "Inordine dupa delete: ";
    afisareInordine(root);
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
    else if (a < root->data)
    {
        insertNode(root->lChild, a);
    }
    else if (a > root->data)
    {
        insertNode(root->rChild, a);
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

void afisarePreordine(Node *root)
{
    if (!root)
        return;
    cout << root->data << "   ";
    afisarePreordine(root->lChild);
    afisarePreordine(root->rChild);
}

void afisarePostordine(Node *root)
{
    if (!root)
        return;
    afisarePostordine(root->lChild);
    afisarePostordine(root->rChild);
    cout << root->data << "   ";
}

bool searchBST(Node *root, int d)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->data == d)
    {
        return 1;
    }
    else if (d < root->data)
    {
        return searchBST(root->lChild, d);
    }
    else if (d > root->data)
    {
        return searchBST(root->rChild, d);
    }
    return 0;
}
Node *removeGreatest(Node *&root)
{
    Node *p;
    if (root->rChild == nullptr)
    {
        p = root;
        root = root->lChild;
        return p;
    }
    else
        return removeGreatest(root->rChild);
}

void deleteNode(Node *&root, int d)
{
    Node *p = root;
    if (root == nullptr)
    {
        cout << "valoarea de sters nu a fost gasita" << endl;
        return;
    }

    if (root->data != d)
    {
        if (d < root->data)
            return deleteNode(root->lChild, d);
        if (d > root->data)
            return deleteNode(root->rChild, d);
    }

    if (root->lChild == nullptr)
    {
        root = root->rChild;
    }
    else if (root->rChild == nullptr)
    {
        root = root->lChild;
    }
    else
    {
        root = removeGreatest(root->lChild);
        root->lChild = p->lChild;
        root->rChild = p->rChild;
    }
    delete p;
}
