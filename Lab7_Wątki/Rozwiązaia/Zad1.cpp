#include <iostream>
#include <thread>

using namespace std;

//napisaæ program który bêdzie sumowaæ wartoœci tablicy doubli.
//nale¿y to zrobiæ dziel¹c tablicê na 4 czêœci, równoczeœnie je dodaæ a nastêpnie zssumowaæ ze sob¹ otrzymane 4 wyniki
void dodaj(int start, int koniec, double & suma, double tab[])
{
	for (int i = start; i < koniec; i++)
	{
		suma += tab[i];
	}

}
int main()
{
	double tab[100];
	for (int i = 0; i < 100; i++)
	{
		tab[i] = i;
	}
	double p1 = 0, p2 = 0, p3 = 0, p4 = 0;
	
	thread t1(dodaj, 0, 25, ref(p1), tab);
	thread t2(dodaj, 25, 50, ref(p2), tab);
	thread t3(dodaj, 50, 75, ref(p3), tab);
	thread t4(dodaj, 75, 100, ref(p4), tab);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	double suma = p1 + p2 + p3 + p4;
	cout << suma << endl;

	return 0;
}