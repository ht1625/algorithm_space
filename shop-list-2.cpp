#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <locale.h>
using namespace std;

/*
void diz(int examp[],int k) { // dizinin boyutunu  i�ine yazmana gerek yok , bu �ekilde de �al���r
	for (int i = 0; i <k; i++) {
		cout << examp[i] << " ";
	}
}
int main() {
	int dizi[4] = { 85,96,14,23 };
	diz(dizi,4);
	return 0;
} */



/*
int main() {
	int x = 49;
	int fit = static_cast<int>(x / 6);//b�l�m�n ondal�kl� k�sm�n� al�yor virg�lden sonras�n� alm�yor
	cout << fit;
	return 0;
}*/



/*
struct  renk {
	string t��rtrengi;
	string kotrengi;
};
class daire {
	int x, y;
	renk dolgurengi;
public:
	daire(int s1, int s2, renk dr ) {
		x = s1;
		y = s2;
		dolgurengi = dr;
	}
	void yaz();
};
void daire::yaz() {
	cout << "toplamlar�:" << x + y << endl;
	cout << "renkler:" << dolgurengi.kotrengi << " " << dolgurengi.t��rtrengi << endl;
}
int main() {
	renk rengimiz;
	rengimiz.kotrengi = "blue";
	rengimiz.t��rtrengi = "red";
	daire onedaire( 98, 56, rengimiz);
	onedaire.yaz();
	return 0;
}*/



/*
class  renk {
	string t��rtrengi;
	string kotrengi;
public:
	//renk() {} ;
	renk(string s1, string s2) :t��rtrengi(s1), kotrengi(s2) {}
	void yazd�r() {
		cout << t��rtrengi << " " << kotrengi;
	}
};
class daire {
	int x;
	string  y;
	renk dolgurengi;
public:
    daire (int s1, string s2 ,renk y):x(s1) , y(s2) , dolgurengi(y) {} // bunu yukardaki classta bo� construcyor olmadan da �al���yor
	daire(int s, string y1, renk k) {
		x = s;
		y = y1;
		dolgurengi=k;
	}
	void yaz();
};
void daire::yaz() {
	cout << "toplamlar�:" << x <<" "<< y << endl;
	cout << "renkler:";
	dolgurengi.yazd�r();
}
int main() {
	renk rengimiz("blue", "red");
	daire onedaire(98, "rmflemfe", rengimiz);
	onedaire.yaz();
	return 0;
}*/


/*
struct �r�n�zellkleri {
	string �r�nad�;
	int �r�nmiktar�;
	bool �r�ndurumu=false;
};
class cratelist {
	vector<�r�n�zellkleri>�r�n�zell;
	public:
	cratelist() {};
	void addtoeleman();
	void deletetoeleman(int listnum);
	void makesembyol();
	void showeleman();
};
vector<cratelist>Lists;
void deletelist(int s�ra) {
	Lists.erase(Lists.begin() + s�ra - 1);
}
void cratelist::showeleman() {
	for (int i = 0; i <�r�n�zell.size(); i++) {
		cout << i + 1 << "-) " << �r�n�zell[i].�r�nad�;
		if (�r�n�zell[i].�r�ndurumu == true) {
			cout << "*    ";
		}
		else { cout << "    "; }
	}
	cout << "\n";
}
void cratelist::addtoeleman() {
	�r�n�zellkleri temp;
	string boool;
	cout << "\n�r�n�n ad�n� giriniz:";
	cin >> temp.�r�nad�;
	cout << "�r�n�n miktar�n� giriniz:";
	cin >> temp.�r�nmiktar�;
	cout << "�r�n� i�aretlemek i�in True yoksa False yaz�n�z! ";
	cin >>boool;
	if (boool == "true" || boool=="True") { temp.�r�ndurumu = true; }
	�r�n�zell.push_back(temp);
}
void cratelist::deletetoeleman(int listnum) {
	showeleman();
	int secim;
	cout << "\nSilmek istedi�iniz �r�n�n s�ras�n� giriniz:";
	cin >> secim;
	�r�n�zell.erase(�r�n�zell.begin()+secim - 1);
	if (�r�n�zell.size() == 0) { deletelist(listnum); }
}
void cratelist::makesembyol() {
	showeleman();
	int secim;
	cout << "\n��aretlemek istedi�iniz �r�n�n s�ras�n� giriniz:";
	cin >> secim;
	�r�n�zell[secim - 1].�r�ndurumu = true;
}
int main() {
	setlocale(LC_ALL, "Turkish");
	bool door = true;
	int choose;
	cout << "Welcome to shopping list! :))";
	while (door) {
		cout << "\n\nListe olu�turmak i�in 1'e bas�n!\n";
		cout << "Liste silmek i�in 2'ye bas�n�z!\n";
		cout << "Liste �zerinde i�lem yapmak i�in 3'e bas�n�z!\n";
		cin >> choose;
		if (choose == 1) {
			int sayac;
			cout << "\nKa� �r�n eklemek istersiniz:";
			cin >> sayac;
			cratelist list1;
			for (int i = 0; i < sayac; i++) {
				list1.addtoeleman();
			}
			Lists.push_back(list1);

		}
		else if (choose == 2) {
			for (int i = 0; i < Lists.size(); i++) { Lists[i].showeleman(); }
			int sayac1;
			cout << "\nSilmek istedi�iniz listenin s�ras�n�  giriniz:";
			cin >> sayac1;
			deletelist(sayac1);
		}
		else if (choose == 3) {
			int listnum, elemannum;
			cout << "\n��lem yapmak istedi�iniz listenin s�ras�n� giriniz:";
			cin >> listnum;
			cout << "\nEleman eklemek i�in 1'e bas�n!\n";
			cout << "Eleman silmek i�in 2'ye bas�n�z!\n";
			cout << "Eleman i�aretlemek istiyorsan�z 3'e bas�n�z!\n";
			cin >> elemannum;
			if (elemannum == 1) {
				Lists[listnum - 1].addtoeleman();
			}
			else if (elemannum == 2) {
				Lists[listnum - 1].deletetoeleman(listnum);
			}
			else if (elemannum == 3) {
				Lists[listnum - 1].makesembyol();			
			}
		}
		int df;
		cout << "\n\n��k�� yapmak istiyorsan�z 1'e yoksa 2'ye bas�n�z:";
		cin >> df;
		if (df == 1) { door = false; break; }
	}
	return 0;
}*/


/*
struct lisnum {
	int mik;
	string name;
	bool dor;
};
class d {	
	vector<lisnum>list;
public:
	d() {};
	void kl();
};
void d::kl() {
	lisnum temp;
	cout << "\neleman ad� gir:";
	cin >> temp.name;
	cout << "\n�r�n mikt:";
	cin >> temp.mik;
	cout << "bool durumu.";
	cin >> temp.dor;
	list.push_back(temp);
}
int main() {
	d listem;
	bool fg;
	for (int i = 0; i < 5; i++) {
		//listem.kl();
		cin >> fg;
		cout << "kmded";
	}
	return 0;
}*/


