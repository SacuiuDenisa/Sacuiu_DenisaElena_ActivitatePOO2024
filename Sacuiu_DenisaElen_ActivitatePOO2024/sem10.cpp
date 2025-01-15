//mostenire:facem o clasa pe baza unei clase deja existente is a
//nu merge prajitura pt ca nu e o cofetarie
//sunt niste atriute pe care nu leavem si nu are rost sa le adaugam sus pentru ca trebuie sa modificam toata structura si de aceea facem o clasa care are la baza atributele primei clase dar mai adaugam altele 

#include<iostream>
#include<fstream>

using namespace std;

class Cofetarie {
private:
	string nume; //
	int nrAngajati;//
	float* salarii;
	bool esteVegana;
	const int anDeschidere;
	float adaos;
	static int TVA;

public:
	Cofetarie() : adaos(30), anDeschidere(2024) {
		this->nume = "Delice";
		this->nrAngajati = 0;
		this->esteVegana = true;
		this->salarii = NULL;
	}

	Cofetarie(string nume, int nrAngajati, bool vegan, int an, float adaos) :anDeschidere(an) {
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = vegan;
		this->adaos = adaos;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 1000 + i * 100;
		}
	}

	Cofetarie(const Cofetarie& c) :anDeschidere(c.anDeschidere) {
		this->nume = c.nume;
		this->nrAngajati = c.nrAngajati;
		this->salarii = new float[c.nrAngajati];
		for (int i = 0; i < c.nrAngajati; i++) {
			this->salarii[i] = c.salarii[i];
		}
		this->esteVegana = c.esteVegana;
		this->adaos = c.adaos;
	}
	Cofetarie operator=(const Cofetarie& c) {
		if (&c != this) {
			this->nume = c.nume;
			this->nrAngajati = c.nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[c.nrAngajati];
			for (int i = 0; i < c.nrAngajati; i++) {
				this->salarii[i] = c.salarii[i];
			}
			this->esteVegana = c.esteVegana;
			this->adaos = c.adaos;
		}
		return *this;
	}

	~Cofetarie() {
		if (this->salarii) {
			delete[]this->salarii;
		}
	}

	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		if (nume.length() > 1) {
			this->nume = nume;
		}
	}

	int getNrAngajati() {
		return this->nrAngajati;
	}
	void setNrAngajati(int nrAngajati, float* salarii) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}

	float* getSalarii() {
		return this->salarii;
	}

	float getSalariu(int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	Cofetarie operator+(Cofetarie c)const {
		Cofetarie temp = *this;
		temp.nrAngajati = this->nrAngajati + c.nrAngajati;
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			aux[i] = this->salarii[i];
		}
		for (int i = 0; i < c.nrAngajati; i++) {
			aux[i + this->nrAngajati] = c.salarii[i];
		}
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = aux;
		return temp;
	}

	Cofetarie& operator+=(Cofetarie c) {
		*this = *this + c;
		return *this;
	}

	Cofetarie operator+(float salariu)const {
		Cofetarie temp = *this;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < this->nrAngajati; i++) {
			temp.salarii[i] = this->salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}

	friend Cofetarie operator+(float salariu, Cofetarie c) {
		Cofetarie temp = c;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < c.nrAngajati; i++) {
			temp.salarii[i] = c.salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}
	explicit operator int() { // cast la int 
		return this->nrAngajati;
	}
	explicit operator float() { //cast la float
		float s = 0;
		for (int i = 0; i < this->nrAngajati; i++) {
			s += this->salarii[i];
		}
		return s;
	}
	void afisare() {
		cout << "Nume:" << this->nume << endl;
		cout << "Nr angajati:" << this->nrAngajati << endl;
		cout << "Are produse vegane:" << (this->esteVegana ? "DA" : "NU") << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "Adaos:" << this->adaos << endl;
		cout << "TVA:" << Cofetarie::TVA << endl;
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

	friend ostream& operator<<(ostream& output, Cofetarie c);
	//ofstream mostenea ostream
	friend ofstream& operator<<(ofstream& output, Cofetarie c) {
		output  << c.nume << endl;
		output << c.nrAngajati << endl;
		if (c.salarii != NULL) {
			for (int i = 0; i < c.nrAngajati; i++) {
				output<< c.salarii[i] << " ";
			}
		}
		output << c.esteVegana << endl;
		output  << c.anDeschidere << endl;
		output  << c.adaos << endl;
	

		return output;
	}

	friend istream& operator>>(istream& input, Cofetarie& c) {
		cout << "Nume:";
		input >> c.nume;
		cout << "Nr angajati:";
		input >> c.nrAngajati;
		if (c.salarii != NULL) {
			delete[]c.salarii;
		}
		if (c.nrAngajati > 0) {
			c.salarii = new float[c.nrAngajati];
			for (int i = 0; i < c.nrAngajati; i++) {
				cout << "Salariul " << i + 1 << ":";
				input >> c.salarii[i];
			}
		}
		else {
			c.salarii = NULL;
		}
		cout << "Are produse vegane? 1-DA;0-NU";
		input >> c.esteVegana;
		cout << "Adaos comercial:";
		input >> c.adaos;
		return input;
	};
	friend ifstream& operator>>(ifstream& input, Cofetarie& c) {
		
		input >> c.nume;
	
		input >> c.nrAngajati;
		if (c.salarii != NULL) {
			delete[]c.salarii;
		}
		if (c.nrAngajati > 0) {
			c.salarii = new float[c.nrAngajati];
			for (int i = 0; i < c.nrAngajati; i++) {
				
				input >> c.salarii[i];
			}
		}
		else {
			c.salarii = NULL;
		}
		
		input >> c.esteVegana;
		int x = 10;
		input >> x;
		input >> c.adaos;
		return input;
	};
	bool operator<(Cofetarie c) {
		return this->nrAngajati < c.nrAngajati;
	}
	float& operator[](int index) {
		if (index >= 0 && index < this->nrAngajati) { //validam indexul
			return this->salarii[index];
		}
		else {
			throw "Indexul este in afara limitelor";
			//throw
			//try
			//catch
		}

	}
};
int Cofetarie::TVA = 9;

