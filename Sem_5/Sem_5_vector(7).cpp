#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    vector<int> vect(20);

    //заполнение вектора
    for (int i = 0;i < 20;i++) {
        cout << "Введите элемент вектора " << i + 1 << ": ";
        cin >> vect[i];
    }

    // заполненный вектор
    cout << "Введенный вектор: " << endl;
    for (int i = 0;i < 20;i++) {
        cout << vect[i] << " ";
    }

    // удаление лишних значений,не входящих в промежуток
    vector<int> new_vect = vect;
    new_vect.erase(remove_if(new_vect.begin(), new_vect.end(), [](int num) {
        return num < -50 || num > 50;}),new_vect.end());


    // вывод нового вектора
    cout << "\nОтсортированный вектор: ";
    for (int i = 0;i < new_vect.size();i++)
        cout << new_vect[i] << " ";

    // поиск максимального,минимального, средних значений
    auto max = *max_element(vect.begin(), vect.end());
    cout << "\nМаксимальное значение равно " << max << endl;
    auto min = *min_element(vect.begin(), vect.end());
    cout << "Минимальное значение равно " << min << endl;
    double sr = accumulate(vect.begin(), vect.end(),0.0) / vect.size();
    cout << "Среднее значение равно " << sr << endl;

    //проверка  условия больше ли темпрература -10
    bool good = all_of(vect.begin(), vect.end(), [](int num) {
        return num > -10;
        });

    if (good != 0) {
        cout << "\nТемпературы больше -10";
    }
    else {
        cout << "\nНе все темпаратуры больше -10";
    }
    return 0;
}


