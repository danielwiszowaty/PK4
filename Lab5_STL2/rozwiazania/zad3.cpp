#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int random()
{
	return rand() % 1000;
}


int main()
{
	vector<int> listaLosowa(100);

	generate(listaLosowa.begin(), listaLosowa.end(), random);

	cout << "Lista losowa: " << endl;
	for (vector<int>::iterator i = listaLosowa.begin(); i != listaLosowa.end(); i++)
	{
		cout << *i << endl;
	}
	cout << endl << endl;

	vector<float>odwrotna(100);

	copy(listaLosowa.begin(), listaLosowa.end(), odwrotna.begin());
	for_each(odwrotna.begin(), odwrotna.end(), [&](float& wartosc) {wartosc = 1 / wartosc; });
	sort(odwrotna.begin(), odwrotna.end());
	for_each(odwrotna.begin(), odwrotna.end(), [&](float& wartosc) {cout << wartosc << endl; });
	cout << endl;


	return 0;
}
