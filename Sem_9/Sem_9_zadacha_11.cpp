#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));

    // Ввод количества измерений
    int N;
    cout << "Введите количество измерений: ";
    cin >> N;

    // Заполнение вектора случайными значениями температур от 20.00 до 35.99
    vector<double> signals(N);
    for (int i = 0; i < N; i++) {
        signals[i] = 20 + (rand() % 16) + (rand() % 100) / 100.0;
    }

    // Создание динамического массива через unique_ptr и копирование данных
    auto dynamic_signals = make_unique<double[]>(N);
    for (int i = 0; i < N; i++) {
        dynamic_signals[i] = signals[i];
    }

    // Лямбда-функция для вычисления среднего значения
    auto mean = [](const unique_ptr<double[]>& arr, int size) -> double {
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum / size;
        };

    // Лямбда-функция для нормализации данных (приведение к диапазону [0, 1])
    auto normalize = [](unique_ptr<double[]>& arr, int size, double max_val) {
        for (int i = 0; i < size; i++) {
            arr[i] /= max_val;
        }
        };

    // Лямбда-функция для копирования данных обратно в вектор
    auto copyBack = [](const unique_ptr<double[]>& source, vector<double>& dest, int size) {
        for (int i = 0; i < size; i++) {
            dest[i] = source[i];
        }
        };

    // Вывод исходных данных
    cout << "\nИсходные данные: ";
    for (const auto& val : signals) {
        cout << fixed << setprecision(1) << val << " ";
    }
    cout << endl;

    // Вычисление и вывод среднего значения
    double average = mean(dynamic_signals, N);
    cout << "Среднее значение: " << fixed << setprecision(2) << average << endl;

    // Нормализация данных
    double max_val = *max_element(signals.begin(), signals.end()); // Находим максимальное значение
    normalize(dynamic_signals, N, max_val); // Нормализуем данные
    copyBack(dynamic_signals, signals, N);  // Копируем нормализованные данные обратно в вектор

    // Вывод нормализованных данных
    cout << "Нормализованные сигналы: ";
    for (const auto& val : signals) {
        cout << fixed << setprecision(3) << val << " ";
    }
    cout << endl;

    return 0;
}