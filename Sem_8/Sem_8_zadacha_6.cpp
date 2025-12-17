#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//функция для подсчета суммы всех элементов масссива
int sumElements(int** arr, int n, int m) {
    int sum = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            sum += *(*(arr + i) + j);
        }
    }

    return sum;
}


//функция для очищения памяти
void free2D(int** arr, int n) {
    for (int i = 0;i < n;i++) {
        delete[] arr[i];

    }
    delete[] arr;
}

int main()
{
    setlocale(LC_ALL, "RU");
    int n = 0, m = 0;
    cout << "Введите количество строк: ";
    cin >> n;
    cout << "Введите количество столбцов: ";
    cin >> m;

    // Создание двумерного динамического массива
    int** arr = new int* [n]; //Создание массива указателей на строки 
    // Выделение памяти для каждого столбца в каждой строке
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[m]; // Выделяем память для каждого ряда
    }



    //заполнение матрицы случайными числами
    srand(time(0));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            *(*(arr + i) + j) = rand() % 100;
        }
    }


    
    //вывод исходной матрийы
    cout << "\nИсходная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\n";
        for (int j = 0; j < m; j++) {
            cout << *(*(arr + i) + j) << " ";
        }
        cout << endl;
    }

    int sum = sumElements(arr, n, m);
    cout << "Сумма всех элементов:  " << sum << endl;

    //освобождение памяти
    free2D(arr, n);


    
    return 0;
}
