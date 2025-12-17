#include <iostream>
#include <string>
using namespace std;

// Структура банковского счета
struct BankAccount {
    int accountNumber;    // Номер счета
    string ownerName;     // Владелец
    double balance;       // Баланс
};

int main() {
    setlocale(LC_ALL, "RU");

    BankAccount account;  // Создаем счет
    int choice;           // Выбор в меню

    cout << "=== ПРОСТАЯ БАНКОВСКАЯ СИСТЕМА ===" << endl;

    // Ввод данных счета
    cout << "\nСоздание счета:" << endl;
    cout << "Введите номер счета: ";
    cin >> account.accountNumber;
    cin.ignore();  // Очистка буфера

    cout << "Введите имя владельца: ";
    getline(cin, account.ownerName);

    cout << "Введите начальный баланс: ";
    cin >> account.balance;

    // Главное меню
    do {
        // Меню операций
        cout << "\n==========================" << endl;
        cout << "1. Внести деньги" << endl;
        cout << "2. Снять деньги" << endl;
        cout << "3. Показать информацию" << endl;
        cout << "4. Выйти" << endl;
        cout << "==========================" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: { // Внести деньги
            double amount;
            cout << "Введите сумму для внесения: ";
            cin >> amount;

            if (amount > 0) {
                account.balance += amount;
                cout << "Успешно! Новый баланс: " << account.balance << " руб." << endl;
            }
            else {
                cout << "Ошибка: неверная сумма!" << endl;
            }
            break;
        }

        case 2: { // Снять деньги
            double amount;
            cout << "Введите сумму для снятия: ";
            cin >> amount;

            if (amount > 0 && amount <= account.balance) {
                account.balance -= amount;
                cout << "Успешно! Остаток: " << account.balance << " руб." << endl;
            }
            else if (amount > account.balance) {
                cout << "Ошибка: недостаточно средств!" << endl;
            }
            else {
                cout << "Ошибка: неверная сумма!" << endl;
            }
            break;
        }

        case 3: { // Показать информацию
            cout << "\n=== ИНФОРМАЦИЯ О СЧЕТЕ ===" << endl;
            cout << "Номер: " << account.accountNumber << endl;
            cout << "Владелец: " << account.ownerName << endl;
            cout << "Баланс: " << account.balance << " руб." << endl;
            cout << "==========================" << endl;
            break;
        }

        case 4: { // Выйти
            cout << "Выход из программы. До свидания!" << endl;
            break;
        }

        default: { // Неверный выбор
            cout << "Неверный выбор!" << endl;
            break;
        }
        }

    } while (choice != 4);  // Повторять, пока не выбран выход

    return 0;
}
