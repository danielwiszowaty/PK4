
#include "pch.h"
#include <iostream>


/*  Zad.2.
    Stwórz szablon <typ i rozmiar tablicy> klasy Tablica, która bedzie przechowywala jednowymiarowa tablice dynamiczna.
    Klasa Tablica posiada nastepujace metody:
        - inicjuj - tablica jest zape³niana losowymi wartoœciami
        - rozmiar - zwraca rozmiar tablicy
        - obroc - obraca zawartosc tablicy
        - sortuj - sortuje zawartosc tablicy
        - wyswietl - wyswietla zawartosc tablicy w konsoli
*/


template <class typ, int ilosc>
class Tablica
{
private:
	typ *tab = new typ[ilosc];

public:
	void inicjuj()
	{
	    for(int i=0;i<ilosc;i++)
        {
            tab[i] = rand()% 100+1;
        }
	}

	int rozmiar()
	{
		return ilosc;
	}

	void obroc()
	{
	    for(int i=0;i<ilosc/2;i++)
        {
           std::swap(tab[i],tab[ilosc-1-i]);
        }
	}

	void sortowanie()
	{
	    for(int i=0;i<ilosc;i++)
            for(int j=1;j<ilosc-i;j++) //pêtla wewnêtrzna
                if(tab[j-1]>tab[j])
                    std::swap(tab[j-1], tab[j]); //zamiana miejscami
	}

	void wysw()
	{
		for (int i = 0; i < ilosc; i++)
		{
			std::cout << tab[i] << " ";
		}
	}
};


int main()
{
	//Sprawdzenie zadania

	srand(time(NULL));

	Tablica <char,5>tabk;

	tabk.inicjuj();

	tabk.wysw();

	tabk.obroc();

	std::cout<<"\n\n";

	tabk.wysw();

	tabk.sortowanie();

	std::cout<<"\n\n";

	tabk.wysw();

	return 0;
}