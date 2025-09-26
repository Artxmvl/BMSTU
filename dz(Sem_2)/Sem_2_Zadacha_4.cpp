#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    int num = 0;
    cout << "Введите целое число: ";
    cin >> num;
    if (num % 2 == 0) {
        cout << "Число четное";
    }
    else {
        cout << "Число нечетное";
    }
    return 0;
}


