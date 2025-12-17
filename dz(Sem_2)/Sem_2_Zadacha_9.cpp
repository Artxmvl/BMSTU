#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int n = 0,sum = 0;
    cout << "Введите число: ";
    cin >> n;
    for (int i = 0;i < n;i++) {
        if (i % 2 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    cout << "Сумма равна: " <<  sum;
    return 0;

}

