#include <iostream>

using namespace std;

double determinant(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
	return a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
}


int main() {
	setlocale(LC_ALL, "RU");

	/*
	Система уравнений
	3x - y + 2z = 5
	2x + 4y - z = 6
	x - 3y + z = 2
	*/

	cout << "Решение системы методом Крамера" << endl;
	cout << "3x - y + 2z = 5" << endl;
	cout << "2x + 4y - z = 6" << endl;
	cout << "x - 3y + z = 2" << endl;
	cout << endl;

	// Основной определитель 
	double det = determinant(3, -1, 2, 2, 4, -1, 1, -3, 1);
	cout << "Основной определитель" << endl;
	cout << "|3  -1   2|" << endl;
	cout << "|2   4  -1|" << "=" << det << endl;
	cout << "|1  -3   1|" << endl;

	// Определитель для x (замена первого столбца)
	double det_x = determinant(5, -1, 2, 6, 4, -1, 4, -3, 1);
	cout << "Определитель для x" << endl;
	cout << "|5  -1   2|" << endl;
	cout << "|6   4  -1|" << "=" << det_x << endl;
	cout << "|4  -3   1|" << endl;

	// Определитель для y (замена второго столбца)
	double det_y = determinant(3, 5, 2, 2, 6, -1, 1, 4, 1);
	cout << "Определитель для y" << endl;
	cout << "|3   5   2|" << endl;
	cout << "|2   6  -1|" << "=" << det_y << endl;
	cout << "|1   4   1|" << endl;

	// Определитель для z (замена третьего столбца)
	double det_z = determinant(3, -1, 5, 2, 4, 6, 1, -3, 4);
	cout << "Определитель для z" << endl;
	cout << "|3  -1   5|" << endl;
	cout << "|2   4   6|" << "=" << det_z << endl;
	cout << "|1  -3   4|" << endl;

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