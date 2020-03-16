//
//  Zadanie2.hpp
//  Zadania
//
//  Zadanie 2 - multimapa, słownik z powtórzeniami
//


#ifndef Zadanie2_hpp
#define Zadanie2_hpp

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <fstream>

//funkcje pomocnicze

std::multimap<std::string, std::string> wczytajZwierzeta(std::multimap<std::string, std::string> multimapaZoo);
void zapiszZwierzeta (std::multimap<std::string, std::string> multimapaZoo);
void wyswietlZwierzeta (std::multimap<std::string, std::string> multimapaZoo);

#endif /* Zadanie2_hpp */
