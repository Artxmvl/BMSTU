#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    int matrix[100][100], N = 0, M = 0;
    // ввод параметров матрицы
    cout << "Введите количество строк:  ";
    cin >> N;
    // Границы заполнения
    int top = 0, bottom = N - 1;
    int left = 0, right = N - 1;
    int current = 1; // Текущее число для заполнения

    // Заполнение по спирали
    while (current <= N * N) {
        //  Верхняя строка: слева направо
        for (int j = left; j <= right && current <= N * N; j++) {
            matrix[top][j] = current++;
        }
        top++;

        //  Правый столбец: сверху вниз
        for (int i = top; i <= bottom && current <= N * N; i++) {
            matrix[i][right] = current++;
        }
        right--;

        //  Нижняя строка: справа налево
        for (int j = right; j >= left && current <= N * N; j--) {
            matrix[bottom][j] = current++;
        }
        bottom--;
        // Левый столбец: снизу вверх
        for (int i = bottom; i >= top && current <= N * N; i--) {
            matrix[i][left] = current++;
        }
        left++;
    }

    // Вывод матрицы
    cout << "Результат:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
 

      
    return 0;
}