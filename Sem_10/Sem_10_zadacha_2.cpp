#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    //открытие файла и его создангие
    ofstream file("data.txt");
    //проверка на открытие 
    if (file.fail()) {
        cout << "Файл не открылся";
    }


    //заполнение файла
    file << "dfkjbnhv" << endl;
    file << "oufvdijbu" << endl;
    file << "iudfvdjbdfoui" << endl;
    file << "89343" << endl;
    file << "oufvdibu" << endl;
    file << "7836327" << endl;
    file.close();


    //для чтения
    string str;
    int strok = 0;

    // открытие того же файл для ЧТЕНИЯ
    ifstream readFile("data.txt");

    //вывод содержимого
    cout << "Содержимое файла: " << endl;
    while (getline(readFile, str)) {
        cout << str << endl;
        strok++;

    }
    cout << "Количество строк в файле: " << strok << endl;
    //закрываем файл
    readFile.close();

    return 0;
}
