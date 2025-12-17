#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    // Создание вектора с логами системы
    vector<string> logs = {
        "INFO: Start",
        "ERROR: Disk failure",
        "WARNING: Low memory",
        "ERROR: Disk failure",
        "INFO: Stop"
    };

    // Обертывание вектора в shared_ptr для безопасного разделяемого владения
    shared_ptr<vector<string>> pLogs = make_shared<vector<string>>(logs);

    // Создание коллекции для хранения сообщений об ошибках
    vector<string> errors;

    // Лямбда-функция для фильтрации ошибок - проверяет наличие подстроки "ERROR"
    auto isError = [](const string& log) {
        return log.find("ERROR") != string::npos;
        };

    // Копирование только сообщений об ошибках в новую коллекцию
    copy_if(pLogs->begin(), pLogs->end(), back_inserter(errors), isError);

    // Удаление дублирующихся строк из коллекции ошибок
    sort(errors.begin(), errors.end());
    auto last = unique(errors.begin(), errors.end());
    errors.erase(last, errors.end());

    // Вывод исходного журнала
    cout << "Исходный журнал:" << endl;
    for (const auto& log : *pLogs) {
        cout << log << endl;
    }

    // Вывод очищенного списка ошибок
    cout << "\nОшибки:" << endl;
    for (const auto& error : errors) {
        cout << error << endl;
    }

    return 0;
}