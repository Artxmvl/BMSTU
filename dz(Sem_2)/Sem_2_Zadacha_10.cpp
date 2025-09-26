#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int a;
    cout << "Введите число: ";
    cin >> a;
    if (a < 0) {
        cout << "Ввели число меньше 0";
    }
    else if (a > 0) {
        cout << "Ввели число больше 0";
    }
    else {
        cout << "Ввели чило 0";
    }
    return 0;
}
