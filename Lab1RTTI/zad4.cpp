#include <iostream>
#include <string>
using namespace std;
class pionki {
	public:
	virtual ~pionki() {}
};
class kolor: public pionki{
	string typ, kol;
public:
	kolor() {
		typ = "pionek";
		kol = "bialy";
	}
	kolor(string n, string t) {
		kol = n;
		typ = t;
	}
	string get_kolor() {
		return kol;
	}
	string get_typ() {
		return typ;
	}
	void show() {
		cout << typ << " " << kol << endl;
	}
};
int main()
{
	pionki* tab[2][16];
	for (int i = 0; i < 1; ++i) {
		for (int j = 0; j < 8; ++j) {
			kolor bialy;
			tab[i][j] = dynamic_cast<pionki*>(&bialy);
			bialy.show();
		}
		for (int j = 8; j < 10; ++j) {
			kolor bialy("biala", "wieza");
			tab[i][j] = dynamic_cast<pionki*>(&bialy);
			bialy.show();
		}
		for (int j = 10; j < 12; ++j) {
			kolor bialy("bialy", "skoczek");
			tab[i][j] = dynamic_cast<pionki*>(&bialy);
			bialy.show();
		}
		for (int j = 12; j < 14; ++j) {
			kolor bialy("bialy", "goniec");
			tab[i][j] = dynamic_cast<pionki*>(&bialy);
			bialy.show();
		}
		kolor bialy_h("bialy", "hetman");
		tab[i][14] = dynamic_cast<pionki*>(&bialy_h);
		bialy_h.show();
		kolor bialy_k("bialy", "krol");
		tab[i][15] = dynamic_cast<pionki*>(&bialy_k);
		bialy_k.show();
	}
	for (int i = 1; i < 2; ++i) {
		for (int j = 0; j < 8; ++j) {
			kolor czarny("czarny", "pionek");
			tab[i][j] = dynamic_cast<pionki*>(&czarny);
			czarny.show();
		}
		for (int j = 8; j < 10; ++j) {
			kolor czarny("czarna", "wieza");
			tab[i][j] = dynamic_cast<pionki*>(&czarny);
			czarny.show();
		}
		for (int j = 10; j < 12; ++j) {
			kolor czarny("czarny", "skoczek");
			tab[i][j] = dynamic_cast<pionki*>(&czarny);
			czarny.show();
		}
		for (int j = 12; j<14; ++j) {
			kolor czarny("czarny", "goniec");
			tab[i][j] = dynamic_cast<pionki*>(&czarny);
			czarny.show();
		}
		kolor czarny_h("czarny", "hetman");
		tab[i][14] = dynamic_cast<pionki*>(&czarny_h);
		czarny_h.show();
		
		kolor czarny_k("czarny", "krol");
		tab[i][15] = dynamic_cast<pionki*>(&czarny_k);
		czarny_k.show();
		
	}
}