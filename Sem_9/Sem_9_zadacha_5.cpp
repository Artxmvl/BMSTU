#include <iostream>
#include <memory>

using namespace std;



int main()
{
    setlocale(LC_ALL, "RU");
    int N = 0, M = 0;
    cout << "Введите количество строк массива: ";
    cin >> N;
    cout << "\nВведите количество столбцов массива: ";
    cin >> M;

    unique_ptr<int[]> arr = make_unique<int[]>(N * M);

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            arr[i * M + j] = i * j;
        }
    }

    cout << "\nСозданный массив:  " << endl;
    for (int i = 0;i < N;i++) {
        cout << "\n";
        for (int j = 0;j < M;j++) {
            cout << arr[i * M +j] << " ";
        }
    }


    return 0;
}
