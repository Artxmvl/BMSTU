#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    float num[15];
    int max_in = 0, min_in = 0;
    for (int i = 0;i < 15;i++) {
        cout << "Введите " << i + 1 << " член последовательности: ";
        cin >> num[i];
    }
    for (int i = 0;i < 15; i++) {
        if (num[i] > num[max_in]) {
            max_in = i;
        }
    }


    for (int i = 0;i < 15; i++) {
        if (num[i] < num[min_in]) {
            min_in = i;
        }
    }

    if (min_in > max_in) {
        cout << "Произведение минимального и максимального элементов равно: " << num[min_in] << " * " << num[max_in] << " = " << num[min_in] * num[max_in];
    }
    else {
        cout << "Максимальный элемент не предшествует минимамальному";
    }

    return 0;
}

