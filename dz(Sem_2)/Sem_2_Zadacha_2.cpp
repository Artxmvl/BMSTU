#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	int a = 0, b = 0;
	cout << "Введите длину: "; 
	cin >> a;
	cout << "Введите ширину: ";
	cin >> b;
	cout << "Площадь прямоугольника равна: " << a * b;
	return 0;
}

