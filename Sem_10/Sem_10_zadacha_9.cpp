#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    // Создание файла с температурными данными 
    ofstream file("temperature_data.txt");
    file << "Sensor1 22.5" << endl;
    file << "Sensor2 21.8" << endl;
    file << "Sensor3 23.1" << endl;
    file << "Sensor1 22.7" << endl;
    file << "Sensor2 22.0" << endl;
    file << "Sensor3 23.3" << endl;
    file.close();

    // Чтение данных из файла
    ifstream readFile("temperature_data.txt");

    vector<double> sensor1, sensor2, sensor3;
    string sensor;
    double temp;

    // Читаем данные и группируем по датчикам
    while (readFile >> sensor >> temp) {
        if (sensor == "Sensor1") sensor1.push_back(temp);
        else if (sensor == "Sensor2") sensor2.push_back(temp);
        else if (sensor == "Sensor3") sensor3.push_back(temp);
    }
    readFile.close();

    // Создание отчёта
    ofstream report("report.txt");

    // Обработка Sensor1
    if (!sensor1.empty()) {
        double min1 = sensor1[0], max1 = sensor1[0], sum1 = 0;
        for (double t : sensor1) {
            if (t < min1) min1 = t;
            if (t > max1) max1 = t;
            sum1 += t;
        }
        report << "Sensor1: min = " << min1 << ", max = " << max1 << ", avg = " << sum1 / sensor1.size() << endl;
    }

    // Обработка Sensor2
    if (!sensor2.empty()) {
        double min2 = sensor2[0], max2 = sensor2[0], sum2 = 0;
        for (double t : sensor2) {
            if (t < min2) min2 = t;
            if (t > max2) max2 = t;
            sum2 += t;
        }
        report << "Sensor2: min = " << min2 << ", max = " << max2 << ", avg = " << sum2 / sensor2.size() << endl;
    }

    // Обработка Sensor3
    if (!sensor3.empty()) {
        double min3 = sensor3[0], max3 = sensor3[0], sum3 = 0;
        for (double t : sensor3) {
            if (t < min3) min3 = t;
            if (t > max3) max3 = t;
            sum3 += t;
        }
        report << "Sensor3: min = " << min3 << ", max = " << max3 << ", avg = " << sum3 / sensor3.size() << endl;
    }

    report.close();

    // Вывод содержимого файла отчёта на экран
    ifstream showReport("report.txt");
    string line;

    cout << "Содержимое отчёта:" << endl;
    while (getline(showReport, line)) {
        cout << line << endl;
    }
    showReport.close();

    return 0;
}