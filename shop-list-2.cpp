#include <string>
#include <vector>
#include <sstream>
#include <locale.h>
using namespace std;


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
}
