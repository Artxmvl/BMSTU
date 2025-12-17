#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    setlocale(LC_ALL, "RU");

    // Создаем вектор со 100,000 чисел
    vector<int> numbers(100000);
    for (int i = 0; i < 100000; i++) {
        numbers[i] = i + 1;
    }

    // Лямбда-функция для измерения времени
    auto measure_time = [](const string& method_name, auto function) {
        auto start = steady_clock::now();
        function();
        auto end = steady_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << method_name << ": " << duration.count() << " мс" << endl;
        };

    cout << "СРАВНЕНИЕ СКОРОСТИ ЗАПИСИ В ФАЙЛ" << endl;
    cout << "================================" << endl;

    // Метод 1: Запись каждого числа по отдельности
    measure_time("По одному числу", [&numbers]() {
        ofstream file1("method1.bin", ios::binary);
        for (int num : numbers) {
            file1.write(reinterpret_cast<char*>(&num), sizeof(num));
        }
        file1.close();
        });

    // Метод 2: Запись всех чисел сразу
    measure_time("Все числа сразу", [&numbers]() {
        ofstream file2("method2.bin", ios::binary);
        file2.write(reinterpret_cast<char*>(numbers.data()), numbers.size() * sizeof(int));
        file2.close();
        });

    return 0;
}