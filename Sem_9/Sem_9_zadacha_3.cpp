#include <memory>
#include <iostream>

using namespace std;

void fillArray(unique_ptr<int[]>& arr, int n) {
    for (int i = 0;i < n;i++) {
        arr[i] = i * i;
    }

}

int main()
{
    setlocale(LC_ALL, "RU");

    int N = 0;
    cout << "Введите размер масссива: ";
    cin >> N;

    unique_ptr<int[]> arr = make_unique<int[]>(N);
    fillArray(arr, N);
    

    //вывод заполненного массива
    cout << "Заполненный массив: " << endl;
    for (int i = 0;i < N;i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
