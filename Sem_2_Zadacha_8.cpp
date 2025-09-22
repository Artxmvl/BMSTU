#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    char a;
    string n;
    int count = 0;
    cout << "Введите строку: ";
    cin >> a;
    while (cin.get(a) && a != '\n') {
        n += a;
        if (a == 'a' || a == 'A' || a == 'e' || a == 'E' || a == 'i' || a == 'I' || a == 'o' || a == 'O' || a == 'y' || a == 'Y' || a == 'u' || a == 'U') {
            count += 1;
        }
    }
    cout << "Ваше предложение: " << n;
    cout << "Количество гласных букв в строке: " << count;
    return 0;
}

