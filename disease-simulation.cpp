#include "pch.h"
#include <string>
#include <vector>
#include <map>
#include  <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>
using namespace std;
ofstream filetxt3("C:\\Users\\HP\\Desktop\\TURNS.txt");
vector<string>store;//All inputs from input will be here
string myhabitat[100][3] = { "\n" };// will do an entity check and put the entity name gate and its location here
int usetoendloc[100] = { 0 };
vector < vector<int> >location;//the position of all assets in the input will be here
vector<int>canbeill;
vector<int>normall;//immune assets
vector<int>tamdie;//dead assets that have completed the five-day period
vector<int>ht, tempyi, recover;
vector<vector< int>> willbehealthy;
vector<vector< int>>willdie;
vector<vector< int>>dieds;
map<int, string>endloc;//the last position of dead beings
int  recovered = 0;
bool door = true;
//Conversion of string value to int
int turnint(string tempk) {
	int set = 0;
	for (int i = 0; i < tempk.size(); i++) {
		int kat = 0;
		kat = tempk[i];
		kat = kat - 48;
		set = set * 10 + kat;
	}
	return set;
}
//the situation in which the infected asset will recover or die
void allow(string search1, string myhabitat1) {
	int temp = 0;
	for (int i = 0; i < search1.size(); i++) {
		if (search1[i] == 'A' || search1[i] == 'B' || search1[i] == 'C' || search1[i] == 'D') {
			temp++;
		}
	}
	int entity = turnint(myhabitat1);
	if (temp < 3) {
		tempyi.push_back(entity);
		tempyi.push_back(1);
		willbehealthy.push_back(tempyi);
	}
	else {
		tempyi.push_back(entity);
		tempyi.push_back(1);
		willdie.push_back(tempyi);
	}
	tempyi.clear();
}
//Whether the non-infect entity will be ill
void notill(string search, int sizehbt) {
	int temp = 0;
	for (int i = 0; i < search.size(); i++) {
		if (search[i] == 'A' || search[i] == 'B') {
			temp++;
		}
	}
	if (temp == 0) {
		normall.push_back(sizehbt);
	}
	else {
		canbeill.push_back(sizehbt);
	}
}
//controlb control whether the infected entity will recover or die
void control(int j1) {
	int willill = canbeill[j1];
	string controlharf = myhabitat[willill - 1][1];
	int tempi = 0;
	for (int i = 0; i < controlharf.size(); i++) {
		if (controlharf[i] == 'A' || controlharf[i] == 'B' || controlharf[i] == 'C' || controlharf[i] == 'D') {
			tempi++;
		}
	}
	if (tempi >= 3) {
		tempyi.push_back(willill);
		tempyi.push_back(1);
		willdie.push_back(tempyi);
	}
	else {
		tempyi.push_back(willill);
		tempyi.push_back(1);
		willbehealthy.push_back(tempyi);
	}
	tempyi.clear();
	canbeill.erase(canbeill.cbegin() + j1);
	ht.clear();
}
//Deletion of the same elements in the vector for controld
void htcontol() {
	sort(ht.begin(), ht.end());
	ht.erase(unique(ht.begin(), ht.end()), ht.end());
	for (int it = 0; it < ht.size(); it++) {
		int d = ht[it];
		control(d);
	}
}
//distance measurement from sick assets to potentially sick assets
void controlb1(int set) {
	for (int j = 0; j < canbeill.size(); j++) {
		int farx = location[set - 1][0] - location[(canbeill[j]) - 1][0];
		if (farx < 0) { farx = farx * -1; }
		int fary = location[set - 1][1] - location[(canbeill[j]) - 1][1];
		if (fary < 0) { fary = fary * -1; }
		if (farx <= 3 && fary <= 3) {
			ht.push_back(j);
		}
	}
	if (ht.size() >= 1) {
		htcontol();
	}
}
//string values of 4x5 incoming form are converted int and thrown into the location vector
void turnloc1(string loca) {
	int sayac2 = 0;
	for (int m = 0; m < loca.size(); m++) {
		if (loca[m] == 'x') {
			tempyi.push_back(sayac2);
			sayac2 = 0;
		}
		else {
			int sayac = 0;
			sayac = loca[m];
			sayac = sayac - 48;
			sayac2 = sayac2 * 10 + sayac;
		}
		if (m == loca.size() - 1) {
			tempyi.push_back(sayac2);
		}
	}
}
//here we check the distance between the healthy people who are sent and those who are sick.
void controlb() {
	for (int i = 0; i < willbehealthy.size(); i++) {
		if (willbehealthy[i][1] >= 4) {
			controlb1(willbehealthy[i][0]);
		}
	}
	for (int i = 0; i < willdie.size(); i++) {
		if (willdie[i][1] >= 4) {
			controlb1(willdie[i][0]);
		}
	}
	for (int i = 0; i < dieds.size(); i++) {
		for (auto adres2 = endloc.cbegin(); adres2 != endloc.cend(); ++adres2) {
			int fk = adres2->first;
			if (fk == dieds[i][0]) {
				string loc = adres2->second;
				turnloc1(loc);
				for (int j = 1; j < canbeill.size(); j++) {
					int farx = tempyi[0] - location[(canbeill[j]) - 1][0];
					if (farx < 0) { farx = farx * -1; }
					int fary = tempyi[1] - location[(canbeill[j]) - 1][1];
					if (fary < 0) { fary = fary * -1; }
					if (farx <= 3 && fary <= 3) {
						ht.push_back(j);
					}
				}
				tempyi.pop_back();
				tempyi.pop_back();
			}
		}
		if (ht.size() >= 1) {
			htcontol();
		}
	}
}
//here, increase 1 per turn in turn and see if the time is up accordingly
void controlc(int turnumb) {
	for (int i = 0; i < willbehealthy.size(); i++) {
		willbehealthy[i][1]++;
		if (willbehealthy[i][1] == 31) {
			recover.push_back(willbehealthy[i][0]);
			recovered++;
			willbehealthy.erase(willbehealthy.cbegin() + i);
		}
	}
	for (int i = 0; i < willdie.size(); i++) {
		willdie[i][1]++;
		if (willdie[i][1] == 15) {
			tempyi.push_back(willdie[i][0]);
			tempyi.push_back(6);
			dieds.push_back(tempyi);
			tempyi.clear();
			endloc[willdie[i][0]] = store[willdie[i][0] + 1 + turnumb];;
		    willdie.erase(willdie.cbegin() + i);
		}
	}
	for (int i = 0; i < dieds.size(); i++) {
		dieds[i][1]--;
		if (dieds[i][1] == 0) {
			tamdie.push_back(dieds[i][0]);
			dieds.erase(dieds.cbegin() + i);
		}
	}
}
//Check whether the desired element is in the given vector
bool findit(int tempy, vector<vector<int>>exam) {
	int sayac = 0;
	for (int i = 0; i < exam.size(); i++) {
		if (exam[i][0] == tempy) {
			sayac++;
		}
	}
	if (sayac > 0) { return true; }
	else { return false; }
}
//check whether the incoming asset is sick or dead and write its location
void writing(int i, ofstream& examp) {
	bool door1 = true;
	if (door1) {
		for (int j = 0; j < canbeill.size(); j++) {
			if (canbeill[j] == i) {
				examp << "entity " << i << "  " << location[i - 1][0] << "x" << location[i - 1][1] << "   Normal" << endl;
				door1 = false;
			}
		}
	}
	if (door1) {
		for (int j = 0; j < recover.size(); j++) {
			if (recover[j] == i) {
				examp << "entity " << i << "  " << location[i - 1][0] << "x" << location[i - 1][1] << "   Immune" << endl;
				door1 = false;
			}
		}
	}
	if (door1) {
		for (int j = 0; j < tamdie.size(); j++) {
			if (tamdie[j] == i) {
				examp << "entity " << i << "  " << endloc[i] << "   Dead" << endl;
				door1 = false;
			}
		}
	}
	if (door1) {
		for (int j = 0; j < normall.size(); j++) {
			if (normall[j] == i) {
				examp << "entity " << i << "  " << location[i - 1][0] << "x" << location[i - 1][1] << "   Normal" << endl;
				door1 = false;
			}
		}
	}
	if (door1) {
		for (int j = 0; j < dieds.size(); j++) {
			if (dieds[j][0] == i) {
				examp << "entity " << i << "  " << endloc[i] << "   Dead" << endl;
				door1 = false;
			}
		}
	}
	if (findit(i, willbehealthy) || findit(i, willdie)) {
		examp << "entity " << i << "  " << location[i - 1][0] << "x" << location[i - 1][1] << "   Infected" << endl;
	}
}
//convert the location to int and throw it into location
void turnloc(string loc) {
	turnloc1(loc);
	location.push_back(tempyi);
	tempyi.pop_back();
	tempyi.pop_back();
}
//turns
void turns(int i, int  size) {
	filetxt3 << "Turn " << i << ":" << endl;
	for (int j = 0; j < size + 2; j++) {
		filetxt3 << "- ";
	}
	filetxt3 << endl;
	for (int m = 1; m < size + 1; m++) {
		filetxt3 << "- ";
		for (int j = 1; j < size + 1; j++) {
			bool empty = true;
			for (auto adres = endloc.cbegin(); adres != endloc.cend(); ++adres) {
				if (usetoendloc[adres->first] <= 4) {
				    string lox = adres->second;
				    turnloc1(lox);
				    int ix = tempyi[0];
				    int iy = tempyi[1];
				    tempyi.clear();
				    if (ix == m && iy == j) {
						filetxt3 << "D "; empty = false;
						usetoendloc[adres->first]++;
					}
				}
			}
			for (int k = 0; k < location.size(); k++) {
				if (location[k][0] == m && location[k][1] == j) {
					for (int i = 0; i < willbehealthy.size(); i++) {
						if (willbehealthy[i][0] == k + 1) {
							filetxt3 << "X "; empty = false;
						}
					}
					for (int i = 0; i < willdie.size(); i++) {
						if (willdie[i][0] == k + 1) {
							filetxt3 << "X "; empty = false;
						}
					}
					for (int d = 0; d < canbeill.size(); d++) {
						if (canbeill[d] == k + 1) {
							filetxt3 << "O "; empty = false;
						}
					}
					for (int d = 0; d < normall.size(); d++) {
						if (normall[d] == k + 1) {
							filetxt3 << "0 "; empty = false;
						}
					}
				}
			}
			if (empty) {
				filetxt3 << "  ";
			}
		}
		filetxt3 << "-" << endl;
	}
	for (int j = 0; j < size + 2; j++) {
		filetxt3 << "- ";
	}
	filetxt3 << endl << endl;
}

