#ifndef LAB6_SMARTPOINTERY_ZAD3_H
#define LAB6_SMARTPOINTERY_ZAD3_H
#include <iostream>
#include <memory>
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
 * Sprawdź działanie każdej z metod
 * Przed implementacją zastanów się nad wyborem odpowiedniego wskaźnika (Podpowiedź: przy użyciu niektórych metod możliwe że będą wskaźniki na elementy listy)
 */


template <typename type1, typename type2>
struct Node {
    type1 data1;
    type2 data2;
    std::shared_ptr<Node> pNext;
    Node(type1 data1, type2 data2) : data1(data1), data2(data2), pNext(nullptr){};
};

template <typename type1, typename type2>
class List {
    std::shared_ptr<Node<type1, type2>> pHead;
public:
    int current_lenght=0;
    List() :  pHead(nullptr) {};
    void AddElement(type1 element1, type2 element2);
    void WriteOut();
    void DeleteSpecifiedElement(type1 element1, type2 element2);
    void DeleteList();
    int CurrentLenght();
};

#endif //LAB6_SMARTPOINTERY_ZAD3_H
