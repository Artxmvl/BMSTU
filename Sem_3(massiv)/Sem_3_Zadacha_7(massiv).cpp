#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    int num[15];
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

    if (num[min_in] == 0 || num[max_in] == 0) {
        for (int i = 0;i < min_in;i++) {
            num[i] = 0;
        }
        cout << "Последовательность после изменения: ";
        for (int i = 0;i < 15;i++) {
            cout <<  num[i] << " ";
        }
    }
    else {
        cout << "Эти значения не подходят под условие выполения операции";
    }

    return 0;
}

