#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
	vector<string>listaSlow;
	std::fstream file;
	string reader;
	file.open("source.txt", std::ios::in);
	if (file.good())
	{
		while ((file) >> reader)
		{
			listaSlow.push_back(reader);
		}

	}
	sort(listaSlow.begin(), listaSlow.end());
	listaSlow.erase(unique(listaSlow.begin(), listaSlow.end()), listaSlow.end());
	for_each(listaSlow.begin(), listaSlow.end(), [&](string& wartosc) {cout << wartosc << endl; });

	return 0;
}
