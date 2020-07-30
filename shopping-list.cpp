#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<string>>listt; 
vector<vector<int>>productquantity;

void showlist(int numofelist) { 
	 if(listt.size()>=numofelist){
		cout << "List " << numofelist << " --> ";
		for (int j = 0; j < listt[numofelist-1].size(); j++) {
			cout << j + 1 << "-" << listt[numofelist-1][j] << "   (" << productquantity[numofelist-1][j] << ")    ";
		}
		cout << endl;
	 }
}
int main()
{   
	bool door = true;
	cout << "Welcome to shopping list :)\n\nWe are starting...\n\n";
	while (door) { 
		cout << "1-) Press 1 to create a new list!\n";
		cout << "2-) Press 2 to organize the list!\n";
		cout << "3-) Press 3 to delete the list!\n\n";
		int choice;
		cin >> choice;
		if (choice == 1) {
			vector<string>temp1;
			vector<int>temp2;
			int listsize; 
			cout << "How many products will be on your list ? \n";
			cin >> listsize;
			for (int i = 0; i < listsize; i++) {
				string productname;
				int quantity;
				cout << i + 1 << ". enter the name and quantity of the product: ";
				cin >> productname >> quantity;
				temp1.push_back(productname);
				temp2.push_back(quantity);
			}
			listt.push_back(temp1);
			productquantity.push_back(temp2);
		}
		else if (choice == 2) {	
			for (int i = 0; i < listt.size(); i++) {
				showlist(i+1);
			}
			cout << "\nPress 1 to add item to list!\n";
			cout << "Press 2 to delete item!\n";
			cout << "Press 3 to mark as done undone!\n\n";
			int ht, listnumber;
			cin >> ht;
			cout << "Which list do you want to use ?\n";
			cin >> listnumber;
			if (ht == 1) {
				string productname;
				int quantity;
				cout << "Enter the name and quantity of the product you want to add : ";
				cin >> productname >> quantity;
				listt[listnumber - 1].push_back(productname);
				productquantity[listnumber - 1].push_back(quantity);
			}
			else if (ht == 2) {
				int proloc;
				cout << "Enter the order of the product you want to delete : ";
				cin >> proloc;
				listt.at(listnumber - 1).erase(listt.at(listnumber - 1).begin() + proloc - 1);
				productquantity.at(listnumber-1).erase(productquantity.at(listnumber-1).begin() + proloc - 1);
			}
			else if (ht == 3) {
				int door3;
				cout << "If you want to mark as complete press 1, or 2!";
				cin >> door3;
				if (door3 == 1) {
					int listenum;
					cout << "How many is  products you will mark as completed ?\n";
					cin >> listenum;
					for (int i = 0; i < listenum; i++) {
						int pronum;
						cout << "Enter the order of the " << i + 1 << ".  product we will mark: ";
						cin >> pronum;
						string temp = listt[listnumber - 1][pronum - 1];
						bool door12 = true;
						for (int j = 0; j < listt[listnumber - 1][pronum - 1].size(); j++) {
							if (temp[j] == '*') door12 = true;
						}
						if (door12) listt[listnumber - 1][pronum - 1] += "(*)";
					}
					showlist(listnumber);
				}
				else if (door3 == 2) {				
					int pronumber,uses=-1;				
					cout << "Which product do you want to unmark?\n";
					cin >> pronumber;
					for (int i = 0; i < listt[listnumber - 1][pronumber - 1].size(); i++) {
						if (listt[listnumber - 1][pronumber - 1][i] == '(') uses = i;
					}
					if(uses>=0) listt[listnumber - 1][pronumber - 1].erase(uses,3);
					showlist(listnumber);
				}
			}
			else  cout << "You should press 1, 2 or 3 :(\n"; 
		}
		else if (choice == 3) {
			cout << "\nListeler:\n";
			for (int i = 0; i < listt.size(); i++) {
				showlist(i + 1);
			}
			int lisnum;
			cout << "\nEnter number of list what you want delete: ";
			cin >> lisnum;
			if (lisnum >= listt.size()) {
				listt.erase(listt.begin() + lisnum - 1);
				productquantity.erase(productquantity.begin() + lisnum - 1);
			}
		}
		else cout << "\nYou should press 1, 2 or 3!\n" << endl;
		string door1;	
		cout << "\nFinished your process. If you come back to main menu, write yes or no !  \n";
		cin >> door1;
		if (door1 == "no") {
			cout << "Good bye :)";
			door = false;
		}
		else if (door1 == "yes") cout << "\nWelcome again :)\n";  
		else {
			cout << "You should write the yes or no . So Goodbye :(\n";
			door = false;
		}
	}
	return 0;
}

