//
//  Zadanie1.cpp
//  Zadania
//
//  Zadanie 1 - dwustronnie zakończona kolejka
//

#include "Zadanie1.hpp"


WskaznikWiatru WskaznikWiatru::obecnaPredkosc (int predkosc) {
    this->pomiary.push_front(predkosc);
    if(this->pomiary.size()>12)
        this->pomiary.pop_back();
    return * this;
}

int WskaznikWiatru::najwyzsza() {
//    tworzymy kopię aby nie zatracić oryginalnej kolejności pomiarów
    std::deque <int> kopia = this->pomiary;
    std::make_heap (kopia.begin(),kopia.end());
    return kopia.front();
}

int WskaznikWiatru::najnizsza() {
//    tworzymy kopię aby nie zatracić oryginalnej kolejności pomiarów
    std::deque <int> kopia = this->pomiary;
    std::make_heap (kopia.begin(), kopia.end());
    return kopia.back();
}

int WskaznikWiatru::przecietna() {
    return std::accumulate(this->pomiary.begin(), this->pomiary.end(), 0)/this->pomiary.size();
}
