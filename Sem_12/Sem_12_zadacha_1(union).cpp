#include <iostream>
using namespace std;

union Variant {
    int intValue;
    double doubleValue;
    char charValue;
};

int main() {
    setlocale(LC_ALL, "RU");
    Variant data;
    char choice;

    cout << "Выберите тип данных:\n";
    cout << "i - целое число\n";
    cout << "d - число с плавающей запятой\n";
    cout << "с - символ\n";
    cout << "Ваш выбор:\n";
    cin >> choice;

    switch (choice) {
    case 'i':
        cout << "Введите целое число: ";
        cin >> data.intValue;
        cout << "Вы ввели: " << data.intValue << endl;
        break;

    case 'd':
        cout << "Введите число с плавающей запятой: ";
        cin >> data.doubleValue;
        cout << "Вы ввели: " << data.doubleValue << endl;
        break;

    case 'c':
        cout << "Введите символ: ";
        cin >> data.charValue;
        cout << "Вы ввели: " << data.charValue << endl;
        break;

    default:
        cout << "Неверный выбор!" << endl;
    }

    return 0;
}
