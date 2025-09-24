#include <iostream>
using namespace std;


int main() {
	setlocale(LC_ALL, "RU");
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
	cout << "Введите координаты первой вершины: ";
	cin >> x1 >> y1;
	cout << "Введите координаты второй вершины: ";
	cin >> x2 >> y2;
	cout << "Введите координаты третьей вершины: ";
	cin >> x3 >> y3;
	if ( (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) == 0) {
		cout << "Точки лежат на одной прямой";
	}
	else {
		cout << "Точки не лежат на одной прямой";
	}
	return 0;
}

