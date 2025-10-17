#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <numeric>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    vector<int> vect(50);


    //заполнение случайными числами
    srand(time(0));
    for (int i = 0;i < 50;i++) {
        vect[i] = (rand() % 16) ;
    }

    cout << "Изначальный вектор: " << endl;
    for (int i = 0;i < 50;i++) {
        cout << vect[i] << " ";
    }

    //удаление ошибочных данных
    vector<int> new_vect = vect;
    new_vect.erase(remove_if(new_vect.begin(), new_vect.end(), [](int num) {
        return num < 0 || num > 12;
        }),new_vect.end());
    //вывод получившегося вектора
    cout << "\nОтсортированный вектор: ";
    for (int i = 0;i < new_vect.size();i++) {
        cout << new_vect[i] << " ";
    }

    //вычисление среднего давления
    double sz = accumulate(new_vect.begin(), new_vect.end(), 0.0) / new_vect.size();
    cout << "\n=====================================\nСреднее значение равно: " << sz << endl;

    // нахождение минимального и максимального значений
    auto res = minmax_element(new_vect.begin(), new_vect.end());
    cout << "Минимальное значение: " << *res.first << endl;
    cout << "Максимальное значение: " << *res.second << endl;

    // вывод значений больших 8
    cout << "\n============================\nЗначения больше 8: " << endl;
    for_each(new_vect.begin(), new_vect.end(), [](int num) {
        if (num > 8) {
            cout << num << " ";
        }
        });
    return 0;
}

