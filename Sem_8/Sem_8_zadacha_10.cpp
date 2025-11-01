#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Функция для создания матрицы нагрузок
int** createLoadMatrix(int nodes, int intervals) {
    int** load = new int* [nodes];  // Создаем массив указателей на строки
    for (int i = 0; i < nodes; i++) {
        load[i] = new int[intervals];  // Создаем каждую строку матрицы
    }
    return load;
}

// Функция для генерации случайных нагрузок
void generateRandomLoad(int** load, int nodes, int intervals) {
    srand(time(0));  // Инициализация генератора случайных чисел
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < intervals; j++) {
            // Генерируем нагрузку от 0 до 100%
            load[i][j] = rand() % 101;
        }
    }
}

// Функция для красивого вывода матрицы
void printMatrix(int** load, int nodes, int intervals, const string& title) {
    cout << "\n" << title << ":" << endl;
    cout << "       ";
    // Выводим заголовки интервалов
    for (int j = 0; j < intervals; j++) {
        cout << setw(4) << "T" << j;
    }
    cout << endl;

    // Выводим данные по узлам
    for (int i = 0; i < nodes; i++) {
        cout << "Узел " << i << ":";
        for (int j = 0; j < intervals; j++) {
            cout << setw(4) << load[i][j] << "%";
        }
        cout << endl;
    }
}

// Этап 1: Вычисление средней нагрузки на каждом узле
double* averageLoadPerNode(int** load, int n, int t) {
    double* averages = new double[n];  // Создаем массив для средних значений

    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        // Суммируем нагрузку для текущего узла по всем интервалам
        for (int j = 0; j < t; j++) {
            sum += load[i][j];
        }
        // Вычисляем среднее значение
        averages[i] = sum / t;
    }

    return averages;
}

// Этап 2: Нормализация нагрузки (исправленная версия без зацикливания)
void normalizeLoad(int** load, int n, int t) {
    // Создаем временную копию матрицы для безопасного перераспределения
    int** temp = new int* [n];
    for (int i = 0; i < n; i++) {
        temp[i] = new int[t];
        for (int j = 0; j < t; j++) {
            temp[i][j] = load[i][j];  // Копируем исходные данные
        }
    }

    // Обрабатываем каждый временной интервал
    for (int j = 0; j < t; j++) {
        // Обрабатываем каждый узел в текущем интервале
        for (int i = 0; i < n; i++) {
            // Проверяем, превышает ли нагрузка 80%
            if (temp[i][j] > 80) {
                // Вычисляем 10% от нагрузки для перераспределения
                int loadToRedistribute = round(temp[i][j] * 0.1);

                // Уменьшаем нагрузку на перегруженном узле
                load[i][j] = temp[i][j] - loadToRedistribute;

                // Вычисляем нагрузку для каждого из остальных узлов
                int loadPerNode = loadToRedistribute / (n - 1);

                // Распределяем нагрузку на остальные узлы
                for (int k = 0; k < n; k++) {
                    if (k != i) {
                        load[k][j] = temp[k][j] + loadPerNode;
                        // Гарантируем, что нагрузка не превысит 100%
                        if (load[k][j] > 100) {
                            load[k][j] = 100;
                        }
                    }
                }
            }
        }
    }

    // Освобождаем временную матрицу
    for (int i = 0; i < n; i++) {
        delete[] temp[i];
    }
    delete[] temp;
}

// Этап 3: Определение критического интервала с использованием арифметики указателей
int findCriticalInterval(int** load, int n, int t) {
    int maxTotalLoad = 0;      // Максимальная суммарная нагрузка
    int criticalInterval = 0;  // Индекс критического интервала

    // Проходим по всем временным интервалам
    for (int j = 0; j < t; j++) {
        int totalLoad = 0;
        // Суммируем нагрузку всех узлов в текущем интервале
        // Используем арифметику указателей как требуется в задании
        for (int i = 0; i < n; i++) {
            totalLoad += *(*(load + i) + j);  // Эквивалентно load[i][j]
        }

        // Проверяем, является ли текущий интервал критическим
        if (totalLoad > maxTotalLoad) {
            maxTotalLoad = totalLoad;
            criticalInterval = j;
        }
    }

    return criticalInterval;
}

// Функция для вывода средних нагрузок
void printAverages(double* averages, int nodes) {
    cout << "\nСредняя нагрузка узлов:" << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < nodes; i++) {
        cout << "Узел " << i << ": " << averages[i] << "%" << endl;
    }
}

// Функция для вывода информации о критическом интервале
void printCriticalInfo(int** load, int nodes, int intervals, int critical) {
    int totalLoad = 0;
    // Вычисляем суммарную нагрузку в критическом интервале
    for (int i = 0; i < nodes; i++) {
        totalLoad += load[i][critical];
    }

    cout << "\nКритический интервал: " << critical
        << " (суммарная нагрузка = " << totalLoad << "%)" << endl;
}

// Функция для освобождения памяти
void freeMemory(int** load, double* averages, int nodes) {
    // Освобождаем матрицу нагрузок
    for (int i = 0; i < nodes; i++) {
        delete[] load[i];
    }
    delete[] load;

    // Освобождаем массив средних значений
    delete[] averages;
}

int main() {
    setlocale(LC_ALL, "RU");

    int n, t;

    // Ввод параметров системы
    cout << "Введите количество узлов и интервалов: ";
    cin >> n >> t;

    // Проверка корректности ввода
    if (n <= 0 || t <= 0) {
        cout << "Ошибка: количество узлов и интервалов должно быть положительным!" << endl;
        return 1;
    }

    // Создание и заполнение матрицы нагрузок
    int** load = createLoadMatrix(n, t);
    generateRandomLoad(load, n, t);

    // Вывод исходных данных
    cout << "\n=== ИСХОДНЫЕ ДАННЫЕ ===";
    printMatrix(load, n, t, "Исходная матрица нагрузок");

    // Этап 1: Анализ баланса нагрузки
    double* averages = averageLoadPerNode(load, n, t);
    printAverages(averages, n);

    // Этап 3: Определение критического интервала (до нормализации)
    int criticalBefore = findCriticalInterval(load, n, t);
    printCriticalInfo(load, n, t, criticalBefore);

    // Этап 2: Нормализация нагрузки
    normalizeLoad(load, n, t);

    // Вывод результатов после нормализации
    cout << "\n=== РЕЗУЛЬТАТЫ ПОСЛЕ НОРМАЛИЗАЦИИ ===";
    printMatrix(load, n, t, "Матрица нагрузок после нормализации");

    // Пересчет средних значений после нормализации
    delete[] averages;  // Освобождаем старый массив
    averages = averageLoadPerNode(load, n, t);
    printAverages(averages, n);

    // Определение критического интервала после нормализации
    int criticalAfter = findCriticalInterval(load, n, t);
    printCriticalInfo(load, n, t, criticalAfter);

    // Этап 5: Освобождение памяти
    freeMemory(load, averages, n);

   

    return 0;
}