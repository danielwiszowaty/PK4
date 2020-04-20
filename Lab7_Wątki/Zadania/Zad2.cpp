#include <iostream>
#include <thread>

using namespace std;
//jesteœ spoznionym studentem, musisz jak najszybciej dostac sie na uczelnie, wiêc skondensuj w czasie najwazniejsze czynnosci
class Student
{
public:
	void Pobudka(string & task) {
		task = "budze sie";
	}
	
	void Telefon(string& task) {
		task = "sprawdzam co zapomnialem przygotowac na uczelmnie ";
	}

	void Toaleta(string& task) {
		task = "korzystam z toalety";
	}

	void Mycie_zebow(string& task) {
		task = "myje zeby";
	}

	void Prysznic(string& task){
		task = "biore prysznic";
	}

	void Autobus(string& task) {
		task = "jade autobusem";
	}

	void Nauka(string& task) {
		task = "ucze sie";
	}

	void Sniadanie(string& task) {
		task = "jem sniadanie";
	}

	void Uczelnia(string& task) {
		task="przepraszam za spoznienie i siadam w lawce";
	}
};

int main()
{
	Student Bartus;
	string task;
	Bartus.Pobudka(task);
	cout << task<<endl;



	Bartus.Uczelnia(task);
	cout << task<<endl;
	return 0;
}