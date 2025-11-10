#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RU");
    //открытие файла и его создангие
    ofstream file("input.txt");
    //проверка на открытие 
    if (file.fail()) {
        cout << "Файл не открылся";
    }


    //заполнение файла
    file << "dfkjbnhv" << endl;
    file << "oufvdijbu" << endl;
    file << "iudfvdjbdfoui" << endl;
    file.close();


    //для чтения
    string str;

    // открытие того же файл для ЧТЕНИЯ
    ifstream readFile("input.txt");

    //вывод содержимого
    cout << "Содержимое файла: " << endl;
    while (getline(readFile, str)) {
        cout << str << endl;
    }
    //закрываем файл
    readFile.close();

    return 0;
}

