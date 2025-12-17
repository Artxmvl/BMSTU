#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <numeric>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    vector<int> vect(24);


    //заполнение случайными числами от 100 до 500
    srand(time(0));
    for (int i = 0;i < 24;i++) {
        vect[i] = (rand() % 401) +  100 ;
    }

    cout << "Изначальный вектор: " << endl;
    for (int i = 0;i < 24;i++) {
        cout << vect[i] << " ";
    }

    //сумма всех мощностей и среднее
    double sum = accumulate(vect.begin(), vect.end(), 0.0);
    cout << "\n===========================\nСумма мощностей равна: " << sum << endl;
    int sz = 0;
    sz = sum / vect.size();
    cout << "Среднее значение равно: " << sz << endl;

    //час пикового потребления
    auto max = max_element(vect.begin(), vect.end());
    int hour = distance(vect.begin(), max);
    cout << "Пик мощности :  " << *max << "  Час: " << hour << endl;


    //отклонения каждого часа от среднего
    vector<int> new_vect = vect;
    transform(new_vect.begin(), new_vect.end(), new_vect.begin(),[sz](int num) {
        return num - sz;
        });
    cout << "\n=========================================" << endl;
    for (int i = 0;i < 24;i++) {
        cout << "\nЧас: " << i << " Разница отклонения: " << new_vect[i];
    }


    //сортировка по возрастанию
    sort(vect.begin(), vect.end());
    cout << "\n=======================================\n5 минимальных элементов: " << endl;
    for (int i = 0;i < 5;i++) {
        cout << vect[i] << " ";
    }
    return 0;
}

