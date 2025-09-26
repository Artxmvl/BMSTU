#include <iostream>
#include <cmath>
using namespace std;


int main() {
	setlocale(LC_ALL, "RU");
	double coord[4][2];
	int perimetr = 0;

	for (int i = 0;i < 4;i++) {
		cout << "Введите координаты  вершины (по часовой стрелки) " << i + 1 << ": " << endl;
		cin >> coord[i][0] >> coord[i][1];
	}
	

	for (int i = 0; i < 4; i++) {
		int j = (i + 1) % 4;
		double x = coord[j][0] - coord[i][0];
		double y = coord[j][1] - coord[i][1];
		perimetr += sqrt(x * x + y * y);
	}

	cout << "Периметр многоугольника равен:  " << perimetr;
	return 0;
}
