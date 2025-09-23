#include <iostream>
#include <cmath>
using namespace std;


int main() {
	setlocale(LC_ALL, "RU");
	double coord[6];
	cout << "Введите массив из трех пар координат вершин: " << endl;
	for (int i = 0;i < 6;i++) {
		cin >> coord[i];
	}
	int x1 = coord[0], y1 = coord[1], x2 = coord[2], y2 = coord[3], x3 = coord[4], y3 = coord[5];

	cout << "Площадь треугольника равна: " << abs (0.5 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
	return 0;
}