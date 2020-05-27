int func1(char c) {
	if (c >= '0' && c <= '9')
		return c - 48;
	else
		return -1;
}

int main()
{
	vector<string>charletter;
	int numbers[250] = { 0 };
	string input = "5ABCD1BCD1CDE";

	for (int i = 0; i < 250 && input[i] != '\0'; i++) {
		numbers[i] = func1(input[i]);

	}
	bool çıkış = true;
	int vectorsize = 0;

	while (çıkış == true) {
		for (int i = 0; i < 250 && input[i] != '\0'; i++) {
			if (numbers[i] != -1) {
				int temp = input[i];
				temp = temp - 48;
				vectorsize = vectorsize * 10 + temp;
			}
			else
			{
				çıkış = false;
				break;
			}
		}
	}
	bool b = false;
	string vectorelement = "\0";
	int charsize = 0;
	int sayac = 0;

	for (int i = 0; i < 250 && input[i] != '\0'; i++) {
		if (numbers[i] == -1) {
			charsize++;
			vectorelement = vectorelement + input[i];
			b = true;
		}
		else {
			sayac++;
		}
		if ((sayac == 1 || i == size(input) - 1) && b == true) {
			if (charsize <= vectorsize) {
				charletter.push_back(vectorelement);
				vectorelement = "\0";
				charsize = 0,
					b = false;
			}
			else  break;
		}
		sayac = 0;
	}
	int sayac1 = 1;
	string charcombination[128];
	charcombination[0] = charletter[0][0];
	cout << charcombination[0] << endl;

	for (int i = 0; i < charletter.size(); i++) {
		int sayac2 = 0;
		while (charcombination[sayac2] != "\0") {
			sayac2++;
		}
		for (int j = 0; j < sayac2; j++) {
			int temp = charcombination[j].size() - 1;
			if (charcombination[j][temp] == charletter[i][0]) {
				for (int k = 1; k < charletter[i].size(); k++) {
					charcombination[sayac1] = charcombination[j] + charletter[i][k];
					cout << charcombination[sayac1] << endl;
					sayac1++;
				}
			}
		}
	}
	return 0;
}
