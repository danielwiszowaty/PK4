//
// Created by MacPiston on 05.03.2020.
//
#include <iostream>
#include <stdexcept>
#include "zadanie_1.h"

int main() {
    // ZMODYFIKOWAĆ PONIŻSZY FRAGMENT KODU ABY DZIAŁANIE PROGRAMU NIE ZOSTAŁO PRZERWANE; WYPISAĆ KOMUNIKAT WYJĄTKU (.what())

    random_function();

    //
    std::cout << "Udalo sie zapobiec crashowi programu";
    return 0;
}
