int func1(char c) {
	if (c >= '0' && c <= '9')
		return c - 48;
	else
		return -1;
}

int main()
{
	vector<string>harfdizisi;
	int numbers[250] = { 0 };
	string input = "5ABCD1BCD1CDE";

	for (int i = 0; i < 250 && input[i] != '\0'; i++) {
		numbers[i] = func1(input[i]);

	}
	bool ��k�� = true;
	int vekt�rboyutu = 0;

	while (��k�� == true) {
		for (int i = 0; i < 250 && input[i] != '\0'; i++) {
			if (numbers[i] != -1) {
				int temp = input[i];
				temp = temp - 48;
				vekt�rboyutu = vekt�rboyutu * 10 + temp;
			}
			else
			{
				��k�� = false;
				break;
			}
		}
	}
	bool b = false;
	string vekt�releman� = "\0";
	int harfboyutu = 0;
	int sayac = 0;

	for (int i = 0; i < 250 && input[i] != '\0'; i++) {
		if (numbers[i] == -1) {
			harfboyutu++;
			vekt�releman� = vekt�releman� + input[i];
			b = true;
		}
		else {
			sayac++;
		}
		if ((sayac == 1 || i == size(input) - 1) && b == true) {
			if (harfboyutu <= vekt�rboyutu) {
				harfdizisi.push_back(vekt�releman�);
				vekt�releman� = "\0";
				harfboyutu = 0,
					b = false;
			}
			else  break;
		}
		sayac = 0;
	}
	int sayac1 = 1;
	string harfkombinasyonu[128];
	harfkombinasyonu[0] = harfdizisi[0][0];
	cout << harfkombinasyonu[0] << endl;

	for (int i = 0; i < harfdizisi.size(); i++) {
		int sayac2 = 0;
		while (harfkombinasyonu[sayac2] != "\0") {
			sayac2++;
		}
		for (int j = 0; j < sayac2; j++) {
			int temp = harfkombinasyonu[j].size() - 1;
			if (harfkombinasyonu[j][temp] == harfdizisi[i][0]) {
				for (int k = 1; k < harfdizisi[i].size(); k++) {
					harfkombinasyonu[sayac1] = harfkombinasyonu[j] + harfdizisi[i][k];
					cout << harfkombinasyonu[sayac1] << endl;
					sayac1++;
				}
			}
		}
	}
	return 0;
}