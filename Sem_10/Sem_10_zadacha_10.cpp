#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    // Создание файла с данными энергопотребления
    ofstream file("power_log.txt");
    file << "2025-11-09T08:00:00 MotorA 125" << endl;
    file << "2025-11-09T08:00:00 PumpB 0.95" << endl;
    file << "2025-11-09T08:30:00 MotorA 140" << endl;
    file << "2025-11-09T08:30:00 PumpB 0.90" << endl;
    file << "2025-11-09T09:00:00 MotorA 135" << endl;
    file.close();

    // Чтение и анализ данных
    ifstream readFile("power_log.txt");

    vector<double> motorA, pumpB;
    string timestamp, device;
    double power;

    // Читаем данные и группируем по устройствам
    while (readFile >> timestamp >> device >> power) {
        if (device == "MotorA") motorA.push_back(power);
        else if (device == "PumpB") pumpB.push_back(power);
    }
    readFile.close();

    // Создание отчёта
    ofstream report("energy_report.txt");

    // Обработка MotorA
    if (!motorA.empty()) {
        double totalA = 0;
        for (double p : motorA) {
            totalA += p;
        }
        double averageA = totalA / motorA.size();
        report << "MotorA: measurements = " << motorA.size()
            << ", total = " << totalA << " kWh"
            << ", average = " << averageA << " kW" << endl;
    }

    // Обработка PumpB
    if (!pumpB.empty()) {
        double totalB = 0;
        for (double p : pumpB) {
            totalB += p;
        }
        double averageB = totalB / pumpB.size();
        report << "PumpB: measurements = " << pumpB.size()
            << ", total = " << totalB << " kWh"
            << ", average = " << averageB << " kW" << endl;
    }

    report.close();

    // Вывод содержимого отчёта на экран
    ifstream showReport("energy_report.txt");
    string line;

    cout << "Анализ завершён. Результаты:" << endl;
    while (getline(showReport, line)) {
        cout << line << endl;
    }
    showReport.close();

    return 0;
}