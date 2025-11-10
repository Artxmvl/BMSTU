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
    file << "dfkjbnhv uweofij iofjg fiosljg" << endl;
    file << "oufvdijbu" << endl;
    file << "iudfvdjbdfoui" << endl;
    file << "sifkjf" << endl;
    file << "oufvdibu" << endl;
    file << "kslgj silgjrs nioreljgr" << endl;
    file.close();


    //для чтения
    string str;
    int words = 0;

    // открытие того же файл для ЧТЕНИЯ
    ifstream readFile("data.txt");

    
    //проверка на условие,подсчет количества слов
    while (readFile >> str) {
        words++;
    }

    cout << "Количество слов в файле: " << words << endl;
    //закрываем файл
    readFile.close();

    return 0;
}