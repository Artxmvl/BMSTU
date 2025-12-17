#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    string str;
    cout << "Введите строку: " << endl;
    getline(cin, str);
   
    string result = "";
    string word = "";

    //переворачивания слов до пробела и добавление их в  новую строку
    for (char c : str) {
        if (c == ' ') {
            reverse(word.begin(), word.end());
            result += word + " ";
            word = "";
        }
        else {
            word += c;
        }
    }


    //переворачивание последнего слова
    if (!word.empty()) {
        reverse(word.begin(), word.end());
        result += word;
    }

    cout << "\nОтредактированная строка: " << result << endl;

    return 0;
}

