#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    int matrix[100][100], N = 0, M = 0;
    // ввод параметров матрицы
    cout << "Введите количество строк:  ";
    cin >> N;
    cout << "Введите количество столбцов:  ";
    cin >> M;
    //ввод матрицы
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << "Введите элемент матрицы с индексом [" << i << ";" << j << "]: ";
            cin >> matrix[i][j];
        }
        cout << endl;
    }
    

   //вывод матрицы
    cout << "полученная матрицы:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // поиск минимума и максимума в каждой строке
    int max1[100], min1[100];
    for (int i = 0;i < N;i++) {
        max1[i] = min1[i] = matrix[i][0];
        for (int j = 0;j < M;j++) {
            if (max1[i] < matrix[i][j]) {
                max1[i] = matrix[i][j];
            }
            else if (min1[i] > matrix[i][j]) {
                min1[i] = matrix[i][j];
            }
        }

    }

    // поиск минимума и максимума в каждом столбце
    int max2[100], min2[100];
    for (int j = 0;j < M;j++) {
        max2[j] = matrix[0][j];
        min2[j] = matrix[0][j];
        for (int i = 0;i < N;i++) {
            
            if (max2[j] < matrix[i][j]) {
                max2[j] = matrix[i][j];
            }
            else if (min2[j] > matrix[i][j]) {
                min2[j] = matrix[i][j];
            }
        }
    }
   
    // проверка под условия и вывод ответ
    bool found = false;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            int value = matrix[i][j];

            // Проверяем тип A
            if (value == min1[i] && value == max2[j]) {
                cout << " тип A " << value << "  индексы:  " << (i + 1) << " " << (j + 1) << endl;
                found = true;
            }

            // Проверяем тип B
            if (value == max1[i] && value == min2[j]) {
                cout << " тип B " << value << "  индексы:  " << (i + 1) << " " << (j + 1) << endl;
                found = true;
            }
        }
    }

    // Если не найдено ни одной точки
    if (!found)
        cout << "NONE" << endl;


    return 0;
}
