#include <iostream>
#include <string> 
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

struct Pizza {
	vector<string>ingredients;

};
vector<int> combination;
vector<Pizza>pvec;
vector<vector<int> >pccom;
int maxset = 0;
vector<int>takimsayilari;

//gruplarda bulunan ki�i say�s�na g�re o gruba g�nderilebilecek pizza say�s�n� vekt�re at�yoruz
void pretty_print(const vector<int>& v,int sayac) {
  int pc=0;
  for (int i = 0; i < v.size(); ++i) { pc+=v[i]; }
  if (sayac == pc) {
			pccom.push_back(v);
    }
}
void go(int offset, int k,int sayac) {
  if (k == 0) {
    pretty_print(combination,sayac);
    return;
  }
  for (int i = offset; i <= takimsayilari.size() - k; ++i) {
    combination.push_back(takimsayilari[i]);
    go(i+1, k-1,sayac);
    combination.pop_back();
  }
}
//pizza perm�tasyonlar�na g�re gruplara da��t�yor ve aralar�ndaki en b�y�k �e�itlili�i al�yoruz
int	buldiffnum(int a[], int bas, int son) {

	vector<string>malzemeler;
	for (int i = bas; i < son; i++) {
		int pizzam = a[i];
		for (int j = 0; j < pccom[pizzam].size(); j++) {
			malzemeler.push_back(pvec[pizzam].ingredients[j]);
		}
	}
	map<string, int> m;
	for (int i = 0; i < malzemeler.size(); i++) {
		m[malzemeler[i]]++;
	}
	return m.size()*m.size();
}
//hangi gruplara ka�ar tane pizza verilebilme ihtimallerini yap�yoruz 
void display(int a[] , int n) 
{ 
    	for (int j = 0; j < pccom.size(); j++) {
				int tempfirt = 0, setingredients = 0;
				for (int k = 0; k < pccom[j].size(); k++) {
					setingredients += buldiffnum(a, tempfirt, pccom[j][k] + tempfirt);
					tempfirt = pccom[j][k];
				}
				if (maxset < setingredients) {
					maxset = setingredients;
				}
		}
} 
void findPermutations(int a[], int n) 
{  
    sort(a, a + n); 
    do { 
        display(a, n); 
    } while (next_permutation(a, a + n)); 
} 


int main()
{  
	vector<int>combination;
	string ingredient;
	int pizza_count, numbergroup = 0;
	cin >> pizza_count;
	int n;
    //kullan�c�dan hangi gruplardan ka�ar adet bulundu�unu al�yor ve vekt�re at�yoruz
	for (int i = 0; i < 3; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			takimsayilari.push_back(n + 2);
			numbergroup += n + 2;
		}
	}
    //her pizzan�n i�inde hangi malzeme oldu�unu al�yor ve vekt�re at�yoruz
	for (int i = 0; i < pizza_count; i++) {
		Pizza p;
		pvec.push_back(p);
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> ingredient;
			pvec[i].ingredients.push_back(ingredient);
		}
	}   
	for(int i=1;i<numbergroup;i++){
		go(0,i,pizza_count);
	}
	int temp[pizza_count];
    for(int i=0;i<pizza_count;i++){
    	temp[i]=i+1;
	}
	//pizzalar�n perm�tasyonlar�na g�re verilecek gruplar� ve o gruplardaki maxsetleri al�p kar��la�t�r�yoruz
    findPermutations(temp, pizza_count);
	cout << maxset;

	return 0;
}
