#include <iostream>
#include "zad1.cpp"

using namespace std;
int main() {

    cout<<typeid(*A).name()<<endl;
    cout<<typeid(A).name()<<endl;

    cout<<typeid(*B).name()<<endl;
    cout<<typeid(B).name()<<endl;

    cout<<typeid(*C).name()<<endl;
    cout<<typeid(C).name()<<endl;

    cout<<typeid(*D).name()<<endl;
    cout<<typeid(D).name()<<endl;

    cout<<typeid(*E).name()<<endl;
    cout<<typeid(E).name()<<endl;

    cout<<typeid(*F).name()<<endl;
    cout<<typeid(F).name()<<endl;

    cout<<typeid(*G).name()<<endl;
    cout<<typeid(G).name()<<endl;

/* Grzegorz po nikim nie dziedzczy
 * Nina dziedziczy po Grzegorz
 * Kamil dziedziczy po Grzegorz
 * Patryk dziedzczy po Nina
 * Marek po nikim nie dziedzczy
 * Dominik po nikim nie dziedziczy
 * Zuzanna dziedziczy po Dominik
*/
}
