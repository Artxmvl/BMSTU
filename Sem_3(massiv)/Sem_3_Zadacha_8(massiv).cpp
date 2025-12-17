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


    if (min_in == 4 && max_in == 1) {
        for (min_in = 5; min_in  < 10;min_in++) {
            num[min_in] = num[max_in];
        }
        cout << "Новый измененный массив: ";
        for (int i = 0;i < 10;i++) {
            cout <<  num[i] << " ";
        }

    }
    else {
        cout << "Данные значения не удовлетворяют условию ";
    }

   
    return 0;
}

