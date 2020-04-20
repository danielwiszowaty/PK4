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
		task="wchodze na uczelnie";
	}
};

int main()
{
	Student Bartus;
	string task,task2,task3;
	Bartus.Pobudka(task);
	cout << task<<endl;

	thread t1(&Student::Telefon, &Bartus, ref(task));
	thread t2(&Student::Toaleta, &Bartus, ref(task2));
	t1.join();
	t2.join();
	cout << task+" i "+task2 << endl;

	thread t3(&Student::Prysznic, &Bartus, ref(task));
	thread t4(&Student::Mycie_zebow, &Bartus, ref(task2));
	t3.join();
	t4.join();
	cout << task + " i " + task2 << endl;

	thread t5(&Student::Autobus, &Bartus, ref(task));
	thread t6(&Student::Nauka, &Bartus, ref(task2));
	thread t7(&Student::Sniadanie, &Bartus, ref(task3));
	t5.join();
	t6.join();
	t7.join();
	cout << task + " i " + task2 + " i " + task3 << endl;
	
	Bartus.Uczelnia(task);
	cout << task<<endl;
	return 0;
}