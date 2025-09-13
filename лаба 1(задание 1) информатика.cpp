#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");
    double amount = 0;
    std::cout << "Введите количество топлива:";
    std::cin >> amount;
    if (amount > 50) {
        std::cout << "Топлива достаточно";
    }
    else if (amount >= 20 && amount <= 50) {
        std::cout << "Рекомендуется заправка";
    }
    else {
        std::cout << "Топливо на исходе, срочно заправьтесь!";
    }
    return 0;
}