#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	deque<int> kolejka;

	front_insert_iterator<deque<int>> front_it(kolejka);
	back_insert_iterator<deque<int>> back_it(kolejka);

	*front_it = 10;
	*front_it = 20;

	cout << "Poczatkowe: ";
	for (deque<int>::iterator i = kolejka.begin(); i != kolejka.end(); i++)
		cout << *i << " ";

	cout << endl;

	*back_it = 30;
	*back_it = 40;

	cout << "Koncowe: ";
	for (deque<int>::iterator i = kolejka.begin(); i != kolejka.end(); i++)
		cout << *i << " ";

	cout << endl;

	insert_iterator<deque<int>> wstawiajacy(kolejka, kolejka.begin() + 1);
	*wstawiajacy = 50;

	cout << "Wstawiajacy: ";
	for (deque<int>::iterator i = kolejka.begin(); i != kolejka.end(); i++)
		cout << *i << " ";

	cout << endl;

	back_inserter(kolejka) = 60;

	cout << "Back inserted: ";
	for (deque<int>::iterator i = kolejka.begin(); i != kolejka.end(); i++)
		cout << *i << " ";

	cout << endl;

	copy(kolejka.begin(), kolejka.end(), front_inserter(kolejka));

	cout << "Po skopiowaniu: ";
	for (deque<int>::iterator i = kolejka.begin(); i != kolejka.end(); i++)
		cout << *i << " ";

	cout << endl;

	system("pause");
	return 0;
}
