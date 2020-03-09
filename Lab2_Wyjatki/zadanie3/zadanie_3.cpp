//
// Created by MacPiston on 05.03.2020.
//
#include <iostream>
#include "zadanie_3.h"

int main() {
    BMW auto1;
    Mazda auto2;
    Volvo auto3;

    //ZAPOBIEC WYJĄTKOM (NIE PATRZĄC DO PLIKU .h), WYPISAĆ W KONSOLI KTÓRE AUTO WYRZUCA JAKI WYJĄTEK KORZYSTAJĄC Z .what()

    auto1.throwException();

    auto2.throwException();

    auto3.throwException();

    //
}
