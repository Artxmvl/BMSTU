#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");
    int amount = 0;
    std::cout << "Ââåäèòå êîëè÷åñòâî òîïëèâà:";
    std::cin >> amount;
    if (amount < 0) {
        std::cout << "Ââåëè îòðèöàòàëüíîå ÷èñëî";
    }
    else {
        while (amount >= 0) {
            std::cout << "Ââåäèòå êîëè÷åñòâî òîïëèâà:";
            std::cin >> amount;
            if (amount < 0) {
                std::cout << "Ââåëè îòðèöàòàëüíîå ÷èñëî";
            }
        }
    }

    
    return 0;
}
