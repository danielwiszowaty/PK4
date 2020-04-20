#include <iostream>
#include <thread>
#include <mutex>

//uzywaj¹c mutexów (unicque_lock), uzyzkaæ w konsoli:
//3 razy liczbê 200001
//A powinno wypisaæ L
//B powinno wypisaæ A
//C powinno wypisaæ B
//wypisane mog¹ byæ w dowolnej kolejnoœci
using namespace std;

int a = 2, b = 4, x = 1;

char lab[3] = { 'L','A','B' };

void A()
{

	for (int i = 0; i < 100000; i++)
	{
		x += a;
	}
	cout << x <<endl;
	

	cout << "A pisze: "<<lab[0]<<endl;
	lab[0] = 'A';
	lab[1] = 'B';
	lab[2] = 'L';
}

void B()
{	
	cout << "B pisze: " << lab[1] << endl;


	cout << x <<endl;
}

void C()
{	
	cout << "C pisze: " << lab[2] << endl;
	
	
	a = 100000;
	cout << a * 2 + 1<<endl;
}


int main()
{
	thread t1(A);
	thread t2(B);
	thread t3(C);
	
	
	t1.join();
	t2.join();
	t3.join();
	return 0;
}