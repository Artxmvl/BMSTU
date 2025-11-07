#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));

    int N, M;
    cout << "Введите размеры матрицы N и M: ";
    cin >> N >> M;

    // Создание динамической матрицы
    auto matrix = make_unique<double[]>(N * M);

    // АВТОМАТИЧЕСКОЕ заполнение случайными числами
    // НИКАКОГО ввода элементов от пользователя!
    cout << "\nМатрица " << N << "x" << M << " (заполнена автоматически):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i * M + j] = rand() % 100 + 1; // Автоматическое заполнение
            cout << matrix[i * M + j] << " ";
        }
        cout << endl;
    }

    // Лямбда для сумм столбцов
    auto sumColumns = [&]() {
        vector<double> sums(M, 0.0);
        for (int j = 0; j < M; j++) {
            for (int i = 0; i < N; i++) {
                sums[j] += matrix[i * M + j];
            }
        }
        return sums;
        };

    // Лямбда для поиска максимума
    auto maxIndex = [](const vector<double>& vec) {
        return max_element(vec.begin(), vec.end()) - vec.begin();
        };

    // Вычисления
    auto sums = sumColumns();
    int maxCol = maxIndex(sums);

    // Вывод результатов
    cout << "\nСуммы столбцов: ";
    for (double sum : sums) {
        cout << sum << " ";
    }
    cout << "\nСтолбец с максимальной суммой: " << maxCol + 1 << " (" << sums[maxCol] << ")" << endl;

    return 0;
}