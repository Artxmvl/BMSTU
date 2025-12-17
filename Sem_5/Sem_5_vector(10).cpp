#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <numeric>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    //создание вектора
    vector<int> vect(30);


    //заполнение вектора
    srand(time(0));
    for (int i = 0;i < 30;i++) {
        vect[i] = rand() % 201;
    }

    //вывод полученного вектора
    cout << "Исходный вектор:" << endl;
    for (int i = 0;i < 30;i++) {
        cout << vect[i] << " ";
    }

    //нахождение общей суммы
    auto sum = accumulate(vect.begin(), vect.end(),0.0);
    cout << "\nСумма за все время равна: " << sum << endl;

    //определение среднесуточного значения
    double cz = sum / vect.size();
    cout << "Среднее значение равно: " << cz << endl;

    //нахождение дней  с максимальным  и минимальным элементами
    auto result = minmax_element(vect.begin(), vect.end());
    cout << "Максимальный элемент: " << *result.second << endl;
    cout << "Минимальный элемент:  " << *result.first << endl;


    //фильтр пиковых дней
    vector<int> new_vect = vect;
    new_vect.erase(remove_if(new_vect.begin(), new_vect.end(), [cz](double num) {
        return num < cz * 1.2;
        }), new_vect.end());

    cout << "Новый отсортированный вектор: " << endl;
    for (int i = 0;i < new_vect.size();i++) {
        cout << new_vect[i] << " ";
    }
    cout << "\n";
    return 0;
}

