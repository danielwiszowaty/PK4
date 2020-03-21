#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// stwórz kontener vector<int>
	vector<int> vec;

	// zainicjuj wektor kolejnymi liczbami naturalnymi
	for (int i = 1; i <= 5; i++) 
		vec.push_back(i);

	// wyswietl skladniki wektora tab w petli przy pomocy iteratora
	vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); ++it)
		cout << *it << " ";

	cout << endl;

	// wyœwietl skladniki wektora tab w pêtli przy pomocy odwróconego iteratora
	vector<int>::reverse_iterator it2;
	for (it2 = vec.rbegin(); it2 != vec.rend(); ++it2)
		cout << *it2 << " ";

	cout << endl;

	system("pause");
	return 0;
}