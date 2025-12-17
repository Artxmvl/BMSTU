#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    cout << "Введите координаты точки A(x1,y1): ";
    cin >> x1 >> y1;
    cout << "Введите координаты точки B(x2,y2): ";
    cin >> x2 >> y2;
    cout << "Длина отрезка, соединяющего эти точки равна:  " << sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    return 0;
}

