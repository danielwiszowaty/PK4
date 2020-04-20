#include <iostream>
#include <thread>

using namespace std;

//napisaæ program który bêdzie sumowaæ wartoœci tablicy doubli.
//nale¿y to zrobiæ dziel¹c tablicê na 4 czêœci, równoczeœnie je dodaæ a nastêpnie zssumowaæ ze sob¹ otrzymane 4 wyniki

int main()
{
	double tab[100];
	for (int i = 0; i < 100; i++)
	{
		tab[i] = i;
	}


	return 0;
}