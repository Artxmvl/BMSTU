#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <numeric>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    vector<double> vect(50);


    //заполнение случайными числами
    srand(time(0));
    for (int i = 0;i < 50;i++) {
        vect[i] = 1.0 * (rand() / (double)RAND_MAX);
    }

    cout << "Изначальный вектор: " << endl;
    for (int i = 0;i < 50;i++) {
        cout << vect[i] << " ";
    }


    //сортировка вектора, исключение чисел меньше 0.1
    vector<double> new_vect = vect;
    new_vect.erase(
        remove_if(new_vect.begin(), new_vect.end(), [](double num) {
            return num < 0.1;
            }), new_vect.end());

    //вывод отсортированного вектора
    cout << "\nОтсортированный вектор: " << endl;
    for (int i = 0;i < new_vect.size();i++) {
        cout << new_vect[i] << " ";
    }

    //нахождение максимального значения и среднего значения
    double max = *max_element(vect.begin(), vect.end()) ;
    cout << "\n=======================================\nМаксимальное значение: " << max << endl;
    double cz = accumulate(vect.begin(), vect.end(), 0.0) / vect.size();
    cout << "Среднее значение равно: " << cz << endl;


    //проверка превышения всех значений 0.5
    bool result = all_of(vect.begin(), vect.end(), [](double num) {
        return num > 0.5;
        });

    if (result != 0) {
        cout << "Все значения больше 0,5";
    }
    else {
        cout << "Не все значения больше 0,5";
    }


    //вывод 10 наибольших амплитуд
    sort(vect.begin(), vect.end(),greater<double>());
    cout << "\n10 наибольших амплитуд: " << endl;
    for (int i = 0;i < 10;i++) {
        cout << vect[i] << " ";
    }

    return 0;
}
