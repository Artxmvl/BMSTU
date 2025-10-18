#include <iostream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <set>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    //ввод строки

    cout << "Введите строку: " << endl;
    string str;
    getline(cin, str);

    str.erase(remove(str.begin(), str.end(), ' '),str.end());

    //подсчет количества уникальных символов
    set<char> uni (str.begin(),str.end());
    

    //вывод количества уникальных символов
    cout << "Количество уникальных элементов: " << uni.size() << endl;
    //вывод уникальных элементов
    cout << "Уникальные элементы: ";
    for (char num : uni) {
        cout << "'" << num << "'" << " ";
    }

    return 0;
}

