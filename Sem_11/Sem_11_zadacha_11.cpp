#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    // Чтение данных из файла
    ifstream file("sensor_data.txt");
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    vector<double> temperatures;
    double temp;

    cout << "ЧТЕНИЕ ДАННЫХ С ДАТЧИКОВ" << endl;
    cout << "========================" << endl;

    // Чтение и фильтрация данных
    while (file >> temp) {
        // Фильтрация корректных значений
        if (temp >= -50 && temp <= 50) {
            temperatures.push_back(temp);
            cout << "Корректное значение: " << temp << "°C" << endl;
        }
        else {
            cout << "Некорректное значение: " << temp << "°C" << endl;
        }
    }
    file.close();

    // Вычисление средней температуры
    if (!temperatures.empty()) {
        double sum = accumulate(temperatures.begin(), temperatures.end(), 0.0);
        double average = sum / temperatures.size();

        // Сохранение отфильтрованных данных
        ofstream out("filtered_sensor_data.txt");
        for (double t : temperatures) {
            out << t << endl;
        }
        out.close();

        // Вывод результатов
        cout << "\nРЕЗУЛЬТАТЫ:" << endl;
        cout << "===========" << endl;
        cout << "Корректных значений: " << temperatures.size() << endl;
        cout << "Средняя температура: " << average << "°C" << endl;
        cout << "Отфильтрованные данные сохранены в filtered_sensor_data.txt" << endl;
    }
    else {
        cout << "Нет корректных данных для анализа!" << endl;
    }

    return 0;
}