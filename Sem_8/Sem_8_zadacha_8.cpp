#include <iostream>
#include <iomanip>

using namespace std;

// Простая структура для хранения параметров
struct Simulation {
    int rows;
    int cols;
    int steps;
    double** plate;
};

// 1. Создаем пластину
double** makePlate(int rows, int cols) {
    double** plate = new double* [rows];
    for (int i = 0; i < rows; i++) {
        plate[i] = new double[cols];
    }
    return plate;
}

// 2. Удаляем пластину
void clearPlate(double** plate, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] plate[i];
    }
    delete[] plate;
}

// 3. Заполняем начальными значениями
void initPlate(double** plate, int rows, int cols) {
    // Все клетки = 20°C
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            plate[i][j] = 20.0;
        }
    }
    // Центральная клетка = 100°C (нагреватель)
    plate[rows / 2][cols / 2] = 100.0;
}

// 4. Один шаг распространения тепла
void heatStep(double** plate, int rows, int cols) {
    // Создаем копию для новых температур
    double** tempPlate = makePlate(rows, cols);

    int centerRow = rows / 2;
    int centerCol = cols / 2;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == centerRow && j == centerCol) {
                // Нагреватель - всегда 100°C
                tempPlate[i][j] = 100.0;
            }
            else if (i > 0 && i < rows - 1 && j > 0 && j < cols - 1) {
                // Внутренние клетки: среднее 4 соседей
                double up = plate[i - 1][j];
                double down = plate[i + 1][j];
                double left = plate[i][j - 1];
                double right = plate[i][j + 1];

                tempPlate[i][j] = (up + down + left + right) / 4.0;
            }
            else {
                // Крайние клетки не меняются
                tempPlate[i][j] = plate[i][j];
            }
        }
    }

    // Копируем результаты обратно
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            plate[i][j] = tempPlate[i][j];
        }
    }

    // Очищаем временную пластину
    clearPlate(tempPlate, rows);
}

// 5. Показываем пластину
void displayPlate(double** plate, int rows, int cols) {
    cout << fixed << setprecision(1);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << plate[i][j];
        }
        cout << endl;
    }
    cout << "------------------------" << endl;
}

int main() {
    setlocale(LC_ALL, "RU");


    int rows, cols, steps;
    cout << "Введите размеры (строки столбцы): ";
    cin >> rows >> cols;
    cout << "Введите количество шагов: ";
    cin >> steps;

    // Создаем пластину
    double** plate = makePlate(rows, cols);
    initPlate(plate, rows, cols);

    cout << "\nНачальное состояние:" << endl;
    displayPlate(plate, rows, cols);

    // Выполняем шаги
    for (int step = 1; step <= steps; step++) {
        heatStep(plate, rows, cols);

        if (step % 5 == 0 || step == steps) {
            cout << "Шаг " << step << ":" << endl;
            displayPlate(plate, rows, cols);
        }
    }

    // Очищаем память
    clearPlate(plate, rows);

    cout << "Готово!" << endl;
    return 0;
}