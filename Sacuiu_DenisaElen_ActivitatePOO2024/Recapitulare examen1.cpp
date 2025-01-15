#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

enum vedereCamera {
	laMunte = 1, inStrada = 2
};


class CameraHotel {
	const int nrCamera;
protected:
	char* tip;
	vedereCamera vedere;
	int etaj;
	int nrFacilitati;
	string* facilitati;
	bool rezervata;
public:
	CameraHotel(int nrCamera, const char* tip, vedereCamera vedere, int etaj, int nrFacilitati, string* facilitati, bool rezervata) :nrCamera(nrCamera) {
		this->tip = new char[strlen(tip) + 1];
		strcpy(this->tip, tip);
		this->vedere = vedere;
		this->etaj = etaj;
		this->nrFacilitati = nrFacilitati;
		this->facilitati = new string[this->nrFacilitati];
		for (int i = 0; i < this->nrFacilitati; i++) {
			this->facilitati[i] = facilitati[i];
		}
		this->rezervata = rezervata;
	}

	CameraHotel(const CameraHotel& c) :nrCamera(c.nrCamera) {
		this->tip = new char[strlen(c.tip) + 1];
		strcpy(this->tip, c.tip);
		this->vedere = c.vedere;
		this->etaj = c.etaj;
		this->nrFacilitati = c.nrFacilitati;
		this->facilitati = new string[this->nrFacilitati];
		for (int i = 0; i < this->nrFacilitati; i++) {
			this->facilitati[i] = c.facilitati[i];
		}
		this->rezervata = c.rezervata;
	}
	CameraHotel() :nrCamera(0) {
		this->tip = new char[strlen("Single") + 1];
		strcpy(this->tip, "Single");
		this->vedere = inStrada;
		this->etaj = 0;
		this->nrFacilitati = 0;
		this->facilitati = NULL;
		this->rezervata = 0;
	}
	CameraHotel(int etaj) :nrCamera(0) {
		this->tip = new char[strlen("Single") + 1];
		strcpy(this->tip, "Single");
		this->vedere = inStrada;
		this->etaj = etaj;
		this->nrFacilitati = 0;
		this->facilitati = NULL;
		this->rezervata = 0;
	}
	
	~CameraHotel() {
		if (this->tip != NULL) {
			delete[]this->tip;
		}
		if (this->facilitati != NULL) {
			delete[]this->facilitati;
		}
	}

	CameraHotel& operator=(const CameraHotel& c) {
		if (this != &c) {
			if (this->tip != NULL) {
				delete[]this->tip;
			}
			if (this->facilitati != NULL) {
				delete[]this->facilitati;
			}
			this->tip = new char[strlen(c.tip) + 1];
			strcpy(this->tip, c.tip);
			this->vedere = c.vedere;
			this->etaj = c.etaj;
			this->nrFacilitati = c.nrFacilitati;
			this->facilitati = new string[this->nrFacilitati];
			for (int i = 0; i < this->nrFacilitati; i++) {
				this->facilitati[i] = c.facilitati[i];
			}
			this->rezervata = c.rezervata;
			return *this;
		}
	}

	bool getRezervata() {
		return this->rezervata;
	}

	void setRezervata(bool rezervata) {
		if (rezervata == 0 || rezervata == false) {
			this->rezervata = false;
		}
		else {
			this->rezervata = true;
		}

	}
	int getEtaj() {
		return this->etaj;
	}
	vedereCamera getVedereCamera() {
		return this->vedere;
	}

	
	void setVedereCamera(vedereCamera vedere) {
		this->vedere = vedere;
	}

	friend ostream& operator<<(ostream& out, const CameraHotel& c) {
		out << c.nrCamera << " | " << c.tip << " | ";
		switch (c.vedere)
		{
		case 1: out << "vedere la Munte" << " | "; break;
		case 2: out << "vedere in Strada" << " | "; break;
		default:
			return out << "vedere la Munte" << " | "; break;
		}
		out << c.etaj << " | " << c.nrFacilitati << " | ";
		for (int i = 0; i < c.nrFacilitati; i++) {
			out << c.facilitati[i] << " | ";
		}
		out << c.rezervata << endl;
		return out;
	}

	friend istream& operator>>(istream& in, CameraHotel& c) {
		cout << "Introduceti tip: ";
		delete[]c.tip;
		char aux[100];
		in >> ws;
		in.getline(aux, 99);
		c.tip = new char[strlen(aux) + 1];
		strcpy(c.tip, aux);
		cout << "Introduceti tipul de vedere( 1-> vedere la munte, 2->vedere in strada): ";
		int tipVedere;
		in >> tipVedere;
		c.vedere = (vedereCamera)tipVedere;
		cout << "Introduceti etajul: ";
		in >> c.etaj;
		cout << "Introduceti numarul de facilitati: ";
		in >> c.nrFacilitati;
		delete[]c.facilitati;
		c.facilitati = new string[c.nrFacilitati];
		for (int i = 0; i < c.nrFacilitati; i++) {
			in >> ws;
			getline(in, c.facilitati[i]);
		}
		cout << "Este rezervata?(1-Da sau 0-Nu): ";
		in >> c.rezervata;
		return in;
	}
	CameraHotel& operator++() {
		CameraHotel copie = *this;
		delete[]this->facilitati;
		if (this->nrFacilitati == 0) {
			this->nrFacilitati = 1;
			this->facilitati = new string[this->nrFacilitati];
			this->facilitati[0] = "Wi-fi";
		}
		else {
			this->nrFacilitati++;
			this->facilitati = new string[this->nrFacilitati];
			for (int i = 0; i < copie.nrFacilitati; i++) {
				facilitati[i] = copie.facilitati[i];
			}
			facilitati[this->nrFacilitati - 1] = facilitati[this->nrFacilitati - 2];
		}

		return *this;
	}
	void tipCamera() {
		cout << "Camera este " << this->tip << endl;
	}

	bool operator~() {
		if (this->rezervata == true) {
			this->rezervata = false;
			return true;
		}
		else {
			this->rezervata = true;
			return false;
		}
	}

	explicit operator int() {
		return this->etaj;
	}
	void schimbaAtributele(CameraHotel& c, CameraHotel& c1) {
		CameraHotel copie = *this;
		(*this) = c;
		c = c1;
		c1 = copie;

	}
};
int main() {
	CameraHotel camera;
	cout << camera;

	CameraHotel c1(101, "Family", laMunte, 2, 1, new string[1]{ "Baie in camera" }, 1);
	CameraHotel c2(11, "Single", inStrada, 4, 3, new string[3]{ "Baie in camera","Wi-fi","Mini-bar" }, 0);
	CameraHotel c3(21, "Twin", laMunte, 5, 2, new string[2]{ "Baie in camera","Jacuzzi" }, 0);

	cout << c1 << endl;
	cout << c2 << endl;
	cout << c3 << endl;
	CameraHotel c4 = c3;
	cout << c4 << endl;
	c4 = c2;
	cout << c4 << endl;
	
	CameraHotel c5 = ++c2;
	cout << c5 << endl;
}