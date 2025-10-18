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

    //перевод строки в нижний регистр 
    for (char &c : str) {
        c = tolower(c);
    }

    //подсчет гласных и согласных через сравнение
    int gl = 0, sog = 0;
    for (char c : str) {
        if (isalpha(c)) {
            if (c == 'e' || c == 'a' || c == 'u' || c == 'i' || c == 'y' || c == 'o') {
                gl++;
            }
            else {
                sog++;
            }
        }
            
    }

    cout << "Количество гласных: " << gl << endl;
    cout << "Количество согласных: " << sog << endl;

    return 0;
}

