#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createConfig() {
    ofstream file("config.json");
    file << "{\n";
    file << "    \"app_name\": \"My Application\",\n";
    file << "    \"version\": \"1.0.0\",\n";
    file << "    \"settings\": {\n";
    file << "        \"max_connections\": 100,\n";
    file << "        \"timeout\": 30,\n";
    file << "        \"debug_mode\": true\n";
    file << "    },\n";
    file << "    \"database\": {\n";
    file << "        \"host\": \"localhost\",\n";
    file << "        \"port\": 5432,\n";
    file << "        \"username\": \"admin\"\n";
    file << "    }\n";
    file << "}";
    file.close();
    cout << "Конфигурационный файл создан\n";
}

void readConfig() {
    ifstream file("config.json");
    string line;
    cout << "Текущие настройки:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void changeConfig() {
    // Читаем весь файл
    ifstream in("config.json");
    string content, line;
    while (getline(in, line)) content += line + "\n";
    in.close();

    // Меняем timeout
    size_t pos = content.find("\"timeout\": 30");
    if (pos != string::npos) {
        content.replace(pos, 13, "\"timeout\": 60");
    }

    // Записываем обратно
    ofstream out("config.json");
    out << content;
    out.close();
    cout << "Timeout изменен с 30 на 60\n";
}

int main() {
    setlocale(LC_ALL, "RU");

    // Создаем конфиг
    createConfig();

    // Читаем и показываем
    readConfig();

    // Меняем настройку
    changeConfig();

    // Показываем изменения
    readConfig();

    return 0;
}