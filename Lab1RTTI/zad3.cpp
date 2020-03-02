#include <iostream>

class obliczenia{

public:
    virtual double oblicz(double, double) = 0;
};

class suma: public obliczenia {
    double oblicz(double x, double y){
        return x+y;
    }
};
class roznica: public obliczenia {
    double oblicz(double x, double y){
        return x-y;
    }
};
class iloczyn: public obliczenia {
    double oblicz(double x, double y){
        return x*y;
    }
};
class iloraz: public obliczenia {
    double oblicz(double x, double y){
        return x/y;
    }
};
class potega: public obliczenia {
    double oblicz(double x, double y){
        return pow(x,y);
    }
};
class pierwiastek: public obliczenia {
    double oblicz(double x, double y){
        return pow(x, 1/y);
    }
};

int main() {
 obliczenia* tab[6];
 tab[0]= new suma;
 tab[1]= new roznica;
 tab[2]= new iloczyn;
 tab[3]= new iloraz;
 tab[4]= new potega;
 tab[5]= new pierwiastek;

 double lewa = tab[4]->oblicz(tab[1]->oblicz(2,14),2), srodek = tab[5]->oblicz(tab[1]->oblicz(30,5),2), prawa = 6,
 wynik = tab[2]->oblicz(lewa,tab[3]->oblicz(srodek,prawa));
 std::cout << wynik;

}
