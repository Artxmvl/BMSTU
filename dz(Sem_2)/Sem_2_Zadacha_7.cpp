#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int n = 0;
    cout << "Введите число: ";
    cin >> n;
    for (int i = 0;i < n;i++) {
        cout << i << "*" << i << " = " << i * i << endl;
    }
    return 0;
}
