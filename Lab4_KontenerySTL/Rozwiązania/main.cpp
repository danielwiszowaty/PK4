//
//  main.cpp
//

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Zadanie1.hpp"
#include "Zadanie2.hpp"
#include "Zadanie3.hpp"

int main(int argc, const char * argv[]) {
    
//    zadanie 1
    WskaznikWiatru Chalupy, Hel;
    std::vector<int> wartosciChalupy {12, 5, 9, 3, 7, 7, 3, 9, 10, 11, 11, 8, 5, 4, 9};
    std::vector<int> wartosciHel {12, 5, 2, 3, 7, 9, 3, 9, 10, 6, 1, 8, 5, 1, 4, 6, 8, 2};
    
    for (int i : wartosciChalupy)
        Chalupy = Chalupy.obecnaPredkosc(i);
    
    for (int i : wartosciHel)
        Hel = Hel.obecnaPredkosc(i);
    
    
    int najwyzsza, najnizsza, przecietna;
    
    najwyzsza = Chalupy.najwyzsza();
    najnizsza = Chalupy.najnizsza();
    przecietna = Chalupy.przecietna();
    std::cout << "Predkosci wiatru w Chalupach w ciągu ostatniej godziny to: " << std::endl << "-najwyższa:" << najwyzsza << std::endl << "-najnizsza:" << najnizsza << std::endl << "-przecietna:" << przecietna << std::endl;
    
    najwyzsza = Hel.najwyzsza();
    najnizsza = Hel.najnizsza();
    przecietna = Hel.przecietna();
    std::cout << "Predkosci wiatru na Helu w ciągu ostatniej godziny to: " << std::endl << "-najwyższa:" << najwyzsza << std::endl << "-najnizsza:" << najnizsza << std::endl << "-przecietna:" << przecietna << std::endl;
    
    std::cout << std::endl;
    
//    zadanie 2
    std::multimap<std::string, std::string> multimapaZoo;
    multimapaZoo = wczytajZwierzeta(multimapaZoo);
    wyswietlZwierzeta(multimapaZoo);
    
    wyswietlUwzglednijGatunki(multimapaZoo);
    dodajZwierze(multimapaZoo, "wydra", "Kamil");
    dodajZwierze(multimapaZoo, "zebra", "Bartosz");
    usunZwierze(multimapaZoo, "strus", "Kasper");
    wyswietlDlaGatunku(multimapaZoo, "zebra");
    
    zapiszZwierzeta(multimapaZoo);
    
//    zadanie 3
    
    przeksztalc("obraz.txt", "zmodyfikowanyObraz.txt");
    
    return 0;
}
