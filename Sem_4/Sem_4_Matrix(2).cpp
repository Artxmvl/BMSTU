#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    int mass[50][50], N = 0;
    cout << "Введите количество строк и столбцов в квадратной матрице: ";
    cin >> N;
    // ввод матрицы
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            cout << "Введите  элемент с  индексом [" << i << ";" << j << "] : " ;
            cin >> mass[i][j];
        }
    }

    // вывод матрицы
    for (int i = 0;i < N;i++) {
        cout << "\n";
        for (int j = 0;j < N;j++) {
            cout << mass[i][j] << " ";
        }
    }
    cout << "\n";

    // проверка равенства сумм
    // сумма первой строки , с ней будем сравнивать все остальное
    int sum1 = 0;
    for (int i = 0;i < 1;i++) {
        for (int j = 0;j < N;j++) {
            sum1 += mass[i][j];
        }
    }


    // проверка совпадения суммы остальных строк с первой строкой
    for (int i = 0;i < N;i++) {
        int sum_str = 0;
        for (int j = 0;j < N;j++) {
            sum_str += mass[i][j];
        }
        if (sum_str != sum1) {
            cout << "NO - сумма строк не равна" << endl;
        }
    }


    // проверка совпадения  суммы столбцов с первой строкой
    for (int i = 0;i < N;i++) {
        int sum_sto = 0;
        for (int j = 0;j < N;j++) {
            sum_sto += mass[i][j];
        }
        if (sum_sto != sum1) {
            cout << "NO - сумма столбцов не равна" << endl;
        }
    }

    // проверка совпадения суммы главной диагонали матрицы с первой строкой
    int diag1 = 0;
    for (int i = 0;i < N;i++) {
        diag1 += mass[i][i];
    }
 

    // проверка совпадения суммы побочной диагонали матрицы с первой строкой
    int diag2 = 0;
    for (int i = 0;i < N;i++) {
        diag2 += mass[i][N - i - 1];
    }
    cout << "-----------------------------------------" << "\n Итог:";


    // проверка совпадения разных сумм
    if (sum1 == diag1 && sum1 == diag2) {
        cout << "YES " << "\n Сумма равна: " << sum1;
    }
    else {
        cout << "NO - суммы магического квадрата не равны";
    }
    return 0;
}


