#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    //открытие файла для записывания 1
    ofstream file1("output.txt");
    //проверка на открытие
    if (file1.fail()) {
        cout << "Ошибка открытия файла";
    }
    //заполнение файла
    file1 << "qaz ";
    file1 << "lkjh ";
    file1 << "qwert";
    file1.close();

    //открытие файла для записывания 2
    ofstream file2("text.txt");
    //проверка на открытие
    if (file2.fail()) {
        cout << "Ошибка открытия файла";
    }
    //заполнение файла
    file2 << "qaz ";
    file2 << "lkjhjskf ";
    file2 << "qwerjflgt";
    file2.close();

    //сравнение посимвольное
    string str;
    string line;
    bool f = true;


    ifstream readfile1("output.txt");
    ifstream readfile2("text.txt");
    while (getline(readfile1, str) && (getline(readfile2, line))) {
        if (str != line) {
            f = false;
            break;
        } 
    }
    //проверка на длину
    if (f) {
        // Если один файл закончился, а другой - нет, они разные
        if (!readfile1.eof() || !readfile2.eof()) {
            f = false;
        }
    }

    if (f) {
        cout << "Строки одинаковы" << endl;
    }
    else {
        cout << "Строки  не одинаковы" << endl;
    }
    readfile1.close();
    readfile2.close();


    return 0;
}
