#include <iostream>
#include "Arbore.h"
using namespace std;

void afisareInordine(Nod *root);
void afisarePreordine(Nod *root);
void afisarePostordine(Nod *root);
int getHeight(Nod *root);
int getNodeCount(Nod *root);
int getLeafCount(Nod *root);
char rootGreaterThanSubTree(Nod *root);
char maxInSubtree(Nod* root);
char minInSubtree(Nod* root);
void leftSubLesserThanRight(Nod *root);

int main()
{
	Nod *root = creareArbore();

	cout << endl
		 << "Inordine" << endl;
	afisareInordine(root);
	cout << endl;

	cout << endl
		 << "Preordine: " << endl;
	afisarePreordine(root);
	cout << endl;

	cout << endl
		 << "Postordine: " << endl;
	afisarePostordine(root);
	cout << endl;

	cout << endl << "Adancimea = " << getHeight(root) << endl;
	cout << "Nr de noduri = " << getNodeCount(root) << endl;
	cout << "Nr frunze = " << getLeafCount(root) << endl;

	
	cout << "F) ";
	rootGreaterThanSubTree(root);
	cout << endl;

	cout << "G) ";
	leftSubLesserThanRight(root);
	cout << endl;

	return 0;
}

void afisareInordine(Nod *root)
{
	if (!root)
		return;
	afisareInordine(root->stg);
	cout << root->data;
	afisareInordine(root->drt);
}

void afisarePreordine(Nod *root)
{
	if (!root)
		return;
	cout << root->data;
	afisarePreordine(root->stg);
	afisarePreordine(root->drt);
}

void afisarePostordine(Nod *root)
{
	if (!root)
		return;
	afisarePostordine(root->stg);
	afisarePostordine(root->drt);
	cout << root->data;
}

int getHeight(Nod *root)
{
	if (!root)
		return 0;
	int hLeft = getHeight(root->stg);
	int hRight = getHeight(root->drt);

	return 1 + max(hLeft, hRight);
}

int getNodeCount(Nod *root)
{
	if (!root)
		return 0;

	return 1 + getNodeCount(root->stg) + getNodeCount(root->drt);
}

int getLeafCount(Nod *root)
{
	if (!root)
		return 0;

	if (root->stg == nullptr && root->drt == nullptr)
		return 1;
	
	return getLeafCount(root->stg) + getLeafCount(root->drt);
}

char rootGreaterThanSubTree(Nod *root)
{
	if (!root)
		return 0;

	char leftMax = rootGreaterThanSubTree(root->stg);
	char rightMax = rootGreaterThanSubTree(root->drt);

	
	if (root->data > leftMax && root->data > rightMax &&
		(leftMax != 0 || rightMax != 0))
	{
		cout << root->data << "\t";
	}

	return max(root->data, max(leftMax, rightMax));
}

char maxInSubtree(Nod* root)
{
    if (!root)
        return 0; 

    char leftMax = maxInSubtree(root->stg);
    char rightMax = maxInSubtree(root->drt);

    return max(root->data, max(leftMax, rightMax));
}

char minInSubtree(Nod* root)
{
    if (!root)
        return 'Z' + 1; // higher than any letter

    char leftMin = minInSubtree(root->stg);
    char rightMin = minInSubtree(root->drt);

    return min(root->data, min(leftMin, rightMin));
}

void leftSubLesserThanRight(Nod *root)
{
	if (!root)
		return;
	
	if (root->stg && root->drt)
	{
		char leftMax = maxInSubtree(root->stg);
		char rightMin = minInSubtree(root->drt);

		if (leftMax < rightMin)
		{
			cout << root->data << "\t";
		}
	}
	leftSubLesserThanRight(root->stg);
	leftSubLesserThanRight(root->drt);
}

// A(B(-,D),C(E,F))
// A(B(-,D),C(E(-,K),F))
// C(E(B,D),F(A,-))
// J(H(F(B,G),I),L(K,T(P,X)))
