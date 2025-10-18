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
    
    //создание пустой строки для добавления элементов
    string pust = "";

    //добавдение параметров для повтора повторяющихся элементов
    int count = 1;
    char sumbols = str[0];
    for (int i = 1;i <= str.size();i++) {
        if (str[i] == sumbols) {
            count++;
        }
        else {
            pust += sumbols;
            pust += to_string(count);


            //сбравсывание счетчиков
            count = 1;
            sumbols = str[i];
        }

    }

 

    //Вывод сжатой строки
    cout << "Сжатая строка: " << pust << endl;
    return 0;
}

