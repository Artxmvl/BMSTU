#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

int main()
{
    setlocale(LC_ALL,"RU");

    ifstream readfile("application.log");
    //создание вектора для хранения частей, и строки
    
    string str;

    //создание первой части и номера элемента строкйи
    int part_num = 1, count = 0;

    ofstream current_part;
    //открытие первой части
    current_part.open("log_part1.txt");

    //обработка каждой строки
    while (getline(readfile, str)) {
        current_part << str << endl;
        count++;
        //делаем ограничения на каждую часть(пускай будет 100 символов)
        if (count > 100) {
            current_part.close();
            part_num++;
            current_part.open("log_part" + to_string(part_num) + ".txt");
            count = 0;
        }
        
    }

    //закрытие файла
    current_part.close();
    readfile.close();

    //создание  индекса с индексом о частя

    ofstream index("index.txt");
    index << "Всего частей: " << part_num << endl;
    for (int i = 1; i <= part_num; i++) {
        index << "log_part" << i << ".txt" << endl;
    }
    index.close();

    return 0;
}