ostream& operator<<(ostream& output, Cofetarie c) {
	output << "Nume:" << c.nume << endl;
	output << "Nr angajati:" << c.nrAngajati << endl;
	if (c.salarii != NULL) {
		for (int i = 0; i < c.nrAngajati; i++) {
			output << c.salarii[i] << ",";
		}
	}
	output << "Are produse vegane:" << (c.esteVegana ? "DA" : "NU") << endl;
	output << "An deschidere:" << c.anDeschidere << endl;
	output << "Adaos:" << c.adaos << endl;
	output << "TVA:" << Cofetarie::TVA << endl;

	return output;

}
class CofetarieOnline : public Cofetarie { //3 tipuri de mostenire private public protected; pun : ca asa se face mostenirea 
	char* site;
	int nrColaboratori;
public:
	//const fara parametrii
	CofetarieOnline():Cofetarie() {
		this->site = NULL;
		this->nrColaboratori = 0;
		//atunci cand mostenim trb sa apelam constructorul din clasa parinte de-aia pun: Cofetarie()

	}
	//constructor cu parametrii
	CofetarieOnline(const char* site, int nrColaboratori, string nume, int nrAngajati, float* salarii, bool esteVegana, const int anDeschidere, float adaos):Cofetarie(nume,nrAngajati,esteVegana,anDeschidere,adaos) {

		this->site = new char[strlen(site) + 1];
		strcpy_s(this->site, strlen(site) + 1, site);
		this->nrColaboratori = nrColaboratori;
		//apelam setterul pt ca in noua noastra clasa nu avem salarii
		this->setNrAngajati(nrAngajati, salarii);//este metoda, cand avem metotda sau functie ()

	}
	//destructor
	~CofetarieOnline() {
		if (this->site != NULL) {
			delete[]this->site;
		}

	}
	//cand avem campuri de alocare dinamica trb sa avem op =
	 
	
	//constructo de copiere
	CofetarieOnline(CofetarieOnline& co): Cofetarie (co) {  //up casting inseamna //un obiect de tipul clase fiu poate fi folosit si ca tip parinte 

		this->site = new char[strlen(co.site) + 1];
		strcpy_s(this->site, strlen(co.site) + 1,co.site);
		this->nrColaboratori = co.nrColaboratori;
		//apelam setterul pt ca in noua noastra clasa nu avem salarii
		//this->setNrAngajati(nrAngajati, salarii); //pentru ca e copiat deja 
		 
	}
	CofetarieOnline operator=(const CofetarieOnline& co) {  //nu avem lista pt ca e doar la constructor lista
		// destructor+const de copiere+
		if (this != &co) { ////pt a evita sa copiez acelasi oboect de doua ori autoasignare
			Cofetarie::operator=(co);
			if (this->site != NULL) {
				delete[]this->site;
			}
			this->site = new char[strlen(co.site) + 1];

			strcpy_s(this->site, strlen(co.site) + 1, co.site);
			this->nrColaboratori = co.nrColaboratori;
		
		}
		return *this;
	}
	//operator <<
	friend ostream& operator<<(ostream& out, const CofetarieOnline& co);   //asa se face la mostenire 


	explicit operator int() { //cast la int 
		return this->nrColaboratori;
	}
	float getNrMediuAngajatiPerColaborator() {
		//calculam media 
		return   this->getNrAngajati() / (float)this->nrColaboratori;
	}
};
ostream& operator<<(ostream& out, const CofetarieOnline& co) {
	out << (Cofetarie) co; //cast explicit 
	out << "Site-ul cofetariei : ";
	out << co.site;
	out << "Mr, colaboratori: ";
	out << co.nrColaboratori;
	out << endl;
	return out;
}

int main() {
	//ofstream fisier("Fisier.txt", ios::app); //out suprascrie
	////Cofetarie c("AnaPan", 4, 0, 1990, 10);
	//////declar un vector de tip float ca salariile sunt nr reale
	////float* vector = new float[4] {1000, 2000, 3000, 4000};
	//////apelam setter
	////c.setNrAngajati(4, vector);
	//////apelam ofstream
	////fisier << c;//afisare/scriere in fisier
	//Cofetarie c1("Constance", 5, 0, 1980, 16);
	//fisier << c1; //fisierul vechi va fi suprascris out suprascrie daca folosesc out ; app adauda 






	//fisier.close(); //care e dif intre metode si functie?  o met se apeleaza prin intermediul obiectului;ca sa apelam o met o apelam cu ()//inchiderea fisierului

	ifstream fisier2("Fisier.txt", ios::in);
	Cofetarie c3;
	fisier2 >> c3; //citim
	cout << c3;
	fisier2 >> c3;
	cout << c3;
	return 645;
	//in ostream nu folosim cout

}

////tot ce mostenesc pun in zona protected