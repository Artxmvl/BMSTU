#include <iostream>
using namespace std;


int main() {
	setlocale(LC_ALL, "RU");
	int temp = 0;
	cout << "Введите температуру в градусах Цельсия: ";
	cin >> temp;
	cout << "Температура по Фаренгейту равна: " << temp * 1.8 + 32  ;
	return 0;
   
}


