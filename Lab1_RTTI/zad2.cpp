#include <iostream>
using namespace std;
int main()
{
	int cyfra_int = -1;
	long int cyfra_lint = 1111111111;
	unsigned int cyfra_uint = 321321;
	bool cyfra_bl = 0;
	double cyfra_db = 11.1;
	float cyfra_fl = 111111.111111111;
	int wynik = cyfra_int + static_cast<int>(cyfra_lint) + (cyfra_uint)+static_cast<int>(cyfra_bl) + static_cast<int>(cyfra_db);
	cout << wynik;
}