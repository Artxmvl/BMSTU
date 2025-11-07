#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0)); // Инициализация генератора случайных чисел

    // Варианты для случайного выбора
    vector<string> sensors = { "Temperature", "Pressure", "Voltage", "Current", "Humidity" };
    vector<string> statuses = { "stable", "high", "low", "critical", "normal" };
    vector<string> systems = { "nominal", "optimal", "degraded", "excellent" };

    // Создание трех умных указателей со случайными данными
    unique_ptr<string> part1 = make_unique<string>(
        sensors[rand() % sensors.size()] + " data: " + to_string(20 + rand() % 30)
    );
    unique_ptr<string> part2 = make_unique<string>(
        "Voltage " + statuses[rand() % statuses.size()] + "."
    );
    unique_ptr<string> part3 = make_unique<string>(
        "System " + systems[rand() % systems.size()] + "."
    );

    // Сохранение указателей в вектор
    vector<unique_ptr<string>> reportParts;
    reportParts.push_back(move(part1));
    reportParts.push_back(move(part2));
    reportParts.push_back(move(part3));

    // Лямбда-функция для объединения строк через символ \n
    auto concatParts = [](const vector<unique_ptr<string>>& parts) -> string {
        string result;
        for (const auto& part : parts) {
            if (!result.empty()) {
                result += "\n";
            }
            result += *part;
        }
        return result;
        };

    // Лямбда-функция для подсчета вхождений слова
    auto countWord = [](const string& text, const string& word) -> int {
        int count = 0;
        size_t pos = 0;
        while ((pos = text.find(word, pos)) != string::npos) {
            count++;
            pos += word.length();
        }
        return count;
        };

    // Объединение частей в единый текст
    string report = concatParts(reportParts);

    // Подсчет вхождений слова "data"
    int wordCount = countWord(report, "data");

    // Вывод результатов
    cout << "Отчёт:" << endl;
    cout << report << endl;

    cout << "Слово \"data\" встречается " << wordCount << " раз" << endl;

    return 0;
}