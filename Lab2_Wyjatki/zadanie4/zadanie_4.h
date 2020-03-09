//
// Created by Maciek on 08/03/2020.
//

#ifndef WYJTKI_ZADANIE_4_H
#define WYJTKI_ZADANIE_4_H

#include <string>
#include <iostream>

class Drone {
    bool isConnected = true;
public:
    void closeConnection() {
        isConnected = false;
    }
    void disconnect() {
        if (isConnected) {
            throw std::runtime_error("Drone still connected! Disconnect using .closeConnection()");
        } else {
            std::cout << "Drone disconnected\n";
        }
    }
};

#endif //WYJTKI_ZADANIE_4_H
