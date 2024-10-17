#include <iostream>
using namespace std;
class Cofetarie {
public:
	string nume;
	int nrAngajati;
	bool esteVegana;
	const int anDeschidere; //e constant si de-aia punem const ,nu poate fi modificat
	float adaos;
	static int TVA;//poti sa pui si nr cu virgula(float),toate cofetariile au acelasi tva 

	Cofetarie() : adaos(30), anDeschidere(2024) {
		this->nume = "Delice";
		this->nrAngajati = 3;
		this->esteVegana = true;

	}
	Cofetarie(string nume, int nrAngajati, bool vegana, int an, float adaos) :anDeschidere(an) {
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = vegana;
		this->adaos = adaos;
	}
	void afisare() {
		cout << "Nume: " << this->nume << endl;
		cout << "Nr angajati: " << this->nrAngajati << endl;
		cout << "Are produse vegane: " << (this->esteVegana ? "DA" : "NU") << endl;
		cout << "An deschidere: " << this->anDeschidere << endl;
		cout << "Adaos: " << this->adaos << endl;
		cout << "TVA: " << this->Cofetarie::TVA << endl;


	}

};
int Cofetarie::TVA = 9;
int main() {
	Cofetarie c1;
	c1.afisare();
	Cofetarie c2("DolceVita", 6, false, 2019, 10);
	c2.afisare();
	return 0;
}


//cum modificam TVA-ul?

#include <iostream>
using namespace std;
class Cofetarie {
public:
	string nume;
	int nrAngajati;
	bool esteVegana;
	const int anDeschidere; //e constant si de-aia punem const ,nu poate fi modificat
	float adaos;
	static int TVA;//poti sa pui si nr cu virgula(float),toate cofetariile au acelasi tva 

	Cofetarie() : adaos(30), anDeschidere(2024) {
		this->nume = "Delice";
		this->nrAngajati = 3;
		this->esteVegana = true;

	}
	Cofetarie(string nume, int nrAngajati, bool vegana, int an, float adaos) :anDeschidere(an) {
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = vegana;
		this->adaos = adaos;
	}
	void afisare() {
		cout << "Nume: " << this->nume << endl;
		cout << "Nr angajati: " << this->nrAngajati << endl;
		cout << "Are produse vegane: " << (this->esteVegana ? "DA" : "NU") << endl;
		cout << "An deschidere: " << this->anDeschidere << endl;
		cout << "Adaos: " << this->adaos << endl;
		cout << "TVA: " << this->Cofetarie::TVA << endl;


	}
	static void modificaTVA(int noulTVA) {

		if (noulTVA > 0) {
			Cofetarie::TVA = noulTVA;
		}

	}
	static int calculeazaNrTotalAngajati(int nrCofetarii, Cofetarie* vector) {
		int suma = 0;
		for (int i = 0; i < nrCofetarii; i++) {
			suma += vector[i].nrAngajati;

		}
		return suma;
	}
};
int Cofetarie::TVA = 9;
int main() {
	Cofetarie c1;
	c1.afisare();
	Cofetarie::modificaTVA(-19);
	Cofetarie c2("DolceVita", 6, false, 2019, 10);
	c2.afisare();

	Cofetarie* pointer;
	pointer = new Cofetarie("Ana State", 3, false, 2020, 20);
	//(*pointer).afisare() dereferentiere, sageata-> inseamna dereferentiere+accesare 
	//[] - deplasare+dereferentiere
	pointer->afisare();
	delete pointer;
	int nrCofetarii = 3;
	Cofetarie* vector; //declar un vector la cofetarie
	vector = new Cofetarie[nrCofetarii];
	for (int i = 0; i < nrCofetarii; i++) {
		vector[i].afisare();

	}
	cout << "Numar total angajati: " << Cofetarie::calculeazaNrTotalAngajati(nrCofetarii, vector);
	delete[]vector;
	return 0;
}