int main() {
	ifstream filetxt("C:\\Users\\HP\\Desktop\\INPUT.txt");
	while (filetxt) {
		string temp;
		filetxt >> temp;
		store.push_back(temp);
	}
	string tempy = store[1];
	int size = turnint(tempy);
	tempy = store[3];
	int turn_count = turnint(tempy);
	int k = 0, turnnumber = 3;
	for (int i = 4; i < store.size(); i++) {
		string entity = store[i];
		if (entity == "entity") {
				myhabitat[k][0] = store[i + 1];
				myhabitat[k][1] = store[i + 2];
				myhabitat[k][2] = store[i + 3];
				if (store[i + 4] == "infected") {
					allow(myhabitat[k][1], myhabitat[k][0]);
				}
				else {
					notill(myhabitat[k][1], k + 1);
				}
				k++;
		}
		else if (entity == "turn") {
			turnnumber++;
			break;
		}
		turnnumber++;
    }
	int sayac = 0;
	for (int i = turnnumber; i < store.size(); i++) {
		if (store[i] == "turn") {
			for (int j = i + 2; j < i + k + 2; j++) {
				string loc = store[j];
				turnloc(loc);
			}			
			controlb();
			turns(sayac + 1, size);//here we print the turns according to the incoming turn
			sayac++;
			if (store[i+k+2]=="turn") {
				controlc(i);
				location.clear();
			}
		}
	}
	ofstream filetxt1("C:\\Users\\HP\\Desktop\\OUTPUT.txt");
	filetxt1 << "Normal     :" << normall.size() + canbeill.size() << endl;
	filetxt1 << "Infected   :" << willbehealthy.size() + willdie.size() << endl;
	filetxt1 << "Dead       :" << dieds.size() + tamdie.size() << endl;
	filetxt1 << "Recovered  :" << recovered << endl;
	//here we printed the final positions and states of the assets
	for (int i = 0; i < k; i++) {
		writing(i + 1, filetxt1);
	}
	return 0;
}
