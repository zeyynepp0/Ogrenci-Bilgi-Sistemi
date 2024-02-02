#include <iostream>
#include "Ogrenci.h"
#include "Main.h"
#include <list>

using namespace std;



void menuyuGoster() {
	cout << " * * * * * * * * *\n";
	cout << " *               *\n";
	cout << " *      MENU     *\n";
	cout << " *               *\n";
	cout << " * * * * * * * * *\n";
	cout << "1. Yeni Kayit ekle\n";
	cout << "2. Tum Listeyi Goster\n";
	cout << "3. Ogrenci id ye gore Kayit Sil\n";
	cout << "4. Ogrenci ara\n";
	cout << "5. Cikis\n";
}


void ogrenciEkle(list<Ogrenci>* lst) {
	int  id;
	string ad, soyad, isim;
	int sinavNot;
	cout << "Lutfen ogrenci id giriniz: ";
	cin >> id;
	cout << "Ad giriniz: ";
	cin >> ad >> soyad;
	isim = ad + " " + soyad;
	cout << "sinav notu giriniz: ";
	cin >> sinavNot;
	Ogrenci ogr(id, isim, sinavNot);
	lst->push_back(ogr);
}


void showList(list<Ogrenci>* lst) {
	list<Ogrenci>::iterator it;
	cout << endl << "- - - - Tum Ogrenci listesi - - - -\n";
	for (it = lst->begin(); it != lst->end(); it++) {
		it->bilgileriYaz();
	}
	cout << endl;
}

void ogrenciSil(list<Ogrenci>* lst) {
	int id;
	cout << "Lutfne silinecek ogrencinin id giriniz: ";
	cin >> id;
	list<Ogrenci>::iterator it;
	for (it = lst->begin(); it != lst->end(); it++) {
		if (it->getId() == id) 
			break;
	}	
	if (it == lst->end())
		cout << "belirtilen id bulunamamistir, silme yapilamadi!";
	else
		lst->erase(it);
}

void ogrenciAra(list<Ogrenci>* lst) {
	int id;
	cout << "Lutfne aranacak ogrencinin id giriniz: ";
	cin >> id;
	list<Ogrenci>::iterator it;
	for (it = lst->begin(); it != lst->end(); it++) {
		if (it->getId() == id)
			break;
	}
	if (it == lst->end())
		cout << "belirtilen id bulunamamistir!";
	else {
		cout << endl << "Aradiginiz ogrencini bilgileri: \n";
		it->bilgileriYaz();
		cout << endl;
	}
		
}

int main() {

	list<Ogrenci>* ogrenciList = new list<Ogrenci>();


	int secim = 0;
	do {
		menuyuGoster();
		cout << "seciminiz: ";
		cin >> secim;
		if (secim == 1)
			ogrenciEkle(ogrenciList);
		else if (secim == 2)
			showList(ogrenciList);
		else if (secim == 3)
			ogrenciSil(ogrenciList);
		else if (secim == 4)
			ogrenciAra(ogrenciList);
		else if (secim == 5)
			break;
		else
			cout << "Hatali secim yaptiniz, yeniden deneyin!\n";

	} while (secim != 5);


	return 0;
}