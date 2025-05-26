#include <iostream>
#include <string>

struct Element
{
    std::string nume;
    int tel;
    Element *succ;
};

void inserareOrdonata(Element *&cap);
void creareLista(Element *&cap);
void afisareLista(Element *cap);
void stergePersoana(Element *&cap);
void cautaNrTel(Element *cap);

int main()
{
    Element *cap = nullptr;

    creareLista(cap);
    std::cout << std::endl
              << "Lista creata: " << std::endl;
    afisareLista(cap);

    // inserareOrdonata(cap);
    // std::cout << std::endl
    //           << "Lista dupa inserare: " << std::endl;
    // afisareLista(cap);

    // std::cout << std::endl
    //           << "Lista dupa stergere persoana: " << std::endl;
    // stergePersoana(cap);
    // afisareLista(cap);

    // std::cout << std::endl;
    // cautaNrTel(cap);

    int x = 1;

    while (x)
    {
        std::cout << std::endl
                  << "Actiuni posibile:" << std::endl
                  << "(1) insereaza un element in lista;" << std::endl
                  << "(2) sterge din lista o persoana data" << std::endl
                  << "(3) cauta in lista nr de telefon al unei persoane" << std::endl
                  << "(4) afiseaza lista in intregime" << std::endl
                  << "(0) iesire din meniu" << std::endl;
        std::cin >> x;

        switch (x)
        {
        case 1:
            std::cout << "Date element de inserat: " << std::endl;
            inserareOrdonata(cap);
            break;
        case 2:
            stergePersoana(cap);
            break;
        case 3:
            cautaNrTel(cap);
            break;
        case 4:
            std::cout << std::endl
                      << "Lista intreaga: " << std::endl;
            afisareLista(cap);
            break;
        case 0:
            x = 0;
            break;
        default:
            std::cout << "Comanda gresita!" << std::endl;
            break;
        }
    }

    return 0;
}

void inserareOrdonata(Element *&cap)
{
    std::string nume;
    int tel;
    std::cout << "Nume = ";
    std::cin >> nume;
    std::cout << "Nr telefon = ";
    std::cin >> tel;

    Element *p = new Element{nume, tel};

    if (cap == nullptr || p->nume.compare(cap->nume) <= 0)
    {
        p->succ = cap;
        cap = p;
        return;
    }

    Element *copy = cap;

    while (copy->succ && p->nume.compare(copy->succ->nume) > 0)
    {
        copy = copy->succ;
    }

    p->succ = copy->succ;
    copy->succ = p;
}

// 1 6 10 12 14
//   9

void creareLista(Element *&cap)
{
    std::cout << "Introduceti persoane in agenda (0 = exit): " << std::endl;
    int k = 1;

    while (k)
    {
        inserareOrdonata(cap);
        std::cout << "Continuati? (1-DA, 0-NU): ";
        std::cin >> k;
    }
}
void stergePersoana(Element *&cap)
{
    if (!cap)
        return;

    std::string numeDeSters;
    std::cout << "Persoana de sters: ";
    std::cin >> numeDeSters;

    if (cap->nume == numeDeSters)
    {
        Element *temp = cap;
        cap = cap->succ;
        delete temp;
        return;
    }

    Element *copy = cap;

    while (copy->succ != nullptr && copy->succ->nume != numeDeSters)
    {
        copy = copy->succ;
    }

    if (copy->succ)
    {
        Element *temp = copy->succ;
        copy->succ = copy->succ->succ;
        delete temp;
    }
}

// Anca   Andrei    Bogdan       Darius
//       Bogdan
//       copy     copy->succ

void afisareLista(Element *cap)
{
    while (cap)
    {
        std::cout << "(nume, nrTel) = (" << cap->nume << ", " << cap->tel << ")" << std::endl;
        cap = cap->succ;
    }
}

void cautaNrTel(Element *cap)
{
    std::string numeDeCautat;
    std::cout << "Ce persoana cautati? ";
    std::cin >> numeDeCautat;

    while (cap && cap->nume != numeDeCautat)
    {
        cap = cap->succ;
    }

    if (cap)
    {
        std::cout << "Nr de telefon al persoanei " << numeDeCautat << " este " << cap->tel << std::endl;
    }
    else
        std::cout << "Persoana cautata nu a fost gasita. " << std::endl;
}
