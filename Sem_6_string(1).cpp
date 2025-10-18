#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    string stroka;
    cout << "Введите строку: " << endl;
    getline(cin, stroka);
    
    // удаление знаков препинания и пробелов для их игнорирования и перевод символов в нижний регистр
    string cleaned;
    for (char c : stroka) {
        if (isalnum(c)) {
            cleaned += tolower(c);
        }
    }

    // разворот строки
    

    string reversed = cleaned;
    reverse(reversed.begin(), reversed.end());


    if (cleaned == reversed) {
        cout << "Строка является палиндромом" << endl;
    }
    else {
        cout << "Строка не является палиндромом" << endl;
    }


    return 0;
}


