#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;

    cout << "Введите координаты первого отрезка:" << endl;
    cout << "точка A(x1 y1): ";
    cin >> x1 >> y1;
    cout << " точка B(x2 y2): ";
    cin >> x2 >> y2;

    cout << "Введите координаты второго отрезка:" << endl;
    cout << "точка C(x3 y3): ";
    cin >> x3 >> y3;
    cout << "точка D(x4 y4): ";
    cin >> x4 >> y4;

    
    int v1 = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3);
    int v2 = (x4 - x3) * (y2 - y3) - (y4 - y3) * (x2 - x3);
    int v3 = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    int v4 = (x2 - x1) * (y4 - y1) - (y2 - y1) * (x4 - x1);


    if ((v1 * v2 < 0) && (v3 * v4 < 0)) {
        cout << "Отрезки пересекаются" << endl;
    }
    else {
        cout << "Отрезки не пересекаются" << endl;
    }
    return 0;
}

