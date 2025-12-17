#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    // Система уравнений:
    // 2x + 3y = 13
    // 5x - y = 9

    double a1 = 2, b1 = 3, c1 = 13;
    double a2 = 5, b2 = -1, c2 = 9;

    cout << "Система уравнений №6:" << endl;
    cout << a1 << "x + " << b1 << "y = " << c1 << endl;
    cout << a2 << "x + " << b2 << "y = " << c2 << endl;

    // Метод Крамера
    double det = a1 * b2 - a2 * b1;
    double det_x = c1 * b2 - c2 * b1;
    double det_y = a1 * c2 - a2 * c1;

    double x = det_x / det;
    double y = det_y / det;

    cout << "\nРешение:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    // Проверка
    cout << "\nПроверка:" << endl;
    cout << a1 << "*" << x << " + " << b1 << "*" << y << " = " << a1 * x + b1 * y;
    cout << " (должно быть " << c1 << ")" << endl;
    cout << a2 << "*" << x << " + " << b2 << "*" << y << " = " << a2 * x + b2 * y;
    cout << " (должно быть " << c2 << ")" << endl;

    return 0;
}