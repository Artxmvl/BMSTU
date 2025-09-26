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
    cout << "Начальный массив: ";
    for (int i = 0;i < 15;i++) {
        cout << num[i] << " ";
    }

    int  min_in = 0, max_in = 0;
    int max = num[14], min = num[0];
   
   
    for (int i = 0;i < 15;i++) {
        if (num[i] > num[max_in]) {
            max_in = i;
        }
    }
    swap(num[14], num[max_in]);

    for (int i = 0;i < 15;i++) {
        if (num[i] < num[min_in]) {
            min_in = i;
        }
    }
    swap(num[0], num[min_in]);
    
    


    cout << "\n" << "Новый измененный массив: ";
    for (int i = 0;i < 15;i++) {
        cout << num[i] << " ";
    }


    

    return 0;
}
    

