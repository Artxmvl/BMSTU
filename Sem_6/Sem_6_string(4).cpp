#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    bool all_found = true;
    string str1,str2;
    cout << "Введите строку A: " << endl;
    getline(cin, str1);
    cout << "Введите строку B: " << endl;
    getline(cin, str2);

    //сравнение символов B с символами А
    for (char c : str2) {
        bool found = false;
        //сравнение с элементами A
        for (char b : str1) {
            if (b == c) {
                found = true;
            }
        }
        //проверка результата
        if (found == false) {
            all_found = false;
            break;
        }
    }
    if (all_found == true) {
        cout << "\nДА" << endl;
    }
    else {
        cout << "\nНЕТ" << endl;
    }
 
    return 0;
}
