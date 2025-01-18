#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

enum Tip {
	Volum, Uscat
};
class Sampon {
private:
	char* tipMiros;
	static int nrIngrediente;
	Tip tip;
	const float pret;
	int nrBucatiVandute;
public:


	char* gettipMiros() {
		return tipMiros;
	}
	void settipMiros(const char* tipMiros) {
		if (this->tipMiros != NULL) {
			delete[]this->tipMiros;
		}
		this->tipMiros = new char[strlen(tipMiros) + 1];
		strcpy(this->tipMiros, tipMiros);

	}
	Tip getTip() {
		return tip;
	}
	void setTip(Tip tipNou) {
		this->tip = tipNou;
	}
	int getNrBucatiVandute() {
		return nrBucatiVandute;
	}

	void setNrBucatiVandute(int nrBucatiVanduteNou) {
		this->nrBucatiVandute = nrBucatiVanduteNou;
	}
	//constructor cu parametrii
	Sampon() :pret(30) {
		this->tipMiros = new char[20];
		strcpy(tipMiros, "Dulce");
		this->tip = Volum;
		this->nrBucatiVandute = 5;
	}
	//constructor cu parametrii
	Sampon(char* tipMiros, Tip tip, int nrBucatiVandute, float pretNou) :pret(pretNou) {
		this->tipMiros = new char[strlen(tipMiros) + 1];
		strcpy(this->tipMiros, tipMiros);
		this->tip = tip;
		this->nrBucatiVandute = nrBucatiVandute;

	}
	//constructor de copiere
	Sampon(const Sampon& s) :pret(s.pret) {
		this->tipMiros = new char[strlen(s.tipMiros) + 1];
		strcpy(this->tipMiros, s.tipMiros);
		this->tip = s.tip;
		this->nrBucatiVandute = s.nrBucatiVandute;

	}
	//destructor
	~Sampon() {
		delete[] tipMiros;
	}

	friend ostream& operator<<(ostream& out, const  Sampon& s) {



		out << "Tip Miros: " << s.tipMiros << endl;
		if (s.tip == 0) {
			out << "Tip:Volum" << endl;
		}
		else {
			out << "Tip:Uscat" << endl;
		}
		out << "Pret: " << s.pret << endl;
		out << "NrbucVandute: " << s.nrBucatiVandute << endl;
		return out;

	}
	Sampon operator=(const Sampon& s) {
		if (&s != this) {
			if (this->tipMiros != NULL) {
				delete[]this->tipMiros;

			}
			this->tipMiros = new char[strlen(s.tipMiros) + 1];
			strcpy(this->tipMiros, s.tipMiros);
			this->tip = s.tip;
			this->nrBucatiVandute = s.nrBucatiVandute;

		}
		return *this;
	}


};
int Sampon::nrIngrediente = 0;

class Crema {
private:

	bool estedeMaini;
	int* valabilitate;
	static string marca;
	const float pret;
	float gramaj;
	int lunaDeschidere;
public:
	bool getEstedeMaini() {
		return this->estedeMaini;
	}
	void setEstedeMaini(bool estedeMainiNou) {
		this->estedeMaini = estedeMainiNou;
	}
	int* getValabilitate() {
		return this->valabilitate;
	}
	void setValalilitate(int lunaDeschidere, int* ValabilitateNou) {
		if (lunaDeschidere > 0){
			this->lunaDeschidere = lunaDeschidere;
			if (this->valabilitate != NULL) {
				delete[]this->valabilitate;
			}
			this->valabilitate = new int[this->lunaDeschidere];
			for (int i = 0; i<this->lunaDeschidere; i++) {
				this->valabilitate[i] = ValabilitateNou[i];
			}


		}
	}
	int getlunaDeschidere() {
		return this->lunaDeschidere;
	}
	int getGramaj() {
		return this->gramaj;
	}
	void setGramaj(int  gramajNou) {
		this->gramaj = gramajNou;
	}
	//fara parametrii
	Crema() :pret(20) {
		this->estedeMaini = 1;
		this->valabilitate = new int[3];
		for (int i = 0; i < 3; i++) {
			this->valabilitate[i] = i * 4;
		}
		this->gramaj = 300;
		this->lunaDeschidere = 3;


	}
	//cu parametrii

	Crema(bool estedeMaini, int* valabilitate, float pretNou, float gramaj, int lunaDeschidere) :pret(pretNou) {
		this->estedeMaini = estedeMaini;

		this->valabilitate = new int[lunaDeschidere];
		for (int i = 0; i < lunaDeschidere; i++) {
			this->valabilitate[i] = valabilitate[i];
		}
		this->gramaj = gramaj;
		this->lunaDeschidere = lunaDeschidere;

	}
	//de copiere
	Crema(const Crema& c) :pret(c.pret) {
		this->estedeMaini = c.estedeMaini;

		this->valabilitate = new int[c.lunaDeschidere];
		for (int i = 0; i < c.lunaDeschidere; i++) {
			this->valabilitate[i] = c.valabilitate[i];
		}
		this->gramaj = c.gramaj;
		this->lunaDeschidere = c.lunaDeschidere;

	}
	Crema operator=(const Crema& c) {
		if (&c != this) {
			this->estedeMaini = c.estedeMaini;

			this->valabilitate = new int[c.lunaDeschidere];
			for (int i = 0; i < c.lunaDeschidere; i++) {
				this->valabilitate[i] = c.valabilitate[i];
			}
			this->gramaj = c.gramaj;
			this->lunaDeschidere = c.lunaDeschidere;
		}
		return *this;

	}
	~Crema() {
		if (valabilitate) {
			delete[] valabilitate;
		}
	}
	friend ostream& operator<<(ostream& out, const Crema& c) {

		out << "Este de maini" << c.estedeMaini << endl;
		out << "Luna deschidere" << c.lunaDeschidere << endl;
		out << "Valabilitatea este: ";
		if (c.valabilitate != NULL) {
			for (int i = 0; i < c.lunaDeschidere; i++) {
				out << c.valabilitate[i] << ", ";
			}
		}
		out << endl;
		out << "Pretul e: " << c.pret << endl;
		out << "Gramaj: " << c.gramaj << endl;
		return out;
	}


};
string Crema::marca = "Wash";

