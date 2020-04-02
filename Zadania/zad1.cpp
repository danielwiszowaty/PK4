#include <iostream>
#include <random>
#include <exception>
#include <memory>

/* ZAD 1 Jednym z g³ównych celów korzystania ze inteligentnych wskaŸników 
* jest automatyczne zwalnianie przez nie pamiêci.
* Popraw ten program, tak by nie korzysta³ z surowych wskaŸników 
* poprzez zamienienie ich na wskaŸniki inteligentne.
*/

struct Odd_exception : public std::exception {
	const char* what_is_it() const throw () {
		return "This is odd exception";
	}
};

bool check_if_even(int number) {
	if (number % 2 != 0)
		throw Odd_exception();
	return true;
}

int main()
{
	int* array;
	array = new int[50];
	for (int i = 0; i < 50; i++) {
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> distribution(1,100);
		array[i] = distribution(rng);
	}
	try {
		check_if_even(array[0]);
		delete[]array;
		std::cout << "Pamiec zostala zwolniona!" << std::endl;
	}
	catch (Odd_exception & e) {
		/*Jeœli wyst¹pi wyj¹tek pamiêæ zajmowana przez wskaŸniki nie zostanie zwolniona
		i powstanie wyciek pamiêci*/
		std::cout << "Pamiec nie zostanie zwolniona" << std::endl;
	}
	
	return 0;
}