#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	int a;
	cout << "Введите число: ";
	cin >> a;
	if (a % 3 == 0 && a % 5 == 0) {
		cout << "Число делится и на 3, и на 5 одновременно";
	}
	else if (a % 3 == 0) {
		cout << "Число делится на 3";
	}
	else if (a % 5 == 0) {
		cout << "Число делится на 5";
	}
	else {
		cout << "Число не делится ни на 3, ни на 5";
	}
	
	return 0;
}

