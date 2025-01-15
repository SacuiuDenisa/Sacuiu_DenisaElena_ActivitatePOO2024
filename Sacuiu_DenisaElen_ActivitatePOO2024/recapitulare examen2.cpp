#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <fstream>
#include <vector>

enum Tip {
	Partiala, Totala
};
class Broker {
private:
	static int id;
	char* nume;
	float suma;
	Tip tip;
	int durata;
	const float salariu;

public:

	//set si get
	char* getNume() {
		return nume;
	}
	float getSuma() {
		return suma;
	}
	Tip getTip() {
		return tip;
	}
	int getDurata() {
		return durata;
	}

	void setNume(char* numeNou) {
		this->nume = new char[strlen(numeNou) + 1];
		strcpy(this->nume, numeNou);
	}
	//string 
	//this->nume = numeNou;

	void setSuma(float sumaNoua) {
		this->suma = sumaNoua;
	}
	void setTip(Tip tipNou) {
		this->tip = tipNou;
	}

	//float* suma
	//this->suma = new float(sumaNoua);
	//string*
	//void setNume(string* numeNou) {
	//	this->nume = new string[strlen(numeNou) + 1];
	//	this->nume=numeNou

	void setDurata(int durataNoua) {
		this->durata = durataNoua;
	}

	//constructor fara parametrii
	Broker() :salariu(5000) {
		this->id = 0;
		this->nume = new char[20];
		strcpy(this->nume, "Denisa");
		this->suma = 2000;
		this->tip = Partiala;
		this->durata = 5;


	}

	//constructor cu parametrii
	Broker(int id, char* nume, float suma, Tip tip, int durata, float salariuAngajat) : salariu(salariuAngajat) {
		this->id = id;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->suma = suma;
		this->tip = tip;
		this->durata = durata;

	}
	//constructor de copiere
	Broker(const Broker& b) :salariu(b.salariu) {
		this->id = b.id;
		this->nume = new char[strlen(b.nume) + 1];
		strcpy(this->nume, b.nume);
		this->suma = b.suma;
		this->tip = b.tip;
		this->durata = b.durata;
	}
	//operatorul de afisare <<
	friend ostream& operator<<(ostream& out, Broker& b) { //intotdeauna la fel
		out << "Id: " << b.id << endl;
		out << "nume: " << b.nume << endl;
		out << "suma: " << b.suma << endl;
		if (b.tip == 0) {
			out << "tip:Partiala" << endl;
		}
		else {
			out << "Tip:Totala" << endl;
		}
		out << "Durata" << b.durata << endl;
		out << "Salariu" << b.salariu << endl;
		return out;
	}
	//operatorul ()
	float operator()(float cursSchimb) {
		return suma * cursSchimb;
	}

	//op de conversie la double

	operator double() {
		return suma;
	}
	//metodele necesare pentru scriere/citire
	void scrieinFisier(string file) {
		ofstream f(file);
		if (f.is_open()) {
			f.write(reinterpret_cast<const char*>(&id), sizeof(id));
			int lungime = strlen(nume);
			f.write(reinterpret_cast<const char*>(&lungime), sizeof(lungime));
			f.write(nume, lungime);
			f.write(reinterpret_cast<const char*>(&suma), sizeof(suma));
			f.write(reinterpret_cast<const char*>(&durata), sizeof(durata));
			f.close();
		}

	}
	void citireFisier(string file) {
		ifstream f(file);
		if (f.is_open()) {
			f.read(reinterpret_cast<char*>(&id), sizeof(id));
			int lungime;
			f.read(reinterpret_cast<char*>(&lungime), sizeof(lungime));
			this->nume = new char[lungime + 1];
			f.read(&nume[0], lungime);
			nume[lungime] = '\0';
			f.read(reinterpret_cast <char*>(&suma), sizeof(suma));
			f.read(reinterpret_cast<char*>(&durata), sizeof(durata));
			f.close();



		}
	}



};
int Broker::id = 0;


//conceptul has a 
class Companie {
	vector<Broker>vectorBroker;
public:
	float calcularemedieAsigurare() {
		float suma = 0;
		for (auto& i : vectorBroker) {
			suma += i.getSuma();
		}
		suma = suma / vectorBroker.size();
		return suma;
	}
	//functie adaugare broker in companie de facut de fiecare data cand e struct vector
	void adaugaBroker(Broker b) {
		vectorBroker.push_back(b);
	}
	float calculareSuma() {
		float suma = 0;
		for (auto& i : vectorBroker) {
			suma += i.getSuma();
		}
		return suma;
	}
};

int main() {
	Broker b1; //apelare constructor fara parametrii
	Broker b2(1, (char*)"Ana", 800.20, Tip::Totala, 6, 8000); //apelare constr cu parametrii
	Broker b3 = b2;
	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;
	cout << b2(4.9) << endl; //pt op ()
	b2.scrieinFisier("Broker.bin");
	b1.citireFisier("Broker.bin");
	cout << b1 << endl;

	Companie c1;
	c1.adaugaBroker(b1);
	c1.adaugaBroker(b2);
	c1.adaugaBroker(b3);
	cout << c1.calcularemedieAsigurare() << endl;

	cout << c1.calculareSuma() << endl;



}