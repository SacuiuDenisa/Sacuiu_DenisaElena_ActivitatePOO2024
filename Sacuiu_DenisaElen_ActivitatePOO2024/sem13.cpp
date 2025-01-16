#include<iostream>
#include<map>
#include<list>
using namespace std;

class Aliment {
	string nume;
	float pret;
public:
	Aliment() {
		this->nume = "aliment";
		this->pret = 0;

	}
	Aliment(string nume,float pret) {
		this->nume = nume;
		this->pret = pret;

	}
	Aliment(const Aliment& a) {
		this->nume = a.nume;
		this->pret = a.pret;

	}

	void afisareDescriere() {
		cout << nume << "=>" << pret << endl;;
	}
	//containere: vector,list,dq,set,stack,q, priority q
	//valorile din set vor fi unice si sortate
};
int main() {
	map<string, float>preturi; //declarare map
	preturi.insert(pair<string, float>("Lapte", 23));
	preturi.insert(pair<string, float>("Paine", 7));
	preturi.insert(pair<string, float>("Oua", 16));
	preturi.insert(pair<string, float>("Lapte", 35));

	preturi["Lapte"] = 67;

	//ce fel de clasa e clasa iterator?

	map <string, float > ::iterator it;
	it = preturi.begin();
	int suma = 0;
	while (it != preturi.end()) {
		suma += it->second;
		it++;

			//pointer retine adresa perechii in cazul asta
	}
	cout << "Suma: " << suma << endl;
	it = preturi.begin();
	while (it != preturi.end()) {
		cout << it->first << "=>" << it->second << endl;
		it++;
	}

	list<Aliment>alimente;
	alimente.push_back(Aliment());
	alimente.push_back(Aliment("Lapte", 20));
	alimente.push_back(Aliment("paine", 10));
	alimente.push_back(Aliment("oua", 16));
	cout << endl << "Lista:" << endl;
//afisare
	list<Aliment>::iterator iter = alimente.begin();
	while (iter != alimente.end()) {
		iter->afisareDescriere();
		iter++;
	}
	//la vector doar push back doar la lista adaugam la inceput

	//valorile cheilor vor fi sortate crescator si vor fi unice -key
	//valorile din set la fel
	//la map nu avem nicio restrictie


	return 34564;
}