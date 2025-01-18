///*Gandi?i-v? la ce informa?ii trebuie s? re?ine?i pentru un bloc. Exemplu: strada, num?r sc?ri, num?r apartamente, ?i altele. C?uta?i minim 5 caracteristici.
//
//Realiza?i o structura în care v? declara?i atribute pentru toate aceste caracteristici ale blocului. 
//
//Realizati un program in C++ care sa creeze un vector cu 10 blocuri.
//
//Programul trebui s? citeasc? de la tastatur? valori pentru toate aceste caracteristici ale tuturor blocurilor din vector.
//
//Realizati o functie de citire a valorilor, astfel incat sa o puteti apela de 10 ori (cele 10 blocuri).
//
//Implementati o functie care sa afi?eze într-o propozi?ie toate valorile retinute de un bloc. Exemplu: “Blocul de pe strada Maresal Averescu, are 4 scari si un numar total de 54 de apartamente.”. Trebuie sa realizati o propozitie cu toate cele 5 caracteristici.
//
//Apelati aceasta functie pentru toate blocurile din vector.
//
//
//
//Incercati sa realizati un vector de pointeri la Bloc si sa folositi functiile de mai devreme pentru acest vector de pointeri.*/
//
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//struct Bloc {
//    string strada;
//    int numarScara;
//    int numarApartamente;
//    int anConstructie;
//    int etaje;
//};
//void citireBloc(Bloc* b) {
//    cout << "Blocul numarul :";
//
//    cout << "Strada: ";
//    cin >> b->strada;
//
//    cout << "Numar scara: ";
//    cin >> b->numarScara;
//
//    cout << "Numar apartamente: ";
//    cin >> b->numarApartamente;
//
//    cout << "An constructie: ";
//    cin >> b->anConstructie;
//
//    cout << "Numar etaje: ";
//    cin >> b->etaje;
//    cout << endl;
//}
//
//void afisarePropozitie(Bloc* b) {
//    cout << "Blocul se afla pe strada " << b->strada
//        << "si are " << b->numarScara
//        << " scari cu un nr de apartamente de "
//        << b->numarApartamente << " apartamente. "
//        << "A fost construit in anul " << b->anConstructie
//        << " si are " << b->etaje << " etaje" << endl;
//}
//
//int main() {
//    // Crearea unui vector de pointeri la Bloc (10 elemente)
//    Bloc* blocuri[10];
//
//    // Alocarea dinamica a memoriei pentru fiecare bloc
//    for (int i = 0; i < 10; i++) {
//        blocuri[i] = new Bloc;  // Alocare dinamic? pentru fiecare bloc
//    }
//
//    // Citirea caracteristicilor pentru fiecare bloc
//    for (int i = 0; i < 10; i++) {
//        cout << "blocul numarul " << i + 1 << endl;
//        citireBloc(blocuri[i]);  // Apelarea functiei de citire pentru fiecare bloc
//    }
//
//    // Afi?area detaliilor pentru fiecare bloc sub forma unei propozi?ii
//    cout << "blocul numarul:";
//    for (int i = 0; i < 10; i++) {
//        afisarePropozitie(blocuri[i]);  // Apelarea functiei de afisare pentru fiecare bloc
//    }
//
//    // Eliberarea memoriei alocate pentru fiecare bloc
//    for (int i = 0; i < 10; i++) {
//        delete blocuri[i];  // Eliberare memorie
//    }
//
//    return 0;
//}
