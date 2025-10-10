#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    int mass[100][100],N = 0, M = 0;
    // ввод параметров матрицы
    cout << "Введите количество строк:  ";
    cin >> N;
    cout << "Введите количество столбцов:  ";
    cin >> M;

    //заполнение матрицы
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            cout << "Введите элемент с индексом [" << i << ";" << j << "]:  ";
            cin >> mass[i][j];
        }
    }
    // вывод полученной матрицы
    for (int i = 0;i < N;i++) {
        cout << "\n";
        for (int j = 0;j < M;j++) {
            cout << mass[i][j] << " ";
        }
    }

    // создание массива в котором будут храниться данные
    int* massiv = new int[N * M];
    int index = 0;




     // границы для обхода по спирали
    int top = 0, bottom = N - 1;
    int left = 0, right = M - 1;

    // обход матрицы по спирали
    while (top <= bottom && left <= right) {
        // 1. Верхняя строка: слева направо
        for (int j = left; j <= right; j++) {
            massiv[index++] = mass[top][j];
        }
        top++;

        // 2. Правый столбец: сверху вниз
        for (int i = top; i <= bottom; i++) {
            massiv[index++] = mass[i][right];
        }
        right--;

        // 3. Нижняя строка: справа налево (если есть строки)
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                massiv[index++] = mass[bottom][j];
            }
            bottom--;
        }
        // 4. Левый столбец: снизу вверх (если есть столбцы)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                massiv[index++] = mass[i][left];
            }
            left++;
        }
    }

    //вывод полученного массива с строчку
    cout << "\n ------------------------------------------------------------\n отсортированный массив" << endl;
    for (int i = 0;i < N * M;i++) {
        cout << massiv[i] << " ";
    }


    return 0;
}
