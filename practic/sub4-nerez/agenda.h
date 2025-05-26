using namespace std;

#ifndef _AGENDA_
#define _AGENDA_

struct Agenda
{
	string nume;
	string telefon;
	Agenda *link;
};

void InitAgenda(Agenda *&p);
void InsertFata(Agenda *&p, char *num, char *tel);
void InsertMijloc(Agenda *&p, char *num, char *tel);
void CautaPers(Agenda *&p);
void AfisAgenda(Agenda *&p);
void CitAgenda(Agenda *&p);

#endif
