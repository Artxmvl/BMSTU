#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");
    int amount = 0;
    std::cout << "¬ведите количество топлива:";
    std::cin >> amount;
    if (amount < 0) {
        std::cout << "¬вели отрицатальное число";
    }
    else {
        while (amount >= 0) {
            std::cout << "¬ведите количество топлива:";
            std::cin >> amount;
            if (amount < 0) {
                std::cout << "¬вели отрицатальное число";
            }
        }
    }

    
    return 0;
}