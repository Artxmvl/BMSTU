#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int N;
    cout << "Введите размер массива: ";
    cin >> N;


    //создание массива через unique_ptr
    unique_ptr<int[]> arr = make_unique<int[]>(N);

    //заполнение массива 
    for (int i = 0;i < N;i++) {
        arr[i] = i + 1;
    }


    //вывод полученного массива
    cout << "Полученный массив: " << endl;
    for (int i = 0;i < N;i++) {
        cout << arr[i] << " ";
    }



    return 0;
}
