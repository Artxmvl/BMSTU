#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");
    int amount = 0;
    std::cout << "������� ���������� �������:";
    std::cin >> amount;
    if (amount < 0) {
        std::cout << "����� ������������� �����";
    }
    else {
        while (amount >= 0) {
            std::cout << "������� ���������� �������:";
            std::cin >> amount;
            if (amount < 0) {
                std::cout << "����� ������������� �����";
            }
        }
    }

    
    return 0;
}