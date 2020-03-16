//
//  Zadanie2.cpp
//  Zadania
//
//  Zadanie 2 - multimapa, słownik z powtórzeniami
//


#include "Zadanie2.hpp"


std::multimap<std::string, std::string> wczytajZwierzeta (std::multimap<std::string, std::string> mapaZoo) {
    std::ifstream plik ("listaZwierzat.txt");
    std::string gatunek, imie;
    if(plik) {
        while(!plik.eof()){
            plik >> gatunek >> imie;
            mapaZoo.insert(std::pair <std::string, std::string> (gatunek, imie));
        }
    }
    plik.close();
    return mapaZoo;
}

void zapiszZwierzeta (std::multimap<std::string, std::string> mapaZoo) {
    std::ofstream plik ("zmodyfikowanaListaZwierzat");
    if(plik) {
        for(std::pair <std::string, std::string> elem : mapaZoo)
            plik << elem.first<<" " << elem.second << std::endl;
    }
    plik.close();
}

void wyswietlZwierzeta (std::multimap<std::string, std::string> mapaZoo) {
    for(std::pair <std::string, std::string> elem : mapaZoo)
        std::cout << elem.first<<" " << elem.second << std::endl;
}
