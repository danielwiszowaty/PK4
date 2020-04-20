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

void A(mutex &mtx, mutex& mtx2)
{
	unique_lock<mutex> ul1(mtx);
	

	for (int i = 0; i < 100000; i++)
	{
		x += a;
	}
	cout << x <<endl;
	
	ul1.unlock();

	unique_lock<mutex> ul2(mtx2);

	cout << "A pisze: "<<lab[0]<<endl;
	lab[0] = 'A';
	lab[1] = 'B';
	lab[2] = 'L';
}

void B(mutex& mtx, mutex& mtx2)
{
	unique_lock<mutex> ul2(mtx2);
	
	
	cout << "B pisze: " << lab[1] << endl;

	ul2.unlock();

	unique_lock<mutex> ul1(mtx);

	cout << x <<endl;

	ul1.unlock();
	
}

void C(mutex& mtx, mutex& mtx2)
{
	
	unique_lock<mutex> ul2(mtx2);
	
	cout << "C pisze: " << lab[2] << endl;
	ul2.unlock();

	unique_lock<mutex> ul1(mtx);

	a = 100000;

	cout << a * 2 + 1<<endl;
	
	
}


int main()
{
	mutex mtx, mtx2;

	thread t1(A, ref(mtx), ref(mtx2));
	thread t2(B, ref(mtx), ref(mtx2));
	thread t3(C, ref(mtx), ref(mtx2));
	
	
	

	t1.join();
	t2.join();
	t3.join();
	return 0;
}