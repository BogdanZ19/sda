#include <iostream>
#include "lista.h"
using namespace std;

void InitLista(Elem *&p)
{
	p = nullptr;
}

void InsertFata(Elem *&p, int val)
{
	Elem *newHead = new Elem(val);
	if (!p)
	{
		p = newHead;
	}
	else
	{
		newHead->next = p;
		p = newHead;
	}
}

void AfisLista(Elem *p)
{
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void CitElemente(Elem *&p)
{
	int n;
	cout << "Introduceti elementele listei: ";
	cin >> n;

	while (n != 0)
	{
		InsertFata(p, n);
		cin >> n;
	}
}

void CautaVal(Elem *p)
{
	if (!p)
	{
		cout << "Lista in care doriti sa cautati nu exista." << endl;
		return;
	}

	int val;
	bool found = 0;
	cout << "Introduceti valoarea cautata: ";
	cin >> val;

	while (p)
	{
		if (p->data == val)
		{
			found = 1;
			break;
		}
		p = p->next;
	}
	if (found)
		cout << "Valoarea " << val << " este in lista!" << endl;
	else	
		cout << "Valoarea " << val << " nu este in lista!" << endl;
}

void DelElem(Elem *&p)
{
	if (!p)
	{
		cout << "Lista din care vreti sa stergeti nu exista" << endl;
		return;
	}
	int n, idx = 1;
	cout << "Introduceti pozitia elementului de sters: ";
	cin >> n;
	
	if (n == 1)
	{
		Elem *toDelete = p;
		p = p->next;
		delete toDelete;
		return;
	}

	Elem *current = p;
	while (idx != n-1)
	{
		if (current->next)
		{
			current = current->next;
			++idx;
		}
		else
		{
			cout << "Pozitida de sters nu exista" << endl;
			return;
		}
	}
	Elem *toDelete = current->next;
	current->next = current->next->next;
	delete toDelete;
}
