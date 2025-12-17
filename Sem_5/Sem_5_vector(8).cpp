#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <ctime>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    vector<int> vect(50);
    

    //генератор случайных чисел
    srand(time(0));
    for (int i = 0;i < 50;i++) {
        vect[i] = (rand() % 181);
    }

    //вывод полученного вектора
    cout << "Полученный вектор:  ";
    for (int i = 0;i < 50;i++) {
        cout << vect[i] << " ";
    }


    //фильтрация скоростей больших 180
    vector<int> new_vect = vect;
    new_vect.erase(remove_if(new_vect.begin(), new_vect.end(), [](int num) {
        return num < 120;
        }),new_vect.end());

    //вывод нового вектора со скоростями больших 120
    cout << "\nВывод отсортированного вектора: " << endl;
    for (int i = 0;i < new_vect.size();i++) {
        cout << new_vect[i] << " ";
    }

    //средняя скорость
    double sum = accumulate(vect.begin(), vect.end(),0.0) / vect.size();
    cout << "\nСредняя скорость равна: " << sum << endl;



    //определение двигалось ли тело постоянно
    bool speed = all_of(new_vect.begin(), new_vect.end(), [](int num) {
        return num > 0;
        });

    if (speed != 0) {
        cout << "\nТело постоянно двигалось";
    }
    else {
        cout << "\nТело останавливалось";
    }

    // вывод 10 максимальных значений
    sort(vect.begin(), vect.end(), greater<int>());
   
    cout << "\nМаксимальые 10 значений: ";
    for (int i = 0;i < 10;i++) {
        cout << vect[i] << " ";
    }
    cout << "\n";
    return 0;
}

