#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    int n = 0, m = 0;
    cout << "Введите количество строк массива: ";
    cin >> n;
    cout << "Введите количество столбцов массива: ";
    cin >> m;


    //указатель для массива на строки
    int** arr = new int*[n];
    
    //выделение памяти для всех элементов
    for (int i = 0;i < n;i++) {
        arr[i] = new int[m];
    }

    //заполнение масссива числами и вывод
    srand(time(0));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            arr[i][j] = rand() % 100;
        }
    }


    for (int i = 0;i < n;i++) {
        cout << "\n";
        for (int j = 0;j < m;j++) {
            cout << arr[i][j] << " ";
        }
    }

    //освобождение памяти 
    for (int i = 0;i < n;i++) {
         delete[] arr[i];
        
    }
    delete[] arr;

    return 0;
}
