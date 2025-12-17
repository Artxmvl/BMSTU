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


    //удаление чисел из строки и добавление в новую строку
    string digit;
    for (char c : str) {
        if (isdigit(c) == 0) {
            digit += c;
        }
    }

    //вывод новой строки
    cout << "Строка без цифр: " << endl;
    for (char c : digit) {
        cout << c;
    }
    return 0;
}



