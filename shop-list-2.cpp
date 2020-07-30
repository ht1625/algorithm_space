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
void diz(int examp[],int k) { // dizinin boyutunu  içine yazmana gerek yok , bu þekilde de çalýþýr
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
	int fit = static_cast<int>(x / 6);//bölümün ondalýklý kýsmýný alýyor virgülden sonrasýný almýyor
	cout << fit;
	return 0;
}*/



/*
struct  renk {
	string tþörtrengi;
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
	cout << "toplamlarý:" << x + y << endl;
	cout << "renkler:" << dolgurengi.kotrengi << " " << dolgurengi.tþörtrengi << endl;
}
int main() {
	renk rengimiz;
	rengimiz.kotrengi = "blue";
	rengimiz.tþörtrengi = "red";
	daire onedaire( 98, 56, rengimiz);
	onedaire.yaz();
	return 0;
}*/



/*
class  renk {
	string tþörtrengi;
	string kotrengi;
public:
	//renk() {} ;
	renk(string s1, string s2) :tþörtrengi(s1), kotrengi(s2) {}
	void yazdýr() {
		cout << tþörtrengi << " " << kotrengi;
	}
};
class daire {
	int x;
	string  y;
	renk dolgurengi;
public:
    daire (int s1, string s2 ,renk y):x(s1) , y(s2) , dolgurengi(y) {} // bunu yukardaki classta boþ construcyor olmadan da çalýþýyor
	daire(int s, string y1, renk k) {
		x = s;
		y = y1;
		dolgurengi=k;
	}
	void yaz();
};
void daire::yaz() {
	cout << "toplamlarý:" << x <<" "<< y << endl;
	cout << "renkler:";
	dolgurengi.yazdýr();
}
int main() {
	renk rengimiz("blue", "red");
	daire onedaire(98, "rmflemfe", rengimiz);
	onedaire.yaz();
	return 0;
}*/


/*
struct ürünözellkleri {
	string ürünadý;
	int ürünmiktarý;
	bool üründurumu=false;
};
class cratelist {
	vector<ürünözellkleri>ürünözell;
	public:
	cratelist() {};
	void addtoeleman();
	void deletetoeleman(int listnum);
	void makesembyol();
	void showeleman();
};
vector<cratelist>Lists;
void deletelist(int sýra) {
	Lists.erase(Lists.begin() + sýra - 1);
}
void cratelist::showeleman() {
	for (int i = 0; i <ürünözell.size(); i++) {
		cout << i + 1 << "-) " << ürünözell[i].ürünadý;
		if (ürünözell[i].üründurumu == true) {
			cout << "*    ";
		}
		else { cout << "    "; }
	}
	cout << "\n";
}
void cratelist::addtoeleman() {
	ürünözellkleri temp;
	string boool;
	cout << "\nÜrünün adýný giriniz:";
	cin >> temp.ürünadý;
	cout << "Ürünün miktarýný giriniz:";
	cin >> temp.ürünmiktarý;
	cout << "Ürünü iþaretlemek için True yoksa False yazýnýz! ";
	cin >>boool;
	if (boool == "true" || boool=="True") { temp.üründurumu = true; }
	ürünözell.push_back(temp);
}
void cratelist::deletetoeleman(int listnum) {
	showeleman();
	int secim;
	cout << "\nSilmek istediðiniz ürünün sýrasýný giriniz:";
	cin >> secim;
	ürünözell.erase(ürünözell.begin()+secim - 1);
	if (ürünözell.size() == 0) { deletelist(listnum); }
}
void cratelist::makesembyol() {
	showeleman();
	int secim;
	cout << "\nÝþaretlemek istediðiniz ürünün sýrasýný giriniz:";
	cin >> secim;
	ürünözell[secim - 1].üründurumu = true;
}
int main() {
	setlocale(LC_ALL, "Turkish");
	bool door = true;
	int choose;
	cout << "Welcome to shopping list! :))";
	while (door) {
		cout << "\n\nListe oluþturmak için 1'e basýn!\n";
		cout << "Liste silmek için 2'ye basýnýz!\n";
		cout << "Liste üzerinde iþlem yapmak için 3'e basýnýz!\n";
		cin >> choose;
		if (choose == 1) {
			int sayac;
			cout << "\nKaç ürün eklemek istersiniz:";
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
			cout << "\nSilmek istediðiniz listenin sýrasýný  giriniz:";
			cin >> sayac1;
			deletelist(sayac1);
		}
		else if (choose == 3) {
			int listnum, elemannum;
			cout << "\nÝþlem yapmak istediðiniz listenin sýrasýný giriniz:";
			cin >> listnum;
			cout << "\nEleman eklemek için 1'e basýn!\n";
			cout << "Eleman silmek için 2'ye basýnýz!\n";
			cout << "Eleman iþaretlemek istiyorsanýz 3'e basýnýz!\n";
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
		cout << "\n\nÇýkýþ yapmak istiyorsanýz 1'e yoksa 2'ye basýnýz:";
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
	cout << "\neleman adý gir:";
	cin >> temp.name;
	cout << "\nürün mikt:";
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


