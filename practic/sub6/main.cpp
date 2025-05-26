#include <iostream>
#include "stiva.h"
#include <vector>
using namespace std;

int main()
{
	Stiva* p;
	
	initStiva(p);
	PushElem(p, 1);
	PushElem(p, 2);
	PushElem(p, 3);
	AfisStiva(p);
	PopElem(p);
	AfisStiva(p);
	cout << "Top: " << TopElem(p) << endl;
	DeleteStiva(p);
	AfisStiva(p);
	return 0;
}

