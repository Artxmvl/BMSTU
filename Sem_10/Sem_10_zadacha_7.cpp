#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    //открытие файла для записывания
    ofstream file("output.txt");
    //проверка на открытие
    if (file.fail()) {
        cout << "Ошибка открытия файла";
    }
    //заполнение файла
    file << "54 56 46 ";
    file << " 82 ";
    file << "1 3";
    file.close();

    //файл для чтения
    int num;

    ifstream readfile("output.txt");
    int count = 0, sum = 0;
    double sz;

    while (readfile >> num) {
        count++;
        sum += num;
    }

    sz = (double)sum / count;
    cout << "Количество чисел: " << count << endl;
    cout << "Сумма чисел: " << sum << endl;
    cout << "Среднее значение чисел: " << sz << endl;


    
    return 0;
}
