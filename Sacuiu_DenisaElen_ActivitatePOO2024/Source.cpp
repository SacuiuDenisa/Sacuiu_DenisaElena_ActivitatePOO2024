#include<iostream>
using namespace std;
struct Farmacie {
	char* nume;
	string adresa;
	int nrMedicamente;
	float* preturi;
};
void afisareFarmacie(Farmacie f) {
	cout << "Nume:" << f.nume << endl;
	cout << "Adresa:" << f.adresa << endl;
	cout << "Numar medicamente:" << f.nrMedicamente << endl;
	cout << "Preturi: ";
	for (int i = 0; i < f.nrMedicamente; i++) {
		cout << f.preturi[i] << ",";
	}

}
Farmacie citireFarmacie() {
	Farmacie f;
	cout << "La ce adresa este?: ";
	cin >> f.adresa;
	cout << "Numele farmaciei: ";
	char buffer[100];
	cin >> buffer;
	f.nume = new char[strlen(buffer) + 1];
	strcpy_s(f.nume, strlen(buffer) + 1, buffer);
	cout << "Numarul de medicamente";
	cin >> f.nrMedicamente;
	f.preturi = new float[f.nrMedicamente];
	for (int i = 0; i < f.nrMedicamente; i++) {
		cin >> f.preturi[i];
	}
	return f;
}

int main() {

	Farmacie* pointer;//declarare pointer la farmacie-pe stack
	pointer = new Farmacie;//alocam spatiu acestui pointer in heap
	pointer->adresa = "Romana";//initializare
	pointer->nume = new char[strlen("Catena") + 1]; //nu merge pt ca nu e dresa Catena
	strcpy_s(pointer->nume, strlen("Catena") + 1, "Catena");
	pointer->nrMedicamente = 5;
	pointer->preturi = new float[pointer->nrMedicamente];
	for (int i = 0; i < pointer->nrMedicamente; i++) {
		pointer->preturi[i] = i + 1;
	}
	afisareFarmacie(*pointer);
	//declaram un vector de farmacii :int v[100] alocat static si nu e bine
	//int *v;vector alocat dinamic
	delete pointer;
	int nrFarmacii = 3;
	Farmacie* vector; //declararea
	vector = new Farmacie[nrFarmacii]; //[] pt ca avem vector alocam memorie alocam memorie
	//declar vector de pointer la farmacie
	//Farmacie** pointeri;
	//pointeri = new Farmacie * [4]; //dupa new adaugam tipul adica farmacie*
	for (int i = 0; i < nrFarmacii; i++) {
		vector[i] = citireFarmacie();

	}
	for (int i = 0; i < nrFarmacii; i++) {
		delete[]vector[i].nume;
		delete[]vector[i].preturi;

	}
	delete[]vector;
	for (int i = 0; i < nrFarmacii; i++) {
		afisareFarmacie(vector[i]);
	}
	return 0;
}