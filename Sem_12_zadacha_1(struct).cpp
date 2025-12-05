#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    int age;
    string dolgnost;
    double money;
};

int main() {
    setlocale(LC_ALL, "RU");

    // количество человек
    int n = 0;
    cout << "Введите количество человек: ";
    cin >> n;
    cin.ignore(); // очищаем буфер после ввода числа

    //введение переменных для старших и молодых, и сумма зарплат
    Employee young;
    Employee old;
    double sumMoney = 0;

    //цикл для ввода данных
    for (int i = 0; i < n; i++) {
        Employee current; // текущий сотрудник

        cout << "\nСотрудник " << (i + 1) << "===" << endl;

        // Ввод имени
        cout << "Имя: ";
        getline(cin, current.name);

        // Ввод возраста
        cout << "Возраст: ";
        cin >> current.age;
        cin.ignore(); // очищаем буфер

        // Ввод должности
        cout << "Должность: ";
        getline(cin, current.dolgnost);

        // Ввод зарплаты
        cout << "Зарплата: ";
        cin >> current.money;
        cin.ignore(); // очищаем буфер

        // Добавляем зарплату к общей сумме
        sumMoney += current.money;

        // Проверяем, самый ли он молодой/старый
        if (i == 0) { // если это первый сотрудник
            young = current;
            old = current;
        }
        else {
            if (current.age < young.age) {
                young = current;
            }
            if (current.age > old.age) {
                old = current;
            }
        }
    }

    // Вывод результатов
    cout << "\n=== РЕЗУЛЬТАТЫ ===" << endl;

    cout << "Самый молодой сотрудник:" << endl;
    cout << "  Имя: " << young.name << endl;
    cout << "  Возраст: " << young.age << endl;
    cout << "  Должность: " << young.dolgnost << endl;
    cout << "  Зарплата: " << young.money << endl;

    cout << "\nСамый старший сотрудник:" << endl;
    cout << "  Имя: " << old.name << endl;
    cout << "  Возраст: " << old.age << endl;
    cout << "  Должность: " << old.dolgnost << endl;
    cout << "  Зарплата: " << old.money << endl;

    cout << "\nСредняя зарплата: " << (sumMoney / n) << endl;

    return 0;
}