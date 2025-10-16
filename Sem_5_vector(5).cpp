#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    vector<int> vect(20);


    // создание вектора 
    for (int i = 0;i < 20;i++) {
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> vect[i];
    }

    //вывод полученного вектора
    cout << "Полученный вектор:";
    for (int i = 0;i < 20;i++) {
        cout << vect[i] << " ";
    }


    //нахождение максимального и минимального значения
    auto max = *max_element(vect.begin(), vect.end(), [](int a, int b) {
        return a < b;
        });
    auto min = *min_element(vect.begin(), vect.end(), [](int a, int b) {
        return a < b;
        });
    cout << "\n=================================\nМаксимальное значение:  " << max << endl;
    cout << "Минимальное значение:   " << min << endl;


    // посчитать среднее значение
    auto cr = accumulate(vect.begin(), vect.end(), 0.0) / vect.size();
    cout << "\n=================================\nСреднее значение равно  " << cr << endl;


    //нахождение медианы
    vector<int> new_vect = vect;
    sort(new_vect.begin(), new_vect.end());

    // вывод отсортированного массива
    cout << "Отсортированный массив :  ";
    for (int i = 0;i < 20;i++) {
        cout << new_vect[i] << " ";
    }
    //вычисление медианы
    double mediana = 0;
    mediana = (new_vect[9] + new_vect[10]) / 2.0;
    cout << "\nМедиана вектора равна: " << mediana << endl;
    
    return 0;
}

