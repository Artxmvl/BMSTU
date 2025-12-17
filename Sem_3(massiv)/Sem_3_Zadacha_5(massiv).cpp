#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    int num[10];
    for (int i = 0;i < 10;i++) {
        cout << "Введите " << i + 1 << " член последовательности: ";
        cin >> num[i];
    }
    int max_in = 0, min_in = 0;

    for (int i = 0;i < 10;i++) {
        if (num[i] > num[max_in]) {
            max_in = i;
        }
    }


    for (int i = 0;i < 10;i++) {
        if (num[i] < num[min_in]) {
            min_in = i;
        }
    }

    if (min_in == 4 && max_in == 9) {
        cout << "Среднеарифмитическое мин и макс значений равно: " << "0.5 * " << num[min_in] << " * " << num[max_in] << " = " << 0.5 * num[min_in] * num[max_in];
    }
    else {
        cout << "Расположение значений не удовлетворяет условию";
    }
    return 0;
}
