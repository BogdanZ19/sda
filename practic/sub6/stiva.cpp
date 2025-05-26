#include <iostream>
#include "stiva.h"
#include <vector>
using namespace std;

bool isEmpty(Stiva *&p)
{
	if (!p)
		return true;
	return false;
}

void PushElem(Stiva *&p, Atom data)
{
	Stiva *node = new Stiva(data);
	if (!p)
	{
		p = node;
	}
	else
	{
		node->link = p;
		p = node;
	}
}

Atom PopElem(Stiva *&p)
{
	Atom toReturn = p->data;
	//Stiva *toDelete = p;

	p = p->link;

	//delete toDelete;
	return toReturn;
}

Atom TopElem(Stiva *&p)
{
	return p->data;
}

void initStiva(Stiva *&p)
{
	p = nullptr;
}

void DeleteStiva(Stiva *&p)
{
	while (!isEmpty(p))
	{
		PopElem(p);
	}
}

void AfisStiva(Stiva *p)
{
	if(isEmpty(p))
	{
		cout << "stiva este goala" << endl;
		return;
	}
	while (p)
	{
		cout << PopElem(p) << " ";
	}
	cout << endl;
}

Stiva *copy(Stiva *p)
{
	Stiva *newStiva = nullptr;
	vector<int> queue;

	while(!isEmpty(p))
	{
		queue.push_back(PopElem(p));
	}

	while(!queue.empty())
	{
		PushElem(newStiva, queue.back());
		queue.pop_back();
	}

	return newStiva;
}
