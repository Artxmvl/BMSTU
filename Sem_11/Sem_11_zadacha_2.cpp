#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    //чтение файла и записывание
    ofstream file("config.txt");
    

    //проверка на открытие файла
    if (file.fail()) {
        cout << "Ошибка в открытии файла";
    }

    //заполнение файла
    file << "server_ip=192.168.1.1" << endl ;
    file << "port=8080" << endl;
    file << "timeout=30" << endl;
    file << "max_connections=100" << endl;
    file.close();

    //создание вектора
    vector<string> vect;
    string str;
 


    //добавления строки в вектор
    fstream readfile("config.txt");
    while (getline(readfile, str)) {
        vect.push_back(str);
    }
    readfile.close();

    string key = "timeout="; // что ищем
    for (int i = 0; i < vect.size();i++) {
        if (vect[i].find(key) != string::npos) {
            vect[i] = "timeout=60";//то, на что меняют
           
        }
    }

    //переписание файла
    ofstream endfile("config.txt");
    for (int i = 0; i < vect.size(); i++) {
        endfile << vect[i] << endl;
    }
    endfile.close();


    return 0;
}
