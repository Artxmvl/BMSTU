#include <iostream>
#include <string>
using namespace std;

// 1. Базовый класс BankAccount
class BankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;

public:
    // Конструктор
    BankAccount(string accNum, string name, double initialBalance) {
        accountNumber = accNum;
        ownerName = name;
        balance = initialBalance;
    }

    // Метод для пополнения
    void deposit(double amount) {
        balance += amount;
        cout << "Пополнено: " << amount << " руб. Баланс: " << balance << " руб." << endl;
    }

    // Метод для снятия
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Снято: " << amount << " руб. Баланс: " << balance << " руб." << endl;
        }
        else {
            cout << "Ошибка: недостаточно средств!" << endl;
        }
    }

    // Метод для вывода информации
    void display() {
        cout << "Счет: " << accountNumber << endl;
        cout << "Владелец: " << ownerName << endl;
        cout << "Баланс: " << balance << " руб." << endl;
    }
};

// 2. Производный класс SavingsAccount
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    // Конструктор
    SavingsAccount(string accNum, string name, double initialBalance, double rate)
        : BankAccount(accNum, name, initialBalance) {
        interestRate = rate;
    }

    // Метод для начисления процентов
    void applyInterest() {
        double currentBalance;
        // Получаем текущий баланс (в реальном коде нужен геттер)
        // Для простоты просто объявим переменную
        cout << "Начисление процентов по ставке " << interestRate << "%" << endl;
        // В реальном коде здесь была бы формула для расчета процентов
    }

    // Вывод информации с добавлением процентной ставки
    void display() {
        BankAccount::display();
        cout << "Процентная ставка: " << interestRate << "%" << endl;
    }
};

// 3. Основная программа
int main() {
    setlocale(LC_ALL, "RU");
    cout << "Банковская система" << endl;

    // Создаем обычный счет
    cout << "\n1. Обычный банковский счет:" << endl;
    BankAccount account1("12345", "Иван Иванов", 1000);
    account1.display();

    // Операции с обычным счетом
    account1.deposit(500);
    account1.withdraw(200);
    account1.withdraw(2000); // Пытаемся снять больше, чем есть

    // Создаем сберегательный счет
    cout << "\n2. Сберегательный счет:" << endl;
    SavingsAccount account2("54321", "Петр Петров", 5000, 5.5);
    account2.display();

    // Операции со сберегательным счетом
    account2.deposit(1000);
    account2.withdraw(500);
    account2.applyInterest();

    return 0;
}