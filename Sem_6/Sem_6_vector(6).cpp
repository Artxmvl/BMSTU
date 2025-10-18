#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    string str;
    cout << "Введите строку: " << endl;
    getline(cin, str);
    int shift;
    cout << "Сдвиг: ";
    cin >> shift;

    //сдвиг вне зависимости от регистра
    for (char &c : str) {
        if (isupper(c)) {
            c = (c - 'A' + shift) % 26 + 'A';
        }
        else if (islower(c)) {
            c = (c - 'a' + shift) % 26 + 'a';
        }
    }

    //вывод сдвинутого текста
    cout << "Сдвинутый текст: " << str << endl;
   
    return 0;
}

