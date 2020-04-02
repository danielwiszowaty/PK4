#ifndef LAB6_SMARTPOINTERY_ZAD3_H
#define LAB6_SMARTPOINTERY_ZAD3_H
#include <iostream>
/* Zadanie nr3
 * Korzystając ze smart pointerów zaproponuj własną implementację listy jednokierunkowej.
 * Lista ma przechowywać dwie dane: data1 i data2, mogące być RÓŻNEGO DOWOLNEGO typu.
 * Dodatkowo powinna posiadać informację o długości listy i być uaktualniana wraz z działaniem odpowiednich metod.
 * Zaimplementuj metody:
 * void AddElement - dodająca nowy element na koniec listy
 * void WriteOut - wypisująca całą listę
 * void DeleteSpecifiedElement - usuwająca węzeł o określonych parametrach
 * void DeleteList - usuwająca całą listę
 * int CurrentLenght - zwracającą obecną długość listy
 *
 * Przed implementacją zastanów się nad wyborem odpowiedniego wskaźnika (Podpowiedź: przy użyciu niektórych metod możliwe że będą wskaźniki na elementy listy)
 */

struct Node {
    ??? data1;
    ??? data2;
};

class List {
    
public:
    int current_lenght=0;
    List();
    void AddElement();
    void WriteOut();
    void DeleteSpecifiedElement();
    void DeleteList();
    int CurrentLenght();
};

#endif //LAB6_SMARTPOINTERY_ZAD3_H
