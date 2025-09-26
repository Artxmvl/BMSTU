#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    int n = 0, count = 0;
    cout << "Введите количество членов последовательности: ";
    cin >> n;
    int* num = new int[n];
    for (int i = 0;i < n;i++) {
        cout << "Введите " << i + 1 << "  элемент массива: ";
        cin >> num[i];
    }
    int max_n = num[0];
    for (int i = 0;i < n;i++) {
        if (num[i] % 2 != 0) {
            if (num[i] > max_n) {
                max_n = num[i];
            }
        }
        else {
            count++;
        }

    }
    if (max_n % 2 == 0) {
        cout << "В последовательности нет нечетных чисел" << endl;
    }
    cout << "Наибольшее нечетное число: " << max_n << endl;
    cout << "Количество четных чисел равно: " << count;
    delete[] num;



    return 0;
}

