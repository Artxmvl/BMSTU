#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//функция для вычисления суммы каждой строки
int   SumN(int* arr, int m) {
    int sum = 0;
    for (int j = 0;j < m;j++) {
        sum += arr[j];
    }
    return sum;
}

// Функция для сортировки строк по сумме элементов
void sortSum(int** arr, int n, int m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (SumN(arr[j], m) > SumN(arr[j + 1], m)) {
                // Меняем местами указатели на строки
                int* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
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
            arr[i][j] = rand() % 100;
        }
    }

    //вывод исходной матрийы
    cout << "\nИсходная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Строка " << i + 1 << " (сумма: " << SumN(arr[i], m) << "): ";
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //сортировка
    sortSum(arr, n, m);

    //вывод отсортированной матрицы
    cout << "Отсортированная матрица (по возрастанию суммы строк):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Строка " << i + 1 << " (сумма: " << SumN(arr[i], m) << "): ";
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    


    //освобождение памяти
    free2D(arr, n);

    return 0;
}
