#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    float num[15];
    for (int i = 0;i < 15;i++) {
        cout << "Введите " << i + 1 << " член последовательности: ";
        cin >> num[i];
    }

    int max_in = 0, min_in = 0;

    for (int i = 0;i < 15;i++) {
        if (num[i] > num[max_in]) {
            max_in = i;
        }
    }

    for (int i = 0;i < 15;i++) {
        if (num[i] < num[min_in]) {
            min_in = i;
        }
    }
    
    if (min_in == 1 && max_in == 0) {
        for (int i = 0;i < 15;i++) {
            num[i] *= 0.5;
        }
        cout << "Новая последоватльность: ";
        for (int i = 0;i < 15;i++) {
            cout << num[i] << " ";
        }
    }
    else {
        cout << "Такие значения не соответсвуют условию";
    }

    return 0;
}