enum Ingrediente {
	Lavanda, Margaritar
};
class Parfum {
private:

	string nume;
	const int idStoc;
	float* pret;
	static int luniValabilitate;
	Ingrediente nota_principala;
	int nrBucati;

public:
	string getnume() {
		return this->nume;
	}
	void setNume(string NumeNou) {
		if (NumeNou.length() > 1) {
			this->nume = NumeNou;
		}
	}
	Ingrediente getNota_Principala() {
		return this->nota_principala;
	}
	void setNota_Principala(Ingrediente nota_principala_nou) {
		this->nota_principala = nota_principala_nou;
	}
	int getNrBucati() {
		return nrBucati;
	}
	float* getpret() {
		return this->pret;
	}

	void setnrBucati(int nrBucati, float* pret) {
		if (nrBucati > 0) {
			this->nrBucati = nrBucati;
		    if (this->pret != NULL) {
				delete[]this->pret;
			}
			this->pret = new float(this->nrBucati);
			for (int i = 0; i < nrBucati; i++) {
				this->pret[i] = pret[i];
			}
		}
	}



	Parfum() :idStoc(1) {
		this->nume = "Rosa";
		this->nrBucati = 4;
		this->pret = new float[4];
		for (int i = 0; i < 4; i++) {
			this->pret[i] = 1 + i * 2;
		}
		this->nota_principala = Lavanda;


	}
	//fara param

	Parfum(string nume, int idStocNou, float* pret, Ingrediente nota_principala, int nrBucati) : idStoc(idStocNou) {
		this->nume = nume;
		this->nrBucati = nrBucati;
		this->pret = new float[nrBucati];
		for (int i = 0; i < nrBucati; i++) {
			this->pret[i] = pret[i];
		}
		this->nota_principala = nota_principala;

	}

	//de copiere
	Parfum(const Parfum& p) : idStoc(p.idStoc) {
		this->nume = p.nume;
		this->pret = new float[p.nrBucati];
		for (int i = 0; i < p.nrBucati; i++) {
			this->pret[i] = p.pret[i];
		}

	}
	Parfum operator=(const Parfum& p) {
		if (&p != this) {
			this->nume = p.nume;
			this->pret = new float[p.nrBucati];

			for (int i = 0; i < p.nrBucati; i++) {
				this->pret[i] = p.pret[i];
			}
			return *this;
		}
	}
	~Parfum() {
		if (pret) {
			delete[] pret;
		}
	}

	friend ostream& operator<<(ostream& out, Parfum& p) {


		out << "Nume: " << p.nume << endl;
		out << "nrBucati" << p.nrBucati << endl;
		out << "Pretul este: ";
		if (p.pret != NULL) {
			for (int i = 0; i < p.nrBucati; i++) {
				out << p.pret[i] << " ";
			}

		}
		out << endl;
		if (p.nota_principala == 0) {
			out << "Tip:Lavanda" << p.nota_principala << endl;
		}
		else {
			out << "Tip:Margaritar" << p.nota_principala << endl;
		}
		out << "Numar bucati" << p.nrBucati << endl;
		return out;
	}

};
int Parfum::luniValabilitate = 12;


int main() {
	Sampon s1;
	cout << s1 << endl;

	Sampon s2((char*)"Dulce", Tip::Uscat, 10, 4.7);
	cout << s2<<endl;

	Sampon s3;
	s3 = s2;
	cout << s3<<endl;

	int valabilitate[] = { 10 , 11,12 };
	Crema c1;
	cout << c1<<endl;

	Crema c2(1, valabilitate, 7.5, 207, 3);
	cout << c2<<endl;

	Crema c3;
	c3 = c2;
	cout << c3;

	Parfum p1;
	cout << p1<<endl;

	float preturi[] = { 100.5, 150.3, 140, 199.9 ,4 };

	Parfum p2("La vie e belle", 1, preturi, Lavanda, 4);
	cout << p2<<endl;

	Parfum p3;
	p3 = p2;
	cout << p3<<endl;

	//apel seter
	/*Apel setter: Se apeleaza toti la fel       
	e4.setScoala("Nr 3");
	e4.setNrNote(4);
	int nr_n[] = { 4,5,6,7 };
	e4.setNote(4, nr_n);*/

	

	Sampon s4;
	s4.settipMiros("Floral");
	Sampon s5;
	s5.setTip(Uscat);
	Sampon s6;
	s6.setNrBucatiVandute(7);
	cout << s4<<endl;
	cout << s5<<endl;
	cout << s6<<endl;

	Crema c4;
	c4.setEstedeMaini(1);
	cout << c4<<endl;
	Crema c5;
	c5.setGramaj(500);
	cout << c5<<endl;

	Crema c6;
	int lunadeschidere[] = { 6,8,12,7 };
	c6.setValalilitate(3, lunadeschidere);
	cout << c6<<endl;

	
}