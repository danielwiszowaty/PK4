
#include "pch.h"
#include <iostream>


/*  Zadanie 3
    Stworz klase Lista reprezentujaca szablon listy jednokierunkowej.
    Parametr szablonu okresla jaki typ danych przechowuje lista.
    W polu prywatnym utworzyc strukture zawierajaca przechowywana dane i wskaznik na nastepny element.
    W polu publicznym metody, które umozliwic dodanie elementu, usuniecie calej listy, zsumowanie wszystkich elementów listy i zwrócenie ilosci elementów, które lista zawiera.
*/

template <typename typ>
class Lista
{
private:
    struct Elem
    {
        typ dane;
        Elem *pNext;
    };

    Elem *head;

public:
    Lista();
    void dodaj(typ nowy);
    void usun();
    typ suma();
    int rozmiar();
    void wysw();
    ~Lista();
};

template <typename typ> Lista<typ>::Lista()
{
    head = nullptr;
}

template <typename typ> void Lista<typ>::dodaj(typ nowy)
{
    if(head==nullptr)
    {
        head = new Elem;
        head->dane = nowy;
        head->pNext=nullptr;
    }
    else
    {
        Elem *tmp=head;

        while(tmp->pNext)
        {
            tmp=tmp->pNext;
        }

          Elem *nw = new Elem;
          nw->dane=nowy;
          nw->pNext=nullptr;

          tmp->pNext=nw;

    }
}

template <typename typ> void Lista<typ>::usun()
{
    if(head==nullptr)
    {
        std::cout<<"Nie ma co usunac.\n";
    }
    else
    {
        Elem *tmp = head;

        while(head!=nullptr)
        {
            tmp=head;
            head=head->pNext;
            delete tmp;
        }
    }
}

template <typename typ> typ Lista<typ>::suma()
{
    typ sumaW = 0;

    Elem *tmp=head;

    while(tmp)
    {
        sumaW+=tmp->dane;
        tmp=tmp->pNext;
    }

    return sumaW;
}

template <typename typ> int Lista<typ>::rozmiar()
{
    if(head==nullptr)
        return 0;

    Elem *tmp=head;
    int rozm=0;

    while(tmp)
    {
        rozm++;
        tmp=tmp->pNext;
    }

    return rozm;
}

template <typename typ> void Lista<typ>::wysw()
{
    if(head==nullptr)
    {
        std::cout<<"Nie ma nic do wyswietlenia.\n";
    }
    else
    {
        Elem *tmp=head;
        int numer = 1;

        while(tmp)
        {
            std::cout<<"Element nr " << numer<< " : " << tmp->dane << "\n";
            numer++;
            tmp=tmp->pNext;
        }
    }
}

template <typename typ> Lista<typ>::~Lista()
{
    Elem *tmp = head;

        while(head!=nullptr)
        {
            tmp=head;
            head=head->pNext;
            delete tmp;
        }
}


int main()
{
	//Sprawdzenie zadania

	Lista<int> lis;

   	lis.dodaj(12);
   	lis.dodaj(15);
   	lis.dodaj(18);
   	lis.dodaj(21);
   	lis.wysw();

   	std::cout << lis.suma() << "\n" << lis.rozmiar() << "\n";

    lis.usun();
    lis.wysw();

	return 0;
}
