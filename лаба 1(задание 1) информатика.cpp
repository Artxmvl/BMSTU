#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");
    double amount = 0;
    std::cout << "������� ���������� �������:";
    std::cin >> amount;
    if (amount > 50) {
        std::cout << "������� ����������";
    }
    else if (amount >= 20 && amount <= 50) {
        std::cout << "������������� ��������";
    }
    else {
        std::cout << "������� �� ������, ������ �����������!";
    }
    return 0;
}