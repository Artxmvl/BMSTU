#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int a = 0;
    cout << "Введите целое число: ";
    cin >> a;
    if (a % 2 == 0) {
        cout << "Число четное";
    }
    else {
        cout << "Число нечетное";
    }
    return 0;
}

