//
//  Zadanie1.hpp
//  Zadania
//
//  Zadanie 1 - dwustronnie zakończona kolejka
//



#ifndef Zadanie1_hpp
#define Zadanie1_hpp

#include <stdio.h>
#include <deque>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>

class WskaznikWiatru
{
public:
    std::deque <int> pomiary;
    WskaznikWiatru obecnaPredkosc(int prekosc);
    int najwyzsza();
    int najnizsza();
    int przecietna();
};

#endif /* Zadanie1_hpp */
