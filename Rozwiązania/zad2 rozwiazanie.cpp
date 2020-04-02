#include <iostream>

/*
 * Zadanie nr2
 * Stwórz shared_ptr sharedPtr o dowolnej wskazywanej wartości dowolnego typu.
 * Na jego podstawie utwórz weak_ptr weakPtr
 * Za pomocą funkcji use_count() oraz expired() zbadaj ich właściwości. Zwróć uwagę które funkcje są dostępne dla danych typów wskaźników
 * Funkcją lock() zbadaj informacje przechowywane przez sharedPtr
 * Zwolnij weakPtr i ponownie zbadaj informacje przechowywane przez sharedPtr *
 *
 * W celu ułatwienia odczytu stanu wskaźników skorzystaj z manipulatora std::boolalpha
 */

int main(){
    std::cout << std::boolalpha;
    auto sharedPtr = std::make_shared<double>(137.58);
    std::weak_ptr<double> weakPtr(sharedPtr);

    std::cout << "Liczba zarzadzanych przez weakPtr: " << weakPtr.use_count() << std::endl;
    std::cout << "Liczba zarzadzabych przez sharedPtr: " << sharedPtr.use_count() << std::endl;
    std::cout << "Czy weakPtr jest pusty: " << weakPtr.expired() << std::endl;

    if( std::shared_ptr<double> sharedPtr1 = weakPtr.lock() ) {
        std::cout << "Wartosc przechowywana przez sharedPtr: " << *sharedPtr << std::endl;
        std::cout << "Liczba zarzadzanych przez sharedPtr1: " << sharedPtr1.use_count() << std::endl;
    } else {
        std::cout << "weakPtr na nic nie wskazuje!" << std::endl;
    }

    weakPtr.reset();

    if( std::shared_ptr<double> sharedPtr1 = weakPtr.lock() ) {
        std::cout << "Wartosc przechowywana przez sharedPtr: " << *sharedPtr << std::endl;
        std::cout << "Liczba zarzadzanych przez sharedPtr1: " << sharedPtr1.use_count() << std::endl;
    } else {
        std::cout << "weakPtr na nic nie wskazuje!" << std::endl;
    }

    return 0;
}