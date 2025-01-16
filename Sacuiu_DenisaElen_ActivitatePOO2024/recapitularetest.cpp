//#include<iostream>
//#include <cstring>
//using namespace std;
//enum shoptype { LOCATION, ONLINE };
//class FlowerShop {
//private:
//	const int shopId;
//	char* nume;
//	shoptype type;
//	bool hasWebsite = false;
//	string url;
//	int soldflowers;
//	static const float  AVERAGE_FLOWER_PRICE;
//public:
//	FlowerShop(int shopId, const char* shopnume, shoptype shoptype, int soldflowers) : shopId(shopId), type(shoptype), soldflowers(soldflowers > 0 ? soldflowers : 0) {
//		nume = new char[strlen(shopnume) + 1];
//		strcpy(nume, shopnume);
//	}
//	//-shopId nu are nevoie sa i se schimbe numele pentru ca e de tipul int; ->int shopId shopId
//	//-nume are nevoie sa i se schimbe numele pentru ca e de tipul char* si punem const in fata pentru ca 
//	//nu vrem sa i se schimbe valoare si de-aia atunci cand il sdeclaram in constructor ii punem alt nume ->const char* shopnume
//	//-shoptype shoptype are structura asta pentru ca este enum
//	//soldflowers nu are nevoie sa i se schimbe numele pentru ca e de tipul int ->int shopflowers 
//	//lui nume ii alocam memorie separat pentru ca e de tipul char*
//
//	~FlowerShop() {
//		delete[]nume;
//	}
//	//dezalocam unde am alocat mai sus mai exact ce a avut char*
//	FlowerShop(const FlowerShop& other) : shopId(other.shopId), type(other.type), hasWebsite(other.hasWebsite), url(other.url), soldflowers(other.soldflowers) {
//		nume = new char[strlen(other.nume) + 1];
//		strcpy(nume, other.nume);
//	}
//	//geteri si setteri pentru nume
//
//	const char* getnume() const {
//		return nume; //geter
//
//	}
//	void setnume(const char* newnume) {
//		delete[] nume;
//		nume = new char[strlen(newnume) + 1];
//		strcpy(nume, newnume);
//	}
//	//id (read)
//	const int getshopId() const {
//		return shopId;
//	}
//	//number of sold flowers (read and write)
//	int getsoldflowers() const {
//		return soldflowers;
//	}
//	void setsoldflowers(int newsoldflowers) {
//		if (newsoldflowers > 0) {
//			soldflowers = newsoldflowers;
//		}
//	}
//	// Suprascrierea operatorului de stream <<
//	friend ostream& operator<<(ostream& out, const FlowerShop& shop) {
//		out << "ID: " << shop.shopId << ", Name: " << shop.nume << ", Type: "
//			<< (shop.type == ONLINE ? "ONLINE" : "LOCATION")
//			<< ", Website: " << (shop.hasWebsite ? shop.url : "No website")
//			<< ", Sold Flowers: " << shop.soldflowers;
//		return out;
//	}
//
//};
//
//int main() {
//	FlowerShop f1(1, "Maria", ONLINE, 15);
//	cout << "Initial f1 :" << f1 << endl;
//	FlowerShop f3 = f1;
//	cout << "f3 (copied from f1): " << f1 << endl;
//}