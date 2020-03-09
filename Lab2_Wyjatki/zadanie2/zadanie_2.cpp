//
// Created by MacPiston on 05.03.2020.
//
#include <iostream>
#include <vector>
#include <stdexcept>

int main() {
    std::vector<char> charVector(15);
    int decision = 0;
    std::cout << "Na ktorym miejscu chcesz wstawic 5tke?: ";
    std::cin >> decision;

    // ZMODYFIKOWAĆ PONIŻSZĄ CZĘŚĆ TAK ABY PROGRAM DLA DOWOLNEJ LICZBY CAŁKOWITEJ NIE CRASHOWAŁ
    
    charVector.at(decision) = 5;

    //
    return 0;
}
