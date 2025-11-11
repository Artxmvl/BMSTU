#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RU");

    //создание файла
    ofstream file("source.txt");

    //проверка на открытие
    if (file.fail()) {
        cout << "Файл не открылся";
    }

    //заполнение файла
    file << "ueigjibdflgjnb" << endl;
    file << "9378" << endl;
    file << "urfjkn ursojvi 398" << endl;
    file.close();

    string str;


    //создание файла для копирования и счетчик для строк
    ifstream readfile("source.txt");
    ofstream copyfile("copy.txt");
    
    int strok = 0;

    //заполнение файла копи содержимым первого файла и вывод скопированного файла
    cout << "Вывод скопированного файла" << endl;
    while (getline(readfile, str)) {
        copyfile << str << endl;
        cout << str << endl;
        strok++;
    }
    //закрываем получившиеся файлы
    readfile.close();
    copyfile.close();


   

    return 0;
}

