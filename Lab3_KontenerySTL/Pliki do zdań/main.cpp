//
//  main.cpp
//

#include <iostream>
#include <map>
#include <string>

#include "Zadanie1.hpp"
#include "Zadanie2.hpp"
#include "Zadanie3.hpp"

int main(int argc, const char * argv[]) {
    
//    zadanie 1
    WskaznikWiatru Chalupy, Hel;
    std::vector<int> wartosciChalupy {12, 5, 9, 3, 7, 7, 3, 9, 10, 11, 11, 8, 5, 4, 9};
    std::vector<int> wartosciHel {12, 5, 2, 3, 7, 9, 3, 9, 10, 6, 1, 8, 5, 1, 4, 6, 8, 2};
    
//    zadanie 2
    std::multimap<std::string, std::string> multimapaZoo;
    multimapaZoo = wczytajZwierzeta(multimapaZoo);
    wyswietlZwierzeta(multimapaZoo);
    zapiszZwierzeta(multimapaZoo);
    
//    zadanie 3
    
    przeksztalc("obraz.txt", "zmodyfikowanyObraz.txt");
    
    return 0;
}
