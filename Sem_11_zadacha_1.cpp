#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RU");
    //чтение файла
    ifstream readfile("book.txt");
    string str;

    //проверка на открытие файла
    if (readfile.fail()) {
        cout << "Ошибка в открытии файла";
    }

    //создание вектора для хранения результата
    vector<pair<int, int>> vect;

    int stroka = 0;
    int position = 0;
    int count = 0;

    while (getline(readfile, str)) {
        position = 0;
        while ((position = str.find("герой",position)) != string::npos) {
           
                vect.push_back({ stroka, position });
                count++;
                position += 5;
          
        }
        stroka++;
    }

    //записывание в файл для результат
    ofstream file("result.txt");
    for (auto& p : vect) {
        file << "Строка: " << p.first << " Позиция: " << p.second << endl;
      

    }

    
    file << "Общее количество вхождений: " << count << endl;

    return 0;
}
