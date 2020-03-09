//
// Created by MacPiston on 05.03.2020.
//

#ifndef PREZKA_ZADANIE_3_H
#define PREZKA_ZADANIE_3_H

#include <stdexcept>

class myException {
public:
    virtual const char* what() = 0;

};

class myFirstException : public myException {
public:
    const char* what() override {
        return "Pierwszy wyjątek";
    }
};

class mySecondException : public myException {
public:
    const char* what() override {
        return "Drugi wyjątek";
    }
};

class myThirdException : public myException {
public:
    const char* what() override {
        return "Trzeci wyjątek";
    }
};

class Car {
public:
    virtual void throwException() = 0;
};

class BMW : public Car {
public:
    void throwException() override {
        throw myThirdException();
    }
};

class Mazda : public Car {
public:
    void throwException() override {
        throw myFirstException();
    }
};

class Volvo : public Car {
public:
    void throwException() override {
        throw mySecondException();
    }
};
#endif //PREZKA_ZADANIE_3_H
