//#include<iostream>
//
//using namespace std;
//
//class Angajat {
//protected:
//	int marca;
//	string nume;
//	float salariu;
//
//
//public:
//	Angajat() {
//		this->marca = 1234;
//		this->nume = "No name";
//		this->salariu = 3000;
//
//	}
//
//	Angajat(int marca, string nume) {
//		this->marca = marca;
//		this->nume = nume;
//		this->salariu = salariu;
//	}
//
//	virtual float getVenitIncasat() = 0;
//
//	float getSalariu() {
//		return this->salariu;
//	}
//};
//
//class Manager : public Angajat {
//private:
//	int nrSubordonati;
//	float sporPerAngajat;
//
//public:
//	Manager() :Angajat() {
//		//apelam din clasa angajat vnh
//		this->nrSubordonati = 0;
//		this->sporPerAngajat = 0;
//
//
//
//	}
//
//	Manager(int nrSubordonati, float sporPerAngajat) {
//		this->nrSubordonati = nrSubordonati;
//		this->sporPerAngajat = sporPerAngajat;
//	}
//
//	float getSporConducere() {
//		return this->sporPerAngajat;
//
//
//	}
//
//};
//
//class ManagerDepartament :public Manager {
//private:
//	string numeDepartament;
//	bool deCercetare;
//
//public:
//	ManagerDepartament() :Manager() {
//		//apelam constructorul fara parametrii
//		this->numeDepartament = "Departament";
//		this->deCercetare = false;
//
//	}
//
//	ManagerDepartament(string nume, bool deCercetare) {
//		this->numeDepartament = nume;
//		this->deCercetare = deCercetare;
//	}
//
//	float getVenitIncasat() {
//		float venit = this->salariu;
//		if (this->deCercetare) {
//			venit += (10 / 100) * salariu;
//		}
//		return venit;
//	}
//};
//
//class ManagerDeProiect :public Manager {
//private:
//	string numeProiect;
//	int nrZile;
//	float sporPerZi;
//
//public:
//	ManagerDeProiect(string numeProiect, int nrZile, int nrSubordonati, float sporPerSubordonat) :Manager() {
//		this->numeProiect = numeProiect;
//		this->nrZile = nrZile;
//	}
//
//
//};
//
//
//
//template<class T>
//class Vector {
//	int nrElemente;
//	T** elemente;
//public:
//	Vector() {
//		this->nrElemente = 0;
//		this->nrElemente = NULL;
//
//	}
//
//	Vector(int nr, T** elemente) {
//		this->nrElemente = nr;
//		this->nrElemente = new T * [nr];
//		for (int i = 0; i < nr; i++) {
//			this->nrElemente[i] = new T(*elemente[i]);
//		}
//	}
//
//	Vector(const Vector& v) {
//		this->nrElemente = v.nrElemente;
//		this->elemente = new T * [v.nrElemente];
//		if (v.nrElemente) {
//			for (int i = 0; i < v.nrElemente; i++) {
//				this->nrElemente[i] = new T(*(v.elemente[i]));
//			}
//		}
//		else {
//			this->elemete = NULL;
//		}
//	}
//
//
//
//	~Vector() {
//		if (this->elemente) {
//			for (int i = 0; i < this->nrElemente; i++) {
//				delete[]this->elemente;
//			}
//		}
//	}
//
//	void adaugaElement(T* elementNou) {
//		T** aux = new T * [this->nrElemente + 1];
//		for (int i = 0; i < this->nrElemente; i++) {
//			aux[i] = this->elemente[i];
//			aux[this->nrElemente] = elementNou;
//			
//		}
//		if (this->elemente) {
//			delete[]this->elemente;
//		}
//this->nrElemente++;
//		this->elemente = aux;
//	}
//
//	int getNrElemente() {
//		return this->nrElemente;
//	}
//};
//		int main() {
//			ManagerDepartament* m1 = new ManagerDepartament("ABC", 1);
//			Vector<Angajat> Manageri;  // Constructor implicit
//			Manageri.adaugaElement(m1);
//			cout << Manageri.getNrElemente();
//			return 0;
//		}
//		
//
//// late biding la momentul executiei
//// earlybiding la momentul compilarii