#include <iostream>
#include <memory>
#include "zad3.h"

template <typename type1, typename type2>
void List<type1,type2>::AddElement(type1 element1, type2 element2) {
    if(!pHead){
        pHead = std::move(std::make_shared<Node<type1,type2>>(element1, element2));
        current_lenght = 1;
    } else {
        auto pNew = std::make_shared<Node<type1,type2>>(element1, element2);
        pNew->pNext=nullptr;
        auto temp = pHead;
        while(temp->pNext){
            temp = temp->pNext;
        }
        temp->pNext = std::move(pNew);
        current_lenght++;
    }
}

template <typename type1, typename type2>
void List<type1,type2>::WriteOut() {
    if(!pHead){
        std::cout << "Lista jest pusta" << std::endl;
    } else {
        auto temp = pHead;
        while(temp){
            std::cout << temp->data1 << " " << temp->data2 << std::endl;
            temp = temp->pNext;
        }
        std::cout << "Koniec listy, liczba elementow wynosi: " << current_lenght << std::endl;
    }
}

template <typename type1, typename type2>
void List<type1,type2>::DeleteSpecifiedElement(type1 element1, type2 element2) {
    if(!pHead){
        std::cout << "Lista jest pusta" << std::endl;
    } else {
        auto temp = pHead;
        if(pHead->data1 == element1 && pHead->data2 == element2) {
            pHead = temp->pNext;
            temp.reset();
        } else {
            while (temp->pNext->data1!= element1 && temp->pNext->data2!= element2) {
                temp = temp->pNext;
            }
            temp->pNext = temp->pNext->pNext;
            current_lenght--;
        }
    }
}

template <typename type1, typename type2>
void List<type1,type2>::DeleteList() {
    while(pHead){
        pHead.reset();
    }
    current_lenght = 0;
}

template <typename type1, typename type2>
int List<type1,type2>::CurrentLenght() {
    return current_lenght;
}


int main() {
    List<int, double> list;
    list.AddElement(1, 5);
    list.AddElement(4, 8);
    list.AddElement(5, 12);
    list.WriteOut();
    list.DeleteSpecifiedElement(4,8);
    list.WriteOut();
    list.DeleteList();
    std::cout << std::endl;
    list.WriteOut();
    list.AddElement(8, 15);
    list.WriteOut();
    std::cout << "Obecna dlugosc wynosi: " << list.CurrentLenght() << std::endl;
    return 0;
}
