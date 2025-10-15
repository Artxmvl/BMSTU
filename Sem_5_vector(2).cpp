#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    vector<int> vect(10);
    for (int i = 0;i < 10;i++) {
        cout << "Введите значение элемента " << i + 1 << "  :  ";
        cin >> vect[i]  ;
    }
    cout << "Изначальный массив : ";
    for (int i = 0;i < 10;i++) {
        cout << vect[i] << " ";
    }


    cout << "\n============================================\n Изменённый вектор: ";
    for_each(vect.begin(), vect.end(), [](int &num)
        {
            num  *= 2;
        });
    for_each(vect.begin(), vect.end(), [](int num) {
        cout << num << " ";
        });
    return 0;
}

