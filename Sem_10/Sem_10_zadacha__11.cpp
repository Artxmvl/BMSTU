#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>  

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    // Создание файла с вибрационными данными
    ofstream file("vibration_log.txt");
    file << "0.02" << endl;
    file << "0.05" << endl;
    file << "0.03" << endl;
    file << "0.10" << endl;
    file << "0.09" << endl;
    file << "0.07" << endl;
    file << "0.15" << endl;
    file << "0.04" << endl;
    file.close();

    // Считываем все значения амплитуды в вектор
    ifstream readFile("vibration_log.txt");
    vector<double> amplitudes;
    double value;

    while (readFile >> value) {
        amplitudes.push_back(value);
    }
    readFile.close();

    // Используем лямбда-функции для анализа
    vector<double> filtered;
    auto filterLambda = [](double x) { return x > 0.05; };
    copy_if(amplitudes.begin(), amplitudes.end(), back_inserter(filtered), filterLambda);

    double sum = 0;
    auto sumLambda = [&sum](double x) { sum += x; };
    for_each(amplitudes.begin(), amplitudes.end(), sumLambda);
    double average = sum / amplitudes.size();

    double minAmplitude = *min_element(amplitudes.begin(), amplitudes.end());
    double maxAmplitude = *max_element(amplitudes.begin(), amplitudes.end());

    // Сохраняем результаты анализа в файл
    ofstream report("vibration_report.txt");
    report << "Количество измерений: " << amplitudes.size() << endl;
    report << "Фильтрованные значения (>0.05): ";
    for (double amp : filtered) {
        report << amp << " ";
    }
    report << endl;
    report << "Среднее значение: " << average << endl;
    report << "Минимум: " << minAmplitude << endl;
    report << "Максимум: " << maxAmplitude << endl;
    report.close();

    //  Выводим содержимое файла в консоль
    cout << "\nСодержимое файла vibration_report.txt:" << endl;
    cout << "----------------------------------------" << endl;

    ifstream showReport("vibration_report.txt");
    string line;  // Объявляем строку ДО цикла

    while (getline(showReport, line)) {  
        cout << line << endl;
    }
    showReport.close();

    return 0;
}