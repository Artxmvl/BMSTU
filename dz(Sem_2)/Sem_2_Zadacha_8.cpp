#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    char c;
    int count = 0;
    string n;
    cout << "Введите строку: ";
    while (cin.get(c) && c != '\n') {
        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'y' || c == 'Y' || c == 'u' || c == 'U') {
            count += 1;
        }
    }

    cout << "Количество гласных букв в строке: " << count;
    return 0;
    }


