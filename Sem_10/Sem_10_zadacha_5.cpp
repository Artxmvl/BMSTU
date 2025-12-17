#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    //создание файла
    ofstream file("input.txt");

    //проверка на открытие
    if (file.fail()) {
        cout << "Файл не открылся";
    }

    //заполнение файла
    file << "ueigjibdflgjnb" << endl;
    file << "9378" << endl;
    file << "urfjkn ursojvi 398" << endl;
    file.close();

    


   //счетчик для подсчета символом
    int k = 0;
    char c;

    ifstream readfile("input.txt");
   //подсчет символов
    while (readfile.get(c)) {
        k++;
   }

    cout << "Количество символов в файле: " << k << endl;
    return 0;
}

