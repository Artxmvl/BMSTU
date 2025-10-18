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

    //начальная буква каждого предложения становится заглавной,остальные символы переходят в нижний регистр

    str[0] = toupper(str[0]);
    for (int i = 1;i < str.size();i++) {
        if ((str[i - 1] == '.' || str[i - 1] == '!' || str[i - 1] == '?') && isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
        else {
            str[i] = tolower(str[i]);
        }
    }

    //вывод отредактированного текста
    cout << "Отредактированный текст: " << str << endl;

    return 0;
}

