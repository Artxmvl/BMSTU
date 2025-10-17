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
        vect[i] = rand() % 100;
    }

    cout << "Изначальный вектор: " << endl;
    for (int i = 0;i < 50;i++) {
        cout << vect[i] << " ";
    }


   //нахождение минимального уровня топлива
    auto min = *min_element(vect.begin(), vect.end());
    cout << "\n==============================\nМинимальный элемент:  " << min;

    //проверка на падение уровня топлива на 5%
    auto max = *max_element(vect.begin(), vect.end());
    bool result = all_of(vect.begin(), vect.end(), [max](int num) {
        return num * 100 >= 95 * max;
        });
    if (result != 0) {
        cout << "\nУровень падал не больше чем на 5% от макс";
    }
    else {
        cout << "\nУровень падал больше чем на 5% от макс";
    }

    //разность начального  и конечного значений
    int delta = 0;
    delta = vect[0] - vect[49];
    cout << "\nРазность начального и конечного значения: " << delta << endl;

    //сортировка значений и нахождение медианы
    sort(vect.begin(), vect.end());
    double mediana = 0;
    mediana = (vect[24] + vect[25]) / 2.0;
    cout << "Медиана равна: " << mediana;
    return 0;
}

