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

void wyswietlUwzglednijGatunki (std::multimap<std::string, std::string> mapaZoo) {
    for ( auto elem = mapaZoo.begin(), end = mapaZoo.end(); elem != end; elem = mapaZoo.upper_bound(elem->first))
    {
      std::cout << "Liczba zwierzat gatunku " << elem->first << " to " << mapaZoo.count(elem->first) << ":";
      std::multimap<std::string, std::string>::iterator it;
      for (it=mapaZoo.equal_range(elem->first).first; it!=mapaZoo.equal_range(elem->first).second; ++it)
        std::cout << ' ' << (*it).second;
      std::cout << '\n';
    }
}

void dodajZwierze (std::multimap<std::string, std::string> mapaZoo, std::string gatunek, std::string imie) {
    mapaZoo.insert(std::pair <std::string, std::string> (gatunek, imie));
}

void usunZwierze (std::multimap<std::string, std::string> mapaZoo, std::string gatunek, std::string imie) {
    for ( auto elem = mapaZoo.begin(), end = mapaZoo.end(); elem != end; elem = mapaZoo.upper_bound(elem->first))
    {
        if(elem-> first == gatunek && elem->second == imie)
            mapaZoo.erase(elem);
    }
}

void wyswietlDlaGatunku (std::multimap<std::string, std::string> mapaZoo, std::string gatunek) {
    std::pair <std::multimap<std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator> ret;
    ret = mapaZoo.equal_range(gatunek);
    std::cout << "Imiona zwierząt gatunku " << gatunek << " to:";
    for (std::multimap<std::string, std::string>::iterator it=ret.first; it!=ret.second; ++it)
      std::cout << ' ' << it->second;
    std::cout << '\n';
}
