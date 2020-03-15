
#include "pch.h"
#include <iostream>


/*  Zad.1.
    Stworz szablon:
        - funkcji min(),
        - funkcji max(),
    ktora porowna porowna dwie liczby dla konfiguracji int-int, double-double, int-int
    oraz zwróci odpowiednio najmniejsza/najwieksza liczbê typu double.
    Nastepnie sprawdzi dzialanie powyzszych funkcji dla dowolnych wartosci odpowiednich typów.
*/

template <typename jakis_typ1, typename jakis_typ2 >
double min(jakis_typ1 a, jakis_typ2 b) {
	if (a < b) {
		return a;
	}
	return b;
}

template <typename jakis_typ1, typename jakis_typ2 >
double max(jakis_typ1 a, jakis_typ2 b) {
	if (a > b) {
		return a;
	}
	return b;
};


int main()
{
	//Sprawdzenie funkcji

	int a = 5, b = 6;
	double c = 5.33, d = 5.44;

	std::cout << "Max <int, int>: " << max(a,b) << "\n";
	std::cout << "Max <double, double>: " << max(c,d) << "\n";
	std::cout << "Min <int, int>: " << min(a, b) << "\n";
	std::cout << "Min <double, double>: " << min(c, d) << "\n";

	std::cout << "Max <int, double>: " << max(a, c) << "\n";
	std::cout << "                   " << max(a,d) << "\n";
	std::cout << "                   " << max(b,c) << "\n";
	std::cout << "                   " << max(b,d) << "\n";

    std::cout << "Min <int, double>: " << min<int>(a,c) << "\n";
	std::cout << "                   " << min<int>(a,d) << "\n";
	std::cout << "                   " << min<int>(b,c) << "\n";
	std::cout << "                   " << min<int>(b,d) << "\n\n";

	return 0;
}