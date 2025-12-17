#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int age;
    cout << "Введите свой возраст: ";
    cin >> age;
    if (age < 18) {
        cout << "Ваш возраст меньше 18 лет";
    }
    else if (age >= 18 && age <= 60) {
        cout << "Ваш возраст от 18 лет до 60 лет";
    }
    else {
        cout << "Ваш возраст старше 60 лет";
    }
    return 0;
}
