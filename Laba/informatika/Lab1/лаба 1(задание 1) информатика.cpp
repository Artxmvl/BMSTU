#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");
    double amount = 0;
    std::cout << "Ââåäèòå êîëè÷åñòâî òîïëèâà:";
    std::cin >> amount;
    if (amount > 50) {
        std::cout << "Òîïëèâà äîñòàòî÷íî";
    }
    else if (amount >= 20 && amount <= 50) {
        std::cout << "Ðåêîìåíäóåòñÿ çàïðàâêà";
    }
    else {
        std::cout << "Òîïëèâî íà èñõîäå, ñðî÷íî çàïðàâüòåñü!";
    }
    return 0;
}
