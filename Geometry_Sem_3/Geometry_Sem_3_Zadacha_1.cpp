#include <iostream>
#include <cmath>
using namespace std;


int main() {
	setlocale(LC_ALL, "RU");
	double coord[3][2];

	for (int i = 0;i < 3;i++) {
		cout << "Введите координаты  вершины " << i + 1 << ": " << endl;
		cin >> coord[i][0] >> coord[i][1];
	}
	int x1 = coord[0][0], y1 = coord[0][1], x2 = coord[1][0], y2 = coord[1][1], x3 = coord[2][0], y3 = coord[2][1];

	cout << "Площадь треугольника равна: " << abs(0.5 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
	return 0;
}
