#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <ctime>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    vector<int> vect(20);


    //генератор случайных чисел
    srand(time(0));
    for (int i = 0;i < 20;i++) {
        vect[i] = (rand() % 200) - 100;
    }

    //вывод полученного вектора
    cout << "Полученный вектор:  " << endl;
    for (int i = 0;i < 20;i++) {
        cout << vect[i] << " ";
    }


    //удаление мощности меньше 0
    vector<int> new_vect = vect;
    new_vect.erase(remove_if(new_vect.begin(), new_vect.end(), [](int num) {
        return num < 0;
        }), new_vect.end());

    cout << "\nИсправленный вариант : " << endl;
    for (int i = 0;i < new_vect.size();i++) {
        cout << new_vect[i] << " ";
    }

    //нахождение минимального,максимального и среднего значения
    auto max = *max_element(vect.begin(), vect.end(), [](int a, int b) {
        return a < b;
        });
    auto min = *min_element(vect.begin(), vect.end(), [](int a, int b) {
        return a < b;
        });
    cout << "\n=================================\nМаксимальное значение:  " << max << endl;
    cout << "Минимальное значение:   " << min << endl;

    auto cr = accumulate(vect.begin(), vect.end(), 0.0) / vect.size();
    cout << "\n=================================\nСреднее значение равно  " << cr << endl;

    bool time = all_of(vect.begin(), vect.end(), [](int num) {
        return num < 10 || num > 90;
        });
    if (time != 0) {
        cout << "Мощность была в диапазоне от 10 до 90" << endl;
    }
    else {
        cout << "Мощность была в другом диапазоне" << endl;
    }


    // сортировка вектора по возрастанию
    vector<int> vect1 = vect;
    sort(vect1.begin(), vect1.end());
    double mediana = 0;
    mediana = (vect1[9] + vect1[10]) / 2.0;
    cout << "\nМедиана вектора равна: " << mediana << endl;

    return 0;
}
