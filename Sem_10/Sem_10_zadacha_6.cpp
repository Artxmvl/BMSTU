#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main()
{
    setlocale(LC_ALL,"RU");
    //открытие файла для записывания
    ofstream file("output.txt");
    //проверка на открытие
    if (file.fail()) {
        cout << "Ошибка открытия файла";
    }
    char c;
    string line;

    cout << "Введите строки(пустая строка завершает ввод):" << endl;
    //проверка на пустую строку
    while (true) {
        getline(cin, line);
        if (line.empty()) {
            break;
        }
        file << line << endl;
    }
    file.close();

    //для проверки
    ifstream readfile("output.txt");
    string str;
    cout << "Записанный файл: " << endl;
    while (getline(readfile, str)) {
        cout << str << endl;
    }
    return 0;
}
