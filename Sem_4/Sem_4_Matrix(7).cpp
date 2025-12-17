#include <iostream>

using namespace std;

double determinant(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
	return a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
}


int main() {
	setlocale(LC_ALL, "RU");

	/*
	Система уравнений
	x + y + z = 6 
	2x - y + 3z = 14
	-x + 4y - z = 2
	*/

	cout << "Решение системы методом Крамера" << endl;
	cout << "x + y + z = 6" << endl;
	cout << "2x - y + 3z = 14" << endl;
	cout << "-x + 4y - z = 2" << endl;
	cout << endl;

	// Основной определитель 
	double det = determinant(1, 1, 1, 2, -1, 3, -1, 4, -1);
	cout << "Основной определитель" << endl;
	cout << "|1   1   1|" << endl;
	cout << "|2  -1   3|" << "=" << det << endl;
	cout << "|-1  4  -1|" << endl;

	// Определитель для x (замена первого столбца)
	double det_x = determinant(6, 1, 1, 14, -1, 3, 2, 4, -1);
	cout << "Определитель для x" << endl;
	cout << "|6   1   1|" << endl;
	cout << "|14  -1  3|" << "=" << det_x << endl;
	cout << "|2   4  -1|" << endl;

	// Определитель для y (замена второго столбца)
	double det_y = determinant(1, 6, 1, 2, 14, 3, -1, 2, -1);
	cout << "Определитель для y" << endl;
	cout << "|1   6   1|" << endl;
	cout << "|2  14   3|" << "=" << det_y << endl;
	cout << "|-1  2  -1|" << endl;

	// Определитель для z (замена третьего столбца)
	double det_z = determinant(1, 1, 6, 2, -1, 14, -1, 4, 2);
	cout << "Определитель для z" << endl;
	cout << "|1   1   6|" << endl;
	cout << "|2  -1  14|" << "=" << det_z << endl;
	cout << "|-1  4   2|" << endl;

	// Проверяем, имеет ли система решение
	if (det != 0) {
		double x = det_x / det;
		double y = det_y / det;
		double z = det_z / det;

		cout << "Решение:" << endl;
		cout << "x = det_x / det = " << det_x << " / " << det << " = " << x << endl;
		cout << "y = det_y / det = " << det_y << " / " << det << " = " << y << endl;
		cout << "z = det_z / det = " << det_z << " / " << det << " = " << z << endl;
		cout << endl;
	}
	else {
		cout << "Система не имеет единственного решения (определитель = 0)" << endl;
	}



	return 0;
}
