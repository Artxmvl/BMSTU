#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    // Система уравнений №7:
    // x + y + z = 6
    // 2x - y + 3z = 14  
    // -x + 4y - z = 2

    // Метод Крамера для системы 3x3
    int a1 = 1, b1 = 1, c1 = 1, d1 = 6;
    int a2 = 2, b2 = -1, c2 = 3, d2 = 14;
    int a3 = -1, b3 = 4, c3 = -1, d3 = 2;

    cout << "Система уравнений №7:" << endl;
    cout << a1 << "x + " << b1 << "y + " << c1 << "z = " << d1 << endl;
    cout << a2 << "x + " << b2 << "y + " << c2 << "z = " << d2 << endl;
    cout << a3 << "x + " << b3 << "y + " << c3 << "z = " << d3 << endl;

    // Главный определитель
    int det = a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);

    // Определитель для x
    int det_x = d1 * (b2 * c3 - b3 * c2) - b1 * (d2 * c3 - d3 * c2) + c1 * (d2 * b3 - d3 * b2);

    // Определитель для y
    int det_y = a1 * (d2 * c3 - d3 * c2) - d1 * (a2 * c3 - a3 * c2) + c1 * (a2 * d3 - a3 * d2);

    // Определитель для z
    int det_z = a1 * (b2 * d3 - b3 * d2) - b1 * (a2 * d3 - a3 * d2) + d1 * (a2 * b3 - a3 * b2);

    if (det == 0) {
        cout << "Система не имеет единственного решения" << endl;
        return 0;
    }

    int x = det_x / det;
    int y = det_y / det;
    int z = det_z / det;

    cout << "\nРешение:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    // Проверка
    cout << "\nПроверка:" << endl;
    cout << "1: " << a1 << "*" << x << " + " << b1 << "*" << y << " + " << c1 << "*" << z << " = "
        << a1 * x + b1 * y + c1 * z << " (должно быть " << d1 << ")" << endl;
    cout << "2: " << a2 << "*" << x << " + " << b2 << "*" << y << " + " << c2 << "*" << z << " = "
        << a2 * x + b2 * y + c2 * z << " (должно быть " << d2 << ")" << endl;
    cout << "3: " << a3 << "*" << x << " + " << b3 << "*" << y << " + " << c3 << "*" << z << " = "
        << a3 * x + b3 * y + c3 * z << " (должно быть " << d3 << ")" << endl;


    return 0;
}